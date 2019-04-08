#include <iostream>
#include <string>

using namespace std;

int main()
{
    string tekst;
    int i = 0;
    int liczba_kotow = 0;
    cout << "Prosze wprowadzic wiersz z tekstem: ";
    getline(cin, tekst, '\n');
    for (i = tekst.find("kot", 0); i != string::npos; i = tekst.find("kot", i)  )
    {
        liczba_kotow++;
        i++;
    }
    cout << "Slowo kot wystepuje " << liczba_kotow << " razy w tekscie " << '"' << tekst << '"';
    return 0;
}
