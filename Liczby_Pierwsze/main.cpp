#include <iostream>

using namespace std;

int main()
{
    int czynnik_pierwszy;
    int suma;
    bool czy_pierwsza;
    bool czy_ipierwsza;
    int z;

    for (int i = 2; i <= 1000; i++)
    {
        z = i;
        czynnik_pierwszy = 2;
        czy_pierwsza = true;
        czy_ipierwsza = false;
        suma = 0;
        while (z > 1)
        {
            while (z % czynnik_pierwszy == 0)
            {
                suma = suma + czynnik_pierwszy;
                z = z / czynnik_pierwszy;
            }
            czynnik_pierwszy++;
        }

        for (int j = 2; j < suma; j++)
        {
            if (suma % j == 0)
            {
                czy_pierwsza = false;
                break;
            }
        }

        for (int x = 2; x < i; x++)
        {
            if (i % x == 0)
            {
                break;
            }
            czy_ipierwsza = true;
        }
        if ( (czy_pierwsza == true) && (czy_ipierwsza == false) )
        {
            cout << i << endl;
        }
    }

    return 0;
}
