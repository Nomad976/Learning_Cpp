#include <iostream>
#include "header.h"
#include "header_node.h"

using namespace std;

struct node
{
    int key;
    int height;
    node *p_left_child;
    node *p_right_child;
    node *p_father;
};

node *add_node (node *p_tree, int given_key)
{
    if (p_tree == nullptr)
    {
        node *p_new_node = new node;
        p_new_node->p_left_child = nullptr;
        p_new_node->p_right_child = nullptr;
        p_new_node->p_father = nullptr;
        p_new_node->key = given_key;
        return p_new_node;
    }

    if (given_key < p_tree->key)
    {
        p_tree->p_left_child = add_node(p_tree->p_left_child, given_key);
        p_tree->p_left_child->p_father = p_tree;
    }
    else if (given_key > p_tree->key)
    {
        p_tree->p_right_child = add_node(p_tree->p_right_child, given_key);
        p_tree->p_right_child->p_father = p_tree;
    }
    return p_tree;
}

void display_tree_basic (node *p_tree)
{
    if (p_tree == nullptr)
    {
        cout << "The tree is empty." << endl;
        return;
    }

    cout << p_tree->key << endl;
    if (p_tree->p_left_child != nullptr)
    {
        display_tree_basic(p_tree->p_left_child);
    }
    if (p_tree->p_right_child != nullptr)
    {
        display_tree_basic(p_tree->p_right_child);
    }
}

void display_tree_incr (node *p_tree)
{
    if (p_tree == nullptr)
    {
        cout << "The tree is empty." << endl;
    }

    if (p_tree->p_left_child != nullptr)
    {
        display_tree_incr(p_tree->p_left_child);
    }

    cout << p_tree->key << " Father: ";
    if (p_tree->p_father == nullptr)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << p_tree->p_father->key << endl;
    }

    if (p_tree->p_right_child != nullptr)
    {
        display_tree_incr(p_tree->p_right_child);
    }

}

void display_tree_decr(node *p_tree)
{
    if (p_tree == nullptr)
    {
        cout << "The tree is empty." << endl;
    }

    if (p_tree->p_right_child != nullptr)
    {
        display_tree_decr(p_tree->p_right_child);
    }

    cout << p_tree->key << endl;

    if (p_tree->p_left_child != nullptr)
    {
        display_tree_decr(p_tree->p_left_child);
    }

}

void count_nodes (node *p_tree, int &counter)
{
    if (p_tree == nullptr)
    {
        cout << "The tree is empty." << endl;
    }

    if (p_tree->p_right_child != nullptr)
    {
        count_nodes(p_tree->p_right_child, counter);
    }

    if (p_tree->p_left_child != nullptr)
    {
        count_nodes(p_tree->p_left_child, counter);
    }

    counter++;
}

int find_height(node *p_tree)
{
    int left_height = 0;
    int right_height = 0;

    if (p_tree->p_left_child != nullptr)
    {
       left_height = find_height(p_tree->p_left_child);
    }
    if (p_tree->p_right_child != nullptr)
    {
        right_height = find_height(p_tree->p_right_child);
    }

    if (p_tree->p_left_child == nullptr && p_tree->p_right_child == nullptr)
    {
        return 0;
    }
    else if (left_height > right_height)
    {
        return left_height + 1;
    }
    else if (right_height > left_height)
    {
        return right_height + 1;
    }
    else
    {
        return right_height + 1;
    }
}

bool balanced (node *p_tree)
{
    int left_height;
    int right_height;
    bool left_sorted;
    bool right_sorted;

    if (p_tree->p_left_child == nullptr)
    {
        left_sorted = true;
        left_height = 0;
    }
    else
    {
        left_sorted = balanced(p_tree->p_left_child);
        left_height = find_height(p_tree->p_left_child) + 1;
    }
    if (p_tree->p_right_child == nullptr)
    {
        right_sorted = true;
        right_height = 0;
    }
    else
    {
        right_sorted = balanced(p_tree->p_right_child);
        right_height = find_height(p_tree->p_right_child) + 1;
    }

    if ( (left_height == right_height || left_height == right_height + 1 || left_height == right_height - 1) && left_sorted && right_sorted )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool sorted (node *p_tree)
{
    bool left_sorted;
    bool right_sorted;

    if (p_tree->p_left_child != nullptr)
    {
        if (p_tree->p_left_child->p_left_child != nullptr || p_tree->p_left_child->p_right_child != nullptr)
        {
            left_sorted = sorted(p_tree->p_left_child);
        }
        else if (p_tree->p_left_child->key < p_tree->key)
        {
            left_sorted = true;
        }
    }
    else
    {
        left_sorted = true;
    }
    if (p_tree->p_right_child != nullptr)
    {
        if (p_tree->p_right_child->p_left_child != nullptr || p_tree->p_right_child->p_right_child != nullptr)
        {
            right_sorted = sorted(p_tree->p_right_child);
        }
        else if (p_tree->p_right_child->key > p_tree->key)
        {
            right_sorted = true;
        }
    }
    else
    {
        right_sorted = true;
    }

    if (p_tree->p_left_child == nullptr)
    {
        if (p_tree->p_right_child->key > p_tree->key && left_sorted && right_sorted)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (p_tree->p_right_child == nullptr)
    {
        if (p_tree->p_left_child->key < p_tree->key && left_sorted && right_sorted)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (p_tree->p_right_child->key > p_tree->key && p_tree->p_left_child->key < p_tree->key && left_sorted && right_sorted)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

node *delete_tree (node *p_tree)
{
    while (p_tree != nullptr)
    {
        if (p_tree->p_left_child != nullptr)
        {
            node *p_temp;
            p_temp = p_tree->p_left_child;
            p_tree->p_left_child = p_tree->p_left_child->p_right_child;
            p_temp->p_right_child = p_tree;
            p_tree = p_temp;
        }
        else
        {
            node *p_temp;
            p_temp = p_tree;
            p_tree = p_tree->p_right_child;
            delete p_temp;
        }
    }
    return p_tree;

}

void menu_display()
{
    cout << "Menu:" << endl;
    cout << "1. Add node to the tree" << endl;
    cout << "2. Display the tree" << endl;
    cout << "3. Display the values from the tree in an increasing manner" << endl;
    cout << "4. Display the values from the tree in a decreasing manner" << endl;
    cout << "5. Count nodes in the tree" << endl;
    cout << "6. Find the height of the tree" << endl;
    cout << "7. Check if the tree is properly balanced" << endl;
    cout << "8. Check if the tree is properly sorted" << endl;
    cout << "9. Delete the tree" << endl;
    cout << "10. Exit" << endl;
}
