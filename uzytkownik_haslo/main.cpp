#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nazwa;
    string haslo;
    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwa;

    cout << "Podaj haslo: " << endl;
    cin >> haslo;

    if ( (nazwa == "admin" && haslo == "xyzzy") || (nazwa == "admin1" && haslo == "xyzzy1") || (nazwa == "admin2" && haslo == "xyzzy2") )
    {
        cout << "Dostep przyznany";
    }
    else
    {
        cout << "Niepoprawny login lub haslo, sprobuj ponownie" << endl << "Nazwa uzytkownika:" << endl;
        cin >> nazwa;
        cout << "Haslo:" << endl;
        cin >> haslo;
        if ( (nazwa == "admin" && haslo == "xyzzy") || (nazwa == "admin1" && haslo == "xyzzy1") || (nazwa == "admin2" && haslo == "xyzzy2") )
        {
            cout << "Dostep przyznany";
        }
        else
        {
            cout << "Odmowa dostepu";
        }
    }
    return 0;
}
