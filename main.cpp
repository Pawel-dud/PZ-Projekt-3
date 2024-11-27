#include "mergesort.h"

int main() {
    MergeSort MS;

    int tab[] = { 3, -4, 24, 0, 50, 17, -1, 108};
    int rozmiar = sizeof(tab) / sizeof(tab[0]);

    cout << "Tablica przed sortowaniem: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}