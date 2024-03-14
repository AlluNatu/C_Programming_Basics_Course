#include <stdio.h>
#include <string.h>

int main(void){
    char cMerkki;
    char aSana[20];

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);
    printf("Annoit merkin '%c'.\n", cMerkki);
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", aSana);
    printf("Annoit merkkijonon '%s'.\n", aSana);
    return(0);
}