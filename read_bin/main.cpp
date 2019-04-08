#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file ("wyniki.bin", ios::binary | ios::in);

    if ( ! file.is_open() )
    {
        cout << "Couldn't open the file" << endl;
        return 1;
    }

    int byte;
    while ( ! file.eof() )
    {
        file.read( reinterpret_cast<char*>( & byte), sizeof(byte) );
        if (file.eof() )
        {
            break;
        }
        cout << byte << endl;
    }
    return 0;
}
