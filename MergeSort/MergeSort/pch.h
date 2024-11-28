/// @file pch.h Plik zawierajacy klase

//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
/// @brief Klasa Sorter oraz deklaracje jej metod
class Sorter {
private:
	string* tab;///< wskaznik do Zmiennej zawierajacej nieposortowana tablice typu string
	int* tabs;///< wskaznik do tablicy zawierajacej posortowana tablice tab
public:

	Sorter(string a);
	~Sorter();
	int Sprawdz(int i, string a);
	int Dlugtab(string a);
	void zwrocniesort(string a);
	void zamien(int a);
	void sort(int a);
	string zwrocniesorts(string a);
	int* wskaztab();
};