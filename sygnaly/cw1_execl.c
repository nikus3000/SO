#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//void my_sighandler(int sig_nr)
//{
//printf("Przechwycono sygnal nr %d \n",sig_nr);
//}

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
    
    int pid=fork();
    switch(fork())
    {
        case -1:
            perror("Niepoprawne dzialanie funkcji fork() \n");
            exit(EXIT_FAILURE);
            break;
        case 0:
            execl("./cw1_2","cw1_2",f,s,NULL);
            break;
        default:
            printf("Wysłano sygnal %d do procesu %d\n",s, pid);
            kill(pid,s);
            break;
    }

    
  /*  if (f==1)
    {
        if(signal(s, SIG_DFL)==SIG_ERR)
        {
            perror("Funkcja SIG_DFL ma problem z wybranym sygnalem \n");
            exit(1);
        }
    }
    if(f==2)
    {
        
        if(signal(s, SIG_IGN)==SIG_ERR)
        {
            perror("Funkcja SIG_IGN ma problem z wybranym sygnalem \n");
            exit(2);
        }
    }
    if(f==3)
    {
        if(signal(s, my_sighandler)==SIG_ERR)
        {
            perror("Funkcja my_sighandler ma problem z wybranym sygnalem \n");
            exit(3);
        }
    }
    pause();
    */
  
    return 0;
}
