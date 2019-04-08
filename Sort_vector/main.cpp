#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void sort_vector (vector<T> & passed_vector)
{
    typename vector<T>::iterator itr;
    typename vector<T>::iterator sub_itr;
    T temp;

    for (itr = passed_vector.begin(); itr != passed_vector.end(); itr++)
    {
        for (sub_itr = itr; sub_itr != passed_vector.end(); sub_itr++)
        {
            if (*itr > *sub_itr)
            {
                temp = *itr;
                *itr = *sub_itr;
                *sub_itr = temp;
            }
        }
    }
}

template <typename T>
void display (const vector<T> passed_vector)
{
    typename vector<T>::const_iterator itr;

    for (itr = passed_vector.begin(); itr != passed_vector.end(); itr++)
    {
        cout << *itr << endl;
    }
}

int main()
{
    vector<char> chars;
    vector<int> integers;
    vector<double> doubles;

    chars.push_back('d');
    chars.push_back('a');
    chars.push_back('f');

    integers.push_back(10);
    integers.push_back(9);
    integers.push_back(11);

    doubles.push_back(10.5);
    doubles.push_back(10.1);
    doubles.push_back(10.9);

    cout << "chars:" << endl;
    display(chars);
    cout << "integers:" << endl;
    display(integers);
    cout << "doubles:" << endl;
    display(doubles);

    cout << "sort" << endl;
    sort_vector(chars);
    sort_vector(integers);
    sort_vector(doubles);

    cout << "chars:" << endl;
    display(chars);
    cout << "integers:" << endl;
    display(integers);
    cout << "doubles:" << endl;
    display(doubles);


    return 0;
}
