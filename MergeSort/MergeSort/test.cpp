/// @file test.cpp Plik główny

#include "pch.h"
#include <cstdlib>
#include <ctime>


/// @brief Test-1,czy zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco,
TEST(testy, niezmieniona_tablica) {
	string wprowadz = ("1 2 3 4 5 6 7 8 9 10");
	Sorter a(wprowadz);
	EXPECT_EQ(wprowadz, a.zwrocniesorts(wprowadz));
}
/// @brief Test-2,czy potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności,
TEST(testy, odwrotna_tablica) {
	string wprowadz = ("6 5 4 3 2 1 0");
	Sorter a(wprowadz);
	EXPECT_EQ("0 1 2 3 4 5 6", a.zwrocniesorts(wprowadz));
}
/// @brief Test-3, czy poprawnie sortuje losową tablicę liczb,
TEST(testy, losowa_tablica) {
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 1;
	while (i < t) {
		r += to_string(rand() % 10000 - 2001);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	Sorter a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}

	
	int j = 0;
	int* tab = a.wskaztab();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}
/// @brief Test-4 poprawnie sortuje tablice tylko z liczbami ujemnymi,
TEST(testy, liczby_ujemne) {
	string wprowadz = ("-6 -20 -23 -2 -200");
	Sorter a(wprowadz);
	EXPECT_EQ("-200 -23 -20 -6 -2", a.zwrocniesorts(wprowadz));
}
/// @brief Test-5 czy poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi,
TEST(testy, liczby_ujemne_i_dodatnie) {
	string wprowadz = ("10 -2 0 -5 12");
	Sorter a(wprowadz);
	EXPECT_EQ("-5 -2 0 10 12", a.zwrocniesorts(wprowadz));
}
/// @brief Test-6 czy obsługuje pustą tablicę bez rzucania wyjątkiem,
TEST(testy, pusta_tablica) {
	string wprowadz = ("");
	Sorter a(wprowadz);
	EXPECT_EQ("", a.zwrocniesorts(wprowadz));
}
/// @brief Test-7 nie zmienia tablicy, która zawiera tylko jeden element,
TEST(testy, tylko_jeden_element) {
	string wprowadz = ("5");
	Sorter a(wprowadz);
	EXPECT_EQ("5", a.zwrocniesorts(wprowadz));
}
/// @brief Test-8 poprawnie sortuje tablicę z duplikatami liczb,
TEST(testy, duplikaty_liczb) {
	string wprowadz = ("3 3 2 2 2");
	Sorter a(wprowadz);
	EXPECT_EQ("2 2 2 3 3", a.zwrocniesorts(wprowadz));
}
/// @brief Test-9 czy poprawnie sortuje tablice ujemną z duplikatami,
TEST(testy, ujemne_duplikaty_liczb) {
	string wprowadz = ("-7 -7 -8 -5 -5");
	Sorter a(wprowadz);
	EXPECT_EQ("-8 -7 -7 -5 -5", a.zwrocniesorts(wprowadz));
}
/// @brief Test-10 czy  poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami,
TEST(testy, tablica_dodatnie_ujemne_duplikaty) {
	string wprowadz = ("10 12 0 0 -2 20 20 -2 -2 -5");
	Sorter a(wprowadz);
	EXPECT_EQ("-5 -2 -2 -2 0 0 10 12 20 20", a.zwrocniesorts(wprowadz));
}
/// @brief Test-11 czy poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej,
TEST(testy, tablica_dwuelementowa) {
	string wprowadz = ("5 10");
	Sorter a(wprowadz);
	EXPECT_EQ("5 10", a.zwrocniesorts(wprowadz));
}
/// @brief Test-12 czy poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów,
TEST(testy, duza_tablica_ponad_100_el){
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 100;
	while (i < t) {
		r += to_string(rand() % 10000 - 2001);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	Sorter a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}


	int j = 0;
	int* tab = a.wskaztab();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}
/// @brief Test-13 czy poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami,
TEST(testy, duza_tablica_ponad_100_el_liczby_ujemne_dodatnie_duplikaty) {
	srand(static_cast<unsigned int>(time(0)));
	int i = 0;
	string r;
	int t = rand() % 100 + 100;
	while (i < t) {
		int y = rand() % 4000 - 2001;
		r += to_string(y);
		r += " ";
		r += to_string(y);
		if (i != (t - 1)) {
			r += " ";
		}
		i++;
	}

	Sorter a(r);

	int spaces = 0;
	for (int j = 0; j < r.length(); j++) {
		if (r[j] == ' ') {
			spaces += 1;
		}
	}


	int j = 0;
	int* tab = a.wskaztab();
	while (j < spaces - 1) {
		if (tab[j] == tab[j + 1]) {
			EXPECT_EQ(tab[j], tab[j + 1]);
		}
		else {
			EXPECT_LT(tab[j], tab[j + 1]);
		}
		j += 1;
	}
}