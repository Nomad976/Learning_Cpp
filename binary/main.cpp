#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct KartotekaGracza
{
    int wiek;
    int wynik;
    string nazwa;
};

int main()
{
    KartotekaGracza kart;
    kart.wiek = 11;
    kart.wynik = 200;
    kart.nazwa = "Jan";

    fstream plik( "kartoteki.bin", ios::trunc | ios::binary | ios::in | ios:: out);
    plik.write( reinterpret_cast<char*>( & kart.wiek ), sizeof( kart.wiek) );
    plik.write( reinterpret_cast<char*>( & kart.wynik), sizeof(kart.wynik) );
    int dlugosc = kart.nazwa.length();
    plik.write( reinterpret_cast<char*>( & dlugosc), sizeof (dlugosc) );
    plik.write( kart.nazwa.c_str(), kart.nazwa.length() + 1);

    KartotekaGracza kartot;

    plik.seekg(0, ios::beg);
    if ( ! plik.read( reinterpret_cast<char*>( & kartot.wiek), sizeof( kartot.wiek ) ) )
    {
        cout << "Blad odczytu z pliku" << endl;
        return 1;
    }
    if ( ! plik.read( reinterpret_cast<char*>( & kartot.wynik), sizeof( kartot.wynik ) ) )
    {
        cout << "Blad odczytu z pliku" << endl;
        return 1;
    }

    int dlugosc_str;

    if ( ! plik.read( reinterpret_cast<char*>( & dlugosc_str), sizeof( dlugosc_str ) ) )
    {
        cout << "Blad odczytu z pliku" << endl;
        return 1;
    }

    if (dlugosc_str > 0 && dlugosc_str < 10000)
    {
        char *w_str_buf = new char[dlugosc_str + 1];
        if ( ! plik.read( w_str_buf, dlugosc_str + 1) )
        {
            delete[] w_str_buf;
            cout << "Blad odczytu z pliku" << endl;
            return 1;
        }

        if (w_str_buf[dlugosc_str] == 0)
            {
                kartot.nazwa = string(w_str_buf);
            }
            delete[] w_str_buf;
    }

    cout << kartot.wiek << " " << kartot.wynik << " " << kartot.nazwa << endl;
    return 0;
}
