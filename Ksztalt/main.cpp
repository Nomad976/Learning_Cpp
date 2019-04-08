#include <iostream>

using namespace std;

int main()
{

    {
	int rozmiar;
	cout << "Podaj ilosc linii na ktorych mam wyswietlic ksztalt" << endl;
	cin >> rozmiar;

	for (int i = 0; i < rozmiar; i++)
	{
		if (i % 4 == 1)
		{
			cout << "./\." << endl;
        }
		else if (i % 4 == 2)
		{
			cout << "/..\ " << endl;
		}
		else if (i % 4 == 3)
		{
			cout << "\../" << endl;
		}
		else if (i % 4 == 0)
		{
			cout << ".\/." << endl;
		}
	}
}
}
