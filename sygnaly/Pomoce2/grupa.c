#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
 
int main(int argc, char ** argv) {
	int i = 0 ;

	if (argc != 3) {
		perror ("Nieprawidlowa liczba argumentow.");
		exit (EXIT_FAILURE);
	}

	char *dzialanie = argv[1];
	int sygnal = atoi (argv[2]);

	printf("Uruchamiam program obsluga.x z parametrem %s\n", dzialanie) ;

	for(i = 0 ; i < 3 ; i++) {
		switch ( fork() ) {
		case -1:
			perror ("Nie udalo sie utworzyc procesu potomnego.");
			exit (EXIT_FAILURE);
			break;
		case 0:
			break;
		default:
			execl ("obsluga.x", "obsluga.x", dzialanie, (char*) NULL);
			printf("Working!\n");
			break ;
		}
	
		printf("Sygnal %d wyslany do grupy procesow o identyfikatorze %d\n", sygnal, getpgid(getpid()) );
		kill(-getpgid(getpid()), sygnal);
	}

	
	return EXIT_SUCCESS;
}
