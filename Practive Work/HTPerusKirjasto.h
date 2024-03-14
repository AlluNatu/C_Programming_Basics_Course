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
/* Tehtävä Harjoitustyö, tiedoston nimi HTPerusKirjasto.h */
/* eof */

#ifndef HTPERUSKIRJASTO_H
#define HTPERUSKIRJASTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct tiedot {
    char aSana[MAX];
    int iTyyppi;
    struct tiedot* pSeuraava;
} TIEDOT;

typedef struct luokka {
    int iSanaLuokka;
} LUOKKA;

typedef struct sanaAnalyysi {
    int iLukumaara;
    float fPituus;
    char aPisin[MAX];
    char aLyhyin[MAX];
    char aEnsimmainen[MAX];
    char aViimeinen[MAX];
    int iLyhinsana;
    int iPisinsana;
} SANAALYYSI;


int valikko();

void tiedostoNimi(char *aTiedosto);

TIEDOT* dynaaminenTallennus();

LUOKKA* luokkaTallennus();

SANAALYYSI* sanaTallennus();

TIEDOT* lueTiedosto(char* aTiedosto, TIEDOT* pAlku);

LUOKKA* luokkaAnalyysi(LUOKKA *Taulukko, TIEDOT* pAlku);

SANAALYYSI* sanaAnalyysi(SANAALYYSI* sanat, TIEDOT* pAlku);

void kirjoitaTuloste(FILE* tietovirta, LUOKKA* Taulukko, SANAALYYSI* Sanat);

void kirjoitaTiedosto(char *aTiedosto, LUOKKA* Taulukko, SANAALYYSI* Sanat);

TIEDOT* vapauttaja(TIEDOT *pAlku);

#endif
