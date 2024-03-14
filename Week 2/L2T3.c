/*2023-24-1 Aleksi Natunen L2T3.c*/
#include<stdio.h>
#include<string.h>

int main(void){
    char aMerkkijono[15];
    char cMerkki;
    char *ptr;
    int iLuku;
    int iLuku2;
    int iYhteenlaskettu = 0;

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);

    iLuku = cMerkki;
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", cMerkki, iLuku);
    printf("Anna merkkijono: ");
    scanf("%s", aMerkkijono);
    ptr = aMerkkijono;
   
    while (*ptr != '\0') {
        iLuku2 = *ptr;
        iYhteenlaskettu = iYhteenlaskettu + iLuku2;
        ptr++;
    }
    printf("Merkkijonon '%s' merkkien summa on %d.\n", aMerkkijono, iYhteenlaskettu);
    return(0);
}