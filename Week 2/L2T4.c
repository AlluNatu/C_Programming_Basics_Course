/*2023-24-1 Aleksi Natunen L2T4.c*/
#include<stdio.h>

#define PII 3.141

int main(void){
    float fSade;
    int iValinta;
    float fKeha;
    float fPinta;

    printf("Anna ympyrän säde: \n");
    scanf("%f", &fSade);



    printf("Valikko:\n1) Laske ympyrän kehän pituus\n2) Laske ympyrän pinta-ala\nValitse: ");
    scanf("%d", &iValinta);

    switch (iValinta) {
        case 1:
            fKeha = 2 * PII * fSade;
            printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.\n", fSade, fKeha);
            break;

        case 2:
            fPinta = PII * fSade * fSade;
            printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.\n", fSade, fPinta);
            break;
        default:
            printf("Tuntematon valinta.\n");
            break;
    }
    return(0);
}