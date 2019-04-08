#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int losowa;
    int wprowadzona;
    srand (time (NULL) );
    losowa = rand() % 101;

    cout << "Liczba zostala wylosowana, sproboj zgadnac:" << endl;

    do
    {
        cin >> wprowadzona;
        if (wprowadzona == losowa)
            {
                cout << "Zgadles";
            }
        else if (wprowadzona > losowa)
            {
                cout << "Wprowadziles wieksza liczbe" << endl;
            }
        else if (wprowadzona < losowa)
            {
                cout << "Wprowadziles mniejsza liczbe" << endl;
            }

    } while (wprowadzona != losowa);



    return 0;
}
