/*2023-19-02 Aleksi Natunen L5T2.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tiedosto(char *aTiedosto){
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aTiedosto);
}

void tarkistaja(char *aTiedosto){
    FILE *tiedosto;
    char aRivi[30], *p1, *p2;
    char aTiimi[26];
    int iPienin = 101;
    int iTarkastus = 0;

    if ((tiedosto = fopen(aTiedosto, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedosto '%s' luettu.\n", aTiedosto);
    while (fgets(aRivi, 30, tiedosto) != NULL) {
        p1 = strtok(aRivi, ";");
        p2 = strtok(NULL, "\n");
        iTarkastus = atoi(p2);
        if (iTarkastus < iPienin){
            iPienin = iTarkastus;
            strcpy(aTiimi, p1);
        }
    }
    printf("Pienin pistemäärä oli joukkueella '%s' %d pisteellä.\n", aTiimi, iPienin);
}


int main(){
    char aTiedosto[30];

    tiedosto(aTiedosto);
    tarkistaja(aTiedosto);
    printf("Kiitos ohjelman käytöstä.\n");
}