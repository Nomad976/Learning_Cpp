#include <iostream>

using namespace std;

void reverse_table (int table[], int numerator)
{
    if (numerator == 50)
    {
        cout << table[numerator] << endl;
        return;
    }
    reverse_table(table, numerator + 1);
    cout << table[numerator] << endl;
}

int main()
{
    int table [50];
    for (int i = 0; i < 50; i++)
    {
        table[i] = i;
    }
    reverse_table(table, 0);
    return 0;
}
