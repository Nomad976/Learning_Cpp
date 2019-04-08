#include <iostream>

using namespace std;

int main()
{
    for (int i = 99; i > 2; i--)
    {
        cout << i << " bottles of beer on the wall, " << i << " bottles of beer. Take one down and pass it around - " << i - 1 << " bottles of beer on the wall." << endl;
    }

    cout << "2 bottles of beer on the wall, 2 bottles of beer. Take one down and pass it around - 1 bottle of beer on the wall." << endl;
    cout << "1 bottle of beer on the wall, 1 bottle of beer. Take one down and pass it around - no more bottles of beer on the wall.";

    return 0;
}
