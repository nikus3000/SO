#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  printf("PID=%d \n", getpid());
  
    int f; //opcja obslugi
    int s;//nr sygnalu
    
    if (argc>=3)
    {
        f=atoi(argv[1]);
        s=atoi(argv[2]);
        
    }
    else
    {
        perror("Nieprawidlowa liczna argumentow! \n");
        exit(EXIT_FAILURE);
        
    }
    
    printf("Uruchamiam program do obslugi sygnalow... \n");
    
    int i;
    for(i=0;i<3;i++)
    {
        switch(fork())
        {
            case -1:
                perror("Niepoprawne dzialanie funkcji fork() \n");
                exit(EXIT_FAILURE);
                break;
            case 0:
                printf("Tworze proces potomny o PID:%d i GID:%d \n",getpid(),getpgid(getpid()));
                execl("./cw1_2","cw1_2",f,s,NULL);
                exit(0);
            default:
                break;
        }
        sleep(3);
        //printf("Wyslano sygnal %d do grupy procesow o PGID=%d \n",s,getpgid(getpid()));
        //kill(getpgid(getpid()),s);
    }
    
    printf("Wysylam sygnal %d do grupy procesow o PGID=%d \n",s,getpgid(getpid()));
    kill(getpgid(getpid()),s);
    return 0;
}
