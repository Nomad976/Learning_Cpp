#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct card_set
{
    string name;
    string colour;
    int ID;
    bool on_table;
};

void card_names (card_set card[])
{
    for(int i = 0; i < 52; i++)
    {
        card[i].on_table = false;
        int j = i % 13;
        switch (j)
        {
        case 0:
            card[i].name = "Two";
            card[i].ID = 0;
            break;
        case 1:
            card[i].name = "Three";
            card[i].ID = 1;
            break;
        case 2:
            card[i].name = "Four";
            card[i].ID = 2;
            break;
        case 3:
            card[i].name = "Five";
            card[i].ID = 3;
            break;
        case 4:
            card[i].name = "Six";
            card[i].ID = 4;
            break;
        case 5:
            card[i].name = "Seven";
            card[i].ID = 5;
            break;
        case 6:
            card[i].name = "Eight";
            card[i].ID = 6;
            break;
        case 7:
            card[i].name = "Nine";
            card[i].ID = 7;
            break;
        case 8:
            card[i].name = "Ten";
            card[i].ID = 8;
            break;
        case 9:
            card[i].name = "Knave";
            card[i].ID = 9;
            break;
        case 10:
            card[i].name = "Queen";
            card[i].ID = 10;
            break;
        case 11:
            card[i].name = "King";
            card[i].ID = 11;
            break;
        case 12:
            card[i].name = "Ace";
            card[i].ID = 12;
            break;
        }
    }
}

void card_colours (card_set card[])
{
    for (int i = 0; i < 52; i++)
    {
        if (i < 13)
        {
            card[i].colour = "spades";
        }
        else if (i < 26)
        {
            card[i].colour = "hearts";
        }
        else if (i < 39)
        {
            card[i].colour = "diamonds";
        }
        else if (i < 52)
        {
            card[i].colour = "clubs";
        }

    }
}

void randomise (card_set card[])
{
    int random_number_1;
    int random_number_2;
    card_set temp;
    for (int i = 0; i < 1024; i++)
    {
        random_number_1 = rand() % 52;
        random_number_2 = rand() % 52;
        temp = card[random_number_1];
        card[random_number_1] = card[random_number_2];
        card[random_number_2] = temp;

    }
}

void card_exchange (card_set card[], int card_number)
{
    card_set temp;
    int random_number = (rand() % 47) + 5;
    temp = card[card_number];
    card[card_number] = card[random_number];
    card[random_number] = temp;
}

void card_display (card_set card[])
{
    cout << "Hand: " << endl;
    cout << card[0].name << " of " << card[0].colour << endl;
    cout << card[1].name << " of " << card[1].colour << endl;
    cout << card[2].name << " of " << card[2].colour << endl;
    cout << card[3].name << " of " << card[3].colour << endl;
    cout << card[4].name << " of " << card[4].colour << endl;
}

int combination (card_set card[])
{
    bool straight = false;
    bool flush = false;
    bool royal = false;

    for (int i = 0; i < 8; i++)
    {
        if ( (card[4].ID == 0 + i) && (card[3].ID == 1 + i) && (card[2].ID == 2 + i) && (card[1].ID == 3 + i) && (card[0].ID == 4 + i) )
        {
            straight = true;
        }
        else if ( (card[0].ID == 12) && (card[1].ID == 4) && (card[2].ID == 3) && (card[3].ID == 2) && (card[4].ID == 1) )
        {
            straight = true;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if ( (card[0].colour == card[1].colour) && (card[0].colour == card[2].colour) && (card[0].colour == card[3].colour) &&
             (card[0].colour == card[4].colour) )
        {
            flush = true;
        }
    }

    if ( (card[4].ID == 8) && (card[3].ID == 9) && (card[2].ID == 10) && (card[1].ID == 11) && (card[0].ID == 12) )
    {
        royal = true;
    }

    if (royal && flush)
    {
        return 9;
    }
    else if (straight && flush)
    {
        return 8;
    }
    else if ( ( (card[0].ID == card[1].ID) && (card[0].ID == card[2].ID) && (card[0].ID == card[3].ID) ) ||
              ( (card[1].ID == card[2].ID) && (card[1].ID == card[3].ID) && (card[1].ID == card[4].ID) ) )
    {
        return 7;
    }
    else if ( ( (card[0].ID == card[1].ID) && (card[2].ID == card[3].ID) && (card[2].ID == card[4].ID) ) ||
              ( (card[0].ID == card[1].ID) && (card[0].ID == card[2].ID) && (card[3].ID == card[4].ID) ) )
    {
        return 6;
    }
    else if (flush)
    {
        return 5;
    }
    else if (straight)
    {
        return 4;
    }
    else if ( ( (card[0].ID == card[1].ID) && (card[0].ID == card[2].ID) ) ||
              ( (card[1].ID == card[2].ID) && (card[1].ID == card[3].ID) ) ||
              ( (card[2].ID == card[3].ID) && (card[2].ID == card[4].ID) ) )
    {
        return 3;
    }
    else if ( ( (card[0].ID == card[1].ID) && (card[2].ID == card[3].ID) ) ||
              ( (card[4].ID == card[3].ID) && (card[2].ID == card[1].ID) ) ||
              ( (card[0].ID == card[1].ID) && (card[3].ID == card[4].ID) ) )
    {
        return 2;
    }
    else if ( (card[0].ID == card[1].ID) || (card[1].ID == card[2].ID) || (card[2].ID == card[3].ID) || card[3].ID == card[4].ID )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sort_hand (card_set card[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (card[i].ID < card[j].ID)
            {
                card_set temp;
                temp = card[i];
                card[i] = card[j];
                card[j] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    card_set card[52];
    card_names(card);
    card_colours(card);
    randomise(card);
    card_display(card);
    int choice;
    int counter = 0;

    cout << "Select the cards to exchange or type in \"0\" to finish the selection: " << endl;
    cin >> choice;

    while ( (choice != 0) && (counter < 4) )
    {
        switch (choice)
        {
        case 1:
            card_exchange(card, 0);
            card_display(card);
            counter++;
            break;
        case 2:
            card_exchange(card, 1);
            card_display(card);
            counter++;
            break;
        case 3:
            card_exchange(card, 2);
            card_display(card);
            counter++;
            break;
        case 4:
            card_exchange(card, 3);
            card_display(card);
            counter++;
            break;
        case 5:
            card_exchange(card, 4);
            card_display(card);
            counter++;
            break;
        default:
            cout << "Invalid card choice." << endl;
            break;
        }
        if (counter == 4)
        {
            cout << "You have already chosen 4 cards." << endl;
            break;
        }
        cin >> choice;
    }

    cout << endl;
    sort_hand(card);
    card_display(card);
    cout << endl;

    switch (combination(card))
    {
    case 0:
        cout << "High card" << endl;
        break;
    case 1:
        cout << "One pair" << endl;
        break;
    case 2:
        cout << "Two pair" << endl;
        break;
    case 3:
        cout << "Three of a kind" << endl;
        break;
    case 4:
        cout << "Straight" << endl;
        break;
    case 5:
        cout << "Flush" << endl;
        break;
    case 6:
        cout << "Full house" << endl;
        break;
    case 7:
        cout << "Four of a kind" << endl;
        break;
    case 8:
        cout << "Straight flush" << endl;
        break;
    case 9:
        cout << "Royal flush" << endl;
        break;
    default:
        cout << "Some kind of error has occurred" << endl;
    }

    return 0;
}




