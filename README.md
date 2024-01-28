# Programmierprojekt 23F, 1. Semester

## 1. Projektteilnehmer/innen

- Wiedemann, Tobias
- Pratyaksh, Jain
- Limberger, Robert

Kontakt: inf23089@lehre.dhbw-stuttgart.de

&nbsp;

## 2. Projektbeschreibung

- **Aufgabenstellung**: 
  Ein kurzes text-basiertes Videospiel entwickeln. (*Text Adventure Game/Interactive Fiction*)
- **Funktionsumfang**:
  - Der Spieler kann verschiedene Dialogoptionen wählen
  - Das Spiel ist in Kapitel unterteilt
  - Der Spieler kann verschiedene Aktionen ausführen, wie zum Beispiel `lookat`, `lookaround`, `pickup` etc.
  - Kleinere Rätsel um von Raum zu Raum vorwärtszukommen
  - Player-Stats: `health`, `strength` etc.
  - (Steht noch nicht fest) Kampfsequenzen
  - Größtenteils lineares Spiel, jedoch alternative Enden
  - Entscheidungen des Spielers sollen Konsequenzen haben
  - Es soll ein Handbuch/Guide erstellt werden, um Spielern eine Hilfe zu bieten
- **Angestrebte Lösung aus technischer Sicht**:
  - Benutzen von diversen C-Bibliotheken, wie `stdio.h`, `stdbool.h`, `string.h`
  - Die einzelnen Kapitel sollen in verschiedene C-Dateien ausgelagert werden
  - Die einzelnen .c Dateien für die Kapitel sollen eine minimale `main`-Funktion haben und das Verarbeiten der Spieler-commands soll in eine Funktion "`parseExecute`" ausgelagert werden
  - Es soll mit Konversationsebenen gearbeitet werden, sodass sich verschiedene Entscheidungen des Spielers auf den Fluss der Unterhaltung/den Verlauf des Spiel auswirken
  - Die `main.c` Datei soll möglichst minimal gehalten werden
  - Es sollen 3-4 Kapitel programmiert werden
  - Das Spiel soll auf Windows und Unix-Systemen ausführbar sein


