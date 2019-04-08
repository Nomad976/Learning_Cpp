#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (1)
    {
        string imie;
        getline(cin, imie, ',');

        if (imie.size() == 0)
        {
            break;
        }
        string nazwisko;
        getline(cin, nazwisko, ',');

        string klasa_gracza;
        getline(cin, klasa_gracza, '\n');
        cout << imie << " " << nazwisko << " ma klase " << klasa_gracza << endl;
    }
    return 0;
}
