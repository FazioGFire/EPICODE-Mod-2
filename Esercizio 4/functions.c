//#include <stdio.h>
#include <stdlib.h>

int loadFiles()
{
    FILE *fLeaderboard = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\leaderboard.txt", "a");
    if (fLeaderboard == NULL) {printf("Il file ""leaderboard"" non esiste.\n");} else {printf("Lettura file leaderboard okay\n");}

    FILE *fDomande = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\domande.txt", "r");
    if (fDomande == NULL) {printf("Il file domande non esiste.\n");} else{printf("Lettura file domande okay\n");}

    FILE *fRisposte = fopen("C:\\Users\\Utente\\.vscode\\progetti\\qa\\risposte.txt", "r");
    if (fRisposte == NULL) {printf("Il file risposte non esiste\n");} else{printf("Lettura file risposte okay\n");}
    
    return 0;
}

void gameFetch()
{


}


int leaderBoard(int punteggio)
{
    return punteggio;
}