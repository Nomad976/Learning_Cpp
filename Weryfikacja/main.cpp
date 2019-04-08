#include <iostream>

using namespace std;

string haslo;

void sprawdzanie();

int main()
{
    int i = 0;


    while ( (i < 6) && (haslo != "xyzzy") )
    {
        cout << "Podaj haslo: ";
        cin >> haslo;
        i++;
    }

    sprawdzanie();

    return 0;
}

void sprawdzanie()
{
     if ( haslo == "xyzzy")
    {
        cout << "Dostep przyznany";
    }
    else
    {
        cout << "Odmowa dostepu";
    }
}
