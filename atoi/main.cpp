#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Uzycie: " << argv[0] << " <liczba>" << endl;
    }
    else
    {
        int wart = atoi( argv[1] );
        cout << wart * wart;
    }
    return 0;
}
