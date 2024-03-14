/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet 
* Tekijä: Natunen Aleksi
* Opiskelijanumero: RETRACTED
* Päivämäärä: 12.03.2023
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla:
* Stackoverflow.com, täältä otin apua jotta sain tehtyä aakkosjärjestykseen (https://stackoverflow.com/questions/7656475/strcmp-return-values-in-c)
* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
* vaikuttaneet siihen yllä mainituilla tavoilla.
*/
/*************************************************************************/
/* Tehtävä Harjoitustyö, tiedoston nimi HTPerusKirjasto.c */
/* eof */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HTPerusKirjasto.h"

//Funktio valikkoa varten
int valikko() {
    int iValinta;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    getchar();

    return (iValinta);
}
//Funktio tiedoston nimeä varten
void tiedostoNimi(char *aTiedosto) {
    printf("Anna tiedoston nimi: ");
    scanf("%s", aTiedosto);
    return;
}

//Funktio linkitetyn listan muistin varaamiseen 
TIEDOT* dynaaminenTallennus(){
    TIEDOT* pUusi;
    if ((pUusi = (TIEDOT*)malloc(sizeof(TIEDOT))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return (pUusi);
}

//Funktio luokka structia muistin varaamista varten
LUOKKA* luokkaTallennus(){
    LUOKKA* Taulukko;
    if ((Taulukko = (LUOKKA*)malloc(sizeof(LUOKKA)*10)) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return(Taulukko);
}

//Funktio sana-analyysin structin muistin varaamista vartetn
SANAALYYSI* sanaTallennus(){
    SANAALYYSI* Sanat;
    if ((Sanat = (SANAALYYSI*)malloc(sizeof(SANAALYYSI))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return(Sanat);
}

//Funktio joka lukee tiedoston ja tallentaa tiedot linkitettyyn listaan
TIEDOT* lueTiedosto(char* aTiedosto, TIEDOT* pAlku) {
    TIEDOT *pUusi = NULL, *ptr;
    char aRivi[MAX], *p1, *p2;

    FILE *tiedosto;
    if ((tiedosto = fopen(aTiedosto, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    fgets(aRivi, MAX, tiedosto);

    while(fgets(aRivi, MAX, tiedosto) != NULL) {
        if ((p1 = strtok(aRivi, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui,\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, ";")) == NULL){
            printf("Merkkijonon '%s' pilkkominen epäonnistui,\n", aRivi);
            exit(1);
        }

        pUusi = dynaaminenTallennus();

        strcpy(pUusi->aSana, p1);
        pUusi->iTyyppi = atoi(p2);
        pUusi->pSeuraava = NULL;
        if (pAlku == NULL){
            pAlku = pUusi;
        } else {
            ptr = pAlku;
            while (ptr->pSeuraava != NULL)
                ptr = ptr->pSeuraava;
            ptr->pSeuraava = pUusi;
        }
    }
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu.\n", aTiedosto);
    return (pAlku);
}

//Funktio joka ottaa vastaan linkitetyn listan ja tallentaa tästä struct sanat listaan sanojen luokkien määrät
LUOKKA* luokkaAnalyysi(LUOKKA *Taulukko, TIEDOT* pAlku){
    TIEDOT *ptr = pAlku;
    for(int i = 0; i < 10; i++) {
        Taulukko[i].iSanaLuokka = 0;
    }
    while (ptr != NULL) {
        Taulukko[ptr->iTyyppi-1].iSanaLuokka = Taulukko[ptr->iTyyppi-1].iSanaLuokka + 1;
        ptr = ptr->pSeuraava;
    }
    printf("Sanaluokittaiset lukumäärät analysoitu.\n");
    return (Taulukko);
}

//Koko linkitetyn listan analysointi eri tietoihin
SANAALYYSI* sanaAnalyysi(SANAALYYSI* sanat, TIEDOT* pAlku) {
    TIEDOT *ptr = pAlku;
    int iLkm = 0;
    float fsanaPituus = 0;
    int iLyhyin = strlen(ptr->aSana);
    int iPisin = strlen(ptr->aSana);
    strcpy(sanat->aEnsimmainen, ptr->aSana);
    strcpy(sanat->aViimeinen, ptr->aSana);
    while (ptr != NULL) {
        iLkm = iLkm + 1;
        fsanaPituus = fsanaPituus + strlen(ptr->aSana);
        if (strlen(ptr->aSana)>iPisin){
            iPisin = strlen(ptr->aSana);
            sanat->iPisinsana = iPisin;
            strcpy(sanat->aPisin, ptr->aSana);
        }
        if (strlen(ptr->aSana)<iLyhyin){
            iLyhyin = strlen(ptr->aSana);
            sanat->iLyhinsana = iLyhyin;
            strcpy(sanat->aLyhyin, ptr->aSana);
        }
        if (strcmp(ptr->aSana, sanat->aEnsimmainen) < 0){
            strcpy(sanat->aEnsimmainen, ptr->aSana);
        }
        if (strcmp(ptr->aSana, sanat->aViimeinen) > 0){
            strcpy(sanat->aViimeinen, ptr->aSana);
        }
        ptr = ptr->pSeuraava;
    }
    sanat->iLukumaara = iLkm;
    sanat->fPituus = fsanaPituus/iLkm;
    printf("Analysoitu %d sanaa.\n", sanat->iLukumaara);
    return (sanat);
}

//Funktio kirjoittaa tulosteet, saa tietovirtana stdout ja tiedosto kahvan, jonka takia se suorittaa molemmat konsoliin ja tiedostoon
void kirjoitaTuloste(FILE* tietovirta, LUOKKA* Taulukko, SANAALYYSI* Sanat){
    fprintf(tietovirta, "Tilastotiedot %d sanasta:\n", Sanat->iLukumaara);
    fprintf(tietovirta, "Keskimääräinen sanan pituus on %.1f merkkiä.\n", Sanat->fPituus);
    fprintf(tietovirta, "Pisin sana '%s' on %d merkkiä pitkä.\n", Sanat->aPisin, Sanat->iPisinsana);
    fprintf(tietovirta, "Lyhyin sana '%s' on %d merkkiä pitkä.\n", Sanat->aLyhyin, Sanat->iLyhinsana);
    fprintf(tietovirta, "Aakkosjärjestyksessä ensimmäinen sana on '%s'.\n", Sanat->aEnsimmainen);
    fprintf(tietovirta, "Aakkosjärjestyksessä viimeinen sana on '%s'.\n", Sanat->aViimeinen);
    fprintf(tietovirta, "\nSanaluokka;Lkm\n");
    for (int i = 0; i < 10; i++){
        fprintf(tietovirta, "Luokka %d;%d\n", i+1, Taulukko[i].iSanaLuokka);
    }
    return;
}

//Funktio kutsuu aikaisempaa funktiota ja käsittelee tiedoston
void kirjoitaTiedosto(char *aTiedosto, LUOKKA* Taulukko, SANAALYYSI* Sanat) {
    FILE *tiedosto = fopen(aTiedosto, "w");
    kirjoitaTuloste(stdout, Taulukko, Sanat);
    if (tiedosto == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    kirjoitaTuloste(tiedosto, Taulukko, Sanat);
    fclose(tiedosto);
    printf("Tiedosto '%s' kirjoitettu.\n", aTiedosto);
    return;
}

//Funktio vapauttaa linkitetyn listan muistit
TIEDOT* vapauttaja(TIEDOT *pAlku){
    TIEDOT *ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    return (pAlku);
}
