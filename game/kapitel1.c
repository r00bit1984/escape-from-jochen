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
static char progressionInit[20] = "0";
typedef struct {
    char name[50]; 
} Item;
Item inventory[10];
int itemCount = 0;

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

void addItem(Item item) {

    inventory[itemCount++] = item;

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
        //Inventar 
        if (strcmp(choice, "inventory") == 0)
        {
            printf("In deinem Inventar befinden sich:\n %s\n", inventory);
        }
        // INSPECT
        else if (strcmp(choice, "lookaround") == 0 && strcmp(progression, "0") == 0)
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
            printf("und eine alte, holzerne ");
            printf(BLU);
            printf("Tür ");
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
        else if (strcmp(choice, "inspect.Tür") == 0)
        {
            printf("Die Tür sieht ganz schön stabil aus.\nDu wirst sie wohl nicht so einfach öffnen können.\nGlücklicherweise hat sie wenigstens ein ");
            printf(BLU);
            printf("Schloss.");
            printf(RESET);
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
        else if (strcmp(choice, "goto.Tür") == 0)
        {
            printf("Du befindest dich jetzt vor der Tür.\nSie ist verschlossen.");
            strcpy(progression, "tür");
        }   

        // Kleiderschrank
        else if (strcmp(choice, "open.Kleiderschrank") == 0 && strcmp(progression, "schrank") != 0)
        {
            printf("Du kannst den Kleiderschrank nicht öffnen, da du nicht nah genug bist.\nVersuche doch mal den command `goto.Kleiderschrank`.");
        }
        else if (strcmp(choice, "open.Kleiderschrank") == 0 && strcmp(progression, "schrank") == 0)
        {
            printf("Du öffnest die schweren Türen des Schranks und wirst\nerst einmal mit einer Ladung Staub begrüßt.\nDu sieht diverse Kleidungsstücke, Jacken, Hemden und Hosen.\nDu siehst einen gläzenden Gegenstand in einer der ");
            printf(BLU);
            printf("Jackentaschen.");
            printf(RESET);
            strcpy(progression, "schrankoffen");
        }
        else if (strcmp(choice, "inspect.Jackentasche") == 0 && strcmp(progression, "schrankoffen") == 0)
        {
            printf("Du bist selbst verwundert dass dir trotz deiner Müdigkeit\nund deines schmerzenden Kopfes der kleine metallische\nGegenstand in der Jackentasche aufgefallen ist. Vielleicht ein ");
            printf(BLU);
            printf("Schlüssel?");
            printf(RESET);
        }
        else if (strcmp(choice, "inspect.Schlüssel") == 0 && strcmp(progression, "schrankoffen") == 0)
        {
            printf("Der Schlüssel ist schon ein wenig angerostet. Er sieht nicht danach aus, als würde er in das Schloss der ");
            printf(BLU);
            printf("Tür ");
            printf(RESET);
            printf("passen.");
        }
        else if (strcmp(choice, "pickup.Schlüssel") == 0 && strcmp(progression, "schrankoffen") == 0)
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "schlüssel", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du hast den Schlüssel aufgehoben und in deine Tasche gesteckt.");
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }

        // Tür
        else if (strcmp(choice, "inspect.Schloss") == 0 && strcmp(progression, "tür") == 0)
        {
            printf("Das Schloss scheint noch in Takt zu sein.\nVielleicht findest du ja irgendwo einen Schlüssel?");
        }
        else if (strcmp(choice, "open.Schloss") == 0 && strcmp(progression, "tür") == 0 && strstr(inventory, "schlüssel") == NULL)
        {
            printf("Das Schloss scheint noch in Takt zu sein.\nVielleicht findest du ja irgendwo einen Schlüssel?");
        }
        else if (strcmp(choice, "open.Schloss") == 0 && strcmp(progression, "tür") == 0 && strstr(inventory, "schlüssel") != NULL)
        {
            printf("Der Schlüssel passt ins Schloss und du hörst ein leises Klicken.\nDie Tür ist nun offen.\nDu stehst nun in einem dunklen Flur.");
        }


        // Schreibtisch
        else if (strcmp(choice, "open.Schublade") == 0 && strcmp(progression, "tisch") != 0)
        {
            printf("Du kannst die Schublade nicht öffnen, da du nicht nah genug bist.\nVersuche doch mal den command `goto.Schreibtisch`.");
        }
        
        else if (strcmp(choice, "open.Schublade") == 0 && strcmp(progression, "tisch") == 0)
        {
            printf("Du öffnest die Schublade und findest darin einen ");
            printf(BLU);
            printf("Faden");
            printf(RESET);
            printf(" und einen ");
            printf(BLU);
            printf("Brief.");
            printf(RESET);
            strcpy(progression, "schubladeoffen");
        }
        
        

        // Fenster
        else if (strcmp(choice, "open.Fenster") == 0 && strcmp(progression, "fenster") != 0)
        {
            printf("Du bist zu weit vom Fenster entfernt.\nVersuche doch mal den command `goto.Kleiderschrank`.");
        }
        else if (strcmp(choice, "open.Fenster") == 0 && strcmp(progression, "fenster") == 0)
        {
            printf("Du versuchst die Bretter vor dem Fenster zu entfernen, doch mit blo.\nVersuche doch mal den command `goto.Kleiderschrank`.");
        }

    }
return true;
}