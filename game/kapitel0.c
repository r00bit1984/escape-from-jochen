#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"

bool getInput();
bool parseExecute(char *input, char *conLevelInit);

static char input[100];
static char conLevelInit[5] = "0";

int main(){
	printf("Game XY is starting...\n");
	printf("\nAlles ist dunkel. Dein Schädel brummt und du weißt nicht wo du gerade bist.\n");
	printf("\nUnbekannte Stimme: ");
	printf(BRED);	
	printf("Wach auf.\n");
	printf(RESET);
	printf("\n1. Versuche dich auf die mysteriöse Stimme zu konzentrieren\n2. Gehe zurück in den endlosen und friedlichen Zustand der Unwissenheit\n");
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
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "0") == 0)
		{
			printf("\nDu hörst nun keine Stimme mehr. Du fühlst dich wie im Halbschlaf.\nWarum spricht jemand mit dir? Wahrscheinlich ist es einfach deine Vorstellung...\n");
			printf("1. Versuche dich daran zu erinnern, wer du bist\n2. Versuche etwas in der Dunkelheit um dich herum zu erblicken\n");
			strcpy(conLevel, "1a");
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "0") == 0)
		{
			printf("Du merkst wie dich die Müdigkeit wieder zurück in die Dunkelheit zieht.\nDu willst nichts mehr als einfach nur zu schlafen.\n");
			printf("\n1. Gib auf und lass dich von der Dunkelheit konsumieren.\n2. Greife den letzten Strang der dich noch zurück zur Realität bringen kann.\n");
			strcpy(conLevel, "1b");
		}
		//Erste Gesprächsebene A
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "1a") == 0)
		{
			printf("Du merkst, wie dir jegliche Erinnerung fehlt.\nDu kannst dich nicht einmal an deinen eigenen Namen erinnern.\n1. Versuche etwas in der Dunkelheit um dich herum zu erblicken.\n");
			strcpy(conLevel, "2b");
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "1a") == 0)
		{
			printf("Du konzentriest dich auf deine innere Umgebung und kannst auf einmal ein schwaches Leuchten ausmachen.\nEs bringt dich wieder ein Stück näher an die Realität.\n");
			printf(BLU);
			printf("\n1. <Fortfahren>\n");
			printf(RESET);
			strcpy(conLevel, "2b");
		}
		//Erste Gesprächsebene B
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "1b") == 0)
		{
			printf("\nDu merkst wie du weiter in die Dunkelheit gleitest und dein metaphorischer Körper von einem dunklen Nebel eingehüllt wird.\nDu bist jetzt Teil der Dunkelheit und es gibt keine Chance mehr, dass du je wieder zurück zur Realität gelangst.\n");
			printf(BRED);
			printf("\nGAME OVER\n");
			printf(RESET);
			exit(1);
			strcpy(conLevel, "2c");
		}
		else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "1b") == 0)
		{
			printf("platzhalter 1b2");
			strcpy(conLevel, "2d");
		}
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "2b") == 0)
		{
			printf("\nDas Leuchten wir ein wenig stärker und du fängst an, deinen Körper wieder ein wenig spüren zu können.\nDeine Augenlieder öffnen sich allmählich und deine Sinne werden mit Licht überflutet.\nNach ein paar Momenten merkst du, dass es gar nicht so hell ist.\nDu befindest dich in einem Zimmer und jetzt wo sich deine Augen an das Licht gewöhnt haben merkst du, dass es hier ganz schön dunkel ist.\n1. Richte dich auf.");
			strcpy(conLevel, "3");
		}
		else if (strcmp(choice, "help") == 0)
		{
			printf(BLU);
			printf("In diesem Kapitel kannst du noch keine Aktionen ausführen.\nTippe die Zahlen, die den dir präsentierten Optionen entsprechen und dann Enter.\n");
			printf(RESET);
		}
		else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "3") == 0)
		{
			exit(0);
		}
		else
		{
			printf(URED);
			printf("\nDeine Eingabe ist nicht zulässig.\nSchreibe `help` um eine Hilfestellung zu erhalten.\n");
			printf(RESET);
		}
	}
	return true;
}