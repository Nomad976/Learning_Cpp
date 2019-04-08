#include <iostream>

using namespace std;

int main()
{
    int y = 1000;
    int x = 100000;
    if (&x > &y)
    {
        cout << x << " " << y;
    }
    else if (&y > &x)
    {
        cout << y << " " << x;
    }
    else if (&y == &x)
    {
        cout << "lol";
    }
    return 0;
}
