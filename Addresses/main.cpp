#include <iostream>

using namespace std;

int main()
{
    int tab[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &tab[i][j] << endl;
        }
    }


    return 0;
}
