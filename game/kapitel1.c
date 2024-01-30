#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"

bool getInput1();
bool parseExecute1(char *input, char *progressionInit);

static char input[100];
static char progressionInit[5] = "0";

int main1()
{
    printf("\nDeine Muskel fühlen sich schwach an, aber du stehst nun.\nDu scheinst dich in einem alten Schlafzimmer zu befinden.\n");
    printf(BLU);
    printf("TUTORIAL:\nDir stehen nun verschiedene Aktionen zur Verfügung:\n- lookaround\n- inspect\n- pickup\n- goto\n- open\n- use");
    printf(RESET);
    while(1)
    {
       if(getInput1())
            parseExecute1(input, progressionInit);
        else
            return 0;
    } 
    return 0;
}

bool getInput1()
{
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}

bool parseExecute1(char *input, char *progressionInit)
{
    char *choice = strtok(input, " \n");
    char *progression = strtok(progressionInit, " \n");
    if (choice != NULL)
    {
        if (strcmp(choice, "quit") == 0)
        {
            printf("Shutting down...");
            exit(1);
        }
        // Keine Progression
        if (strcmp(choice, "lookaround") == 0 && strcmp(progression, "0") == 0)
        {
            printf("Das Zimmer hat keine Fenster und es ist sehr dunkel.\nDeine Sicht ist immer noch verschwommen und du musst dich anstrengen mehr als nur Silhoutten von Objekten um dich herum zu erkennen.\nIn dem Zimmer befindet sich ein altes "); 
            printf(BLU);
            printf("Bett");
            printf(RESET);
            printf(", alter ");
            printf(BLU);
            printf("Schreibtisch "); 
            printf(RESET);  
            printf("aus Holz, ein ");
            printf(BLU);
            printf("Kleiderschrank ");
            printf(RESET);
            printf("und ein mit Holzplanken verbarrikadiertes ");
            printf(BLU);
            printf("Fenster. "); 
            printf(RESET);
            printf("An der Wand hängt ein eingerahmtes ");
            printf(BLU);
            printf("Bild. ");
            printf(RESET);
            printf("Du fragst dich warum du überhaupt hier bist.");
        }
        else if (strcmp(choice, "inspect Bett") == 0)
        {
            printf("Das Bett ist verstaubt, sieht jedoch trotzdem wie frisch gemacht aus.\nDas Bett erinnert dich an deine Müdigkeit und du würdest dich am liebsten einfach wieder schlafen legen.\n");
        }
        else if (strcmp(choice, "inspect Schreibtisch") == 0)
        {
            printf("Der Schreibtisch sieht uralt aus.\nEr hat eine "); 
            printf(BLU);
            printf("Schublade");
            printf(RESET);
            printf(" und es liegt ein ");
            printf(BLU);
            printf("Kulli");
            printf(RESET);
            printf(" und ein ");
            printf(BLU);
            printf("Zettel ");
            printf(RESET);
            printf("auf der Schreibfläche.");
        }
        
    }
return true;
}