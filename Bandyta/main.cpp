#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int lewy;
    int srodkowy;
    int prawy;
    char cos;

    srand (time (NULL));

    do
    {


    cout << "Kliknij by zaczac losowanko. Kliknij 0 jesli chcesz wyjsc." << endl;
    cin >> cos;

    if (cos == '0')
    {
        break;
    }

    lewy = rand() % 10;
    srodkowy = rand () % 10;
    prawy = rand () % 10;

    cout << lewy << " " << srodkowy << " " << prawy << endl;

    if ( (lewy == srodkowy) && (prawy == srodkowy) )
    {
        cout << "Wygrana." << endl;
    }
    else
    {
        cout << "Przegrana." << endl;
    }

    } while (cos != '0');

    return 0;
}
