#include <iostream>
#include "Porownywalne.h"

using namespace std;

int main()
{
    TabelaWynikow moja_tabela(0);
    TabelaWynikow inna_tabela(1);
    TabelaWynikow jakas_tabela(2);
    vector <Porownywalne*> tabele;

    moja_tabela.add_score("A", 13);
    moja_tabela.add_score("B", 13);
    moja_tabela.add_score("C", 100);


    tabele.push_back(&inna_tabela);
    tabele.push_back(&jakas_tabela);
    tabele.push_back(&moja_tabela);

    vector<Porownywalne*>::iterator itr;
    for (itr = tabele.begin(); itr != tabele.end(); itr++)
    {
        cout << (*itr)->identifier << endl;
    }

    sortuj(tabele);
    cout << endl;

    for (itr = tabele.begin(); itr != tabele.end(); itr++)
    {
        cout << (*itr)->identifier << endl;
    }
    return 0;
}
