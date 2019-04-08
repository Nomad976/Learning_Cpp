#include <iostream>

using namespace std;

struct my_friend
{
    string name;
    int days_since_conv;
};

my_friend *more_friends (my_friend *p_friends, int *m_size)
{
    *m_size *= 2;
    my_friend *p_new_friends = new my_friend[*m_size];
    for (int i = 0; i < *m_size; i++)
    {
        p_new_friends[i] = p_friends[i];
    }
    delete [] p_friends;
    return p_new_friends;
}

void menu_display ()
{
    cout << "Menu: " << endl;
    cout << "1. Add a friend" << endl;
    cout << "2. Update the date of your last conversation with a friend" << endl;
    cout << "3. Display your friend list" << endl;
    cout << "4. Exit" << endl;
}

void add_friend(int &counter, int &m_size, my_friend *p_friends)
{
    if (counter >= m_size)
    {
        p_friends = more_friends(p_friends, &m_size);
    }
    int input;
    cout << "Type in the name of the friend: " << endl;
    cin >> p_friends[counter].name;
    cout << "Type in the number of days since last conversation: " << endl;
    cin >> input;
    while (input < 0)
    {
        cout << "Invalid number, please try again: " << endl;
        cin >> input;
    }
    p_friends[counter].days_since_conv = input;
    counter++;
}

void update(int counter, my_friend *p_friends)
{
    string search_for_name;
    bool name_found = false;
    cout << "Type in the name of the friend to update the date of conversation with them: " << endl;
    cin >> search_for_name;
    for (int i = 0; i < counter; i++)
    {
        if (search_for_name == p_friends[i].name)
        {
            int input;
            cout << "Days since conversation: " << endl;
            cin >> input;
            while (input < 0)
            {
                cout << "Invalid number, please try again: " << endl;
                cin >> input;
            }
            p_friends[i].days_since_conv = input;
            name_found = true;
            break;
        }
    }
    if (name_found == false)
    {
        cout << "Could not find this name on your friend list." << endl;
    }
}

void friends_display(int choice, int counter, my_friend *p_friends)
{
    if (choice == 1)
    {
        for (int i = 0; i <= counter; i++)
        {
            for (int j = i; j<= counter; j++)
            {
                if(p_friends[i].days_since_conv > p_friends[j].days_since_conv)
                {
                    my_friend temp = p_friends[i];
                    p_friends[i] = p_friends[j];
                    p_friends[j] = temp;
                }
            }
        }
    }
    else if (choice == 2)
    {

    }
}

int main()
{
    int choice;
    int m_size = 1;
    int counter = 0;
    my_friend *p_friends = new my_friend[1];
    menu_display();
    cin >> choice;

    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            add_friend(counter, m_size, p_friends);
            break;
        case 2:
            update(counter, p_friends);
            break;
        case 3:
            cout << "Do you want your list sorted by date of last conversation(1) or by names of your friends(2)?" << endl;
            cin >> choice;

        }
    }

    return 0;
}
