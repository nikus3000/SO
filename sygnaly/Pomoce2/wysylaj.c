#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
 
int main(int argc, char ** argv) {
	if (argc != 3) {
		perror ("Nieprawidlowa liczba argumentow.");
		exit (EXIT_FAILURE);
	}

	char * dzialanie = argv[1];
	int sygnal = atoi (argv[2]);

	printf("Otwieram program obsluga.x z parametrem %s\n", dzialanie) ;
	int pid = fork() ;
	switch ( pid ) {
		case -1:
			perror ("Blad funkcji fork()\n");
			exit (EXIT_FAILURE);
			break;
		case 0:
			execl ("obsluga.x", "obsluga.x", dzialanie, (char*) NULL);
			break;
		default:
			printf ("Sygnal %d wyslany do procesu %d\n", sygnal, pid);
			kill (pid, sygnal);
			break;
	}
	return EXIT_SUCCESS;
}

