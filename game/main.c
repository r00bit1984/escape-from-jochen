#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include"kapitel0.h"

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"

static char input[100];
static char conLevelInit[5] = "0";

int main()
{
	printf("Game XY is starting...\n");
	printf("\nAlles ist dunkel. Dein Schädel brummt und du weißt nicht wo du gerade bist.\n");
	printf("\nUnbekannte Stimme: ");
	printf(BRED);	
	printf("Wach auf.\n");
	printf(RESET);
	printf("\n1. Versuche dich auf die mysteriöse Stimme zu konzentrieren\n2. Gehe zurück in den endlosen und friedlichen Zustand der Unwissenheit\n");
	while(parseExecute(input, conLevelInit) && getInput());
	printf("\nBye!\n");
	return 0;
}
