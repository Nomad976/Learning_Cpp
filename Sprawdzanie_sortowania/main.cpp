#include <iostream>

using namespace std;

void sortuj(int tablica[]);
void zamien(int tablica[], int pierwszy_indeks, int drugi_indeks);
int znajdzNajmniejszyPozostalyElement(int tablica[], int indeks);


int main()
{
    int tablica[10];
    bool posortowana = true;
    cout << "Wprowadz wartosci do tablicy: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> tablica[i];
    }

    for (int j = 0; j < 10; j++)
    {
        for (int x = j + 1; x < 10; x++)
        {
            if (tablica[j] > tablica[x])
            {
                posortowana = false;
                break;
            }
        }
    }

    if (posortowana == true)
    {
        cout << "Twoja tablica jest posortowana";
    }
    else if (posortowana == false)
    {
        cout << "Twoja tablica jest nieposortowana, ale zaraz ja posortujemy" << endl;
        sortuj(tablica);
        cout << "Posortowana tablica:" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << tablica[i] << endl;
        }
    }

    return 0;
}


int znajdzNajmniejszyPozostalyElement(int tablica[], int indeks)
{
    int indeks_najmniejszej_wartosci = indeks;
    for (int i = indeks + 1; i < 10; i++)
    {
        if (tablica[i] < tablica[indeks_najmniejszej_wartosci] )
        {
            indeks_najmniejszej_wartosci = i;
        }
    }
    return indeks_najmniejszej_wartosci;
}

void sortuj(int tablica[])
{
    for (int i = 0; i < 10; i++)
    {
        int indeks = znajdzNajmniejszyPozostalyElement(tablica, i);
        zamien(tablica, i, indeks);
    }
}

void zamien(int tablica[], int pierwszy_indeks, int drugi_indeks)
{
    int tymczas = tablica [pierwszy_indeks];
    tablica[pierwszy_indeks] = tablica[drugi_indeks];
    tablica[drugi_indeks] = tymczas;
}
