#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv){
	int pid;
	switch(pid=fork()){
		case -1:
			perror("fork error");
			exit(1);
		case 0:
			execl("./sigchild.x", "sigchild.x", NULL);
			exit(2);
			break;
		default:
			break;
	}
	sleep(5);
	int i;
	for(i=0; i<6; i++){
		kill(pid, SIGINT);
		sleep(1);
	}
return 0;


}
