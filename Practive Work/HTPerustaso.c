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
/* Tehtävä Harjoitustyö, tiedoston nimi HTPerustaso.c */
/* eof */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HTPerusKirjasto.h"

//Ohjelman pääohjelma
int main(void) {
    TIEDOT* pAlku = NULL;
    LUOKKA* pTaulukko = NULL;
    SANAALYYSI* sanat = NULL;
    char aTiedosto[30];
    int iValinta;
    do {
        iValinta = valikko();
            if (iValinta == 1){
                if (pAlku != NULL){
                     pAlku = vapauttaja(pAlku);
                }
                tiedostoNimi(aTiedosto);
                pAlku = lueTiedosto(aTiedosto, pAlku);
            }
            else if (iValinta == 2){
                if (sanat != NULL){
                    free(sanat);
                    sanat = NULL;
                }
                if (pTaulukko != NULL){
                    free(pTaulukko);
                    pTaulukko = NULL;
                }
                if (pAlku == NULL){
                    printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
                }
                else {
                    sanat = sanaTallennus();
                    sanat = sanaAnalyysi(sanat, pAlku);
                    pTaulukko = luokkaTallennus();
                    pTaulukko = luokkaAnalyysi(pTaulukko, pAlku);
                }
            }

            else if (iValinta == 3){
                if (sanat == NULL){
                    printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
                }
                else {
                    tiedostoNimi(aTiedosto);
                    kirjoitaTiedosto(aTiedosto, pTaulukko, sanat);
                }
            }

            else if (iValinta == 0){
                printf("Lopetetaan.\n");
                printf("\n");
                break;
            }

            else{
                printf("Tuntematon valinta, yritä uudestaan.\n");
            }
            printf("\n");
        } while (iValinta != 0);
        pAlku = vapauttaja(pAlku);
        free(pTaulukko);
        pTaulukko = NULL;
        free(sanat);
        sanat = NULL;
        printf("Kiitos ohjelman käytöstä.\n");
        return (0);
}
