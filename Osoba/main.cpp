#include <iostream>

using namespace std;

struct wpis
{
    string imie;
    string nazwisko;
    string numer_telefonu;
};

int main()
{
    wpis osoba;

    cout << "Podaj imie:" << endl;
    cin >> osoba.imie;
    cout << "Podaj nazwisko: " << endl;
    cin >> osoba.nazwisko;
    cout << "Podaj numer telefonu: " << endl;
    cin >> osoba.numer_telefonu;

    cout << endl;
    cout << osoba.imie << " " << osoba.nazwisko << endl;
    cout << osoba.numer_telefonu;
    return 0;
}
