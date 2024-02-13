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

bool getInput3();
bool parseExecute3(char *input, char *conLevelInit);

static char input[100];
static char conLevelInit[5] = "0";

int main3()
{
    printf("\nDu trittst in einen dunklen Raum ein.\nDer Raum hat Wände aus Beton und du merkst, wie stickig und feucht die Luft ist. In der Mitte des Raumes ist ein alter, rostiger Stuhl.\n\n");
    printf(BLU);
    printf("1. Fortfahren\n");
    printf(RESET);
 
    /*
    while(1)
    {
        if(getInput3())
        parseExecute3(input, conLevelInit);
         else
            return 0;
     } 
     return 0;
     */

    while (parseExecute3(input, conLevelInit) && getInput3());
    return 0;
}

bool getInput3()
{
    printf("\n--> ");
    return fgets(input, sizeof input, stdin) != NULL;
}

bool parseExecute3(char *input, char *conLevelInit)
{
    char *choice = strtok(input, " \n");
    char *conLevel = strtok(conLevelInit, " \n");
    if (choice != NULL)
    {
        if (strcmp(choice, "quit") == 0)
        {
            printf("Shutting down...");
            exit(1);
        }
        //Inventar 
        else if (strcmp(choice, "inventory") == 0 || strcmp(choice, "Inventory") == 0)
        {
            printf("In deinem Inventar befinden sich:\n");
            for(int i = 0; i < itemCount; i++)
            {
            printf("%s\n", inventory[i]);
            }
        }

        // Jumpscare
        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "0") == 0)
        {
            puts("lxO00Oxoc:lc,.',cloooodkOOkkkkkOkkkkkkkOkOOO0KK000K00OOOkOkxxoc,..                       .coc;.");
            puts("lkO0ko;....         ...,;;:clodxkkkkkxkkOkkkO0K0O000OkkkOxo:.                            .cl");      
            puts(".oOOd'                      ...,coxkdldkkkkkOO00OOOOkkkxxdc.                               .'..");     
            puts(";oc.                            .cdxxxocldxxxkOOOOkkkkxdl'                                .co;..");   
            puts(" .,.                              .,oxxdl::olldoldkkxkkxo,                                .:xx:..");   
            puts("    .                                .,oxkkxddxxdlcdkdcoxl,.                ...          ..,oxxxl,..");  
            puts("    .,'                                .,okOxllc;cdOOkxl,'..    .                       .;loxkOkxc..");   
            puts("    .,.                   ..        .   ;xkOkxoccldkkkd,.    .''                     .;oxxxkkkxo,...");  
            puts("    .....                          .''.'cxkO00Okdloxdo:'.   ..cl:,'..              .:dkxlcdkkxdc'.");    
            puts("    .::'. ..                      .:oc:ldxkO000OOOkxooc'.  ..':xkkxdl:;;'.    ...':dkOd;.,dOkdc'..");    
            puts("    .cko:;;. ... ...         ..':ldkxolloxkkOOOOOkxc,'.       .;oddxkkxoccc:clodxkkOkkc,lxOkxl;,.");     
            puts("    .;;;,..,:.         ....';:okOkOkkxddxkkkOOkd:.       .,:.  .:cclxkkxkOkkkOkkOOOOx;:xOOkd;..");      
            puts("        .','.',,.',........;cclxkO0000Okxxdxkkkkd:.   .. ....';. ,lxkdclxkocokkkkkkkO00Oc,lxOxl.");        
            puts("        .:oo,,:,;okxoc::coxkkOO0000O00Okxxxxxxxo,. .'lxoc:,,'   ,dkOOkxxkkkdldo:lodxkO00d'.ldl,.");        
            puts("        .,:;..'cxkkkxolllxOO0000OOOOOkxxxkxxxxl'..cxOOOxc:l;.,.;xkO0OkkkkOOOkxoc;;:okO0k:..:c.");         
            puts("        ':c:coodkkkkkkOxldOOOOOOOOkkkkkxkkkkxo,'cxOO0Oxlcllcc';xO000OkkkkkOOOOkdc..ck0Ol'..;.");         
            puts("        ,oc':dkkOOkkkkkkkkOOkOOOOOkkkxxxkkxxdlcxkO0K0kdloxoc:oxkO0Okkkxo::cdOkd;.'ddlddlc,. .");        
            puts("        .cc;cxkkOOkkkxxkOkkkOO0OOOOkkxddxxxxxxxkkO000OkkkkxxdxxkOOkxdlccccc:od;..cxxlcclol.");          
            puts("            'codxkkkkxxoldxkkkkkOOOOOOkkxxdxxxxxkkkOO000OkkkkxxxxkkOkkxo:lxkxo;cd;.,okdll:,c:.");          
            puts("            ':cooooc:oddddxkkkkkOkOOkkkkxddxxxkkkkO0KX0OOkkkkxxdxkkkkkdcokkdooxo:cclxl',;...");           
            puts("            .ldlllldxo;,,cdxxkkOOOOOkkkxddxdxOOkO0KXNX0kkkkkkxdxxkkOOxoclxkkkxol:oxdl:,.");              
            puts("            .lxxxkkkkdo::::oxkOOOkOkkkkxxddxkOOOO0KNXKOkkOOkkxxkkOOOkkxolcdxl:coxl:cc.");               
            puts("                .:oxkkkOOkxl'.:xkkOOOkkkkkxxxxkkkkOOOO000OOOkkkxoodkkOOOkkxoc:,.:dxo:::;.");               
            puts("                ,oddxkkxo'  ,dkkkOOOkkkkxddoodxkkOOOOOkkkxoc:,..:dkO0Okkkkkdc,;ol;;;''.");               
            puts("                ,c::oxd,  .lxkkkkOOOkkkkxc'.,cloxkxxxdoc;'.  .:oxO00OkkkkOkkdc;..'..");                 
            puts("                    .',cc;,..:dxkkkkkkkOkkkkxl:'.'.':ccc:..  .;coxkOkkOkOkkkkkkxc'.     .");               
            puts("                    ..'....;:oxkkkkkkkkkkOkkxddoc;;'...',,:oxkkkkkkkkOkxocoxd;.....");                   
            puts("                            ..';coxkkkkkkkkkkkkkkkxxkdlclxkkkkkkkkkkkkdlcooloc,...  .");                   
            puts("                        ......',cxkkkkkkkxkkOOkxdddddxxdddddddxdoxkd;'cxkd;''..  ..");                   
            puts("                            ..  . .:ldkkkxddxkkoc:,...,co:......';,cdo,.,:c:,;' .'..");                    
            puts("                            ..  ..  .,:ool;'''.         .           ... .   .'.';,..");                    
            puts("                            ...;,...  .,...                            ',,cdoc:'.");                      
            puts("                            ...,;;. .c;...                 ..      .'lkkdoxdc.");                        
            puts("                                .''..,c;. ..                       .':cldlcl;.");                         
            puts("                                    .;;;c;..,,...               ...':olloxxc.");                           
            puts("                                    ...;lccl;;lo;...'::ccccc::coxxxkkOkxd:.");                            
            puts("                                        .,:lolokOkdddxkkOOOOOkkkkOOOOkkd:.");                              
            puts("                                        .,ldxkkOOOOOkkk00000OOO00OOkdc;.");                               
            puts("                                        .,cldkOOOOOOOO0000OOO00kxo;.");                                 
            puts("                                            .;ldxxkOOkkOOOOkxxkkd;.");                                   
            puts("                                                .':lodooodkkoc,.'.");                                     
            puts("                                                    .  ..,,..");                                         
        
            printf("Ein stechender Schmerz fährt dir schlagartig durch den Kopf.\nAuf dem Stuhl vor dir erscheint ein Wesen. Noch nie hast du auch nur etwas annähernd verstörendes gesehen wie dieses etwas,\nwas sich nun vor dir auf dem Stuhl bequem gemacht hat.\n\n");
            printf(BLU);
            printf("1. Fortfahren\n");
            printf(RESET);
            strcpy(conLevel, "1");

        }
        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "1") == 0)
        {
            printf("Wieder hörst du diese Stimme in deinem Kopf, aber auch der Mund dieses Wesens bewegt sich passend zu den Worten:\n");
            printf(BRED);
            printf("Du hast mich also gefunden... so so, was mach ich denn jetzt mit dir?\n");
            printf(RESET);
            printf(BLU);
            printf("1. Greife das Wesen an\n");
            printf("2. Versuche mit dem Wesen zu reden\n");
            printf(RESET);
            strcpy(conLevel, "2");
        }
        else if ((strcmp(choice, "1") == 0 && strcmp(conLevel, "2") == 0) || (strcmp(choice, "2") == 0 && strcmp(conLevel, "6") == 0) || (strcmp(choice, "2") == 0 && strcmp(conLevel, "7") == 0))
        {
            int foundbogen = 0;
            for (int i = 0; i < itemCount; i++)
            {
                if (strstr(inventory[i].name, "Bogen") != NULL)
                {
                    foundbogen = 1;
                    break;
                }
            }
            if (foundbogen == 1)
            {
                printf("Du greifst nach deinem Bogen und versuchst das Wesen zu treffen.\nJochen: ");
                printf(BRED);
                printf("\n\nWas tust du da?!\nGlaubst du ich will dir etwas antun?\nDenkst du ich würde es dir so leicht machen\nund dir alle nötigen Materialien geben, um mich zu töten?\n");
                printf(RESET);
                printf("\nDu ignoriest Jochen und spannst deinen Bogen.\n");
                printf("Du weißt gar nicht wie du so eine Präzision hast aber durch das ganze Adrenalin\ntriffst du Jochen mitten ins Gesicht.\n");
                printf("Der Pfeil geht tief in Jochens Schädel und das Blut spritzt dir ins Gesicht.\n");
                printf("Das Blut ist eine Mischung aus dunkelrot und schwarz.\nDeine Hände zittern und du kannst nicht glauben was du gerade getan hast.\n");
                printf("Jochen: \n");
                printf(BRED);
                printf("FREU DICH NICHT ZU FRÜH...\n");
                printf(RESET);
                printf("Du hörst ein lautes Krachen, Jochen verschwindet und lässt eine Lache Blut zurück.\nDir wird schlecht und du fühlst dich schwindelig.\n");
                printf(BLU);
                printf("1. Fortfahren\n");
                printf(RESET);
                strcpy(conLevel, "3");
                

            }
            else
            {
                printf("Mit erhobenen Fäusten rennst du auf das Wesen los, bereit ihm mitten ins Gesicht zu boxen!\n");
                printf(BRED);
                printf("Ist das dein Ernst? Denkst du wirklich du hättest mit bloßen Händen eine Chance gegen mich?\n");
                printf(RESET);
                printf("Mit einem Satz springt das Wesen auf dich zu, so schnell dass du keine Möglichkeit zum reagieren hast.\n");
                printf("Die Hand des Wesens rast auf deinen Hals zu und schon im nächsten Moment schlitzt es mit seinen klauenartigen Fingern deine Kehle durch.\n");
                printf(BRED);
                printf("Was für ein jämmerlicher Versuch sollte das denn werden?\n");
                printf(RESET);
                printf("Du fällst zu Boden. Du merkst, wie das warme Blut deinen Hals entlang strömt.\nLangsam wird alles um dich herum dunkel.\n");
                printf(BRED);
			    printf("\nGAME OVER\n\n");
			    printf(RESET);
                return false; 
            }        
        }
        // Help
        else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "2") == 0)

        {
            printf(BLU);
            printf("1. Versuche um Jochens Gnade zu flehen\n");
            printf("2. Versuche Jochens Schmerz zu verstehen\n");
            printf(RESET);
            strcpy(conLevel, "5");
        }
        
        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "3") == 0)
        {
            printf("Dir fällt ein kleines abgedecktes Fenster auf, das du vorher nicht gesehen hast.\nDu gehst hin und hebst die Abdeckung an.\n");
            printf("Du krabbelst aus dem kleinen Fenster raus und landest auf einem dunklen, schlammigen Boden.\n");
            printf("Du siehst dich um und merkst, dass du dich in einem Wald befindest.\n");
            printf("Du rappelst dich auf und fängst an zu rennen\nEin Gefühl der Freiheit überkommt dich.\nVielleicht war das alles nur ein komischer Traum und du wachst gleich auf.\n");
            
            printf(BLU);
            printf("1. Fortfahren\n");
            printf(RESET);
            strcpy(conLevel, "4");
        }
        
        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "4") == 0)
        {
            printf("Auf einmal verspürst du einen stechenden Schmerz in deinem Kopf.\nDu fällst zu Boden und um dich herum wird schwarz.\nJochen, in deinem Kopf: \n");
            printf(BRED);
            printf("\nDU DACHTEST DOCH NICHT WIRKLICH, DASS DU MICH SO EINFACH LOS WIRST, ODER?\n");
            printf(RESET);
            printf("\nDu merkst wie du die Kontrolle über deine Muskeln verlierst.\nDu rappelst dich auf und bewegst dich gegen deinen Willen auf das Haus zu.\n");
            printf("Du schreist, aber niemand hört dich.\nDu bist gefangen in deinem eigenen Körper.\n");
            printf(BRED);
            printf("Du wirst nie wieder entkommen.\nIch werde dich noch bis in die Unendlichkeit als mein Versuchskaninchen benutzen.\n");
            printf(RESET);
            printf("Du befindest dich jetzt wieder in dem Raum, in dem du aufgewacht bist.\n");
            printf("Alles um dich herum wird schwarz und du fällst in Ohnmacht.\n");
            printf(BRED);
            printf("Alles fängt von vorne an, den ganzen Spaß den ich mit dir hatte noch einmal! Ich danke dir, du bist das Beste auf das ich je gestoßen bin\n");
            printf(RESET);
            printf("\nAlles ist dunkel. Dein Schädel brummt und du weißt nicht wo du gerade bist.\n");
            printf("\nUnbekannte Stimme: ");
            printf(BRED);
            printf("Wach auf...\n");
            printf(RESET);
            printf(BRED);
			printf("\nGAME OVER\n\n");
			printf(RESET);
            return false;
        }
        
        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "5") == 0)
        {
            printf("Du fällst vor dem Wesen auf deine Knie, tränen rennen deine Wangen hinunter.\nDu bettelst um dein Leben.\nEin kaltes Lachen erfüllt den Raum.\n");
            printf(BRED);
            printf("Ja, gib mir mehr, MEHR!\n");
            printf(RESET);
            printf(BLU);
            printf("1. Mach weiter\n");
            printf("2. Reiß dich zusammen und hör auf, kämpfe!\n");
            printf(RESET);
            strcpy(conLevel, "6");
        }
        
        else if (strcmp(choice, "2") == 0 && strcmp(conLevel, "5") == 0)
        {
            printf("Du erinnerst dich an alles, was die Stimme bei den Bildern zu dir sagte.\nEr muss vor lauter Schmerz sehr leiden.\n");
            printf("Du machst langsam eine Schritt auf das Wesen und sagst dabei:\n");
            printf(GRN);
            printf("Ich versteh dich, all der Wut und all der Hass, nach allem was du erlebt hast würde es mir nicht anders gehen.\nDoch all das zerfrisst dich und hat dich zerstört. Das ist doch kein Leben.\n");
            printf(RESET);
            printf("Die leeren Augen starren dich ausdruckslos an... ist überhaupt noch was menschliches in ihm übrig?\n");
            printf(BLU);
            printf("1. Mach weiter\n");
            printf("2. Es hat keinen Zweck, ich muss kämpfen\n");
            printf(RESET);
            strcpy(conLevel, "7");
        }

        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "6") == 0)
        {
            printf("Vor lauter heulen versteht man kaum noch ein Wort welches du von dir gibst.\nDas kalte lachen wird immer lauter während das Wesen langsam auf dich zukommt.\nDu spührst die trockenen Hände an deinem Kopf als es zupackt.\nOhne auch nur einer Spur von Anstengung reißt es dir deinen Kopf von den Schultern.\n");
            printf("Das letzte was du siehst ist das höhnische lächeln des Wesens, welches dir in deinen letzten Sekunden direkt ins Gesicht blickt\n");
            printf(BRED);
			printf("\nGAME OVER\n\n");
			printf(RESET);
            return false;
        }

        else if (strcmp(choice, "1") == 0 && strcmp(conLevel, "7") == 0)
        {
            printf(GRN);
            printf("Bitte, das muss ein Ende haben.\nDu hast doch schon genug gelitten.\n");
            printf(RESET);
            printf("Langsam neigt das Wesen seinen Kopf Richtung Boden.\nIst das etwa eine Träne die da aus den leeren Augen hervorquillt?\n");
            printf(BRED);
            printf("Du hast recht, ich kann das alles nicht mehr... du musst nun meine Last tragen.\n");
            printf(RESET);
            printf("Voller Schrecken beobachtest du wie sich das Wesen in einen dichten, dunklen Nebel verwandelt und auf dich zufliegt.\nDu merkst wie dich eine Welle von Hass durchströmt während der Nebel in dich eindringt.\n");
            printf(BRED);
            printf("Du bist der Erste, der mich versteht. Ich werde nun für immer an deiner Seite bleiben.\n");
            printf(RESET);
            printf("Langsam sackst du in den Stuhl ein. Nun heißt es warten... warten bis dein nächstes Opfer auftaucht.\n");
            printf(BRED);
			printf("\nGAME OVER\n\n");
			printf(RESET);
            return false;
        }
        
        else if (strcmp(choice, "help") == 0)
        {
            printf(BLU);
            printf("\n1. `quit` - Beendet das Spiel\n");
            printf("2. `inventory` - Zeigt das Inventar an\n");
            printf("In diesem Kapitel kannst du nicht mehr viel mit der Welt um dich herum interagieren.\nWähle einfach mit den entsprechenden Zahlen die dir präsentierten Optionen\n");
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