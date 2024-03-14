/*2023-15-02 Aleksi Natunen L5T1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* dynaaminen(){
    char *pMuisti;

    if ((pMuisti = (char *)malloc(30)) == NULL){
    perror("Muistinvaraus epäonnistui");
     exit(0);
    }
    printf("Muisti varattu 30 merkille.\n");

    return pMuisti;
}


void sana(char *pMuisti){
    printf("Anna merkkijono: ");
    fgets(pMuisti, 30, stdin);
    pMuisti[strlen(pMuisti)-1]='\0';
}

int main(){
    char *pMuisti = dynaaminen();
    sana(pMuisti);
    printf("Annoit merkkijonon '%s'.\n", pMuisti);
    free(pMuisti);
    pMuisti = NULL;
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}