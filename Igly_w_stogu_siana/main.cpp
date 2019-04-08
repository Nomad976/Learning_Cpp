#include <iostream>
#include <string>

using namespace std;

int main()
{
    string igla;
    string stog;
    int liczba_igiel = 0;
    cout << "Podaj igle: ";
    getline(cin, igla, '\n');
    cout << "Podaj stog siana: ";
    getline(cin, stog, '\n');


    for (int i = stog.find(igla, 0); i != string::npos; i = stog.find(igla, i))
    {
        liczba_igiel++;
        i++;
    }
    cout << "Jest " << liczba_igiel << " igiel w tym stogu siana" << endl;
    return 0;
}
