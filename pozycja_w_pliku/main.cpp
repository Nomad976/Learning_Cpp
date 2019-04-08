#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    fstream plik ( "wyniki.txt", ios::in | ios::out);
    if ( ! plik.is_open() )
    {
        cout << "Nie moglem otworzyc pliku" << endl;
        return 0;
    }
    int nowy_wynik;
    cout << "Podaj nowy wynik: ";
    cin >> nowy_wynik;

    streampos poprz_poz_wyniku = plik.tellg();
    int biez_wynik;
    while (plik >> biez_wynik)
    {
        if (biez_wynik < nowy_wynik)
        {
            break;
        }
        poprz_poz_wyniku = plik.tellg();
    }

    if ( plik.fail() && ! plik.eof() )
    {
        cout << "Niepoprawny odczyt wyniku - wychodze z programu";
        return 0;
    }

    plik.clear();
    plik.seekg(poprz_poz_wyniku);

    vector<int> punktacja;
    while (plik >> biez_wynik)
    {
        punktacja.push_back(biez_wynik);
    }

    if ( ! plik.eof() )
    {
        cout << "Niepoprawny odczyt wyniku - wychodze z programu";
        return 0;
    }

    plik.clear();

    plik.seekp(poprz_poz_wyniku);

    if (poprz_poz_wyniku != streampos(0) )
    {
        plik << endl;
    }

    plik << nowy_wynik << endl;

    for (vector<int>::iterator itr = punktacja.begin(); itr != punktacja.end(); itr++)
    {
        plik << *itr << endl;
    }
    return 0;
}
