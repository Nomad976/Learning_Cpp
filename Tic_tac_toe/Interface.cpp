#include <iostream>
#include "header.h"

using namespace std;

void interface::initialise_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '_';
        }
    }
}

void interface::display_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void interface::mov(char player_sign)
{
    int vertical_coordinate;
    int horizontal_coordinate;

    do
    {
        cin >> vertical_coordinate;
        cin >> horizontal_coordinate;
        vertical_coordinate -= 1;       // altering coordinates in order to access the adequate squares
        horizontal_coordinate -= 1;
        if (vertical_coordinate >= BOARD_SIZE || horizontal_coordinate >= BOARD_SIZE || vertical_coordinate < 0 || horizontal_coordinate < 0 ||
            board[vertical_coordinate][horizontal_coordinate] != '_')
        {
            cout << "Invalid coordinates, try again." << endl;
        }
    } while (vertical_coordinate >= BOARD_SIZE || horizontal_coordinate >= BOARD_SIZE || vertical_coordinate < 0 || horizontal_coordinate < 0 ||
            board[vertical_coordinate][horizontal_coordinate] != '_');

    board[vertical_coordinate][horizontal_coordinate] = player_sign;
}

bool interface::check_board(char player_sign)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        bool row = true;
        bool column = true;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            row &= board[i][j] == player_sign;      // checking verticals
            column &= board[j][i] == player_sign;   // checking horizontals
        }
        if (row || column)
        {
            return true;
        }
    }
    if (board[2][0] == player_sign && board[1][1] == player_sign && board[0][2] == player_sign)  // check diagonals
    {
        return true;
    }
    else
    {
        return false;
    }
}
