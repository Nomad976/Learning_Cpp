#include <iostream>

using namespace std;

void dodawanie();
void odejmowanie();
void mnozenie();
void dzielenie();

int main()
{
    string dzialanie;
    cout << "Podaj operator arytmetyczny dzialania ktore chcesz wykonac: " << endl;
    cin >> dzialanie;

    if ( dzialanie != "+" && dzialanie != "-" && dzialanie != "/" && dzialanie != "*" )
    {
        cout << "Niepoprawny operator dzialania";
        return 0;
    }



    if ( dzialanie == "+" )
    {
        dodawanie();
    }
    else if ( dzialanie == "-" )
    {
        odejmowanie();
    }
    else if ( dzialanie == "*" )
    {
        mnozenie();
    }
    else if ( dzialanie == "/" )
    {
        dzielenie();
    }
    return 0;
}

void dodawanie()
{
    double pierwszy_argument;
    double drugi_argument;
    cout << "Podaj pierwszy a nastepnie drugi argument dzialania:" << endl;
    cin >> pierwszy_argument;
    cin >> drugi_argument;
    cout << "Wynik dzialania to: " << pierwszy_argument + drugi_argument;
}

void odejmowanie()
{
    double pierwszy_argument;
    double drugi_argument;
    cout << "Podaj pierwszy a nastepnie drugi argument dzialania:" << endl;
    cin >> pierwszy_argument;
    cin >> drugi_argument;
    cout << "Wynik dzialania to: " << pierwszy_argument - drugi_argument;
}

void mnozenie()
{
    double pierwszy_argument;
    double drugi_argument;
    cout << "Podaj pierwszy a nastepnie drugi argument dzialania:" << endl;
    cin >> pierwszy_argument;
    cin >> drugi_argument;
    cout << "Wynik dzialania to: " << pierwszy_argument * drugi_argument;
}

void dzielenie()
{
    double pierwszy_argument;
    double drugi_argument;
    cout << "Podaj pierwszy a nastepnie drugi argument dzialania:" << endl;
    cin >> pierwszy_argument;
    cin >> drugi_argument;
    cout << "Wynik dzialania to: " << pierwszy_argument / drugi_argument;
}
