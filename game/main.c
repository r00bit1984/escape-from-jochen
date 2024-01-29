#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include"kapitel0.h"

#define BRED "\e[1;31m"
#define URED "\e[4;31m"
#define BLU "\e[0;34m"
#define RESET "\033[0m"

static char input[100];
static char conLevelInit[5] = "0";

int main()
{
	main0();
}
