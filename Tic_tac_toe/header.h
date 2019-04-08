#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define BOARD_SIZE 3

class interface
{
public:

    void initialise_board();
    void display_board();
    void mov(char player_sign);
    bool check_board(char player_sign);

private:

    char board[BOARD_SIZE][BOARD_SIZE];
};


#endif // HEADER_H_INCLUDED
