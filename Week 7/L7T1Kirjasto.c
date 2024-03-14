/*a2023-05-03 Aleksi Natunen L7T1Kirjasto.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L7T1Kirjasto.h"

void tiedosto(char *aTiedosto){
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aTiedosto);

}

KALA* laskin(char *aTiedosto, KALA *aKalat){
    int i = 0;
    FILE *tiedosto;
    char aRivi[30], *p1, *p2;
    
    if ((tiedosto = fopen(aTiedosto, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fgets(aRivi, 30, tiedosto);
    printf("Tiedosto '%s' luettu.\n", aTiedosto);
    while (fgets(aRivi, 30, tiedosto) != NULL) {
        p1 = strtok(aRivi, ";");
        p2 = strtok(NULL, "\n");
        (aKalat + i)->hinta= atoi(p2);
        (aKalat + i)->vuosi= atoi(p1);
        i++;
    }
    fclose(tiedosto);
    return(aKalat);
}

void lukija(KALA *aKalat){
    int iYhteensa = 0;
    printf("Akvaariokalojen tuonti euroina:\n");
    for (int i = 0; i < 10; i++){
        printf("%d\t%d\n", aKalat[i].vuosi, aKalat[i].hinta);
        iYhteensa = aKalat[i].hinta + iYhteensa;
    }
    printf("Ajanjaksolla tuonti oli yhteensä %d euroa.\n\n", iYhteensa);
}

