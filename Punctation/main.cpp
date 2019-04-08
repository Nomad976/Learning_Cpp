#include <iostream>

#define SCORE_NUMBER 5

using namespace std;

struct players
{
    string name;
    int points[SCORE_NUMBER];
};

void all_scores_display(players player)
{
    cout << player.name << ":" << endl;
    if (player.points[0] == -1)
    {
        cout << "No scores given yet." << endl;
    }
    for (int i = 0; i < SCORE_NUMBER; i++)
    {
        if (player.points[i] == -1)
        {
            break;
        }
        cout << player.points[i] << endl;
    }
}

void greatest_score(players player_1, players player_2, players player_3)
{
    int greatest_score_1 = player_1.points[0];
    int greatest_score_2 = player_2.points[0];
    int greatest_score_3 = player_3.points[0];

    for (int i = 1; i < SCORE_NUMBER; i++)
    {
        if (player_1.points[i - 1] < player_1.points[i])
        {
            greatest_score_1 = player_1.points[i];
        }

        if (player_2.points[i - 1] < player_2.points[i])
        {
            greatest_score_2 = player_2.points[i];
        }

        if (player_1.points[i - 1] < player_1.points[i])
        {
            greatest_score_2 = player_2.points[i];
        }
    }
    if (greatest_score_1 == -1)
    {
        cout << "Player 1 greatest score: no score given yet." << endl;
    }
    else
    {
        cout << "Player 1 greatest score: " << greatest_score_1 << endl;
    }

    if (greatest_score_2 == -1)
    {
        cout << "Player 2 greatest score: no score given yet." << endl;
    }
    else
    {
        cout << "Player 2 greatest score: " << greatest_score_2 << endl;
    }

    if (greatest_score_3 == -1)
    {
        cout << "Player 3 greatest score: no score given yet." << endl;
    }
    else
    {
        cout << "Player 3 greatest score: " << greatest_score_3 << endl;
    }
}

int main()
{
    players player_1;
    players player_2;
    players player_3;
    int wybor;
    player_1.name = "NOT GIVEN";
    player_2.name = "NOT GIVEN";
    player_3.name = "NOT GIVEN";

    for (int i = 0; i < SCORE_NUMBER; i++)
    {
        player_1.points[i] = -1;
        player_2.points[i] = -1;
        player_3.points[i] = -1;
    }

    cout << "Menu:" << endl;
    cout << "1. Show the greatest score of every player." << endl;
    cout << "2. Show all the scores of a given player." << endl;
    cout << "3. Show all the scores of all players." << endl;
    cout << "4. Show the list of players." << endl;
    cout << "5. Input the name of a player." << endl;
    cout << "6. Input scores of a player." << endl;
    cout << "7. Exit." << endl;
    cin >> wybor;

    while (wybor != 7)
    {
        int player_choice;
        int points_iterator_1 = 0;
        int points_iterator_2 = 0;
        int points_iterator_3 = 0;
        switch(wybor)
        {
        case 1:
            greatest_score(player_1, player_2, player_3);
           break;
        case 2:
            cout << "Choose a player: " << endl;
            cin >> player_choice;
            switch(player_choice)
            {
            case 1:
                all_scores_display(player_1);
                break;
            case 2:
                all_scores_display(player_2);
                break;
            case 3:
                all_scores_display(player_3);
                break;
            default:
                cout << "Invalid player choice" << endl;
                break;
            }
            break;
        case 3:
            all_scores_display(player_1);
            cout << endl << "---" << endl;
            all_scores_display(player_2);
            cout << endl << "---" << endl;
            all_scores_display(player_3);
            break;
        case 4:
            cout << "Player 1: " << player_1.name << endl;
            cout << "Player 2: " << player_2.name << endl;
            cout << "Player 3: " << player_3.name << endl;
            break;
        case 5:
            cout << "Choose a player: " << endl;
            cin >> player_choice;
            switch (player_choice)
            {
            case 1:
                cin >> player_1.name;
                break;
            case 2:
                cin >> player_2.name;
                break;
            case 3:
                cin >> player_3.name;
                break;
            default:
                cout << "Invalid player selection." << endl;
                break;
            }
            break;
            case 6:
                cout << "Choose a player: " << endl;
                cin >> player_choice;
                switch(player_choice)
                {
                case 1:
                    cin >> player_1.points[points_iterator_1];
                    points_iterator_1++;
                    if (points_iterator_1 == 6)
                    {
                        points_iterator_1 = 0;
                    }
                    break;
                case 2:
                    cin >> player_2.points[points_iterator_2];
                    points_iterator_2++;
                    if (points_iterator_2 == 6)
                    {
                        points_iterator_2 = 0;
                    }
                    break;
                case 3:
                    cin >> player_3.points[points_iterator_3];
                    points_iterator_3++;
                    if (points_iterator_3 == 6)
                    {
                        points_iterator_3 = 0;
                    }
                    break;
                }
                break;
            case 7:
                break;
            default:
            cout << "Invalid selection" << endl;
        }
        if (wybor == 7)
        {
            break;
        }
        cin >> wybor;
    }



    return 0;
}
