#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ship
{
    int x_dimension;
    int y_dimension;
    bool on_screen;
};


int main()
{
    srand(time(NULL));
    ship fleet[50];
    bool fleet_on_screen = true;
    for (int i = 0; i < 50; i++)
    {
        fleet[i].x_dimension = (rand() % 1024) + 1;
        fleet[i].y_dimension = (rand() % 768) + 1;
        fleet[i].on_screen = true;
    }

    while (fleet_on_screen)
    {
        cout << 0;
        for (int i = 0; i < 50; i++)
        {
            if (fleet[i].x_dimension > 1024 || fleet[i].y_dimension > 768)
            {
                fleet[i].on_screen = false;
            }
        }
        for (int i = 0; i < 50; i++)
        {
            fleet[i].x_dimension++;
            fleet[i].y_dimension++;
        }

        for (int i = 0; i < 50; i++)
        {
            if (fleet[i].on_screen)
            {
                fleet_on_screen = true;
            }
            else
            {
                fleet_on_screen = false;
            }
        }

    }

    return 0;
}
