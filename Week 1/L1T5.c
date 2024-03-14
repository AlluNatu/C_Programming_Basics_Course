#include<stdio.h>
#include<string.h>

int main(void){
    char aSana1[30];
    char aSana2[30];
    int iLuku;
    float fLiukuluku;

    printf("Anna lemmikin nimi: ");
    scanf("%s, \n", aSana1);
    printf("Anna lemmikin rotu: ");
    scanf("%s, \n", aSana2);
    printf("Anna lemmikin ikä: ");
    scanf("%d, \n", &iLuku);
    printf("Anna lemmikin paino: ");
    scanf("%f, \n", &fLiukuluku);
    printf("Lemmikin nimi on %s ja rotu on %s.\n", aSana1, aSana2);
    printf("Sen ikä on %d vuotta ja paino %1.1f kg.", iLuku, fLiukuluku);
    return(0);

}