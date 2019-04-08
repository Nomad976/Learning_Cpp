#include "Porownywalne.h"

using namespace std;

TabelaWynikow::TabelaWynikow(int cos)
{
    identifier = cos;
    sort_by_names = false;
    data_size = 0;
}

void TabelaWynikow::display_table()
{
    int counter = 1;
    vector<int>::iterator it;
    vector<string>::iterator sub_it;

    for (it = scores.begin(), sub_it = names.begin(); it != scores.end(); it++, sub_it++)
    {
        cout << counter << ". " << *sub_it << ": " << *it << endl;
        counter++;
    }
}

void TabelaWynikow::resort()
{
    vector<int>::iterator it;
    vector<int>::iterator sub_it;
    vector<int>::iterator current_first_int;
    vector<string>::iterator it_s;
    vector<string>::iterator sub_it_s;
    vector<string>::iterator current_first_string;
    int temp_int;
    string temp_string;

    for (it_s = names.begin(), it = scores.begin(); it_s != names.end(); it_s++, it++)
    {
        current_first_string = it_s;
        current_first_int = it;
        for (sub_it_s = it_s, sub_it = it; sub_it_s != names.end(); sub_it_s++, sub_it++)
        {
            if (*sub_it_s < *current_first_string)
            {
                current_first_string = sub_it_s;
                current_first_int = sub_it;
            }
        }
        temp_string = *it_s;
        temp_int = *it;
        *it_s = *current_first_string;
        *it = *current_first_int;
        *current_first_string = temp_string;
        *current_first_int = temp_int;
    }
}

void TabelaWynikow::add_score(string name, int score)
{
    if (scores.empty() == true)
    {
        scores.push_back(score);
        names.push_back(name);
        data_size++;
        return;
    }

    vector<int>::iterator it;
    vector<string>::iterator it_s;
    if (sort_by_names == false)
    {
        for (it = scores.begin(); it != scores.end(); it++)
        {
            if (score == *it)
            {
                sort_by_names = true;
                resort();
                add_score(name, score);
                return;
            }
        }

        for (it = scores.begin(), it_s = names.begin(); it != scores.end(); it++, it_s++)
        {
            if (score > *it)
            {
                scores.insert(it, score);
                names.insert(it_s, name);
                data_size++;
                return;
            }
        }

        if (it == scores.end() )
        {
            scores.push_back(score);
            names.push_back(name);
            data_size++;
            return;
        }
    }
    else
    {
        for (it_s = names.begin(), it = scores.begin(); it_s != names.end(); it_s++, it++)
        {
            if (name < *it_s)
            {
                names.insert(it_s, name);
                scores.insert(it, score);
                data_size++;
                return;
            }
        }

        if (it_s == names.end() )
        {
            names.push_back(name);
            scores.push_back(score);
            data_size++;
            return;
        }
    }
}

int TabelaWynikow::porownaj(Porownywalne *inny)
{
    if (this->data_size == inny->data_size)
    {
        return 0;
    }
    else if (this->data_size > inny->data_size)
    {
        return 1;
    }
    else if (this->data_size < inny->data_size)
    {
        return -1;
    }
}

void sortuj (vector<Porownywalne*> &tabela_tabel)
{
    vector<Porownywalne*>::iterator itr;
    vector<Porownywalne*>::iterator sub_itr;
    Porownywalne *temp;

    for (itr = tabela_tabel.begin(); itr != tabela_tabel.end(); itr++)
    {
        for (sub_itr = itr; sub_itr != tabela_tabel.end(); sub_itr++)
        {
            if ( (*itr)->data_size < (*sub_itr)->data_size)
            {
                temp = *itr;
                *itr = *sub_itr;
                *sub_itr = temp;
            }
        }
    }
}
