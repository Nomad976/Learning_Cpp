#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand( time( NULL ));
    int losowa = rand() % 2;
    if (losowa == 0)
    {
        cout << "Orzel";
    }
    else if (losowa == 1)
    {
        cout << "Reszka";
    }
    return 0;
}
