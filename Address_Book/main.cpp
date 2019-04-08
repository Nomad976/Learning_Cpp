#include <iostream>

using namespace std;

struct wpis
{
    string imie;
    string nazwisko;
    string numer_telefonu;
    wpis *nastepny_wpis;
};

wpis *lista = NULL;

void nowy_wpis()
{
    string podane_imie;
    string podane_nazwisko;
    string podany_nr_tel;
    cout << "Podaj imie: " << endl;
    cin >> podane_imie;
    cout << "Podaj nazwisko: " << endl;
    cin >> podane_nazwisko;
    cout << "Podaj nr telefonu: " << endl;
    cin >> podany_nr_tel;

    wpis *nowy = new wpis;
    nowy->imie = podane_imie;
    nowy->nazwisko = podane_nazwisko;
    nowy->numer_telefonu = podany_nr_tel;
    nowy->nastepny_wpis = lista;
    lista = nowy;

}

int main()
{
    int wybor = 0;
    cout << "Menu:" << endl;
    cout << "1. Wyswietl ksiazke adresowa" << endl;
    cout << "2. Dodaj wpis" << endl;
    cout << "3. Znajdz numer" << endl;
    cout << "4. Wyjdz" << endl;
    cin >> wybor;

    while (wybor != 4)
    {
        if (wybor == 1)
        {
            wpis *w_aktualny = lista;
            cout << endl;
            while (w_aktualny != NULL)
            {
                cout << w_aktualny->imie << " " << w_aktualny->nazwisko << endl;
                cout << w_aktualny->numer_telefonu << endl << endl;
                w_aktualny = w_aktualny->nastepny_wpis;
            }
        }
        else if (wybor == 2)
        {
            nowy_wpis();
        }
        else if (wybor == 3)
        {
            bool cos_znaleziono = false;
            string szukana_fraza;
            cout << "Podaj imie badz nazwisko szukanej osoby" << endl;
            cin >> szukana_fraza;
            wpis *w_aktualny = lista;
            while (w_aktualny != NULL)
            {
                if (w_aktualny->imie == szukana_fraza || w_aktualny->nazwisko == szukana_fraza)
                {
                    cout << "Znaleziono pasujace dane: " << endl;
                    cout << w_aktualny->imie << " " << w_aktualny->nazwisko << endl;
                    cout << w_aktualny->numer_telefonu << endl;
                    cos_znaleziono = true;
                }
                w_aktualny = w_aktualny->nastepny_wpis;
            }
            if (w_aktualny == NULL && cos_znaleziono == false)
            {
                cout << "Niestety nie znaleziono zadnych pasujacych danych" << endl;
            }
        }
        cin >> wybor;
    }
    return 0;
}

