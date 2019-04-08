#include <iostream>

using namespace std;

struct WrogiStatekKosmiczny
{
    int wspolrzedna_x;
    int wspolrzedna_y;
    int sila_broni;
};

WrogiStatekKosmiczny generujNowegoWroga()
{
    WrogiStatekKosmiczny statek;
    statek.wspolrzedna_x = 0;
    statek.wspolrzedna_y = 0;
    statek.sila_broni = 20;
    return statek;
}

WrogiStatekKosmiczny ulepszBron (WrogiStatekKosmiczny statek)
{
    statek.sila_broni += 10;
    return statek;
}

int main()
{
    WrogiStatekKosmiczny wrog = generujNowegoWroga();
    wrog = ulepszBron(wrog);
    return 0;
}
