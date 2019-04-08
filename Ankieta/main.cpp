#include <iostream>

using namespace std;

int main()
{
    int odpowiedz;
    int wartosc1 = 0;
    int wartosc2 = 0;
    int wartosc3 = 0;

    while (odpowiedz != 0)
    {
        cout << "Ile?" << endl;
        cin >> odpowiedz;

        if (odpowiedz == 1)
        {
            wartosc1++;
        }
        else if (odpowiedz == 2)
        {
            wartosc2++;
        }
        else if (odpowiedz == 3)
        {
            wartosc3++;
        }

    }

    cout << "Odpowiedzi 1 udzielilo " << wartosc1 << " osob" << endl;
    cout << "Odpowiedzi 2 udzielilo " << wartosc2 << " osob" << endl;
    cout << "Odpowiedzi 3 udzielilo " << wartosc3 << " osob" << endl;

    return 0;
}
