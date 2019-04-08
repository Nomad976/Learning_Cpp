#include <iostream>
#include "header.h"
#include "header_node.h"

using namespace std;

int main()
{
    int choice;
    node *p_tree = nullptr;

    menu_display();
    cin >> choice;

    while (choice != 10)
    {
        switch (choice)
        {
            int counter;    // variable needed in case 5

        case 1:     // adding a new node
            int key;
            cout << "Key to add: ";
            cin >> key;
            p_tree = add_node(p_tree, key);
            break;
        case 2:     // displaying the tree in the default way
            display_tree_basic(p_tree);
            break;
        case 3:     // displaying the tree in an increasing manner
            display_tree_incr(p_tree);
            break;
        case 4:     // displaying tree in a decreasing manner
            display_tree_decr(p_tree);
            break;
        case 5:     // counting and displaying the number of nodes in the tree
            counter = 0;
            count_nodes(p_tree, counter);
            cout << "Number of nodes: " << counter << endl;
            break;
        case 6:     // finding and displaying the height of the tree
            cout << "Height: " << find_height(p_tree) << endl;
            break;
        case 7:     // checking if the tree is properly balanced
            if (balanced(p_tree) )
            {
                cout << "The tree is properly balanced." << endl;
            }
            else
            {
                cout << "The tree is not properly balanced." << endl;
            }
            break;
        case 8:     // checking if the tree is properly sorted
            if (sorted(p_tree) )
            {
                cout << "The tree is properly sorted." << endl;
            }
            else
            {
                cout << "The tree is not properly sorted." << endl;
            }
            break;
        case 9:     // deleting the whole tree
            p_tree = delete_tree(p_tree);
            cout << "The tree has been deleted." << endl;
            break;
        default:
            cout << "Invalid choice - choose again: ";
            break;
        }

        cin >> choice;
    }

    return 0;
}
