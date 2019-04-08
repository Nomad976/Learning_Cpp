#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    interface inter;
    int counter = 0;    // when the counter reaches 9 (number of squares on the board), the game ends with a draw

    inter.initialise_board();
    inter.display_board();

    while (counter < BOARD_SIZE * BOARD_SIZE)
    {
        cout << "Player 1 move: " << endl;
        inter.mov('o');
        counter++;
        inter.display_board();
        if (inter.check_board('o') == true)
        {
            cout << "Player 1 won" << endl;
            return 0;
        }

        if (counter == BOARD_SIZE * BOARD_SIZE)
        {
            break;
        }

        cout << "Player 2 move: " << endl;
        inter.mov('x');
        counter++;
        inter.display_board();
        if (inter.check_board('x') == true)
        {
            cout << "Player 2 won" << endl;
            return 0;
        }
    }

    if (counter == BOARD_SIZE * BOARD_SIZE)
    {
        cout << "No more possible moves - draw" << endl;
    }
    return 0;
}
