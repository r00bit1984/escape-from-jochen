# Dokumentation
- Unser Spiel ist in verschiedene `.c` Dateien aufgeteilt (Kapitelweise)
- Jede diese Dateien hat eine zugehörige Header-Datei, in der die Funktionen der einzelnen `.c` Dateien deklariert werden
- Die `main()`-Funktionen der einzelnen Kapitel werden der Übersicht halber einfach in `main.c` aufgerufen
- Verschiedene Bibliotheken werden benutzt, beispielsweise:
  - `stdio.h`: Die Standard-Bibliothek
  - `studbool.h`: Funktionen geben Wahr/Falsch zurück
  - `string.h`: Funktionen wie `strcmp` werden ausgiebig verwendet
  - `stdlib.h`: Für die Funktion `exit`
- Farben werden z.B. verwendet um Gegenstände hervorzuheben, mit denen interagiert werden kann
  - Sie werden als ANSI color codes definiert:
  ```C
  #define BRED "\e[1;31m"
  #define URED "\e[4;31m"
  #define BLU "\e[0;34m"
  #define RESET "\033[0m"
  #define GRN "\e[0;32m"
  ```

- Für das **Erfassen** der Eingaben des Spielers wird eine Funktion `getInput` eingesetzt
```C
bool getInput()
{
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}
```

- Für das **Verarbeiten** der Eingaben des Spielers wird eine Funktion `getInput` eingesetzt\
Ausschnitt der Funktion:
```C
bool parseExecute1(char *input, char *progressionInit)
{
    char *choice = strtok(input, " \n");
    char *progression = strtok(progressionInit, " \n");
    if (choice != NULL)
    {
        if (strcmp(choice, "quit") == 0) // Hier wird definiert, was passiert, wenn der Spieler "quit" eingibt
        {
            printf("Shutting down...");
            exit(1);
        }
        // ... Mehr User-Input
```

- Es werden diverse Variablen angelegt, die den Fortschritt tracken
```C
...
int fadenPickedUp = 0;
int brecheisenPickedUp = 0;
int astPickedUp = 0;
int stockPickedUp = 0;
...
```

- Das Inventar wird in eine seperate `c`-Datei ausgelagert
```C
// inventory.c
#include "inventory.h"

Item inventory[10];
int itemCount;

// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    char name[50];
} Item;

extern int itemCount;
extern Item inventory[10];

#endif // INVENTORY_H
```
  - Um dann das Inventar zu Printen wird folgende Lösung verwendet:
  ```C
  //Inventar
  if (strcmp(choice, "inventory") == 0 || strcmp(choice, "Inventory") == 0)
  {
      printf("In deinem Inventar befinden sich:\n");
      for(int i = 0; i < itemCount; i++)
      {
      printf("%s\n", inventory[i]); // Ausgeben des Inhalts des Inventars
      }
  }
  ```

- Um das Inventar auf die Existenz eines spezifischen Items zu überprüfen musste dann folgende Funktion eingesetzt werden:
```C
if(itemCount < 10)
{
    strncpy(inventory[itemCount].name, "Feder", sizeof(inventory[itemCount].name) - 1); // Hier wird auf das Vorkommen von "Feder" geprüft
    itemCount++; // Der Item Count wird erhöht
    printf("Du nimmst die Feder und verstaust sie in einer Hosentasche.");
    federPickedUp = 1;
}
```




