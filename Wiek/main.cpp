#include <iostream>

using namespace std;

int main()
{
    int wiek_pierwszej_osoby;
    int wiek_drugiej_osoby;
    cout << "Podaj wiek pierwszej osoby: " << endl;
    cin >> wiek_pierwszej_osoby;
    cout << "Podaj wiek drugiej osoby: " << endl;
    cin >> wiek_drugiej_osoby;
    if ( wiek_pierwszej_osoby > 100 && wiek_drugiej_osoby > 100 )
    {
        cout << "Obie osoby maja wiecej niz 100 lat" << endl;
    }
    if ( wiek_pierwszej_osoby > wiek_drugiej_osoby )
    {
        cout << "Pierwsza osoba jest starsza od drugiej" << endl;
    }
    else if ( wiek_pierwszej_osoby == wiek_drugiej_osoby )
    {
        cout << "Obie osoby sa w takim samym wieku" << endl;
    }
    else if ( wiek_pierwszej_osoby < wiek_drugiej_osoby )
    {
        cout << "Druga osoba jest starsza od pierwszej" << endl;
    }
    return 0;
}
