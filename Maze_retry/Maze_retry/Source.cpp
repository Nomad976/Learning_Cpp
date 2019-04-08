#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void place_vertical_wall(char **p_p_maze, int column, int begin_coord, int end_coord)
{
	for (int i = begin_coord; i <= end_coord; i++)
	{
		if (p_p_maze[i][column] == '-' || p_p_maze[i][column] == '+')
		{
			p_p_maze[i][column] = '+';		// place corners in spots where the wall crosses with another perpendicular wall
		}
		else
		{
			p_p_maze[i][column] = '|';
		}
	}
}

void place_horizontal_wall(char **p_p_maze, int row, int begin_coord, int end_coord)
{
	for (int i = begin_coord; i <= end_coord; i++)
	{
		if (p_p_maze[row][i] == '|' || p_p_maze[row][i] == '+')
		{
			p_p_maze[row][i] = '+';		//place corners in spots where the wall crosses with another perpendicular wall
		}
		else
		{
			p_p_maze[row][i] = '-';
		}
	}
}

void place_vertical_gap(char **p_p_maze, int column, int begin_coord, int end_coord)
{
	int random_spot = (rand() % (end_coord - begin_coord - 1)) + begin_coord + 1;	// the random spot has to be  
																					// between begin and end coords
	p_p_maze[random_spot][column] = ' ';
}

void place_horizontal_gap(char **p_p_maze, int row, int begin_coord, int end_coord)
{
	int random_spot = (rand() % (end_coord - begin_coord - 1)) + begin_coord + 1;

	p_p_maze[row][random_spot] = ' ';
}

void build_outer_walls(char **p_p_maze, int vertical_size, int horizontal_size)
{
	place_horizontal_wall(p_p_maze, 0, 0, horizontal_size - 1);
	place_horizontal_wall(p_p_maze, vertical_size - 1, 0, horizontal_size - 1);
	place_vertical_wall(p_p_maze, 0, 0, vertical_size - 1);
	place_vertical_wall(p_p_maze, horizontal_size - 1, 0, vertical_size - 1);
}

