# Dokumentation
- Unser Spiel ist in verschiedene '.c' Dateien aufgeteilt (Kapitelweise)
- Jede diese Dateien hat eine zugehörige Header-Datei, in der die Funktionen der einzelnen `.c` Dateien deklariert werden
- Die `main()`-Funktionen der einzelnen Kapitel werden der Übersicht halber einfach in `main.c` aufgerufen
- Verschiedene Bibliotheken werden benutzt, beispielsweise:
	- `stdio.h`: Die Standard-Bibliothek
    - `studbook.h`: Funktionen geben Wahr/Falsch zurück
    - `string.h`: Funktionen wie `strcmp` werden ausgiebig verwendet
    - `stdlib.h`: Für die Funktion `exit`
-