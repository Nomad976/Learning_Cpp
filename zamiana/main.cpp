#include <iostream>

using namespace std;

void zamien1 (int lewy, int prawy)
{
    int tymczas = lewy;
    lewy = prawy;
    prawy = tymczas;
}

void zamien2 (int *w_lewy, int *w_prawy)
{
    int tymczas = *w_lewy;
    *w_lewy = *w_prawy;
    *w_prawy = tymczas;
}

int main()
{
    /*int x = 1;
    int y = 2;
    zamien1 ( x, y );
    cout << x << " " << y << endl;
    zamien2 (& x, & y);
    cout << x << " " << y << endl;*/

    int *p_var;
    int var = 5;
    p_var = &var;

    cout << "*p_var: " << *p_var << endl;
    cout << "p_var: " << p_var << endl;
    cout << "&var: " << &var << endl;
    cout << "&p_var:" << &p_var << endl;
    return 0;
}
