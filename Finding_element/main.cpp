#include <iostream>

using namespace std;

struct SMTH
{
    string name;
    int ID;
    SMTH *p_next_SMTH;
};

SMTH *list_pointer = NULL;

void new_SMTH(string name_of_new, int number)
{
    SMTH* p_SMTH = new SMTH;
    p_SMTH->ID = number;
    p_SMTH->name = name_of_new;
    p_SMTH->p_next_SMTH = list_pointer;
    list_pointer = p_SMTH;
}

void display()
{
    SMTH *p_actual = list_pointer;
    while (p_actual != NULL)
    {
        cout << "Name: " << p_actual->name << ", ID: " << p_actual->ID << endl;
        p_actual = p_actual->p_next_SMTH;
    }
}

int main()
{
    new_SMTH("Flop", 1);
    new_SMTH("Wheatley", 2);
    new_SMTH("Glados", 3);
    new_SMTH("Caroline", 4);
    string name_search;
    cout << "Type in the name to search for: " << endl;
    cin >> name_search;

    SMTH *p_actual = list_pointer;
    while (p_actual != NULL)
    {
        if (p_actual->name == name_search)
        {
            cout << "Name found in database, ID: " << p_actual->ID << endl;
            break;
        }
        else if (p_actual->p_next_SMTH == NULL)
        {
            cout << "No such name in database." << endl;
        }
        p_actual = p_actual->p_next_SMTH;
    }



    return 0;
}
