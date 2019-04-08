#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool vec_search (vector<T> passed_vector, T value)
{
    typename vector<T>::iterator itr;
    for (itr = passed_vector.begin(); itr != passed_vector.end(); itr++)
    {
        if (value == *itr)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<char> integers;
    integers.push_back('a');
    integers.push_back('b');
    integers.push_back('d');
    if (vec_search(integers, 1) )
    {
        cout << "Found";
    }
    return 0;
}
