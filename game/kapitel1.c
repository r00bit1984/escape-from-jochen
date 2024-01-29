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
    return 0;
}