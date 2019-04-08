#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    //fstream file ("wyniki.bin", ios::trunc | ios::binary | ios::in | ios::out);
    fstream file ( "wyniki.bin", ios::binary | ios::out | ios::in);

    if ( ! file.is_open() )
    {
        cout << "Can't open the file." << endl;
        return 1;
    }

    int score;
    cout << "Give the score to write in the file: ";
    cin >> score;

    streampos prev_position = file.tellg();
    int curr_score;
    while (file.read( reinterpret_cast<char*>( & curr_score), sizeof(curr_score) ) )
    {
        if (curr_score < score)
        {
            break;
        }
        prev_position = file.tellg();
    }

    if (file.fail() && ! file.eof() )
    {
        cout << "Improper input" << endl;
        return 1;
    }

    file.clear();

    file.seekg(prev_position);

    vector<int> scores;
    while (file.read( reinterpret_cast<char*>( & curr_score), sizeof(curr_score) ) )
    {
        scores.push_back(curr_score);
    }

    if ( ! file.eof() )
    {
        cout << "Improper input" << endl;
        return 1;
    }

    file.clear();

    file.seekp(prev_position);

    /*if (prev_position != streampos(0) )
    {
        file << endl;
    }*/

    file.write(reinterpret_cast<char*>( & score), sizeof(score) );

    for (vector<int>::iterator itr = scores.begin(); itr != scores.end(); itr++)
    {
        file.write(reinterpret_cast<char*>(& (*itr) ), sizeof(*itr) );
    }

    return 0;
}
