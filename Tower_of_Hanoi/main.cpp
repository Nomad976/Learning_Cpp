#include <iostream>

#define EMPTY 6

using namespace std;

void display_towers(const int left_tower[], const int middle_tower[], const int right_tower[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << left_tower[i] << "  " << middle_tower[i] << "  " << right_tower[i] << endl;
    }
}

void mov(int first_tower[], int second_tower[])     // a function that moves a number between towers
{
    int number_to_move;

    for (int i = 0; i < 5; i++)     // find the highest element of the first tower
    {
        if (first_tower[i] != 0)
        {
            number_to_move = first_tower[i];
            first_tower[i] = 0;     //  free the spot where the element is taken from
            break;
        }
    }

    for (int i = 4; i >= 0; i--)    // put the found element on top of the second tower
    {
        if (second_tower[i] == 0)
        {
            second_tower[i] = number_to_move;
            break;
        }
    }
}

int highest_element(const int tower[])
{
    for (int i = 0; i < 5; i++)     // find the highest element of the given tower
    {
        if (tower[i] != 0)
        {
            return tower[i];
        }
    }
    return EMPTY;   // executes if the loop did not find any element
}

void solve(int left_tower[], int middle_tower[], int right_tower[], int* recently_moved /*pointer to the tower on top of which an element was put in the previous call function*/)
{
    int left_highest = highest_element(left_tower);
    int middle_highest = highest_element(middle_tower);
    int right_highest = highest_element(right_tower);

    if (right_tower[0] != 1)    // when 1 is the top element of the right tower, the puzzle is solved
    {
        /* an element is moved between towers only if it is smaller than the element on top
           of the second tower, has different parity from that element (when the tower is not empty),
           and if it was not moved in the previous call to function  */

        if (left_highest < right_highest && ( ( (right_highest + left_highest) % 2) != 0 || right_highest == EMPTY ) && recently_moved != left_tower)
        {                                                   // moving from left tower
            mov(left_tower, right_tower);                   // to right tower
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, right_tower);
        }
        else if (left_highest < middle_highest && ( ( (middle_highest + left_highest) % 2) != 0 || middle_highest == EMPTY ) && recently_moved != left_tower)
        {
            mov(left_tower, middle_tower);                  // left->middle
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, middle_tower);
        }
        else if (right_highest < middle_highest && ( ( (middle_highest + right_highest) % 2) != 0 || middle_highest == EMPTY ) && recently_moved != right_tower)
        {
            mov(right_tower, middle_tower);                 // right->middle
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, middle_tower);
        }
        else if (middle_highest < left_highest && ( ( (left_highest + middle_highest) % 2) != 0 || left_highest == EMPTY ) && recently_moved != middle_tower)
        {
            mov(middle_tower, left_tower);                  // middle->left
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, left_tower);
        }
        else if (middle_highest < right_highest && ( ( (right_highest + middle_highest) % 2) != 0 || right_highest == EMPTY ) && recently_moved != middle_tower)
        {
            mov(middle_tower, right_tower);                 // middle->right
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, right_tower);
        }
        else if (right_highest < left_highest && ( ( (left_highest + right_highest) % 2) != 0 || left_highest == EMPTY ) && recently_moved != right_tower)
        {
            mov(right_tower, left_tower);                   // right->left
            display_towers(left_tower, middle_tower, right_tower);
            cout << endl;
            solve(left_tower, middle_tower, right_tower, left_tower);
        }
    }
    else
    {
        cout << "Solved: " << endl;
        display_towers(left_tower, middle_tower, right_tower);
    }
}

int main()
{
    int left_tower[5];
    int middle_tower[5];
    int right_tower[5];

    for (int i = 0; i < 5; i++)
    {
        left_tower[i] = i + 1;
        middle_tower[i] = 0;
        right_tower[i] = 0;
    }

    display_towers(left_tower, middle_tower, right_tower);
    cout << endl;
    solve(left_tower, middle_tower, right_tower, nullptr);
    cout << endl;
    return 0;
}
