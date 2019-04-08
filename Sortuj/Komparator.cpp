#include "Porownywalne.h"

using namespace std;

int sub_Komp::porownaj(const string &lewy, const string &prawy)
{
    string temp_lewy = lewy;
    string temp_prawy = prawy;

    for (int i = 0; i < temp_lewy.length(); i++)
    {
        temp_lewy[i] = tolower(temp_lewy[i]);
    }
    for (int i = 0; i < temp_prawy.length(); i++)
    {
        temp_prawy[i] = tolower(temp_prawy[i]);
    }

    if (temp_lewy > temp_prawy)
    {
        return 1;
    }
    else if (temp_prawy > temp_lewy)
    {
        return -1;
    }
    else if (temp_lewy == temp_prawy)
    {
        return 0;
    }
}
