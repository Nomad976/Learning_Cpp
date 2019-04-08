#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand ( time ( NULL ) );
    cout << rand() << endl;
    return 0;
}
