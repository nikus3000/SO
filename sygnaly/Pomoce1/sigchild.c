#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int counter;

void signal_handler(int sig_num){
	if(counter++<5){
		printf("...");
	}else{
		exit(0);
	}
	printf("Don't do that!\n");
	
}

int main(int argc, char **argv){
	counter=0;
	signal(SIGINT, signal_handler);
	for(;;){
		pause;
	}
return 0;


}
