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

void MergeSort::scalanie(int tab[], int lewa, int srodek, int prawa) {
    int cz1 = srodek - lewa + 1;
    int cz2 = prawa - srodek;

    // tymczasowe tablice
    int* L = new int[cz1];
    int* P = new int[cz2];

    // kopiowanie do tymczasowych tablic
    for (int i = 0; i < cz1; i++) {
        L[i] = tab[lewa + i];
    }
    for (int j = 0; j < cz2; j++) {
        P[j] = tab[srodek + 1 + j];
    }

    int i = 0, j = 0, k = lewa;

    // scalanie dwóch części
    while (i < cz1 && j < cz2) {
        if (L[i] <= P[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = P[j];
            j++;
        }
        k++;
    }

    // dodawanie pozostałych elementów
    while (i < cz1) {
        tab[k] = L[i];
        i++;
        k++;
    }
    while (j < cz2) {
        tab[k] = P[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] P;
}