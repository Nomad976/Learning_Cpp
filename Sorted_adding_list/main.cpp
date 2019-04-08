#include <iostream>

using namespace std;

struct SMTH
{
    int ID;
    SMTH *p_next_SMTH;
};

SMTH *list_pointer = NULL;

void new_SMTH(int iteration)
{
    SMTH* p_SMTH = new SMTH;
    p_SMTH->ID = iteration;
    p_SMTH->p_next_SMTH = list_pointer;
    list_pointer = p_SMTH;
}

void display()
{
    SMTH *p_actual = list_pointer;
    while (p_actual != NULL)
    {
        cout << "ID: " << p_actual->ID << endl;
        p_actual = p_actual->p_next_SMTH;
    }
}

void add(int iteration)
{
    SMTH *p_actual = list_pointer;
    bool done = false;
    while (p_actual != NULL && done == false)
    {
        if (p_actual->p_next_SMTH != NULL)
        {
            if ( (iteration <= p_actual->ID) &&  (iteration >= p_actual->p_next_SMTH->ID) )
            {
                SMTH *p_SMTH = new SMTH;
                p_SMTH->ID = iteration;
                p_SMTH->p_next_SMTH = p_actual->p_next_SMTH;
                p_actual->p_next_SMTH = p_SMTH;
                done = true;
            }
            else if (p_actual == list_pointer && iteration > p_actual->ID)
            {
                SMTH *p_SMTH = new SMTH;
                p_SMTH->ID = iteration;
                p_SMTH->p_next_SMTH = p_actual;
                list_pointer = p_SMTH;
                done = true;
            }
        }
        else if (p_actual->p_next_SMTH == NULL && iteration < p_actual->ID)
        {
            SMTH *p_SMTH = new SMTH;
            p_SMTH->ID = iteration;
            p_SMTH->p_next_SMTH = NULL;
            p_actual->p_next_SMTH = p_SMTH;
            done = true;
        }

        p_actual = p_actual->p_next_SMTH;
    }
}

int main()
{
    new_SMTH(1);
    new_SMTH(4);
    new_SMTH(7);
    display();
    int number;
    cin >> number;
    add(number);
    display();
    return 0;
}
