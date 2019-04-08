#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int najmniejsza (int tablica_przekazana[]);
int najwieksza (int tablica_przekazana[]);
int srednia (int tablica_przekazana[]);

int main()
{
    srand (time (NULL) );
    int tablica[50];
    for (int i = 0; i < 50; i++)
    {
        tablica[i] = rand() % 100;
    }

    cout << "Wartosc najmniejsza: " << najmniejsza(tablica) <<  endl;
    cout << "Wartosc najwieksza: " << najwieksza(tablica) << endl;
    cout << "Srednia: " << srednia(tablica) << endl;
    cout << "Cala tablica: " << endl;
    for (int i = 0; i < 50; i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << tablica[i];
    }

    return 0;
}

int najmniejsza(int tablica_przekazana[])
{
    int indeks_najmniejszej_wartosci = 0;

    for (int i = 1; i < 50; i++)
    {
        if (tablica_przekazana[indeks_najmniejszej_wartosci] > tablica_przekazana[i] )
        {
            indeks_najmniejszej_wartosci = i;
        }
    }
    return tablica_przekazana[indeks_najmniejszej_wartosci];
}

int najwieksza(int tablica_przekazana[])
{
    int indeks_najwiekszej_wartosci = 0;

    for (int i = 1; i < 50; i++)
    {
        if (tablica_przekazana [indeks_najwiekszej_wartosci] < tablica_przekazana[i])
        {
            indeks_najwiekszej_wartosci = i;
        }
    }
    return tablica_przekazana[indeks_najwiekszej_wartosci];
}

int srednia(int tablica_przekazana[])
{
    int suma = 0;
    for (int i = 0; i < 50; i++)
    {
        suma = suma + tablica_przekazana[i];
    }
    suma = suma / 50;
    return suma;

}
