#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"
#define GRN "\e[0;32m"

#include "inventory.h"

bool getInput2();
bool parseExecute2(char *input, char *progressionInit);

static char input[100];
static char progressionInit[20] = "0";

int bildCount = 0;
bool workBench = false;
bool hasBow = false;

int main2()
{
    printf("Du stehst nun in einem langen, dunklen Flur.\nAn den Wänden hängen noch mehr ");
    printf(BLU);
    printf("Bilder");
    printf(RESET);
    printf(" von Personen, die du nicht erkennst.\nUnter jedem Bild wurde ein Namensschild ");
    printf("angebracht.");
    /*
    while(1)
    {
       if(getInput2())
            parseExecute2(input, progressionInit);
        else
            return 0;
    }
    return 0;
    */
    while (getInput2() && parseExecute2(input, progressionInit))
        ;
    return 0;
}

bool getInput2()
{
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}

bool parseExecute2(char *input, char *progressionInit)
{
    char *choice = strtok(input, " \n");
    if (choice != NULL)
    {
        if (strcmp(choice, "quit") == 0)
        {
            printf("Shutting down...");
            exit(1);
        }
        // Inventar
        else if (strcmp(choice, "inventory") == 0 || strcmp(choice, "Inventory") == 0)
        {
            printf("In deinem Inventar befinden sich:\n");
            for (int i = 0; i < itemCount; i++)
            {
                printf("%s\n", inventory[i]);
            }
        }
        else if (strcmp(choice, "lookaround") == 0 && workBench == false)
        {
            printf("Du stehst nun in einem langen, dunklen Flur.\nAn den Wänden hängen noch mehr ");
            printf(BLU);
            printf("Bilder");
            printf(RESET);
            printf(" von Personen, die du nicht erkennst.\nUnter jedem Bild wurde ein Namensschild ");
            printf("angebracht.");
            printf(BLU);
            printf("\n\nTipp: Benutze den Befehl `inspect.Bild` um weiter zu kommen.");
            printf(RESET);
        }
        // Bild der Lehrerin
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 0)
        {
            printf("Du stehst nun vor dem ersten Bild. Der eiskalte Blick einer Dame mittleren Alters guckt auf dich herab.\nAuf einmal hast du wieder diese unbekannte Stimme in deinem Kopf:\n\n");
            printf(BRED);
            printf("Wie konntest du nur sowas zu mir sagen. Ich war doch gerade erst in der zweiten Klasse.\nAus mir würde nie etwas werden meinte die alte Schachtel zu mir.\nKein Wunder das ich danach nie wieder etwas hinbekommen habe in der Schule.");
            printf(RESET);
            printf("\n\nDir läuft es kalt den Rücken runter. Auf dem Namensschild ließt du: Frau Karen, Klassenlehrerin 2. Klasse\nDu gehst weiter zum nächsten Bild.\n");
            bildCount++;
        }

        // Bild seines Freundes
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 1)
        {
            printf("Du erkennst einen blassen, schmächtigen Jungen auf dem Bild. Wieder kommt diese unangenehme Stimme in deinen Kopf:\n\n");
            printf(BRED);
            printf("Wir waren doch immer beste Freunde, wie konntest du nur sowas in deinem Sterbebett zu mir sagen. Du hast mich immer gehasst.\nWieso? Ich war doch immer so nett zu dir.\n\n");
            printf(RESET);
            printf("\nEin mieses Gefühl sticht dir in den Magen. Langsam wendest du dich vom Bild und läufst weiter");

            bildCount++;
        }

        // Bild seines Bruders
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 2)
        {
            printf("Du bleibst vor dem nächsten Bild stehen. Auf diesem ist ein Mann in seinen zwanzigern abgebildet.\nUnbekannte Stimme:\n\n");
            printf(BRED);
            printf("Mein Bruder... wir hätten eine so enge Verbindung haben müssen, aber du hast dich immer einen Dreck um mich gescherrt.\nDu hast dich immer für etwas besseres gehalten, immer auf mich herab geblickt.\nDas werde ich dir NIE verzeihen.\n\n");
            printf(RESET);
            printf("\nDiese Worte hallen in deinem Kopf nach. Du wunderst dich ob du je Geschwister hattest, doch findest du keine Antwort darauf.\nSchnell gehst du weiter.");
            bildCount++;
        }
        // Bild seines Vaters
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 3)
        {
            printf("Das nächste Bild lässt dich sofort erstarren. Noch nie hast du einen Mann gesehen, der nur durch sein Erscheinungsbild so eine Autorität und Schrecken ausstrahlt.\nWieder spricht die unbekannte Stimme zu dir, diesmal voller Hass und... ist das Angst?\n\n");
            printf(BRED);
            printf("Mit dir hat alles angefangen. Wieso nur musste ich als dein Sohn geboren werden?\nSeit dem Tag meiner Geburt hast du mich immer wieder wissen lassen das ich der Schandfleck unserer Familie bin.\nWas nur habe ich getan um das zu verdienen?\nIch war nie gut genug für dich, du hattest nur Interesse für meinen Bruder.\nDafür werde ich dich immer HASSEN!.\n\n");
            printf(RESET);
            printf("\nIn deinem ganzen Körper macht sich diesen ungute Gefühl breit, welches dich für kurze Zeit lähmt. Es ist eine Mischung aus Traurigkeit und Mitleid. Du willst nurnoch weg von hier und läufst weiter zum nächsten Bild.");
            bildCount++;
        }
        // Bild seiner Frau
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 4)
        {
            printf("Du schaust dir das nächste Bild an.\nAbgebildet ist eine Frau, die dich mit einem warmen Lächeln anschaut.\nUnbekannte Stimme:\n\n");
            printf(BRED);
            printf("Du warst das einzig gute was ich hatte und du hast mich einfach so verlassen. Du hast mich einfach so zurückgelassen. Wie hätte ich ohne dich weitermachen können?\n\n");
            printf(RESET);
            printf("\nDu frägst dich, ob du jemals verheiratet warst.\n");
            printf("Du begiebst dich Richtung des letzten Bilds.");
            bildCount++;
        }
        // Bild von Jochen
        else if (strcmp(choice, "inspect.Bild") == 0 && bildCount == 5)
        {
            printf("Als du vor dem letzten Bild im Flur stehen bleibst, erkennst du den Mann sofort wieder.\nEs ist der selbe Mann wie auf dem Bild im Schlafzimmer.\nUnbekannte Stimme:\n\n");
            printf(BRED);
            printf("Mein Leben war von Anfang an zum scheitern verurteilt. Es hätte nie was aus mir werden können.\nMeinem Sohn wäre es niemals so ergangen. Ich hätte ihm all die Liebe und Zuneigung gegeben die mir verwährt wurde.\nHätte ich doch nur die Chance dazu gehabt...");
            printf(RESET);
            printf("\n\nLangsam wendest du von dem letzten Bild ab.\n");
            printf("Am Ende des Flures erblickst du eine ");
            printf(BLU);
            printf("Werkbank");
            printf(RESET);
            printf(".\nVielleicht kannst du dort etwas nützliches anfertigen wenn du die richtigen Sachen bei dir hast. Neben der Werkbank befindet sich eine");
            printf(BLU);
            printf(" Tür");
            printf(RESET);
            workBench = true;
            printf(BLU);
            printf("\n\nTipp: Verwende den Befehl ´craft.Bogen´ um die Werkbank zu benutzen.");
            printf(RESET);
        }

        else if (strcmp(choice, "lookaround") == 0 && workBench == true)
        {
            printf("Du stehst vor der Werkbank. Vielleicht kannst du dort etwas nützliches anfertigen wenn du die richtigen Sachen bei dir hast. Recht neben der Werkbank scheint sich eine offene ");
            printf(BLU);
            printf("Tür");
            printf(RESET);
            printf(" zu befinden.");
        }

        else if (strcmp(choice, "craft.Bogen") == 0 && workBench == true)
        {
            int foundHolzstock = 0;
            int foundAst = 0;
            int foundFeder = 0;
            int foundFaden = 0;
            int found = 0;

            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Holzstock") != NULL)
                {
                    foundHolzstock = 1;
                    break;
                }
            }
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Ast") != NULL)
                {
                    foundAst = 1;
                    break;
                }
            }
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Feder") != NULL)
                {
                    foundFeder = 1;
                    break;
                }
            }
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Faden") != NULL)
                {
                    foundFaden = 1;
                    break;
                }
            }
            if (foundHolzstock && foundAst && foundFeder && foundFaden)
            {
                found = 1;
            }
            if (found)
            {
                printf("Du hast einen Bogen gecraftet.\n");
                if (itemCount < 10)
                {
                    strncpy(inventory[itemCount].name, "Bogen", sizeof(inventory[itemCount].name) - 1);
                    itemCount++;
                    printf("Du hast nun einen Bogen in deinem Inventar. Das wird bestimmt noch nützlich sein.");
                    memset(inventory, 0, sizeof(inventory));

                    strncpy(inventory[1].name, "Bogen", sizeof(inventory[1].name) - 1);
                    strncpy(inventory[2].name, "Schlüssel", sizeof(inventory[2].name) - 1);
                    strncpy(inventory[3].name, "Brecheisen", sizeof(inventory[3].name) - 1);
                    itemCount = 2;
                    hasBow = true;
                }
                else
                {
                    printf("Deine Taschen sind schon komplett gefüllt.");
                }
            }
            else
            {
                printf("Du hast nicht die nötigen Materialien um einen Bogen zu craften.");
            }
        }

        else if (strcmp(choice, "craft.Bogen") == 0 && hasBow == true)
        {
            printf("Du hast bereits einen Bogen in deinem Inventar.");
        }

        else if (strcmp(choice, "help") == 0 && workBench == false)
        {
            printf(BLU);
            printf("\nDu kannst folgende Befehle eingeben:\n");
            printf("1. `inventory` um dein Inventar zu sehen\n");
            printf("2. `lookaround` um dich umzusehen\n");
            printf("3. `inspect.Bild` um ein Bild zu inspizieren\n");
            printf("4. `quit` um das Spiel zu beenden\n");
            printf(RESET);
        }

        else if (strcmp(choice, "help") == 0 && workBench == true)
        {
            printf(BLU);
            printf("\nDu kannst folgende Befehle eingeben:\n");
            printf("1. `inventory` um dein Inventar zu sehen\n");
            printf("2. `lookaround` um dich umzusehen\n");
            printf("3. `inspect.Bild` um ein Bild zu inspizieren\n");
            printf("4. `quit` um das Spiel zu beenden\n");
            printf("5. `craft.Bogen` um einen Bogen zu craften\n");
            printf("goto.Tür um die Türe zu öffnen und fortzufahren\n");
            printf(RESET);
        }
        else if ((strcmp(choice, "use.Tür") == 0 || strcmp(choice, "open.Tür") == 0 || strcmp(choice, "goto.Tür") == 0) && workBench == true)
        {
            printf("Du öffnest langsam die Türe und gehst durch sie durch.");
            return 0;
        }

        else
        {
            printf(URED);
            printf("\nDeine Eingabe ist nicht zulässig.\nSchreibe `help` um eine Hilfestellung zu erhalten.\n");
            printf(RESET);
        }
    }
    return 1;
}