#include <iostream>

#ifndef NEW_CALC_HEADER_H
#define NEW_CALC_HEADER_H
#include "new_calc_header.h"
#endif // NEW_CALC_HEADER_H


using namespace std;

int main()
{
    char calculation;
    int first_number;
    int second_number;
    cout << "Type in the first number: ";
    cin >> first_number;
    cout << "Type in the second number: ";
    cin >> second_number;
    cout << "What kind of calculation do you want to perform?" << endl;
    cin >> calculation;

    cout << "Result: ";
    switch (calculation)
    {
    case '+':
        cout << add(first_number, second_number);
        break;
    case '-':
        cout << subtract(first_number, second_number);
        break;
    case '*':
        cout << multiplicate(first_number, second_number);
        break;
    case '/':
        cout << divide(first_number, second_number);
        break;
    }

    return 0;
}
