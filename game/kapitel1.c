#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"
#define GRN "\e[0;32m"

bool getInput1();
bool parseExecute1(char *input, char *progressionInit);

static char input[100];
static char progressionInit[20] = "0";
typedef struct {
    char name[50]; 
} Item;
Item inventory[10];
int itemCount = 0;
int fensterOpen = 0;
int foundtür = 0;
int foundfenster = 0;
int keyPickedUp = 0;
int federPickedUp = 0;
int fadenPickedUp = 0;
int brecheisenPickedUp = 0;
int astPickedUp = 0;
int main1()
{
    printf("\nDeine Muskel fühlen sich schwach an, aber du stehst nun.\nDu scheinst dich in einem alten Schlafzimmer zu befinden.\n");
    printf(BLU);
    printf("TUTORIAL:\nDir stehen nun verschiedene Aktionen zur Verfügung:\n- lookaround\n- inspect\n- pickup\n- goto\n- open\n- use\n-inventory\n\nExemplarische Benutzung von commands: `goto.Bett`, `inspect.Schreibtisch`");
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
        //Inventar 
        if (strcmp(choice, "inventory") == 0 || strcmp(choice, "Inventory") == 0)
        {
            printf("In deinem Inventar befinden sich:\n");
            for(int i = 0; i < itemCount; i++)
            {
            printf("%s\n", inventory[i]);
            }
        }
        // INSPECT
        else if (strcmp(choice, "lookaround") == 0)
        {
            printf("In dem Zimmer ist es sehr dunkel.\nDeine Sicht ist immer noch verschwommen und du musst dich anstrengen mehr als nur Silhoutten von Objekten um dich herum zu erkennen.\nIn dem Zimmer befindet sich ein altes "); 
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
            printf("Das Bett ist verstaubt, sieht jedoch trotzdem wie frisch gemacht aus.\nDas Bett erinnert dich an deine Müdigkeit und du würdest dich am liebsten einfach wieder schlafen legen.\nUnter dem Bett liegt ein ");
            printf(BLU);
            printf("Holzstock.");
            printf(RESET);
        }
        else if (strcmp(choice, "inspect.Schreibtisch") == 0)
        {
            printf("Der Schreibtisch sieht uralt aus.\nEr hat eine "); 
            printf(BLU);
            printf("Schublade");
            printf(RESET);
            printf(" und es liegt eine ");
            printf(BLU);
            printf("Feder");
            printf(RESET);
            printf("auf der Schreibfläche.");
        }
        else if (strcmp(choice, "inspect.Kleiderschrank") == 0)
        {
            printf("Der Kleiderschrank ist aus massivem, dunklem Holz.\nVielleicht lässt er sich öffnen?");
        }
        else if (strcmp(choice, "inspect.Fenster") == 0 && fensterOpen == 0)
        {
            printf("Das Fenster sieht aus als wäre es schon immer verbarrikadiert gewesen.\nDu zweifelst daran die Holzplanken entfernen zu können.");
        }
        else if (strcmp(choice, "inspect.Fenster") == 0 && fensterOpen == 1)
        {
            printf("Auf dem Vorsprung liegt ein krummer ");
            printf(BLU);
            printf("Ast.");
            printf(RESET);  
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
    
        
        // Bett

        else if(strcmp(choice, "use.Bett") == 0)
        {
            printf("Du fühlst dich zwar sehr müde, aber du kannst nicht einfach wieder schlafen gehen.\nDu musst herausfinden wo du bist und wie du hierher gekommen bist.");
        }
        else if(strcmp(choice, "pickup.Holzstock") == 0)
        {    
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Schlüssel", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du hast den Schlüssel aufgehoben und in deine Tasche gesteckt.");
                keyPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        // GOTO
        else if (strcmp(choice, "goto.Bett") == 0)
        {
            printf("Du befindest dich nun vor dem Bett.");
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
            strcpy(progression, "bild");
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
        else if (strcmp(choice, "inspect.Schlüssel") == 0 && (strcmp(progression, "schrankoffen") == 0 || strstr(inventory, "Schlüssel") != NULL))
        {
            printf("Der Schlüssel ist schon ein wenig angerostet. Er sieht nicht danach aus, als würde er in das Schloss der ");
            printf(BLU);
            printf("Tür ");
            printf(RESET);
            printf("passen.");
        }
        else if (strcmp(choice, "pickup.Schlüssel") == 0 && strcmp(progression, "schrankoffen") == 0 && keyPickedUp == 0)
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Schlüssel", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du hast den Schlüssel aufgehoben und in deine Tasche gesteckt.");
                keyPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        else if (strcmp(choice, "pickup.Schlüssel") == 0 && strcmp(progression, "schrankoffen") == 0 && keyPickedUp == 1)
        {
            printf("Der Schlüssel befindet sich schon in deinem Besitz.");
        }

        // Tür
        else if (strcmp(choice, "inspect.Schloss") == 0 && strcmp(progression, "tür") == 0)
        {
            printf("Das Schloss scheint noch in Takt zu sein.\nVielleicht findest du ja irgendwo einen Schlüssel?");
        }
       
        else if (strcmp(choice, "open.Schloss") == 0 && strcmp(progression, "tür") == 0)
        {
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Schlüssel") != NULL)
                {
                    foundtür = 1;
                    break;
                }
            }
            if (foundtür)
            {
                printf("Der Schlüssel passt ins Schloss und du hörst ein leises Klicken.\nDie Tür ist nun offen.\nDu stehst nun in einem dunklen Flur.");
            }
            else
            {
                printf("Das Schloss scheint noch in Takt zu sein.\nVielleicht findest du ja irgendwo einen Schlüssel?");

            }
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
            printf("Faden, ");
            printf(RESET);
            printf(" einen ");
            printf(BLU);
            printf("Brief");
            printf(RESET);
            printf(" und ein ");
            printf(BLU);
            printf("Brecheisen.");
            printf(RESET);
            strcpy(progression, "schubladeoffen");
        }
        else if (strcmp(choice, "pickup.Brecheisen") == 0 && strcmp(progression, "schubladeoffen") == 0 && brecheisenPickedUp == 0)
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Brecheisen", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du nimmst das schwere Brecheisen in deine Hand und verstaust es in deiner Tasche.");
                brecheisenPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        else if (strcmp(choice, "pickup.Brecheisen") == 0 && strcmp(progression, "schubladeoffen") == 0 && brecheisenPickedUp == 1)
        {
            printf("Das Brecheisen befindet sich schon in deinem Besitz.");
        }
        else if (strcmp(choice, "pickup.Faden") == 0 && fadenPickedUp == 0 && (strcmp(progression, "schubladeoffen") == 0 || strcmp(progression, "tisch") == 0))
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Faden", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du nimmst den Faden in deine Hand und verstaust ihn in deiner Tasche.");
                fadenPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        else if (strcmp(choice, "pickup.Faden") == 0 && fadenPickedUp == 1 && (strcmp(progression, "schubladeoffen") == 0 || strcmp(progression, "tisch") == 0))
        {
            printf("Der Faden befindet sich schon in deinem Besitz.");
        }
        else if (strcmp(choice, "pickup.Feder") == 0 && federPickedUp == 0 && (strcmp(progression, "schubladeoffen") == 0 || strcmp(progression, "tisch") == 0))
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Feder", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du nimmst die Feder und verstaust sie in einer Hosentasche.");
                federPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        else if (strcmp(choice, "pickup.Feder") == 0 && federPickedUp == 1 && (strcmp(progression, "schubladeoffen") == 0 || strcmp(progression, "tisch") == 0))
        {
            printf("Die Feder befindet sich schon in deinem Besitz.");
        }
        else if (strcmp(choice, "pickup.Brief") == 0 && strcmp(progression, "schubladeoffen") == 0)
        {
            printf("Der Brief hat dich irgendwie verängstigt.\nDu lässt ihn lieber in der Schublade.");
        }
        else if (strcmp(choice, "inspect.Brecheisen") == 0 && strcmp(progression, "schubladeoffen") == 0)
        {
            printf("Das Brecheisen ist schwer und rostig.\nEs sieht so aus als könnte es nicht mehr viel Arbeit leisten.");
        }
        else if (strcmp(choice, "inspect.Brief") == 0 && strcmp(progression, "schubladeoffen") == 0)
        {
            printf("Der Brief scheint von jemandem geschrieben worden sein, der sich in einer ähnlichen Situation befunden hat wie du.\nEs steht geschrieben: ");    
            printf(GRN);
            printf("Ich will das alles nicht tun. Ich will nicht mehr hier sein.\nBitte verzeiht mir. Ich hoffe ihr könnt mir verzeihen.\n");
            printf(RESET);
        }
        else if (strcmp(choice, "inspect.Faden") == 0 && strcmp(progression, "schubladeoffen") == 0)
        {
            printf("Der Faden ist aus einem robusten Material und sieht aus als könnte er noch nützlich sein.");
        }
        else if (strcmp(choice, "use.Brecheisen") == 0 && strcmp(progression, "schubladeoffen") == 0)
        {
            printf("Was willst du denn mit einem Brecheisen anfangen?");
        }
        else if (strcmp(choice, "inspect.Feder") == 0 && (strcmp(progression, "tisch") == 0 || strcmp(progression, "schubladeoffen") == 0))
        {
            printf("Die Feder ist voll mit eingetrockneter Tinte und sieht aus als könnte sie vielleicht noch nützlich sein.");
        }



        // Fenster
        else if (strcmp(choice, "open.Fenster") == 0 && strcmp(progression, "fenster") != 0)
        {
            printf("Du bist zu weit vom Fenster entfernt.\nVersuche doch mal den command `goto.Kleiderschrank`.");
        }

        else if (strcmp(choice, "open.Fenster") == 0 && strcmp(progression, "fenster") == 0)
        {
            
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Brecheisen") != NULL)
                {
                    foundfenster = 1;
                    break;
                }
            }
            if (foundfenster)
            {
                printf("Du löst Stück für Stück die Bretter vom Fenster.\nNachdem das letzte Brett auf den Boden fällt, ist es dir möglich nach draußen zu gucken.\n Es ist nahzu komplett dunkel draußen, lediglich der zunehmende Neumond spendet sperlich etwas Licht.\n Du kannst die Umrisse eines düsteren Waldes erkennen,\nweit und breit ist nichts außer kahlen Bäumen, die sich langsam im Wind bewegen.");
                fensterOpen = 1;
            }
            else
            {
                printf("Die Bretter verriegeln das Fenster, es ist dir nicht möglich das Fenster auch nur einen Spalt zu öffnen.");
            }
        }
        else if (strcmp(choice, "use.Fenster") == 0 && strcmp(progression, "fenster") != 0)
        {
            printf("Du bist zu weit vom Fenster entfernt.\nVersuche doch mal den command `goto.Kleiderschrank`.");
        }
        else if (strcmp(choice, "use.Fenster") == 0 && strcmp(progression, "fenster") == 0 && fensterOpen == 0)
        {
            printf("Die Bretter verriegeln das Fenster, es ist dir nicht möglich das Fenster auch nur einen Spalt zu öffnen.");
        }
        else if (strcmp(choice, "use.Fenster") == 0 && strcmp(progression, "fenster") == 0 && fensterOpen == 1)
        {
            printf("Du kletterst vorsichtig aus dem offenen Fenster auf den Vorsprung.\nAls du runterguckst und den Boden in der ferne erblickst, fängt sich alles um dich herum an zu drehen.\nDu verlierst den Halt und rutscht ab in die Tiefe. Das letzte was du merkst ist wie nahezu jeder Knochen deines Körpers durch den Aufprall zerschmettert.");
            printf(BRED);
			printf("\nGAME OVER\n\n");
			printf(RESET);
        }
        }

        else if (strcmp(choice, "pickup.Ast") == 0 && strcmp(progression, "fenster") == 0 && astPickedUp == 0)
        {
            if(itemCount < 10)
            {
                strncpy(inventory[itemCount].name, "Ast", sizeof(inventory[itemCount].name) - 1);
                itemCount++;
                printf("Du nimmst den Ast in deine Hand und verstaust es in deiner Tasche.");
                astPickedUp = 1;
            }
            else 
            {
                printf("Deine Taschen sind schon komplett gefüllt.");
            }
        }
        

        // Bild
        else if (strcmp(choice, "use.Bild") == 0 && strcmp(progression, "bild") == 0)
        {
            printf("Du drehst das Bild um und siehst wie sich die Bildfläche wölbt.\nDu hörst einen entfernten Schrei.\nAus dem Bild tritt eine Hand hervor und greift nach dir.\nDu fühlst wie du in das Bild hineingezogen wirst und alles um dich herum verschwimmt.");
            printf(BRED);
            printf("\n\nGAME OVER\n\n");
            printf(RESET);
            exit(1);
        }
        else if (strcmp(choice, "pickup.Bild") == 0 && strcmp(progression, "bild") == 0)
        {
            printf("Du willst wirklich ein 2m x 1m großes Bild mitnehmen?");
        }
        
        // Cheats
        else if (strcmp(choice, "cheats.allitems") == 0)
        {
            strncpy(inventory[0].name, "Feder", sizeof(inventory[0].name) - 1);
            strncpy(inventory[1].name, "Schlüssel", sizeof(inventory[1].name) - 1);
            strncpy(inventory[2].name, "Faden", sizeof(inventory[2].name) - 1);
            strncpy(inventory[3].name, "Brecheisen", sizeof(inventory[3].name) - 1);
            itemCount = 4;
            printf("Du hast alle Items erhalten.");
        }
  

        
        else if (strcmp(choice, "help") == 0)
		{
			printf(BLU);
			printf("\nTUTORIAL:\nDir stehen nun verschiedene Aktionen zur Verfügung:\n- lookaround\n- inspect\n- pickup\n- goto\n- open\n- use\n-inventory\n\nExemplarische Benutzung von commands: `goto.Bett`, `inspect.Schreibtisch`");
			printf(RESET);
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
