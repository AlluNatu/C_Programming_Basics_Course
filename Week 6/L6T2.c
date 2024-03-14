/*2023-23-02 Aleksi Natunen L6T2.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct tehtava {
    char aTehtava[6];
    int iMaara;
    struct tehtava *pSeuraava;
} TEHTAVA;


char* tiedosto() {
    char* aTiedosto;
    if ((aTiedosto = (char*)malloc(MAX)) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aTiedosto);
    return (aTiedosto);
}

TEHTAVA* dynaaminen(){
    TEHTAVA* pUusi;
    if ((pUusi = (TEHTAVA*)malloc(sizeof(TEHTAVA))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return (pUusi);
}

TEHTAVA* lukija(char *aTiedosto, TEHTAVA *pAlku){
    TEHTAVA *pUusi = NULL, *ptr;
    char aRivi[MAX], *p1, *p2;
    
    FILE *tiedosto;
    if ((tiedosto = fopen(aTiedosto, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }   
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", aTiedosto);
    while (fgets(aRivi,MAX, tiedosto) != NULL){
        if ((p1 = strtok(aRivi, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui,\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL ,"\n")) == NULL){
            printf("Merkkijonon '%s' pilkkominen epäonnistui,\n", aRivi);
            exit(1);
        }

        pUusi = dynaaminen();

        strcpy(pUusi->aTehtava, p1);
        pUusi->iMaara = atoi(p2);
        pUusi->pSeuraava = NULL;
        if (pAlku == NULL) {
            pAlku = pUusi; 
        } else {
            ptr = pAlku;
            while (ptr->pSeuraava != NULL)
                ptr = ptr->pSeuraava;
            ptr->pSeuraava = pUusi;
        }
    }
    fclose(tiedosto);
    return (pAlku);
}

TEHTAVA* tulosta(TEHTAVA* pAlku){
    TEHTAVA *ptr = pAlku;
    printf("Tehtäviä tehtiin seuraavasti:\n");
    while (ptr != NULL) {
        printf("Tehtävän %s teki %d opiskelijaa.\n", ptr->aTehtava, ptr->iMaara);
        ptr = ptr->pSeuraava;
    }
    return (pAlku);
}

TEHTAVA* vapauttaja(TEHTAVA *pAlku){
    TEHTAVA *ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    return (pAlku);
}


int main (void){
    TEHTAVA *pAlku = NULL;
    char* aTiedosto = NULL;
    aTiedosto = tiedosto();
    pAlku = lukija(aTiedosto, pAlku);
    tulosta(pAlku);
    pAlku = vapauttaja(pAlku);
    free(aTiedosto);
    aTiedosto = NULL;
    printf("\nMuisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
}