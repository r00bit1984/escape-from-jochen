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

static char input[20];
static char progressionInit[20] = "0";

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
        // INSPECT
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
        else if (strcmp(choice, "inspect.Bett") == 0)
        {
            printf("Das Bett ist verstaubt, sieht jedoch trotzdem wie frisch gemacht aus.\nDas Bett erinnert dich an deine Müdigkeit und du würdest dich am liebsten einfach wieder schlafen legen.\n");
        }
        else if (strcmp(choice, "inspect.Schreibtisch") == 0)
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
        else if (strcmp(choice, "inspect.Kleiderschrank") == 0)
        {
            printf("Der Kleiderschrank ist aus massivem, dunklem Holz.\nVielleicht lässt er sich öffnen?");
        }
        else if (strcmp(choice, "inspect.Fenster") == 0)
        {
            printf("Das Fenster sieht aus als wäre es schon immer verbarrikadiert gewesen.\nDu zweifelst daran die Holzplanken entfernen zu können.");
        }
        else if (strcmp(choice, "inspect.Bild") == 0)
        {
            printf("Das Bild hat einen vergoldeten Rahmen und bildet ein Portät eines Mannes ab.\nDer Mann hat eine aufrechte Position und hat eine stolze Ausstrahlung.\nDu fragst dich wer dieser Mann ist.");
        }
        
        // GOTO
        else if (strcmp(choice, "goto.Bett") == 0)
        {
            printf("Du befindest dich nun vor dem Bett.\nHier gibt es nichts mehr für dich zu tun.");
            strcpy(progression, "bett");
        }
        else if (strcmp(choice, "goto.Schreibtisch") == 0)
        {
            printf("Du befindest dich jetzt vor dem hölzernen Schreibtisch.");
            strcpy(progression, "tisch");
        }
        else if (strcmp(choice, "goto.Kleiderschrank") == 0)
        {
            printf("Du befindest dich jetzt vor dem großen Kleiderschrank.");
            strcpy(progression, "schrank");
        }
        else if (strcmp(choice, "goto.Fenster") == 0)
        {
            printf("Du befindest dich jetzt vor dem Fenster.\nDie Holzplanken wirst du nicht entfernen können.");
            strcpy(progression, "fenster");
        }
        else if (strcmp(choice, "goto.Bild") == 0)
        {
            printf("Du befindest dich jetzt vor dem Gemälde.\nDer Mann hat eine ominöse Ausstrahlung.");
            strcpy(progression, "fenster");
        }

    }
return true;
}