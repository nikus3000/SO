

Zawartosc:
Katalog zawiera programy z Zestawu 2 / Sygnaly

I. Program do obslugi sygnalow 
	1) obsluga.c - program glowny

II. Program do obslugi programu obsluga
	1) wysylaj.c - program glowny

III. Uruchamia grupe procesow i wysyla do nich sygnal
	1) grupa.c - program glowny

-------------------------------------------------
Jak uruchomic programy:
=======================

W katalogu znajduje sie Makefile do kompilacji, linkowania 
i uruchamianie programow, a takze do czyszczenia katalogu 
i jego archiwizacji.

-> Aby skompilowac i zlinkowac programy nalezy wykonac komende
	make

-> Aby uruchomic pierwszy program, nalezy wykonac komende
	make obsluga

-> Aby uruchomic drugi program, nalezy wykonac komende
	make wysylaj

-> Aby uruchomic trzeci program, nalezy wykonac komende
	make grupa
	
-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac
	make tar
	
-> W celu wyczyszczenia katalogu nalezy wykonac komende
	make clean
