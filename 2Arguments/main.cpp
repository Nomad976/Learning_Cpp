#include <iostream>

using namespace std;

int calculate(int argument_1, int argument_2, int &second_result)
{
    second_result = argument_1 * argument_2;
    return argument_1 + argument_2;
}

int main()
{
    int argument_1;
    int argument_2;
    int second_result;
    cout << "Type in 2 numbers: " << endl;
    cin >> argument_1;
    cin >> argument_2;
    cout << "Sum: " << calculate(argument_1, argument_2, second_result) << endl;
    cout << "Product: " << second_result;

    return 0;
}
