#include <iostream>

using namespace std;

int sumujTablice (int wartosci[], int rozmiar)
{
    int suma = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        suma += wartosci [i];
    }
    return suma;
}

int main()
{
    int wartosci [10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Podaj wartosc " << i << ": ";
        cin >> wartosci [i];
    }
    cout << sumujTablice(wartosci, 10) << endl;


    return 0;
}
