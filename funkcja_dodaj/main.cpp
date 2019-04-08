#include <iostream>

using namespace std;

int dodaj (int x, int y)
{
    return x + y;
}

int main()
{
    int wynik = dodaj ( 1 , 2);
    cout << "Pierwszy wynik to " << wynik << endl;
    cout << "Wynikiem dodawania 3 i 4 jest " << dodaj ( 3 , 4);

    return 0;
}
