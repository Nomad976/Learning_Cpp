#include <iostream>

using namespace std;

struct node
{
    int ID;
    node *p_next_node;
    node *p_prev_node;
};

node *p_list = NULL;

void display_list ()
{
    node *p_actual;
    p_actual = p_list;
    while (p_actual != NULL)
    {
        cout << p_actual->ID << endl;
        p_actual = p_actual->p_next_node;
    }
}

void add_elements (int number_of_elements, int existing_elements)
{
    if (number_of_elements + existing_elements != existing_elements)
    {
        add_elements(number_of_elements - 1, existing_elements);
    }
    else if (existing_elements > 0)
    {
        return;
    }

    node *p_new_node;
    p_new_node = new node;
    p_new_node->ID = number_of_elements + existing_elements;
    p_new_node->p_next_node = p_list;
    if (p_new_node->p_next_node != NULL)
    {
        p_new_node->p_next_node->p_prev_node = p_new_node;
    }
    p_list = p_new_node;
    p_new_node->p_prev_node = NULL;

}

void add_elements_iteration (int number_of_elements, int existing_elements)
{
    for (int i = existing_elements + 1; i <= number_of_elements + existing_elements; i++)
    {
        node *p_new_node;
        p_new_node = new node;
        p_new_node->ID = i;
        p_new_node->p_next_node = p_list;
        if (p_new_node->p_next_node != NULL)
        {
            p_new_node->p_next_node->p_prev_node = p_new_node;
        }
        p_list = p_new_node;
        p_new_node->p_prev_node = NULL;
    }
}

void delete_elements (int number_of_elements, int existing_elements, node *p_act)
{
    if (p_act->ID != existing_elements - number_of_elements + 1)
    {
        delete_elements(number_of_elements, existing_elements, p_act->p_next_node);
    }
    if (p_act->ID == existing_elements - number_of_elements + 1)
    {
        p_act->p_next_node->p_prev_node = NULL;
        p_list = p_act->p_next_node;
    }
    delete p_act;

}

void delete_elements_iteration (int number_of_elements, int existing_elements, node *p_act)
{
    while (p_act->ID > existing_elements - number_of_elements + 1)
    {
        node *p_temp;
        p_temp = p_act;
        p_act = p_act->p_next_node;
        p_list = p_act->p_next_node;
        delete p_temp;
    }
}

int main()
{
    add_elements(10, 0);
    add_elements(5, 10);
    display_list();
    cout << endl;

    node *p_act;
    p_act = p_list;

    delete_elements(5, 15, p_act);
    p_act = p_list;
    delete_elements(5, 10, p_act);
    display_list();

    return 0;
}


