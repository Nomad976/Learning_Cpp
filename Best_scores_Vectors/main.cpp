#include <iostream>
#include <vector>

using namespace std;

void add_score (vector<int> &best_scores)
{
    int score;
    cout << "Score: " << endl;
    cin >> score;
    if (best_scores.empty() )
    {
        best_scores.push_back(score);
    }
    else
    {
        vector<int>::iterator i = best_scores.begin();
        while (*i > score)
        {
            i++;
        }
        if (i == best_scores.end() )
        {
            best_scores.push_back(score);
        }
        else
        best_scores.insert(i, score);
    }
}

void display_scores (vector<int> best_scores)
{
    vector<int>::iterator i = best_scores.begin();
    int place = 1;
    while (i != best_scores.end() )
    {
        cout << place << ". " << *i << endl;
        i++;
        place++;
    }
}

int main()
{
    vector<int> best_scores(0);

    cout << "Menu: " << endl;
    cout << "1. Add a new score" << endl;
    cout << "2. Display scores" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            add_score(best_scores);
            break;
        case 2:
            display_scores(best_scores);
            break;
        case 3:
            break;
        default :
            cout << "Invalid selection, try again: " << endl;
        }
        cin >> choice;
    }

    return 0;
}
