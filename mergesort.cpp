#include "mergesort.h"

void MergeSort::start(int tab[], int rozmiar) {
    sortowanie(tab, 0, rozmiar - 1);
}

void MergeSort::sortowanie(int tab[], int lewa, int prawa) {
    if (lewa < prawa) {
        int srodek = lewa + (prawa - lewa) / 2;

        sortowanie(tab, lewa, srodek);
        sortowanie(tab, srodek + 1, prawa);

        scalanie(tab, lewa, srodek, prawa);
    }
}