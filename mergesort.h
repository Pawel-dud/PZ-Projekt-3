#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

using namespace std;

class MergeSort {
public:
    void start(int tab[], int rozmiar);

private:
    void sortowanie(int tab[], int lewa, int prawa);

    void scalanie(int tab[], int lewa, int srodek, int prawa);
};

#endif
