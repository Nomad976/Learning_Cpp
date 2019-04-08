#include <iostream>
#include "header.h"

using namespace std;
using namespace moj_wektor;

int main()
{
    wektorInt<char> my_vector(16);

    my_vector.set_at_end('a');
    my_vector.set_at_beginning('s');
    my_vector.set_at_index(2, 'l');
    cout << my_vector.get_value(0) << endl;
    cout << my_vector.get_value(1) << endl;
    cout << my_vector.get_value(2) << endl;
    return 0;
}
