/*2023-05-02 Aleksi Natunen L3T5.c*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

void siemenluku();
int maara();
char* arpoja(int iMaara);
int tarkastaja(char* aMerkkijono);

int main(void){
    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");
    siemenluku();
    int iMaara = maara();
    char* aMerkkijono = arpoja(iMaara);
    int iTarkastus = tarkastaja(aMerkkijono);

    if (iTarkastus == 1){
        printf("\nMerkkijonosta löydettiin merkki 'c'.\n");
    } else {
        printf("\nMerkkijonossa ei ollut merkkiä 'c'.\n");
    }
    printf("Generoitiin merkkijono '%s', jossa on %ld merkkiä.\n", aMerkkijono, strlen(aMerkkijono));

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void siemenluku(){
    int iSiemenluku;
    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &iSiemenluku);
    srand(iSiemenluku);
}

int maara(){
    int iMaara;
    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &iMaara);
    return iMaara;
}

char* arpoja(int iMaara){
    int iLaskuri = 0;
    char *aMerkkijono = malloc(30);
    for(int i=0; i < iMaara; i++){
        int iLuku = rand() %95 + 32;
        char cMerkki = iLuku;
        if (isalpha(cMerkki) || isdigit(cMerkki) || isspace(cMerkki)){
            aMerkkijono[iLaskuri] = cMerkki;
            iLaskuri++;
        }
    }
    aMerkkijono[iMaara] = '\0';

    return(aMerkkijono);
}

int tarkastaja(char* aMerkkijono){
    int iTarkastus = 0;

    if (strchr(aMerkkijono, 'c')){
        iTarkastus++;
    } else {
        iTarkastus == 0;
    }
    return iTarkastus;
}