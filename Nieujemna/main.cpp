#include <iostream>

using namespace std;

int main()
{
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    if ( liczba < 0 )
    {
        cout << "Twoja liczba jest ujemna";
    }
    else
    {
        cout << "Twoja liczba jest nieujemna";
    }
    return 0;
}
