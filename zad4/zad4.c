#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/param.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
    
void producent(int *filedes)
{
    FILE *input;
    input = fopen("towar.txt","r");

    int chleb;
    close(filedes[0]);
    while(!feof(input))
    {
        printf("============\n");
        fscanf(input,"%d",&chleb);
        if(write(filedes[1],&chleb,sizeof(chleb))==-1)
        {
            perror("Brak miejsca na chleb\n");
            exit(1);
        }
        srand(time(NULL));
        sleep((rand()%4));
    }
    fclose(input);
    close(filedes[1]);

    return;
}


void konsument(int *filedes)
{
    FILE *output;
    output = fopen("odebrane.txt","w");
    
    int chleb;
    close(filedes[1]);
    while(read(filedes[0], &chleb, sizeof(chleb)) >0)
    {
        printf("*********\n");
        fprintf(output,"%d",chleb);
        srand(time(NULL));
        sleep((rand()%4));
    }
    fclose(output);    
    close(filedes[0]);
    return;
}

int main()
{
    int filedes[2];
    if(pipe(filedes)==-1)
    {
        perror("pipe nie działa\n");
        exit(1);
    }
    switch(fork()) 
    {
        case -1:
            perror("Blad funkcji fork()\n");
            exit(1);
        case 0:
            konsument(filedes);
            break;
        default:
            producent(filedes);
            break;
    }
    return 0;
}