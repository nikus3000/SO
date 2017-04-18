#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **arv){
	pid_t pid;
	int i, towar, towar2;
	int filedes[2];
	FILE *fin, *fout;
	fin = fopen("source.txt", "r");
	fout = fopen("dest.txt", "w");
	if(pipe(filedes)==-1){ /* open pipe */
		perror("pipe error, sorry");
		exit(-1);
	}
	printf("Mam pipe handles %d, %d\n", filedes[0], filedes[1]);
	sleep(2);
	switch(pid=fork()){
		case -1:
			perror("fork error");
			exit(1);
			break;
		case 0:
			close(filedes[1]);
			do{
				int nread=0;
				nread=read(filedes[0], &towar2, sizeof(towar2));
				if(nread==0){
					break;
				}
				fprintf(fout, "%d\n", towar2);
				/* printf("Consument received item %d\n", towar2); */
			}while(1);
			close(filedes[0]);
			fclose(fout);
			/* printf("Consument exiting\n"); */
			exit(0);
			break;
		default:
			close(filedes[0]);
			for(i=0; i<15; i++){
				fscanf(fin, "%d\n", &towar);
				write(filedes[1], &towar, sizeof(towar));
				/* printf("Producent wrote %d", towar);
				sleep(1); */
			}
			close(filedes[1]); /* zamknac zeby child wiedzial w ifie ze jest end of transmition */
			wait(NULL);
			fclose(fin);
			exit(0);
			break;
		}
return 0;
}
