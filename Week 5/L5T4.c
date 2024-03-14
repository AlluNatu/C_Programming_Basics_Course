/*2023-19-02 Aleksi Natunen L5T4.c*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct Maara{
    char teksti[MAX];
    int summa;
} MAARA;

int valikko(){
    int iValinta;
    printf("Valitse haluamasi toiminto:\n1) Lue tiedosto\n2) Laske merkkijonojen summa\n3) Kirjoita tiedosto\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    printf("\n");
    return (iValinta);
}

char* tiedosto(char *Muuttuja){
    char *aTiedosto;
    if ((aTiedosto = (char *)malloc(MAX)) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    printf("Anna %s tiedoston nimi: ", Muuttuja);
    scanf("%s", aTiedosto);
    return aTiedosto;
}

MAARA *dynaaminen(MAARA *pTiedot, int iLkm){
    if ((pTiedot = (MAARA*)realloc(pTiedot, iLkm*sizeof(MAARA))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    return pTiedot;
}

MAARA* lueTiedosto(char* aTiedosto, int *iLkm, MAARA* pTieto){
    char rivi[MAX];
    FILE *tiedosto;
    if ((tiedosto = fopen(aTiedosto, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
       printf("Tiedosto '%s' luettu.\n\n", aTiedosto);

       while (fgets(rivi,30, tiedosto) != NULL){
            (*iLkm)++;
            pTieto = dynaaminen(pTieto, *iLkm);
            rivi[strlen(rivi)-1] = '\0';
            strcpy(pTieto[(*iLkm)-1].teksti, rivi);
    }
        fclose(tiedosto);
    return pTieto;
}

MAARA* laskin(MAARA* pTiedot, int iLkm){
    char *ptr;
    int iLuku2 = 0;
    int iYhteen = 0;
    for (int i=0; i < iLkm; i++){
        ptr = pTiedot[i].teksti;
        while (*ptr != '\0') {
            iLuku2 = *ptr;
            iYhteen = iYhteen + iLuku2;
            ptr++;
        }
        pTiedot[i].summa = iYhteen;
        iYhteen = 0;
    } printf("Summat laskettu %d merkkijonolle.\n\n", iLkm);
    return pTiedot;
}

void kirjoita(char* aTiedosto, MAARA *pTiedot, int iLkm){
    FILE *tiedosto;
        if ((tiedosto = fopen(aTiedosto, "w")) == NULL) {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }
        printf("Tiedostoon kirjoitetaan seuraavat arvot:\n");
        printf("Nimi;Arvo\n");
        fprintf(tiedosto, "Nimi;Arvo\n");
        for (int i=0; i < iLkm; i++){
            printf("%s;%d\n", pTiedot[i].teksti, pTiedot[i].summa);
            fprintf(tiedosto, "%s;%d\n", pTiedot[i].teksti, pTiedot[i].summa);
        } printf("Tiedosto '%s' kirjoitettu.\n", aTiedosto);
        printf("\n");
    fclose(tiedosto);
}

int main(void){
    int iLkm = 0;
    bool Tarkastus = false;
    bool Analyysi = false;
    char aLuettava[15] = "luettavan";
    char aKirjoitettava[15] = "kirjoitettavan";
    char* aTiedosto = NULL;
    MAARA *pTieto = NULL;

    do {
        int iValinta = valikko();
        if (iValinta == 1){
            aTiedosto = tiedosto(aLuettava);
            pTieto = lueTiedosto(aTiedosto, &iLkm, pTieto);
            Analyysi = true;
        } else if (iValinta == 2){
            if (Analyysi) {
                pTieto = laskin(pTieto, iLkm);
                Tarkastus = true;
            } else {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysia.\n\n");
            }
        } else if (iValinta == 3){
            if (Tarkastus){
                aTiedosto = tiedosto(aKirjoitettava);
                kirjoita(aTiedosto, pTieto, iLkm);
            } else {
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n\n");
            }
        } else if (iValinta == 0){
            free(pTieto);
            free(aTiedosto);
            aTiedosto = NULL;
            pTieto = NULL;
            printf("Muisti vapautettu.\n");
            printf("Lopetetaan.\n");
            break;
        } else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    } while (true);
    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}
