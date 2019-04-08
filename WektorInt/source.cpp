#include "header.h"
#include <iostream>

using namespace moj_wektor;

wektorInt::wektorInt()
{
    p_table = new int[32];
    p_allocated_table = new bool[32];
    for (int i = 0; i < 32; i++)
    {
        p_allocated_table[i] = false;
    }
    current_size = 32;
}

wektorInt::wektorInt(int initial_size)
{
    // place an error definition here

    if (initial_size == 0)
    {
        initial_size = 1;
    }

    p_table = new int[initial_size];
    p_allocated_table = new bool[initial_size];
    for (int i = 0; i < initial_size; i++)
    {
        p_allocated_table[i] = false;
    }
    current_size = initial_size;
}

void wektorInt::extend_table()
{
    int *p_table_temp = new int[2 * current_size];
    bool *p_alloc_temp = new bool[2 * current_size];

    for (int i = 0; i < current_size; i++)
    {
        p_table_temp[i] = p_table[i];
        p_alloc_temp[i] = p_allocated_table[i];
    }
    for (int i = current_size; i < 2 * current_size; i++)
    {
        p_alloc_temp[i] = false;
    }
    delete[] p_table;
    delete[] p_allocated_table;
    p_table = p_table_temp;
    p_allocated_table = p_alloc_temp;
    current_size *= 2;
}

void wektorInt::move_values()
{
    int prev_size;  // size of the table before a possible extension of the table
    for (int i = current_size - 1; i >= 0; i--)
    {
        if (p_allocated_table[i] == true)
        {
            prev_size = i;
            break;
        }
    }

    if (p_allocated_table[current_size - 1] == true)
    {
        extend_table();
    }
    for (int i = prev_size; i >= 0; i--)
    {
        p_table[i + 1] = p_table[i];
        p_allocated_table[i + 1] = p_allocated_table[i];
    }
}

int wektorInt::get_value(int index)
{
    // place an error definition here

    if (p_allocated_table[index] == true)
    {
        return p_table[index];
    }
}

void wektorInt::set_at_index(int index, int value)
{
    // place an error definition here

    if (index >= 0 && index < current_size)
    {
        p_table[index] = value;
        p_allocated_table[index] = true;
    }
    else if (index >= current_size)
    {
        extend_table();
        set_at_index(index, value);
    }
}

void wektorInt::set_at_end(int value)
{
    for (int i = current_size - 1; i >= 0; i--)
    {
        if (p_allocated_table[i] == true && i == current_size - 1)
        {
            extend_table();
            p_table[i + 1] = value;
            p_allocated_table[i + 1] = true;
            return;
        }
        else if (p_allocated_table[i] == false && i == 0)
        {
            p_table[i] = value;
            p_allocated_table[i] = true;
            return;
        }
        else if (p_allocated_table[i] == true)
        {
            p_table[i + 1] = value;
            p_allocated_table[i + 1] = true;
            return;
        }
    }
}

void wektorInt::set_at_beginning(int value)
{
    if (p_allocated_table[0] == false)
    {
        p_table[0] = value;
        p_allocated_table[0] = true;
        return;
    }
    else
    {
        move_values();
        p_table[0] = value;
        p_allocated_table[0] = true;
    }
}

void wektorInt::copy_utility(const wektorInt &other)
{
    current_size = other.current_size;
    p_table = new int[current_size];
    p_allocated_table = new bool[current_size];

    for (int i = 0; i < current_size; i++)
    {
        p_table[i] = other.p_table[i];
        p_allocated_table[i] = other.p_allocated_table[i];
    }
}

wektorInt::wektorInt(const wektorInt &other)
{
    copy_utility(other);
}

wektorInt &wektorInt::operator= (const wektorInt &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] p_table;
    delete[] p_allocated_table;

    copy_utility(other);
    return *this;
}

wektorInt::~wektorInt()
{
    delete[] p_table;
    delete[] p_allocated_table;
}
