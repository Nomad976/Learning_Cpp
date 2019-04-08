#include <iostream>

using namespace std;

int main()
{
    int pierwszy_argument;
    int drugi_argument;
    cout << "Podaj pierwszy argument: ";
    cin >> pierwszy_argument;
    cout << "Podaj drugi argument: ";
    cin >> drugi_argument;
    cout << pierwszy_argument << " * " << drugi_argument << " = " << pierwszy_argument * drugi_argument << endl;
    cout << pierwszy_argument << " + " << drugi_argument << " = " << pierwszy_argument + drugi_argument << endl;
    cout << pierwszy_argument << " / " << drugi_argument << " = " << pierwszy_argument / drugi_argument << endl;
    cout << pierwszy_argument << " - " << drugi_argument << " = " << pierwszy_argument - drugi_argument << endl;
    return 0;
}
