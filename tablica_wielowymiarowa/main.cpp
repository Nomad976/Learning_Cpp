#include <iostream>

using namespace std;

int main()
{
    int tablica[8][8];

    for (int i = 0; i < 8; i++)
    {
        for ( int j = 0; j < 8; j++)
        {
            tablica [i][j] = i * j;
        }
    }
    cout << "Tabliczka mnozenia:" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << "[ "<< i <<" ][ "<< j <<" ] = ";
            cout << tablica [i][j] <<" ";
            cout << endl;
        }
    }
    return 0;
}
