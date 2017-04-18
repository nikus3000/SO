#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void signal_handler2(int sig_num) {
	printf("I am the parent. Don't do that!\n");
}

int main(int argc, char **argv){
	int i, pid, gid;
	printf("I'm the parent, my PID is %d and GID is %d\n", getpid(), getpgid(getpid()));
	for(i=0; i<3; i++){
		switch(pid=fork()){
			case -1:
				perror("fork error");
				exit(1);
			case 0:
				printf("I'm the child, my PID is %d and GID %d\n", getpid(), getpgid(getpid()));
				execl("./sigchild.x", "sigchild.x", NULL);
				exit(2);
				break;
			default:
				break;
		}
	}
	gid = getpgid(pid);
	sleep(2);
	signal(SIGINT, signal_handler2);
	for(i=0; i<6; i++){
		kill(-gid, SIGINT);
		sleep(1);
	}
return 0;


}