void display_maze(char **p_p_maze, int vertical_size, int horizontal_size)
{
	cout << " \"+\" represents a corner" << endl << endl;
	for (int i = 0; i < vertical_size; i++)
	{
		for (int j = 0; j < horizontal_size; j++)
		{
			cout << p_p_maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int random_number_exclude_val(int begin_value, int end_value, int excluded_value)
{
	int random = (rand() % (end_value - begin_value - 3)) + begin_value + 2;	// random number cannot point to a corner
	while (random == excluded_value)											// or to a spot adjacent to the corner
	{
		random = (rand() % (end_value - begin_value - 3)) + begin_value + 2;
	}
	return random;
}

void build_interior(char **p_p_maze, int begin_column_coord, int end_column_coord, int begin_row_coord, int end_row_coord)
{
	/* using the "Recursive Division" algorithm */

	bool no_horizontal_wall = false;
	bool no_vertical_wall = false;
	bool three_width = false;
	bool three_height = false;
	int random_row;
	int random_column;

	if ((end_column_coord - begin_column_coord) < 4)
	{
		no_vertical_wall = true;	// no more room for a vertical wall
	}
	else
	{
		random_column = (rand() % (end_column_coord - begin_column_coord - 3)) + begin_column_coord + 2;	// random number cannot point to a corner 
	}																										// or to a spot adjacent to the corner
	if ((end_row_coord - begin_row_coord) < 4)
	{
		no_horizontal_wall = true;	// no more room for a horizontal wall
	}
	else
	{
		random_row = (rand() % (end_row_coord - begin_row_coord - 3)) + begin_row_coord + 2;				// random number cannot point to a corner
	}																										// or to a spot adjacent to the corner
	if (no_horizontal_wall && no_vertical_wall)
	{
		return;		// base case - no more room for any walls
	}

	if ((end_column_coord - begin_column_coord) > 5)
	{
		three_width = true;		// if true, the square has three or more coordinates where a vertical wall can be placed
	}
	if ((end_row_coord - begin_row_coord) > 5)
	{
		three_height = true;	// if true, the square has three or more coordinates where a horizontal wall can be placed
	}

	if (no_horizontal_wall == false)
	{
		while (p_p_maze[random_row][begin_column_coord] == ' ' || p_p_maze[random_row][end_column_coord] == ' ')
		{	
			// generate new coordinates until the wall to be placed does not begin or end at a gap

			if (three_height)
			{
				random_row = random_number_exclude_val(begin_row_coord, end_row_coord, random_row);
			}
			else
			{
				no_horizontal_wall = true;
				break;
			}
		}
	}
	if (no_vertical_wall == false)
	{
		while (p_p_maze[begin_row_coord][random_column] == ' ' || p_p_maze[end_row_coord][random_column] == ' ')
		{	// generate new coordinates until the wall to be placed does not begin or end at a gap
			if (three_width)
			{
				random_column = random_number_exclude_val(begin_column_coord, end_column_coord, random_column);
			}
			else
			{
				no_vertical_wall = true;
				break;
			}
		}
	}

	if (no_horizontal_wall == false && no_vertical_wall == false)
	{
		place_horizontal_wall(p_p_maze, random_row, begin_column_coord, end_column_coord);
		place_vertical_wall(p_p_maze, random_column, begin_row_coord, end_row_coord);

		int gap_placement = rand() % 4;
		switch (gap_placement)	// place gaps in three randomly chosen halves of walls
		{
		case 0:
			place_horizontal_gap(p_p_maze, random_row, random_column, end_column_coord);	// horizontal right
			place_vertical_gap(p_p_maze, random_column, random_row, end_row_coord);			// vertical bottom
			place_horizontal_gap(p_p_maze, random_row, begin_column_coord, random_column);	// horizontal left
			break;
		case 1:
			place_vertical_gap(p_p_maze, random_column, begin_row_coord, random_row);		// vertical up
			place_vertical_gap(p_p_maze, random_column, random_row, end_row_coord);			// vertical bottom
			place_horizontal_gap(p_p_maze, random_row, begin_column_coord, random_column);	// horizontal left
			break;
		case 2:
			place_vertical_gap(p_p_maze, random_column, begin_row_coord, random_row);		// vertical up
			place_horizontal_gap(p_p_maze, random_row, random_column, end_column_coord);	// horizontal right
			place_horizontal_gap(p_p_maze, random_row, begin_column_coord, random_column);	// horizontal left
			break;
		case 3:
			place_vertical_gap(p_p_maze, random_column, begin_row_coord, random_row);		// vertical up
			place_horizontal_gap(p_p_maze, random_row, random_column, end_column_coord);	// horizontal right
			place_vertical_gap(p_p_maze, random_column, random_row, end_row_coord);			// vertical bottom
			break;
		}
		if (three_height && three_width)	// keep building only if there is enough room
		{
			build_interior(p_p_maze, begin_column_coord, random_column, begin_row_coord, end_row_coord);	// top-left square
			build_interior(p_p_maze, random_column, end_column_coord, begin_row_coord, random_row);			// top-right square
			build_interior(p_p_maze, begin_column_coord, random_column, random_row, end_row_coord);			// bottom-left square
			build_interior(p_p_maze, random_column, end_column_coord, random_row, end_row_coord);			// bottom-right square
		}
	}
	else if ((no_horizontal_wall == false) && no_vertical_wall)
	{
		place_horizontal_wall(p_p_maze, random_row, begin_column_coord, end_column_coord);
		place_horizontal_gap(p_p_maze, random_row, begin_column_coord, end_column_coord);

		if (three_height && three_width)	// keep building only if there is enough room
		{
			build_interior(p_p_maze, begin_column_coord, end_column_coord, begin_row_coord, random_row);	// top square
			build_interior(p_p_maze, begin_column_coord, end_column_coord, random_row, end_row_coord);		// bottom square
		}
	}
	else if (no_horizontal_wall && (no_vertical_wall == false))
	{
		place_vertical_wall(p_p_maze, random_column, begin_row_coord, end_row_coord);
		place_vertical_gap(p_p_maze, random_column, begin_row_coord, end_row_coord);

		if (three_height && three_width)	// keep building only if there is enough room
		{
			build_interior(p_p_maze, begin_column_coord, random_column, begin_row_coord, end_row_coord);		// left square
			build_interior(p_p_maze, random_column, end_column_coord, begin_row_coord, end_row_coord);			// right square
		}
	}
}

int main()
{
	srand(time(nullptr));

	int vertical_size;
	int horizontal_size;
	cout << "Enter vertical size of the maze: ";
	cin >> vertical_size;
	cout << "Enter horizontal size of the maze: ";
	cin >> horizontal_size;

	char **p_p_maze = new char*[vertical_size];
	for (int i = 0; i < vertical_size; i++)
	{
		p_p_maze[i] = new char[horizontal_size];
	}
	for (int i = 0; i < vertical_size; i++)
	{
		for (int j = 0; j < horizontal_size; j++)
		{
			p_p_maze[i][j] = ' ';
		}
	}

	build_outer_walls(p_p_maze, vertical_size, horizontal_size);
	place_vertical_gap(p_p_maze, 0, 0, vertical_size - 1);						// place initial gaps
	place_vertical_gap(p_p_maze, horizontal_size - 1, 0, vertical_size - 1);
	build_interior(p_p_maze, 0, horizontal_size - 1, 0, vertical_size - 1);
	display_maze(p_p_maze, vertical_size, horizontal_size);

	for (int i = 0; i < vertical_size; i++)
	{
		delete[] p_p_maze[i];
	}
	delete[] p_p_maze;

	system("pause");
	return 0;
}