/*2023-19-02 Aleksi Natunen L5T3.c*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct lasku{
    int iEka;
    int iToka;
    int iYhteen;
    char aLaskutoimitus[MAX];
} LASKU;

LASKU* dynaaminen(){
        LASKU* aLaskut;
    if ((aLaskut = (LASKU*)malloc(sizeof(LASKU)*MAX)) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }   return aLaskut;
}

char* tiedosto(){
    char *aTiedosto;
    if ((aTiedosto = (char *)malloc(MAX)) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aTiedosto);
    return aTiedosto;
}

int valikko(){
    int iValinta;
    printf("\nValitse haluamasi toiminto:\n1) Anna tiedoston nimi\n2) Lisää lukuun\n3) Kirjoita historia tiedostoon\n4) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    printf("\n");
    return (iValinta);
}

void laskuri(LASKU *pLasku){
    int iLkm = 0;
    int iLkm2 = 1;
    printf("Anna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &pLasku->iToka);
    pLasku->iYhteen = pLasku[iLkm].iEka + pLasku[iLkm].iToka;
    printf("%d+%d=%d\n", pLasku[iLkm].iEka, pLasku[iLkm].iToka, pLasku[iLkm].iYhteen);
    sprintf(pLasku[iLkm].aLaskutoimitus, "%i+%i=%i", pLasku[iLkm].iEka, pLasku[iLkm].iToka, pLasku[iLkm].iYhteen);
    pLasku[iLkm2].iEka = pLasku[iLkm].iYhteen;
    iLkm++;
    iLkm2++;
    return;
}

void kirjoitus(char *aTiedosto, LASKU *Lasku, int iLkm){
    int Maara = iLkm;
    FILE *tiedosto;
    for (int i=0; i < Maara; i++){
        printf("%s\n", Lasku[i].aLaskutoimitus);
    }
    if ((tiedosto = fopen(aTiedosto, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
}
    for (int i=0; i < Maara; i++){
        fprintf(tiedosto, "%s\n", Lasku[i].aLaskutoimitus);
    }
    fclose(tiedosto);
    printf("\nTiedosto '%s' kirjoitettu.\n", aTiedosto);
        return;
}

void lukija(char *aTiedosto){
    char rivi[50];
    FILE *tiedosto;
    if ((tiedosto = fopen(aTiedosto, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
}   
    printf("Tiedostossa oleva laskuhistoria:\n");
    while (fgets(rivi,50, tiedosto) != NULL){
        printf("%s", rivi);
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", aTiedosto);
    fclose(tiedosto);
    return;
}

int main(int argc, char *argv[]){
    bool Tarkastus = false;
    bool Kirjoitus = false;
    int iLuku = 0;
    int iLkm = 0;
    char* aTiedosto;
    LASKU *aLaskut;
    aLaskut = dynaaminen();
    if (argc > 2){
        printf("Annoit liikaa parametreja.\n");
        exit(0);
    }
    if (argc < 2){
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    }
    iLuku = atoi(argv[1]);
    aLaskut->iEka = iLuku;
    printf("Annoit luvun %d.", iLuku);
    do {
    int iValinta = valikko();
    if (iValinta == 1){
        aTiedosto = tiedosto();
        Tarkastus = true;
    } else if (iValinta == 2) {
        laskuri(&aLaskut[iLkm]);
        Kirjoitus = true;
        iLkm++;
    } else if (iValinta == 3){
        if (Kirjoitus){
            if (Tarkastus){
                kirjoitus(aTiedosto, aLaskut, iLkm);
            } else {
                printf("Ei tiedoston nimeä, anna kirjoitettavan tiedoston nimi ensin.\n");
            }
        } else {
            printf("Ei kirjoitettavia tietoja.\n");

        }
    } else if (iValinta == 4){
        if (Tarkastus){
            lukija(aTiedosto);
        } else {
            printf("Ei tiedoston nimeä, anna luettavan tiedoston nimi ensin.\n");
        }
    } else if (iValinta == 0) {
        free(aTiedosto);
        free(aLaskut);
        aTiedosto = NULL;
        aLaskut = NULL;
        printf("Muisti vapautettu.\n");
        printf("Lopetetaan.\n");
        break;
    } else {
        printf("Tuntematon valinta, yritä uudestaan.\n");
    }
}   while (true);
    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}