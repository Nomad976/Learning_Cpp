#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int znajdzNajmniejszyPozostalyElement (int tablica[], int rozmiar, int indeks);
void zamien (int tablica[], int pierwszy_indeks, int drugi_indeks);
void sortuj (int tablica[], int rozmiar);
void wyswietlTablice (int tablica [], int rozmiar);

int main()
{
    int wielkosc;
    srand(time (NULL));
    cout << "Wprowadz wielkosc tablicy: ";
    cin >> wielkosc;
    int tablica[wielkosc];
    for (int i = 0; i < wielkosc; i++)
    {
        tablica[i] = rand() % 100;
    }
    cout << "Tablica wyjsciowa: ";
    wyswietlTablice(tablica, wielkosc);
    cout << endl;
    sortuj(tablica, wielkosc);
    cout << "Tablica posortowana: ";
    wyswietlTablice(tablica, wielkosc);
    cout << endl;

    return 0;
}

int znajdzNajmniejszyPozostalyElement(int tablica[], int rozmiar, int indeks)
{
    int indeks_najmniejszej_wartosci = indeks;
    for (int i = indeks + 1; i < rozmiar; i++)
    {
        if (tablica[i] < tablica[indeks_najmniejszej_wartosci] )
        {
            indeks_najmniejszej_wartosci = i;
        }
    }
    return indeks_najmniejszej_wartosci;
}

void sortuj(int tablica [], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        int indeks = znajdzNajmniejszyPozostalyElement(tablica, rozmiar, i);
        zamien(tablica, i, indeks);
    }
}

void zamien(int tablica[], int pierwszy_indeks, int drugi_indeks)
{
    int tymczas = tablica [pierwszy_indeks];
    tablica[pierwszy_indeks] = tablica[drugi_indeks];
    tablica[drugi_indeks] = tymczas;
}

void wyswietlTablice(int tablica[], int rozmiar)
{
    cout << "{";
    for (int i = 0; i < rozmiar; i++)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << tablica [i];
    }
    cout << "}";
}
