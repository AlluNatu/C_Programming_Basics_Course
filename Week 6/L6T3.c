/*2023-26-02 Aleksi Natunen L5T3.c*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct lasku{
    int iEka;
    int iToka;
    int iYhteen;
    struct lasku *pSeuraava;
} LASKU;

LASKU* dynaaminen(){
    LASKU* pUusi;
    if ((pUusi = (LASKU*)malloc(sizeof(LASKU))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return (pUusi);
}

char* tiedosto(char* Muuttuja){
    char *aTiedosto;
    if ((aTiedosto = (char *)malloc((MAX))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    printf("Anna %s tiedoston nimi: ", Muuttuja);
    scanf("%s", aTiedosto);
    return aTiedosto;
}

int valikko(){
    int iValinta;
    printf("\nValitse haluamasi toiminto:\n1) Lisää lukuun\n2) Kirjoita historia tiedostoon\n3) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    printf("\n");
    return (iValinta);
}

LASKU* laskuri(int iLuku, LASKU *pAlku, bool *ekaTarkastus){
    LASKU *pUusi = NULL, *ptr;
    int iLuku2;
    pUusi = dynaaminen();
    if (*ekaTarkastus){ 
        pUusi->iEka = iLuku2;
    } else {
        pUusi->iEka = iLuku;
        *ekaTarkastus = true;
    }
    printf("Anna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &pUusi->iToka);
    pUusi->iYhteen = pUusi->iEka + pUusi->iToka;
    iLuku2 = pUusi->iYhteen;   
    printf("%i+%i=%i", pUusi->iEka, pUusi->iToka, pUusi->iYhteen); 
    if (pAlku == NULL) {
        pAlku = pUusi; 
    } else {
        ptr = pAlku;
        while (ptr->pSeuraava != NULL)
            ptr = ptr->pSeuraava;
        ptr->pSeuraava = pUusi;
    }
    return (pAlku);
}

void kirjoitus(char *aTiedosto, LASKU *Lasku){
    printf("OKEI");
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
    bool ekaTarkastus = false;
    bool tiedostotar = false;
    LASKU *pAlku = NULL;
    char* aTiedosto = NULL;
    char kijoitettava[15] = "kirjoitettavan";
    char luettava[10] = "luettavan";
    int iLuku = 0;
    if (argc > 2){
        printf("Annoit liikaa parametreja.\n");
        exit(0);
    }
    if (argc < 2){
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    }
    iLuku = atoi(argv[1]);
    printf("Annoit luvun %d.", iLuku);
    do {
        int iValinta = valikko();
        if (iValinta == 1){
            laskuri(iLuku, pAlku, &ekaTarkastus);

        } else if (iValinta == 2) {
            if (tiedostotar){
                free(aTiedosto);
                aTiedosto = NULL;
            }
            aTiedosto = tiedosto(kijoitettava);
            kirjoitus(aTiedosto, pAlku);
            tiedostotar = true;
        } else if (iValinta == 3){
            if (tiedostotar){
                free(aTiedosto);
                aTiedosto = NULL;
            }
            aTiedosto = tiedosto(luettava);
            lukija(aTiedosto);
            tiedostotar = true;
        } else if (iValinta == 0) {
            free(aTiedosto);
            aTiedosto = NULL;
            printf("Muisti vapautettu.\n");
            printf("Lopetetaan.\n");
            break;
        } else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }while (true);
        printf("\nKiitos ohjelman käytöstä.\n");
        return(0);
    }