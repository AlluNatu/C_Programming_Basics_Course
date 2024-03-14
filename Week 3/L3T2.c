/*2023-5-2 Aleksi Natunen L3T2.c*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

int lukija(char *aLuettava);
int kirjoittaja(char *aKirjoitettava, int iTulos);

int main(void){
    int iTulos;
    char aLuettava[MAX];
    char aKirjoitettava[MAX];
    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aLuettava);
    iTulos = lukija(aLuettava);

    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aKirjoitettava);

    kirjoittaja(aKirjoitettava, iTulos);
    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}

int lukija(char *aLuettava){
    char rivi[50];
    int iTulos = 0;
    FILE *tiedosto;

    if ((tiedosto = fopen(aLuettava, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("Tiedosto '%s' luettu,", aLuettava);

    while (fgets(rivi, 50, tiedosto) != NULL) {
        iTulos = iTulos + atoi(rivi);
    }  
    printf(" lukujen summa oli %i.\n", iTulos);
    printf("\n");

    fclose(tiedosto);

    return(iTulos);
}

int kirjoittaja(char *aKirjoitettava, int iTulos){
    char rivi[50];
    FILE *tiedosto;

    if ((tiedosto = fopen(aKirjoitettava, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
}
    printf("Tiedosto '%s' kirjoitettu.\n", aKirjoitettava);
    fprintf(tiedosto, "Lukujen summa oli %i.", iTulos);

    fclose(tiedosto);

    return(0);
}