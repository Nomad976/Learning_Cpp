#include <iostream>
#include <vector>

using namespace std;

template <typename num_type>
num_type sum_vector (vector<num_type> passed_vector)
{
    num_type sum = 0;
    typename vector<num_type>::iterator itr;
    for (itr = passed_vector.begin(); itr != passed_vector.end(); itr++)
    {
        sum += *itr;
    }
    return sum;
}

int main()
{
    vector<int> integers;
    integers.push_back(1);
    integers.push_back(3);
    integers.push_back(5);
    vector<double> doubles;
    doubles.push_back(4.2);
    doubles.push_back(3.5);
    doubles.push_back(9.1);
    vector<float> floats;
    floats.push_back(9.9);
    floats.push_back(3.3);
    floats.push_back(2.2);

    cout << sum_vector(integers) << endl;
    cout << sum_vector(doubles) << endl;
    cout << sum_vector(floats) << endl;
    return 0;
}
