#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void quicksort(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tablica[i] < v) i++;
		while (tablica[j] > v) j--;
		if (i <= j)
		{
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > lewy) quicksort(tablica, lewy, j);
	if (i < prawy) quicksort(tablica, i, prawy);
}

int main()
{
	srand(time(NULL));
	int tablica[6];
	int strzaly[6];

	cout << "Witam wszystkich na losowaniu duzego lottka." << endl;
	cout << "Podaj prosze 6 liczb z zakresu od 1 do 49 i zobaczymy czy to tobie sprzyja dzis szczescie." << endl;
	cout << "Pierwsza liczba:";
	cin >> strzaly[0];
	cout << "Druga liczba:";
	cin >> strzaly[1];
	cout << "Trzecia liczb:";
	cin >> strzaly[2];
	cout << "Czwarta liczba:";
	cin >> strzaly[3];
	cout << "Piata liczba:";
	cin >> strzaly[4];
	cout << "Szosta liczba:";
	cin >> strzaly[5];
	cout << "Twoje liczby to:" << endl;
	for (int i = 0; i < 6; i++)
	{
		quicksort(strzaly, 0, 5);
		cout << strzaly[i]<< " ";
	}
	for (int i = 0; i < 6;)
	{
		int rnd = rand() % 49 + 1;
		auto j = find(tablica, tablica + i, rnd);
		if (j == tablica + i) { *j = rnd; ++i; }
	}
	cout << endl << "Zobaczmy jakie liczby zostaly wylosowane:" << endl;
	for (int i = 0; i < 6; i++)
	{

		quicksort(tablica, 0, 5);
		cout << tablica[i] << " ";
	}
	cout<< endl << "Sprobuj jeszcze raz." << endl;
	system("Pause");
	return 0;
}

