#include <stdio.h>

int main(void){
    int iLuku1, iLuku2;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d, \n", &iLuku1);
    printf("Anna toinen kokonaisluku: ");    
    scanf("%d, \n", &iLuku2);
    printf("%d * %d = %d\n", iLuku1, iLuku2, ++iLuku1*iLuku2);
    printf("(%d / %d) - 10 = %d\n", --iLuku1, iLuku2, (iLuku1/iLuku2)-10);
    printf("%d %% %d = %d\n", iLuku1, iLuku2, iLuku1%--iLuku2);
    return(0);
}