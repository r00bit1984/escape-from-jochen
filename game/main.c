#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include"kapitel0.h"
#include"kapitel1.h"
#include"kapitel2.h"
#include"kapitel3.h"

#define BCYN "\e[1;36m"
#define reset "\e[0m"

int main()
{
	puts(" _____                            __                         ___            _");    
	puts("|  ___|                          / _|                       |_  |          | |");               
	puts("| |__ ___  ___ __ _ _ __   ___  | |_ _ __ ___  _ __ ___       | | ___   ___| |__   ___ _ __");  
	puts("|  __/ __|/ __/ _` | '_ \\ / _ \\ |  _| '__/ _ \\| '_ ` _ \\      | |/ _ \\ / __| '_ \\ / _ \\ '_ \\"); 
	puts("| |__\\__ \\ (_| (_| | |_) |  __/ | | | | | (_) | | | | | | /\\__/ / (_) | (__| | | |  __/ | | |");
	puts("\\____/___/\\___\\__,_| .__/ \\___| |_| |_|  \\___/|_| |_| |_| \\____/ \\___/ \\___|_| |_|\\___|_| |_|");
	puts("                   | |");                                                                       
	puts("                   |_|");                                                                       
	main0();
	main1();
	main2();
	main3();
	printf(BCYN);
	printf("\n\nVielen Dank fürs Spielen von: Escape from Jochen!\n");
	printf("     Tobias Wiedemann\n");
	printf("     Robert Limberger\n");
	printf("     Pratyaksh Jain\n\n\n\n");
	printf(reset);
	return 0;
}
