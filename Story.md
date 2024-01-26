# Programmieren Projekt: Text Adventure Game in C

## Setting

- 2- stöckige Villa, verlassen und verwahrlost.

- Charakter hat keine Erinnerung, weiß nicht wer er ist und wie er in der Villa gelandet ist

- Charakter hört eine Stimme im Kopf, die sich mit ihm unterhält.

- Charakter vermutet, die Stimme wäre ein innerer Monolog (seine eigenen Gedanken), später stellt sich raus die Stimme gehört zu einer Entität, welche sich als der finale Bosskampf herausstellt

- Erst im laufe des Games wird klar, dass die Stimme nicht den Gedanken aus entspringt und noch später erst dass sie “böse” ist

# Story

## Kapitel 0

- Anfang: Traumsequenz

- Traum/innerer Dialog

- innere Stimme (Gedanken) —> finaler Bosskampf

## Kapitel 1/Tutorial

- Charakter wacht im Haupt-Schlafzimmer auf Boden auf. Erkunden und entkommen aus dem Schlafzimmer ist die Aufgabe von Kapitel 1.

- Bestimmtes Item um zum nächsten stockwerk zu gelangen

- Schlafzimmer:

  - `lookaround`: Das Zimmer hat keine Fenster und es ist sehr dunkel. Deine Sicht ist immer noch verschwommen und du musst dich anstrengen mehr als nur Silhoutten von Objekten um dich herum zu erkennen. In dem Zimmer befindet sich ein altes Bett, ein alter Schreibtisch aus Holz, ein Kleiderschrank und ein mit Holzplanken verbarrikadiertes Fenster. An der Wand hängt ein eingerahmtes Bild. Du fragst dich warum du überhaupt hier bist.

  - `inspect/lookat`:

    - **Bett**: Das Bett ist verstaubt, sieht jedoch trotzdem wie frisch gemacht aus. Das Bett erinnert dich an deine Müdigkeit und du würdest dich am liebsten einfach wieder schlafen legen.

    - **Schreibtisch:** Der Schreibtisch sieht uralt aus. Er hat eine Schublade und es liegt ein Kulli und ein Zettel auf der Schreibfläche.

      - Kulli: Der Kulli ist komplett ausgetrocknet und ist nicht mehr zu gebrauchen. Du fragst dich warum alles so verwahrlost und verlassen wirkt.

      - Schublade: Die Schulblade beeinhaltet bestimmt etwas was dich weiterbringt. Vielleicht solltest du mal versuchen sie zu öffnen?

      - Zettel: Jemand hatte diesen Zettel beschrieben, leider ist der Inhalt jedoch nicht mehr leserlich und du kannst nur einzelne Buchstaben ausmachen:

    - **Schrank**: Der Kleiderschrank ist aus massivem, dunklem Holz. Vielleicht lässt er sich öffnen?

      - offener Schrank: Du öffnest die schweren Türen des Schranks und wirst erst einmal mit einer Ladung Staub begrüßt. Du sieht diverse Kleidungsstücke, Jacken, Hemden und Hosen. Du siehst einen gläzenden Gegenstand in einer der *Jackentaschen.*

      - Jackentasche: Du bist selbst verwundert dass dir trotz deiner Müdigkeit und deines schmerzenden Kopfes der kleine metallische Gegenstand in der Jackentasche aufgefallen ist.

    - **Fenster**: Das Fenster sieht aus als wäre es schon immer verbarrikadiert gewesen. Du zweifelst daran die Holzplanken entfernen zu können.

    - **Bild**: Das Bild hat einen vergoldeten Rahmen und bildet ein Portät eines Mannes ab. Der Mann hat eine aufrechte Position und hat eine stolze Ausstrahlung. Du fragst dich wer dieser Mann ist.

# Commands

- lookAround = kurzer Text der die Umgebung beschreibt

- pickUp(Item) = Hebe ausgewähltes Item auf

## Umsetzung

- **lookaround** command: Gibt eine detaillierte Beschreibung der aktuellen Umgebung/des aktuellen Raums. *Sachen, mit denen interagiert werden kann, sind farblich hervorgehoben*.

- **goto** command: es gibt fixe Orte an die man sich in einem Zimmer bewegen kann

- **pickUp** command: Manche items können nur temporär getragen werden, können aber nicht dem Inventar des Charakters hinzugefügt werden