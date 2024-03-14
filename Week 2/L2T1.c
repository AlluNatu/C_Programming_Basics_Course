/*2023-24-1 Aleksi Natunen L2T1.c*/
#include<stdio.h>

int main(void){
    int iMaara;

    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d, \n", &iMaara);

    if ((0 <= iMaara) && (iMaara <= 14)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 0.\n", iMaara);
    } else if ((15 <= iMaara) && (iMaara <= 17)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 1.\n", iMaara);
    } else if ((18 <= iMaara) && (iMaara <= 20)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 2.\n", iMaara);
    } else if ((21 <= iMaara) && (iMaara <= 23)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 3.\n", iMaara);
    } else if ((24 <= iMaara) && (iMaara <= 26)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 4.\n", iMaara);
    } else if ((27 <= iMaara) && (iMaara <= 30)){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 5.\n", iMaara);
    } else if (iMaara > 30){
        printf("Kurssilla on vain 30 tehtävää.\n");
    } else{
        printf("Ei ole mahdollinen määrä tehtäviä.\n");
    }
    return(0);
}