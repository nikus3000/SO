#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<3;i++)
    {
        switch(fork())
        {
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execl("./program1","program1",NULL);
            perror("execl error");
            _exit(2);
        default:
            break;
        }
        sleep(2);
    }
    return 0;
}
