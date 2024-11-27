/// @file pch.h Plik zawieraj¹cy klasê

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
	string* tab;///< wskaŸnik do Zmiennej zawieraj¹cej nieposortowan¹ tablicê typu string
	int* tabs;///< wskaŸnik do tablicy zawieraj¹cej posortowan¹ tablicê tab
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