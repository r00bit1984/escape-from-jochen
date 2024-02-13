# Programmierprojekt 23F, 1. Semester

# 1. Projektteilnehmer/innen

- Wiedemann, Tobias
- Pratyaksh, Jain
- Limberger, Robert

Kontakt: inf23089@lehre.dhbw-stuttgart.de

&nbsp;

# 2. Projektbeschreibung

- **Aufgabenstellung**: 
  Ein kurzes text-basiertes Videospiel entwickeln. (*Text Adventure Game/Interactive Fiction*)
- **Funktionsumfang**:
  - Der Spieler kann verschiedene Dialogoptionen wählen
  - Das Spiel ist in Kapitel unterteilt
  - Der Spieler kann verschiedene Aktionen ausführen, wie zum Beispiel `inspect`, `lookaround`, `pickup` etc.
  - Kleinere Rätsel um von Raum zu Raum vorwärtszukommen
  - Größtenteils lineares Spiel, jedoch alternative Enden
  - Entscheidungen des Spielers sollen Konsequenzen haben
  - Es soll ein Handbuch/Guide erstellt werden, um Spielern eine Hilfe zu bieten
- **Angestrebte Lösung aus technischer Sicht**:
  - Benutzen von diversen C-Bibliotheken, wie `stdio.h`, `stdbool.h`, `string.h`
  - Die einzelnen Kapitel sollen in verschiedene C-Dateien ausgelagert werden
    - So soll es eine Datei `kapitel0.c`, `kapitel1.c` etc. geben 
  - Die einzelnen .c Dateien für die Kapitel sollen eine minimale `main`-Funktion haben und das Verarbeiten der Spieler-commands soll in den Funktionen "`getInput`" & "`parseExecute`" ausgelagert werden
  - Die beiden Funktionen, mit dem Rückgabewert boolean, werden solange in einer while-Schleife (welche sich in der `main`-Funktion befindet) ausgeführt, bis eine der beiden Funtionen false zurück gibt.
  - Es soll mit Konversationsebenen gearbeitet werden, sodass sich verschiedene Entscheidungen des Spielers auf den Fluss der Unterhaltung/den Verlauf des Spiel auswirken
  - Verschiedene Farben sollen zum Einsatz kommen, z.B. farbliche Kenntmachung von Objekten mit denen interagiert werden kann
  - Die `main.c` Datei soll möglichst minimal gehalten werden
  - Es sollen 3-4 Kapitel programmiert werden
  - Der Spieler kann Hilfe erhalten, wenn er `help` eingibt
  - Das Spiel soll auf Windows und Unix-Systemen ausführbar sein

# 3. Entwicklerdokumentation
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

- Für das **Erfassen** der Eingaben des Spielers wird eine Funktion `getInput` eingesetzt. Diese gibt einen Pfeil aus, um dem Spieler zu signalisieren dass eine Eingabe gefordert wird, gibt true zurück wenn eine Eingabe betätigt wurde und speichert diese in der Variable `input`.
```C
bool getInput()
{
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}
```

- Für das **Verarbeiten** der Eingaben des Spielers wird eine Funktion `parseExecute` eingesetzt. Sie bekommt als Parameter die Eingabe des Spielers (`input`) und den initialen Ort, an dem sich der Spieler befindet (`progressionInit`), übergeben. Der input des Spielers wird in der Variable `choice` abgelegt. Anschließend werden in mehreren if-Verzweigungen die Eingabe sowie die verschiedene andere Vorraussetzungen geprüft (z.B der aktuelle progression-state, ob sich entsprechende Items im Inventar befinden oder andere Fortschritte des Spielers) und die entsprechende Anweisung ausgeführt. Sollte keine der Vorraussetzungen zutreffen, wird eine Hilfe/ ein Tipp an den Spieler ausgegeben. Zum Schluss gibt die Funktion den Rückhabewert true zurück.\
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

- Es werden diverse Variablen angelegt, die den Fortschritt tracken.
```C
...
int fadenPickedUp = 0;
int brecheisenPickedUp = 0;
int astPickedUp = 0;
int stockPickedUp = 0;
int fensterOpen = 0;
int foundtür = 0;
...
```

- Das Inventar wird in seperate Dateien ausgelagert, damit es in den verschiedenen Kapiteln verwendet werden kann ohne das Items "verloren" gehen. Das Inventar ist ein Array des eigens definierten Datentyps `Item`, welches als `char`-Array definiert ist. Die Variable `itemCount` speichert wie viele Items zurzeit gespeichert sind bzw. in welchem Feld des Arrays das nächste Item gespeichert werden soll.
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
  - Um dann das Inventar zu printen wird das Array in einem Loop durchgegangen und die einzelnen Felder ausgegeben.
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

- Um dem Inventar ein Item hinzuzufügen wurde dann folgende Funktion eingesetzt:
```C
if(itemCount < 10)
{
    strncpy(inventory[itemCount].name, "Feder", sizeof(inventory[itemCount].name) - 1); // Hier wird auf das Vorkommen von "Feder" geprüft
    itemCount++; // Der Item Count wird erhöht
    printf("Du nimmst die Feder und verstaust sie in einer Hosentasche.");
    federPickedUp = 1;
}
```


