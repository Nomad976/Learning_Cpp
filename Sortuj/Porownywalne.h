#ifndef POROWNYWALNE_H_INCLUDED
#define POROWNYWALNE_H_INCLUDED
#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>

class Porownywalne
{
public:
    virtual int porownaj (Porownywalne *inny) = 0;
    virtual ~Porownywalne () {}
    int data_size;
    int identifier;
};

class TabelaWynikow : public Porownywalne
{
public:
    TabelaWynikow(int cos);
    void display_table();
    void add_score(std::string name, int score);
    virtual int porownaj(Porownywalne *inny);
private:
    std::vector <int> scores;
    std::vector <std::string> names;
    bool sort_by_names;
    void resort();
};

class Komparator
{
public:
   virtual int porownaj (const std::string &lewy, const std::string &prawy) = 0;
   virtual ~Komparator () {}
};

class sub_Komp : public Komparator
{
public:
    virtual int porownaj(const std::string &lewy, const std::string &prawy);
};

void sortuj (std::vector<Porownywalne*> &tabela_tabel);
void sortuj (std::vector<Komparator*> &tabela_komparatorow);

#endif // POROWNYWALNE_H_INCLUDED
