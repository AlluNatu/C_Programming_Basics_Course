/*a2023-05-03 Aleksi Natunen L7T1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "L7T1Kirjasto.h"
  
int main(){
    KALA aKalat[10];
    char aTiedosto[30];

    tiedosto(aTiedosto);
    laskin(aTiedosto, aKalat);
    lukija(aKalat);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}