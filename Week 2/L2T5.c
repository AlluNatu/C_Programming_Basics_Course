/*2023-24-1 Aleksi Natunen L2T5.c*/

#include <stdio.h>
#include <stdbool.h>
int main(void){

int iLuku;
int iLuku2;
int iValinta;

printf("Anna kokonaisluku: ");
scanf("%d", &iLuku);

do {
    printf("\nValikko:\n1) Lisää lukuun\n2) Vähennä luvusta\n0) Lopeta\nValintasi: ");
    scanf("%d", &iValinta);
    printf("\n");
    if (iValinta == 1) {
        printf("Anna lukuun lisättävä kokonaisluku: ");
        scanf("%d", &iLuku2);
        iLuku = iLuku + iLuku2;
        printf("Luku on nyt %d.\n", iLuku);

    } else if (iValinta == 2){    
        printf("Anna luvusta vähennettävä kokonaisluku: ");
        scanf("%d", &iLuku2);
        iLuku = iLuku - iLuku2;
        printf("Luku on nyt %d.\n", iLuku);

    } else if (iValinta == 0){
        printf("Lopetetaan.\n");
        break;

    } else {
        printf("Tuntematon valinta, yritä uudestaan.\n");
    }
}   while (true);
    printf("\nKiitos ohjelman käytöstä.");
    return(0);
}