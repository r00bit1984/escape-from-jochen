#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool getInput();
bool parseExecute();

static char input[100];
static char conLevelInit[5];

int main()
{
	//conLevelInit = "0";
	printf("Game XY is starting...\n");
	printf("Alles ist dunkel. Dein Schädel brummt und du weißt nicht wo du gerade bist.\n");
	printf("Unbekannte Stimme: \"Wach auch.\"\n");
	printf("1. Versuche dich auf die mysteriöse Stimme zu konzentrieren\n2. Gehe zurück in den endlosen und friedlichen Zustand der Unwissenheit\n");
	while(parseExecute(input, conLevelInit) && getInput());
	printf("\nBye!\n");
}

bool getInput()
{
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

bool parseExecute(char *input, char *conLevelInit)
{
	char *choice = strtok(input, " \n");
	char *conLevel = strtok(conLevelInit, " \n");
	//char *conLevel;
	if(choice != NULL)
	{
		if(strcmp(choice, "quit") == 0)
		{
			return false;
		}
		//Oberste Gesprächsebene, && strcmp(conLevel, "0") == 0
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "0") == 1)
		{
			printf("platzhalter 0");
			conLevel = "1a";
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "0") == 1)
		{
			printf("Du merkst wie dich die Müdigkeit wieder zurück in die Dunkelheit zieht.\nDu willst nichts mehr als einfach nur zu schlafen\n");
			conLevel = "1b";
		}
		//Erste Gesprächsebene A
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "1a") == 0)
		{
			printf("platzhalter 1a1");
			conLevel = "2a";
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "1a") == 0)
		{
			printf("platzhalter 1a2");
			conLevel = "2b";
		}
		//Erste Gesprächsebene B
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "1b") == 0)
		{
			printf("platzhalter 1b1");
			conLevel = "2c";
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "1b") == 0)
		{
			printf("platzhalter 1b2");
			conLevel = "2d";
		}
	}
	return true;
}


/*
else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "1b") == 0)
		{
			printf("platzhalter 1b2");
			conLevel = "2d";
		}
*/