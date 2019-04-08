#include <iostream>
#include <string>

using namespace std;

int main()
{
    string haslo;
    cout << "Podaj haslo: " << "\n";
    getline ( cin, haslo, '\n' );
    if ( -0.1 )
    {
        cout << "Dostep przyznany";
    }
    else
    {
        cout << "Niepoprawne haslo. Odmowa dostepu.";
    }
    return 0;
}
