#define MAKS_DLUGOSC_BLEDU 200
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
 
void sighandler (int sygnal)
{
	printf ("Otrzymalem sygnal %d.\n", sygnal);
}
 
int main (int argc, char *argv[])
{
	char *nazwa_programu = argv[0];
	char *blad;
	blad = malloc (MAKS_DLUGOSC_BLEDU);
	if (argc != 2 && argc != 3)
	{
		sprintf (blad, "Wprowadzono nieprawidlowa liczbe argumentow. Prawidlowa skladnia polecenia: %s <d/i/p> [numer sygnalu]", nazwa_programu);
		perror (blad);
		exit (EXIT_FAILURE);
	}
        char *operacja = argv[1];
	int sygnal ;
	
	sygnal = atoi (argv[2]);
	
 
	if ( strcmp (operacja, "d") == 0 ) /* wykonanie operacji domyslnej dla sygnalu */
	{
		if ( signal (sygnal, SIG_DFL) == SIG_ERR )
		{
			perror ("Ups, SIG_DFL nie radzi sobie z sygnalem.");
			exit (EXIT_FAILURE);
		}
	}
	else if ( strcmp (operacja, "i") == 0 ) /* ignorowanie sygnalu */
	{
		if ( signal (sygnal, SIG_IGN) == SIG_ERR )
		{
			perror ("Ups, SIG_IGN nie radzi sobie z sygnalem.");
			exit (EXIT_FAILURE);
		}
	}
	else if ( strcmp (operacja, "p") == 0 ) /* przechwycenie i wlasna obsluga sygnalu */
	{
		if ( signal (sygnal, sighandler) == SIG_ERR )
		{
			perror ("Ups, sighandler nie radzi sobie z sygnalem.");
			exit (EXIT_FAILURE);
		}
	}
	else
	{
 		pause() ;
		perror ("Wprowadzono nieprawidlowy pierwszy argument. Prawidlowe wartosci: d, i lub p.");
		exit (EXIT_FAILURE);
	}
	printf ("Koniec programu.\n");
	return EXIT_SUCCESS;
}