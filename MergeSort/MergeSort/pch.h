/// @file pch.h Plik zawieraj�cy klas�

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
	string* tab;///< wska�nik do Zmiennej zawieraj�cej nieposortowan� tablic� typu string
	int* tabs;///< wska�nik do tablicy zawieraj�cej posortowan� tablic� tab
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