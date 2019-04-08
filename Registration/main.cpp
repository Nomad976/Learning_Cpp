#include <iostream>
#include <map>

using namespace std;

void menu_display ()
{
    cout << "Menu: " << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit" << endl;
}

void new_user (map<string, string> &name_password)
{
    string username;
    string password;
    cout << "Type in your username: ";
    cin >> username;
    cout << "Type in your password: ";
    cin >> password;
    name_password[username] = password;
}

string log_in (const map<string, string> name_password, bool &logged_in)
{
    string username;
    string password;
    cout << "Username: ";
    cin >> username;
    if (name_password.find(username) != name_password.end() )
    {
        cout << "Password: ";
        cin >> password;
        if (name_password.find(username)->second == password)
        {
            cout << "You are now logged in" << endl;
            logged_in = true;
            return username;
        }
        else
        {
            cout << "Invalid password" << endl;
            logged_in = false;
            return "";
        }
    }
    else
    {
        cout << "Invalid username" << endl;
        logged_in = false;
        return "";
    }
}

void change_password (map<string, string> &name_password, string username)
{
    string password;
    cout << "Your old password: ";
    cin >> password;
    if (name_password[username] == password)
    {
        cout << "Your new password: ";
        cin >> password;
        name_password[username] = password;
    }
    else
    {
        cout << "Wrong password" << endl;
    }
}

int main()
{
    map<string, string> name_password;
    string current_user;
    bool logged_in = false;
    menu_display();
    int choice;
    cin >> choice;

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            new_user(name_password);
            break;
        case 2:
            current_user = log_in(name_password, logged_in);
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice" << endl;
        }

        if (logged_in == true)
        {
            cout << "1. Change password" << endl;
            cout << "2. Log out" << endl;
            int sub_choice;
            cin >> sub_choice;

            while (sub_choice != 2)
            {
                switch (sub_choice)
                {
                case 1:
                    change_password(name_password, current_user);
                    break;
                case 2:
                    break;
                default:
                    cout << "Invalid choice" << endl;
                }
                cin >> sub_choice;
                if (sub_choice == 2)
                {
                    cout << "You are now logged out" << endl;
                    logged_in = false;
                    cout << endl;
                    menu_display();
                }
            }
        }
        cin >> choice;
    }
    return 0;
}
