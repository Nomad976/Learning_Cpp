#include <iostream>

using namespace std;

int main()
{
    int glosy[10];

    for (int i = 0; i < 10; i++)
    {
        glosy[i] = 0;
    }

    int kandydat;
    cout << "Prosze zaglosowac na swoich kandydatow za pomoca ich numerow: 0 1 2 3 4 5 6 7 8 9" << endl;
    cin >> kandydat;

    while (0 <= kandydat && kandydat <= 9)
    {
        glosy[kandydat]++;
        cout << "Prosze oddac nastepny glos: ";
        cin >> kandydat;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << glosy[i] << endl;
    }
    return 0;
}
