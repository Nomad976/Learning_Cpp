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
    wprowadzona = rand () % 101;

    do
    {
        if (wprowadzona == losowa)
            {
                cout << "Zgadles";
            }
        else if (wprowadzona > losowa)
            {
                cout << "Wprowadziles wieksza liczbe" << endl;
                wprowadzona = rand () % wprowadzona;
            }
        else if (wprowadzona < losowa)
            {
                cout << "Wprowadziles mniejsza liczbe" << endl;
                wprowadzona = rand () % (100 - wprowadzona) + wprowadzona + 1;
            }

    } while (wprowadzona != losowa);


    return 0;
}
