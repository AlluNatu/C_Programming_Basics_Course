/*2023-05-02 Aleksi Natunen L3T4.c*/

#include <stdio.h>

#define MAX 60

int tarkastus(char *aMerkkijono);
char* yhdistaja(char *aEnsimmainen, char *aToinen, int iPituus, int iPituus2);


int main(void){
    char aEnsimmainen[MAX];
    char aToinen[MAX];

    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(aEnsimmainen, MAX, stdin);
    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(aToinen, MAX, stdin);

    int iPituus = tarkastus(aEnsimmainen);
    int iPituus2 = tarkastus(aToinen);

    int iYhteensa = iPituus + iPituus2;

    if (iYhteensa > 60) {
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
    }
    else {
    yhdistaja(aEnsimmainen, aToinen, iPituus, iPituus2);
    printf("Yhdistetty merkkijono on:\n");
    printf("'%s'\n", aEnsimmainen);
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int tarkastus(char *aMerkkijono){
    int iPituus = 0;
    char *ptr;

    ptr = aMerkkijono;
    while (*ptr != '\0') {
        iPituus++;
        ptr++;
    }
    return iPituus - 1;
}


char* yhdistaja(char *aEnsimmainen, char *aToinen, int iPituus, int iPituus2){
    int i;

    for (i=0; i < iPituus2; i++){
        aEnsimmainen[iPituus+i] = aToinen[i];
        }

    aEnsimmainen[iPituus + iPituus2] = '\0';
    return(aEnsimmainen);
}