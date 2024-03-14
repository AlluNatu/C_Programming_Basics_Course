#include <stdio.h>
int main(void){
int iLuku;
float fLiukuluku;
printf("Anna kokonaisluku: ");
scanf("%d, \n", &iLuku);
printf("Anna liukuluku: ");
scanf("%f, \n", &fLiukuluku);
printf("Annoit luvut %d ja %3.2f.\n", iLuku, fLiukuluku); 
return(0);
}