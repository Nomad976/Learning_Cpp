#include <iostream>

using namespace std;

void STH(int length, int width, int height)
{

        int *table = new int[length * width * height];
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < height; j++)
            {
                for (int k = 0; k < width; k ++)
                {
                    table[i*j*k] = (i* j * k);
                }
            }
        }

        for (int k = 0; k < length; k++)
        {
            cout <<"Table " << k + 1 << ":" << endl;
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if(i == 0)
                    {
                        cout << j << '\t';
                    }
                    else if (j == 0)
                    {
                        cout << i << '\t';
                    }
                    else
                    {
                        cout << i * j << '\t';
                    }
                }
                cout << endl;
            }
            delete[] table;
        }
}

int main()
{
    int x, y, z;
    cout << "Length: " << endl;
    cin >> z;
    cout << "Height: " << endl;
    cin >> y;
    cout << "Width: " << endl;
    cin >> x;

    STH(z, x, y);

    return 0;
}
