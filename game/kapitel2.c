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

int main2()
{
    printf("Du stehst nun in einem langen, dunklen Flur.\nAn den Wänden hängen noch mehr ");
    printf(BLU);
    printf("Bilder");
    printf(RESET); 
    printf(" von Personen, die du nicht erkennst.\nAuf dem Boden vor den Bildern liegen mehrere ");
    printf(BLU);
    printf("Briefe");
    printf(RESET);
    printf(".");
    while(1)
    {
       if(getInput2())
            parseExecute2(input, progressionInit);
        else
            return 0;
    } 
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
    //Inventar 
    if (strcmp(choice, "inventory") == 0 || strcmp(choice, "Inventory") == 0)
    {
        printf("In deinem Inventar befinden sich:\n");
        for(int i = 0; i < itemCount; i++)
        {
        printf("%s\n", inventory[i]);
        }
    }
    if (strcmp(choice, "lookaround"))
    {
        printf("Du stehst nun in einem langen, dunklen Flur.\nAn den Wänden hängen noch mehr ");
        printf(BLU);
        printf("Bilder");
        printf(RESET); 
        printf(" von Personen, die du nicht erkennst.\nAuf dem Boden vor den Bildern liegen mehrere ");
        printf(BLU);
        printf("Briefe");
        printf(RESET);
        printf(".");
    }
}