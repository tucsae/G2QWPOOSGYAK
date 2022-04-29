#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    // 2 csovezetek:
    // - parent_fds: Amit a szulo hasznal hogy a gyereknek irjon
    // - child_fds: Amit a gyerek hasznal hogy a szulonek irjon
    int parent_fds[2], child_fds[2];


    // olvasas:[0] - iras:[1]
    if (pipe(parent_fds) != 0 || pipe(child_fds) != 0)
    {
        printf("Csovek letrehozasa sikertelen!\n");
        return EXIT_FAILURE;
    }


    // Gyerek processz forkolas
    int child = fork();

    if (child < 0)
    {
        printf("Sikertelen forkolas!\n");
        return EXIT_FAILURE;
    }
    else if (child == 0)
    {

        close(child_fds[0]);
        close(parent_fds[1]);

        // Olvasas szulo csovezetekbol
        int parenttol;
        read(parent_fds[0], &parenttol, sizeof(parenttol));
        printf("GYEREK - PID = %d: Beolvastam a szulotol: %d\n", (int)getpid(), parenttol);

        close(parent_fds[0]);


		// PID irasa a gyerek vezetékbe hogy a szulo kiolvassa
		int pid2=getpid();
        write(child_fds[1], &pid2, sizeof(pid2));
        close(child_fds[1]);

        printf("GYEREK - PID = %d: Rairtam a PID-em a csovezetekre!\n\n", pid2);

    }
    else
    {
        // Lezarom a csovezetekeket
        close(parent_fds[0]);
        close(child_fds[1]);

        // PID irasa a szulo vezetekbe hogy a gyerek kiolvassa
		int pid=getpid();
        printf("SZULO - PID = %d: Rairtam a PID-em a csovezetekre!\n\n", pid);


        write(parent_fds[1], &pid, sizeof(pid));
        close(parent_fds[1]);


        // Olvasas gyerek csovezetekbol
        int childtol;
        read(child_fds[0], &childtol, sizeof(childtol));

        close(child_fds[0]);
        printf("SZULO - PID = %d: Csovezetekrol olvasott: %d\n", (int)getpid(), childtol);
    }
    return 0;
}
