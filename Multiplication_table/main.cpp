#include <iostream>

using namespace std;

int main()
{
    int height;
    int width;
    cout << "Type in the height of the table: " << endl;
    cin >> height;
    cout << "Type in the width of the table: " << endl;
    cin >> width;

    int **p_p_table;
    p_p_table = new int*[height];
    for (int i = 0; i < width; i++)
    {
        p_p_table[i] = new int[width];
    }
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

    return 0;
}
