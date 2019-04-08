#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream odczyt_pliku ( "wyniki.txt" );
    if ( ! odczyt_pliku.is_open() )
    {
        cout << "Nie moglem otworzyc pliku" << endl;
    }
    vector<int> wyniki;
    for (int i = 0; i < 10; i++)
    {
        int wynik;
        if ( ! (odczyt_pliku >> wynik) )
        {
            break;
        }
        wyniki.push_back(wynik);
    }
    return 0;
}
