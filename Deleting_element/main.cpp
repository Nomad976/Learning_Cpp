#include <iostream>

using namespace std;

struct SMTH
{
    int ID;
    SMTH *p_next_SMTH;
    SMTH *p_prev_SMTH;
};

SMTH *list_pointer = NULL;

SMTH* new_SMTH(int &iteration)
{
    SMTH* p_SMTH = new SMTH;
    p_SMTH->ID = iteration;
    p_SMTH->p_next_SMTH = list_pointer;
    list_pointer = p_SMTH;
    if (p_SMTH->p_next_SMTH != NULL)
    {
        p_SMTH->p_next_SMTH->p_prev_SMTH = p_SMTH;
    }
    p_SMTH->p_prev_SMTH = NULL;

    return p_SMTH;
}

void delete_SMTH(int &iteration)
{
    SMTH *p_actual = list_pointer;
    while (p_actual != NULL)
    {
        if (p_actual->ID == iteration)
        {
            if (p_actual->p_prev_SMTH != NULL && p_actual->p_next_SMTH != NULL)
            {
                p_actual->p_prev_SMTH->p_next_SMTH = p_actual->p_next_SMTH;
                p_actual->p_next_SMTH->p_prev_SMTH = p_actual->p_prev_SMTH;
            }
            else if (p_actual->p_prev_SMTH == NULL)
            {
                p_actual->p_next_SMTH->p_prev_SMTH = NULL;
            }
            else if (p_actual->p_next_SMTH == NULL)
            {
                p_actual->p_prev_SMTH->p_next_SMTH = NULL;
            }

            if (p_actual == list_pointer)
            {
                list_pointer = p_actual->p_next_SMTH;
            }
            delete p_actual;
            break;
        }
        p_actual = p_actual->p_next_SMTH;
    }
}

void display()
{
    SMTH *p_actual = list_pointer;
    while (p_actual != NULL)
    {
        cout << "ID: " << p_actual->ID << " ";

        if (p_actual->p_prev_SMTH != NULL)
        {
            cout << "Prev: " << p_actual->p_prev_SMTH->ID << " ";
        }
        else
        {
            cout << "Prev: NULL ";
        }

        if (p_actual->p_next_SMTH != NULL)
        {
            cout << "Next: " << p_actual->p_next_SMTH->ID << endl;
        }
        else
        {
            cout << "Next: NULL" << endl;
        }

        p_actual = p_actual->p_next_SMTH;
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        new_SMTH(i);
    }
    display();
    int choice;
    cout << endl << "Type in the ID of the block to delete: " << endl;
    cin >> choice;
    delete_SMTH(choice);
    cout << endl;
    display();

    return 0;
}
