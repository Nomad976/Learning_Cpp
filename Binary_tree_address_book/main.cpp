#include <iostream>

using namespace std;

struct node
{
    string surname_key;
    string address;
    node *p_left_child;
    node *p_right_child;
    node *p_parent;
};

void menu_display ()
{
    cout << "Menu: " << endl;
    cout << "1. Add a new address" << endl;
    cout << "2. Delete an address" << endl;
    cout << "3. Update an address" << endl;
    cout << "4. Search for an address" << endl;
    cout << "5. Exit" << endl;
}

node *new_address (node *p_tree, string surname, string email)
{
    if (p_tree == nullptr)
    {
        node *p_new_node = new node;
        p_new_node->address = email;
        p_new_node->surname_key = surname;
        p_new_node->p_left_child = nullptr;
        p_new_node->p_right_child = nullptr;
        p_new_node->p_parent = nullptr;
        return p_new_node;
    }

    if (surname < p_tree->surname_key)
    {
        p_tree->p_left_child = new_address(p_tree->p_left_child, surname, email);
        p_tree->p_left_child->p_parent = p_tree;
    }
    else if (surname > p_tree->surname_key)
    {
        p_tree->p_right_child = new_address(p_tree->p_right_child, surname, email);
        p_tree->p_right_child->p_parent = p_tree;
    }

    return p_tree;
}

node *search_for_address (node *p_tree, string surname)
{
    if (p_tree == nullptr)
    {
        return nullptr;
    }

    if (p_tree->surname_key == surname)
    {
        return p_tree;
    }

    if (surname < p_tree->surname_key && p_tree->p_left_child != nullptr)
    {
        p_tree = search_for_address(p_tree->p_left_child, surname);
    }
    else if (surname > p_tree->surname_key && p_tree->p_right_child != nullptr)
    {
        p_tree = search_for_address(p_tree->p_right_child, surname);
    }
    else
    {
        return nullptr;
    }

    return p_tree;
}

void update_address (node *p_tree, string surname)
{
    node *p_address_to_update = search_for_address(p_tree, surname);
    if (p_address_to_update == nullptr)
    {
        cout << "Address not found" << endl;
        return;
    }
    else
    {
        cout << "Surname: " << p_address_to_update->surname_key << " E-mail address: " << p_address_to_update->address << endl;
        cout << "Type in the new address: ";
        cin >> p_address_to_update->address;
    }
}

node *find_min (node *p_tree)
{
    if (p_tree->p_left_child == nullptr)
    {
        return p_tree;
    }
    else
    {
        p_tree = find_min(p_tree->p_left_child);
    }
    return p_tree;
}

