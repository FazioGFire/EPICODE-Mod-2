#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

/*
Il programma è funzionale ma non è stato sistemato in funzioni perchè Visual Studio mi odia e non vuole debuggare più per qualche ragione quindi mi arrendo. E' stato inizialmente composto
da funzioni singole che testavano ogni componente (praticamente un RAD single-player) da poi assemblare alla fine.


Consiste in una struttura di 4 file (in origine 3 prima di scoprire che il regex non funziona in sistemi non unix) facilmente modificabili da un utente esterno per fornire 
domande, opzioni e risposte. Il programma salva la leaderboard su file.
TODO: randomizzare domande da elenco.
TODO: error handling più robusto tramite error ID
TODO: riordina la lista di utenti in leaderboard.txt per punteggio.
*/

int main()
{

    FILE *fLeaderboard = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\leaderboard.txt", "a");
    if (fLeaderboard == NULL) {printf("Il file ""leaderboard"" non esiste.");} else {printf("Lettura file leaderboard okay\n");}

    FILE *fDomande = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\domande.txt", "r");
    if (fDomande == NULL) {printf("Il file domande non esiste.\n");} else{printf("Lettura file domande okay\n");}

    FILE *fRisposte = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\risposte.txt", "r");
    if (fRisposte == NULL) {printf("Il file risposte non esiste\n");} else{printf("Lettura file risposte okay\n");}

    FILE *fSelezione = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\selezione.txt", "r");
    if (fRisposte == NULL) {printf("Il file selezione non esiste\n");} else{printf("Lettura file selezione okay\n");}

    int questionNumber=1; int questionMax;
    char choiceUser = 'n';
    char userName[30]; //char printScore[30];

    printf("Ciao, benvenuto/a nel gioco. Vuoi iniziare una nuova partita? Usa Y, y oppure 1 per dare una risposta positiva, sennò premi qualunque altro tasto per uscire.\n");
    scanf(" %c", &choiceUser);
    printf("\n");
    printf(" %c", choiceUser);
    
    while(choiceUser == 'y' || choiceUser == 'Y' || choiceUser == '1')
    {
        int score = 0; int line = 1; int num = (rand() % (4-1+1))+1;
        printf("Perfetto, iniziamo. Inserisci il tuo username!\n");
        scanf(" %s", &userName);
        printf("\n");

        printf("A quante domande vuoi rispondere?");
        scanf(" %d", &questionMax);
        printf("\n");printf("\n");printf("\n");printf("\n");

        printf("Risponderai a %d", questionMax);printf(" domande\n");

        for(int i=0; i<questionMax; i++)
        {
            printf("Andiamo con la domanda numero %d ", questionNumber);printf("\n");
            int currentLine = 0;
            char chunk[128]; char answer;
            //printf("linea numero %d ", line, "\n");
            printf(" %d", i); printf(" = %d", questionMax);printf("\n");
            while(fgets(chunk, sizeof(chunk), fDomande) != NULL) //stampa il valore di line
            {   
                //printf("\nLo stream del file funziona\n");
                if(sizeof(chunk) >= 128)
                {
                    currentLine++;
                }
                if(currentLine == line)
                {
                    fputs(chunk, stdout);
                    fputs("\n", stdout);
                }
            }
            currentLine = 0;
            while(fgets(chunk, sizeof(chunk), fRisposte) != NULL)
            {
                if(sizeof(chunk) >= 128)
                {
                    currentLine++;
                }
                if(currentLine == line)
                {
                    fputs(chunk, stdout); //TODO regex per escludere risposta esatta UPDATE regex impossible su sistemi non unix
                    fputs("\n", stdout); // /^[^|]*/
                }
        
            }
            currentLine=0;
            while(fgets(chunk, sizeof(chunk), fSelezione) != NULL)
            {   
                if(sizeof(chunk) >= 128)
                {
                    currentLine++;
                }
                if(currentLine == line)
                {
                    printf("Inserisci la tua risposta:");
                    scanf(" %c", &answer);printf("\n");
                    char correct = chunk[0];
                    //printf(" %d", correct); printf("correct\n");
                    //printf(" %d", answer); printf("answer^\n");
                    if(answer == correct)
                    {
                        printf("Risposta corretta! +10 punti!\n");
                        score = score+10;
                    }
                    else {printf("Risposta errata! 0 punti!\n");}
                }
        
            }
            rewind(fDomande);
            rewind(fRisposte);
            rewind(fSelezione);
            line++;
        }

        printf("Domande esaurite! Il tuo punteggio e' di %d \n", score); printf("\n");
        fprintf(fLeaderboard, "Nome:[%s], Punteggio:[%d]\n", userName, score); printf("\n aggiunte entries \n");
        printf("Vuoi giocare di nuovo?Usa y, Y, o 1 per confermare o premi qualsiasi altro tasto per uscire dal gioco\n");
        
        scanf(" %c", &choiceUser);
        printf("\n");

        
    }
    
    fclose(fDomande);
    fclose(fRisposte);
    fclose(fSelezione);
    fclose(fLeaderboard);
    return 0;

}