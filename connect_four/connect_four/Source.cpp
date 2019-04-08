#include <iostream>

using namespace std;

void free_memory(char **p_p_board, int vertical_size)
{
	for (int i = 0; i < vertical_size; i++)
	{
		delete[] p_p_board[i];
	}
	delete[] p_p_board;
}

void display_board(int vertical_size, int horizontal_size, char **p_p_board)
{
	// the board is surrounded by '+' signs from the left,
	// 'x' signs from the right and column indexes from the top

	cout << " ";

	for (int i = 0; i < horizontal_size; i++)
	{
		cout << " " << i + 1 << " ";
	}

	cout << endl;

	for (int i = 0; i < vertical_size; i++)
	{
		cout << '+';
		for (int j = 0; j < horizontal_size; j++)
		{
			cout << " " << p_p_board[i][j] << " ";
		}
		cout << 'x' << endl;
	}
}

void player_move(int vertical_size, int horizontal_size, char **p_p_board, int player_number)
{
	cout << "Player " << player_number << "'s move: " << endl;

	int column = -1;
	while ((column < 0) || (column >= horizontal_size))
	{
		cin >> column;
		column -= 1;	// shift the column to avoid off-by-one errors

		if ((column < 0) || (column >= horizontal_size))
		{
			cout << "Invalid column choice - choose again:" << endl;
			continue;
		}
		else
		{
			for (int i = vertical_size - 1; i >= 0; i--)
			{
				// iterate through the column to find an empty spot

				if (p_p_board[i][column] == '_' && player_number == 1)
				{
					p_p_board[i][column] = 'o';
					break;
				}
				else if (p_p_board[i][column] == '_' && player_number == 2)
				{
					p_p_board[i][column] = '*';
					break;
				}
				else if (i == 0 && p_p_board[i][column] != '_')
				{
					cout << "This column is already fully filled - choose again: " << endl;
					column = -1;
				}
			}
		}
	}
}

bool game_over(int vertical_size, int horizontal_size, char **p_p_board, int player_number)
{
	char sign;
	switch (player_number)
	{
	case 1:
		sign = 'o';
		break;
	case 2:
		sign = '*';
		break;
	}

	for (int i = 0; i < horizontal_size; i++)		// vertical check
	{
		for (int j = vertical_size - 1; j >= 3; j--)
		{
			if (p_p_board[j][i] == sign && p_p_board[j - 1][i] == sign &&
				p_p_board[j - 2][i] == sign && p_p_board[j - 3][i] == sign)
			{
				cout << "Player " << player_number << " won." << endl;
				return true;
			}
		}
	}

	for (int i = 0; i < vertical_size; i++)			// horizontal check
	{
		for (int j = 0; j <= horizontal_size - 4; j++)
		{
			if (p_p_board[i][j] == sign && p_p_board[i][j + 1] == sign &&
				p_p_board[i][j + 2] == sign && p_p_board[i][j + 3] == sign)
			{
				cout << "Player " << player_number << " won." << endl;
				return true;
			}
		}
	}

	for (int i = 0; i <= vertical_size - 4; i++)			
	{
		for (int j = 0; j <= horizontal_size - 4; j++)		// diagonal to the right check
		{
			if (p_p_board[i][j] == sign && p_p_board[i + 1][j + 1] == sign &&
				p_p_board[i + 2][j + 2] == sign && p_p_board[i + 3][j + 3] == sign)
			{
				cout << "Player " << player_number << " won." << endl;
				return true;
			}
		}

		for (int j = horizontal_size - 1; j >= 3; j--)		// diagonal to the left check
		{
			if (p_p_board[i][j] == sign && p_p_board[i + 1][j - 1] == sign &&
				p_p_board[i + 2][j - 2] == sign && p_p_board[i + 3][j - 3] == sign)
			{
				cout << "Player " << player_number << " won." << endl;
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int vertical_size;
	int horizontal_size;

	cout << "Type in the vertical size of your board: ";
	cin >> vertical_size;
	while (vertical_size < 4)
	{
		cout << "This size is too small, try a bigger number: ";
		cin >> vertical_size;
	}

	cout << "Type in the horizontal size of your board: ";
	cin >> horizontal_size;
	while (horizontal_size < 4)
	{
		cout << "This size is too small, try a bigger number: ";
		cin >> horizontal_size;
	}

	cout << "Player 1's coins will be displayed as \"o\" and player 2's - as \"*\"." << endl;

	char **p_p_board = new char*[vertical_size];
	for (int i = 0; i < vertical_size; i++)
	{
		p_p_board[i] = new char[horizontal_size];
	}
	for (int i = 0; i < vertical_size; i++)
	{
		// initialise the board with signs of empty fields

		for (int j = 0; j < horizontal_size; j++)
		{
			p_p_board[i][j] = '_';
		}
	}

	display_board(vertical_size, horizontal_size, p_p_board);

	int counter = 0;	// variable that counts moves in order to detect a draw

	while (counter < horizontal_size * vertical_size)
	{
		player_move(vertical_size, horizontal_size, p_p_board, 1);
		display_board(vertical_size, horizontal_size, p_p_board);
		counter++;
		if (game_over(vertical_size, horizontal_size, p_p_board, 1))
		{
			free_memory(p_p_board, vertical_size);
			system("pause");
			return 0;
		}

		if (counter == horizontal_size * vertical_size)
		{
			break;
		}

		player_move(vertical_size, horizontal_size, p_p_board, 2);
		display_board(vertical_size, horizontal_size, p_p_board);
		counter++;
		if (game_over(vertical_size, horizontal_size, p_p_board, 2))
		{
			free_memory(p_p_board, vertical_size);
			system("pause");
			return 0;
		}
	}

	cout << "All fields have been filled - draw." << endl;

	free_memory(p_p_board, vertical_size);
	system("pause");
	return 0;
}