node *delete_address (node *p_tree, string surname)
{
    node *p_address_to_delete = search_for_address(p_tree, surname);

    if (p_address_to_delete == nullptr)
    {
        cout << "There is no such address in your book" << endl;
        return p_tree;
    }
    else if (p_address_to_delete->p_left_child == nullptr && p_address_to_delete->p_right_child == nullptr)
    {
        if (p_address_to_delete == p_tree)
        {
            p_tree = nullptr;
            delete p_address_to_delete;
        }
        else if (p_address_to_delete->p_parent->surname_key > p_address_to_delete->surname_key)
        {
            p_address_to_delete->p_parent->p_left_child = nullptr;
            delete p_address_to_delete;
            cout << "Address deleted" << endl;
            return p_tree;
        }
        else
        {
            p_address_to_delete->p_parent->p_right_child = nullptr;
            delete p_address_to_delete;
            cout << "Address deleted" << endl;
            return p_tree;
        }
    }
    else if (p_address_to_delete->p_left_child != nullptr && p_address_to_delete->p_right_child == nullptr)
    {
        p_address_to_delete->p_left_child->p_parent = p_address_to_delete->p_parent;
        if (p_address_to_delete != p_tree)
        {
            if (p_address_to_delete->surname_key > p_address_to_delete->p_parent->surname_key)
            {
                p_address_to_delete->p_parent->p_right_child = p_address_to_delete->p_left_child;
            }
            else if (p_address_to_delete->surname_key < p_address_to_delete->p_parent->surname_key)
            {
                p_address_to_delete->p_parent->p_left_child = p_address_to_delete->p_left_child;
            }
        }
        else
        {
            p_tree = p_address_to_delete->p_left_child;
        }
        delete p_address_to_delete;
        cout << "Address deleted" << endl;
        return p_tree;
    }
    else if (p_address_to_delete->p_right_child != nullptr && p_address_to_delete->p_left_child == nullptr)
    {
        p_address_to_delete->p_right_child->p_parent = p_address_to_delete->p_parent;
        if (p_address_to_delete != p_tree)
        {
            if (p_address_to_delete->surname_key > p_address_to_delete->p_parent->surname_key)
            {
                p_address_to_delete->p_parent->p_right_child = p_address_to_delete->p_right_child;
            }
            else if (p_address_to_delete->surname_key < p_address_to_delete->p_parent->surname_key)
            {
                p_address_to_delete->p_parent->p_left_child = p_address_to_delete->p_right_child;
            }
        }
        else
        {
            p_tree = p_address_to_delete->p_right_child;
        }
        delete p_address_to_delete;
        cout << "Address deleted" << endl;
        return p_tree;
    }
    else
    {
        node *p_switch_address = find_min(p_address_to_delete->p_right_child);
        if (p_switch_address == p_address_to_delete->p_right_child)
        {
            p_switch_address->p_parent->p_right_child = nullptr;
        }
        else
        {
           p_switch_address->p_parent->p_left_child = nullptr;
        }
        p_switch_address->p_left_child = p_address_to_delete->p_left_child;
        if (p_switch_address->p_left_child != nullptr)
        {
             p_switch_address->p_left_child->p_parent = p_switch_address;
        }
        p_switch_address->p_right_child = p_address_to_delete->p_right_child;
        if (p_switch_address->p_right_child != nullptr)
        {
            p_switch_address->p_right_child->p_parent = p_switch_address;
        }
        p_switch_address->p_parent = p_address_to_delete->p_parent;
        if (p_address_to_delete == p_tree)
        {
            p_tree = p_switch_address;
            delete p_address_to_delete;
            cout << "Address deleted" << endl;
            return p_tree;
        }
        else if (p_address_to_delete->surname_key > p_address_to_delete->p_parent->surname_key)
        {
            p_address_to_delete->p_parent->p_right_child = p_switch_address;
            delete p_address_to_delete;
            cout << "Address deleted" << endl;
            return p_tree;
        }
        else
        {
            p_address_to_delete->p_parent->p_left_child = p_switch_address;
            delete p_address_to_delete;
            cout << "Address deleted" << endl;
            return p_tree;
        }
    }
}

int main()
{
    node *p_tree = nullptr;
    int choice;
    string surname;
    string email;

    menu_display();
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:     // create new address
            {
                cout << "Surname: ";
                cin >> surname;
                cout << "E-mail address: ";
                cin >> email;
                p_tree = new_address(p_tree, surname, email);
                break;
            }
        case 2:     // delete an address
            {
                cout << "Surname: ";
                cin >> surname;
                p_tree = delete_address(p_tree, surname);
                break;
            }
        case 3:     // update an address
            {
                cout << "Surname: ";
                cin >> surname;
                update_address(p_tree, surname);
                break;
            }
        case 4:     // search for an address
            {

                cout << "Surname: ";
                cin >> surname;
                node *p_searched_addr = search_for_address(p_tree, surname);
                if (p_searched_addr == nullptr)
                {
                    cout << "Can not find this address" << endl;
                }
                else
                {
                    cout << "Address found: " << endl;
                    cout << "Surname: " << p_searched_addr->surname_key << " E-mail address: " << p_searched_addr->address << endl;
                }
                break;
            }
        default:
            {
                cout << "Invalid choice - choose again" << endl;
                break;
            }

        }
        cin >> choice;
    }

    return 0;
}
