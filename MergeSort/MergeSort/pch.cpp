/// @file pch.cpp Plik zawieraj¹cy metody

//
// pch.cpp
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief konstruktor, automatycznie sortuje tablicê
/// @param a - tablica do posortowania 
Sorter::Sorter(string a) {
    if (a != "") {
        int i = 0;
        int tabSprawdz = 0;
        int spaces = Dlugtab(a);
        tab = new string[spaces + 1];
        tabs = new int[spaces + 1];

        while (i < a.length()) {
            if (a[i] == ' ') {
                i += 1;
                continue;
            }

            int wordLength = Sprawdz(i, a);

            tab[tabSprawdz] = a.substr(i, wordLength);
            tabSprawdz += 1;

            i += wordLength;
        }
        zamien(spaces);
        sort(spaces);
    }
    else {
        tab = new string[1];
        tab[0] = "";
        tabs = new int[0];
    }
    
}
/// @brief Destruktor, usuwa zmienne dynamiczne tab i tabs
Sorter::~Sorter() {
    delete[] tab;
    delete[] tabs;
};

/// @brief metoda Sprawdz, zwraca d³ugoœæ danego elementu tablicy
/// @param i - miejece elementu w string a 
/// @param a - nieposortowana tablica tab
int Sorter::Sprawdz(int i, string a) {
    int length = 0;
    while (i + length < a.length() && a[i + length] != ' ') {
        length += 1;
    }
    return length;
}

/// @brief metoda Dlugtab
/// @param a - nieposortowana tablica tab
int Sorter::Dlugtab(string a) {
    int spaces = 0;
    for (int j = 0; j < a.length(); j++) {
        if (a[j] == ' ') {
            spaces += 1;
        }
    }
    return spaces + 1;
}
/// @brief metoda zwrocniesort, wypisuje tablicê z przecinkami
/// @param a - nieposortowana tablica tab
void Sorter::zwrocniesort(string a) {
    int i = 0;
    while (i < Dlugtab(a)) {
        cout << tab[i] << " , ";
        i++;
    }
}
/// @brief metoda zwrocniesort, konwertuje string tab do tablicy int tabs 
/// @param spaces - iloœæ elementów tablicy tabs
void Sorter::zamien(int spaces) {
    int i = 0;
    while (i < (spaces)) {
        tabs[i] = stoi(tab[i]);
        i++;
    }
}
/// @brief metoda sort, sortuje tablicê tabs
/// @param spaces - iloœæ elementów tablicy tabs
void Sorter::sort(int spaces) {
    int mnoznik = 1;

    while (mnoznik < spaces) {
        for (int i = 0; i < spaces; i += (2 * mnoznik)) {
            int mid = min(i + mnoznik, spaces);
            int end = min(i + 2 * mnoznik, spaces);


            int* temp = new int[spaces];
            int left = i, right = mid, k = i;


            while (left < mid && right < end) {
                if (tabs[left] <= tabs[right]) {
                    temp[k++] = tabs[left++];
                }
                else {
                    temp[k++] = tabs[right++];
                }
            }


            while (left < mid) {
                temp[k++] = tabs[left++];
            }


            while (right < end) {
                temp[k++] = tabs[right++];
            }


            for (int j = i; j < end; j++) {
                tabs[j] = temp[j];
            }

            delete[] temp;
        }

        mnoznik *= 2;
    }
}



/// @brief metoda zwrocniesorts,zwraca tablicê w stringu
/// @param a - nieposortowana tablica tab
string Sorter::zwrocniesorts(string a) {
    if (tab[0] == "") {
        return "";
    }
    else {
        int i = 0;
        string r;
        while (i < Dlugtab(a)) {
            r += to_string(tabs[i]);
            if (i != (Dlugtab(a) - 1)) {
                r += " ";
            }
            i++;
        }
        return  r;
    }
}
/// @brief metoda wskaztab, zwraca wskaŸnik na tabs
int* Sorter::wskaztab() {
    return tabs;
}