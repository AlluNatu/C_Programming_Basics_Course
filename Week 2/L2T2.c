/*2023-24-1 Aleksi Natunen L2T2.c*/
#include <stdio.h>

#define MIN 3
#define MAX 10

int main(void){
    int iLuku;
    int i = 0;
    int k = 0;

    printf("Anna kokonaisluku väliltä 3 - 10: ");
    scanf("%d, \n", &iLuku);
    printf("\n");
    if ((iLuku>=MIN) && (iLuku <= MAX)){
        for(i = 0; i < iLuku; i++) {
            for(k = 0; k < iLuku; k++){
                printf("*");
            }
            printf("\n");
        }
    } else{
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
    }
    return(0);
}