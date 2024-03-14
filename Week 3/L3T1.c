/*2023-5-2 Aleksi Natunen L3T1.c*/
#include <stdio.h>

float laskuri(float fKanta, float fKorkeus);

int main(void){
    float fKanta;
    float fKorkeus;
    float fVastaus;

    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &fKanta);
    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &fKorkeus);
    fVastaus = laskuri(fKanta, fKorkeus);
    printf("Suorakulmion pinta-ala on %.2f.\n", fVastaus);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

float laskuri(float fKanta, float fKorkeus){
    float fTulos;
    fTulos = fKanta * fKorkeus;
    return fTulos;
}