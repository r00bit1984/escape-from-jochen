#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static char input[100] = "2";
bool getInput();
bool parseExecute();

int main()
{
	printf("Game XY is starting.../n");
	printf("Alles ist dunkel. Dein Schädel brummt und du weißt nicht wo du gerade bist.\n");
	printf("Unbekannte Stimme: \"Wach auch.\"\n");
	printf("1. Versuche dich auf die mysteriöse Stimme zu konzentrieren\n 2. Gehe zurück in den endlosen und friedlichen Zustand der Unwissenheit\n");
	while(parseExecute(input) && getInput());
	printf("/nBye!/n");
}

bool getInput()
{
	printf("/n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

bool parseExecute(char *input)
{
	char *choice = strtok(input, " \n");
	if(choice != NULL)
	{
		if(strcmp(choice, "quit") == 0)
		{
			return false;
		}
		else if (strcmp(choice, "1") == 0)
		{
			printf("platzhalter");
		}
		else if (strcmp(choice, "2") == 0)
		{
			printf("Du merkst wie dich die Müdigkeit wieder zurück in die Dunkelheit zieht.\nDu willst nichts mehr als einfach nur zu schlafen\n");
		}
	}
	return true;
}
