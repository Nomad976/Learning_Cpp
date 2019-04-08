#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i < 13; i++)
    {
        cout << "On the " << i << " day of Christmas my true love sent to me" << endl;

        if (i > 1)
        {


        switch (i)
        {
        case 12:
            cout << "Drummers Drumming" << endl;
        case 11:
            cout << "Pipers Piping" << endl;
        case 10:
            cout << "Lords a-Leaping" << endl;
        case 9:
            cout << "Ladies Dancing" << endl;
        case 8:
            cout << "Maids a-Milking" << endl;
        case 7:
            cout << "Swans a-Swimming" << endl;
        case 6:
            cout << "Geese a-Laying" << endl;
        case 5:
            cout << "Gold Rings" << endl;
        case 4:
            cout << "Calling Birds" << endl;
        case 3:
            cout << "Three French Hens" << endl;
        case 2:
            cout << "Two Turtle Doves" << endl;
        case 1:
            cout << "and a Partridge in a Pear Tree." << endl;
        }

        }
        else
        {
            cout << "a Partridge in a Pear Tree." << endl;
        }
    }

    return 0;
}
