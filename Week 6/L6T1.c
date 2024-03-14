/*2023-23-02 Aleksi Natunen L6T1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct kirjain {
    char cKirjain;
    struct kirjain *pSeuraava;
} KIRJAIN;


int main(void){
    KIRJAIN *pAlku = NULL, *pLoppu = NULL;
    KIRJAIN *pUusi, *ptr;
    char cSyotto;

    printf("Anna listan kirjaimet.\n");
    while (true) {
        printf("Anna kirjain, q lopettaa:");

        scanf(" %c", &cSyotto);
        /*     ^  getchar(); Mahdollinen korjaus*/
        printf(" ");
        if (cSyotto == 'q'){
            break;
        }

        if ((pUusi = (KIRJAIN*)malloc(sizeof(KIRJAIN))) == NULL ){
            perror("Muistin varaus epäonnistui");
            exit(1);
        }

        pUusi->cKirjain = cSyotto;
        pUusi->pSeuraava = NULL;
        if (pAlku == NULL) {
            pAlku = pUusi; 
            pLoppu = pUusi;
        } else {
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }

    }
    printf("Listassa on seuraavat kirjaimet:\n");
    ptr = pAlku;
    while (ptr != NULL) {
        printf("%c ", ptr->cKirjain);
        ptr = ptr->pSeuraava;
    }

    ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
 }
    printf("\n\nMuisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}