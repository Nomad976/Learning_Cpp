#include <iostream>

using namespace std;

void bottles();
void kalkulator();

int main()
{
    int wybor_opcji;
    do
    {cout << "Menu: " << endl << "1. 99 Bottles of Beer" << endl << "2. Kalkulator" << endl << "3. Wyjdz" << endl;
    cin >> wybor_opcji;
    switch (wybor_opcji)
    {
    case 1:
        bottles();
        break;
    case 2:
        kalkulator();
        break;
    case 3:
        cout << "Wychodzenie";
        return 0;
    }



    } while ( 1 );

}

void bottles()
{
    for (int i = 99; i > 2; i--)
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles of beer. Take one down and pass it around - " << i - 1 << " bottles of beer on the wall." << endl;
    }

    cout << "2 bottles of beer on the wall, 2 bottles of beer. Take one down and pass it around - 1 bottle of beer on the wall." << endl;
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take one down and pass it around - no more bottles of beer on the wall." << endl;
}

void kalkulator()
{
    char dzialanie;
    double pierwszy_argument;
    double drugi_argument;

    cout << "Podaj operator arytmetyczny dzialania ktore chcesz wykonac: " << endl;
    cin >> dzialanie;

    if ( dzialanie != '+' && dzialanie != '-' && dzialanie != '/' && dzialanie != '*' )
    {
        cout << "Niepoprawny operator dzialania" << endl;
        return;
    }

    cout << "Podaj pierwszy a nastepnie drugi argument dzialania:" << endl;
    cin >> pierwszy_argument;
    cin >> drugi_argument;

    switch (dzialanie)
    {
    case '+':
        cout << "Wynik dzialania to: " << pierwszy_argument + drugi_argument << endl;
        break;
    case '-':
        cout << "Wynik dzialania to: " << pierwszy_argument - drugi_argument << endl;
        break;
    case '/':
         cout << "Wynik dzialania to: " << pierwszy_argument / drugi_argument << endl;
         break;
    case '*':
         cout << "Wynik dzialania to: " << pierwszy_argument * drugi_argument << endl;
         break;
    }



}





