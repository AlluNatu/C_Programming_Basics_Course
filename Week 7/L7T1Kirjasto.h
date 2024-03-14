/*a2023-05-03 Aleksi Natunen L7T1Kirjasto.h*/

typedef struct kala {
    int vuosi;
    int hinta;
} KALA;


void tiedosto(char *aTiedosto);
KALA* laskin(char *aTiedosto, KALA *aKalat);
void lukija(KALA *aKalat);
  