#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

namespace moj_wektor
{
    template <typename T>
    class wektorInt
    {
    public:
        wektorInt ();
        wektorInt (int initial_size);
        T get_value (int index);                         // get the value stored under a given index
        void set_at_index (int index, T value);            // set a value under a given index
        void set_at_end (T value);                         // set a value at the end of the vector
        void set_at_beginning (T value);                   // set a value at the beginning of the vector
        wektorInt (const wektorInt &other);
        wektorInt &operator= (const wektorInt &other)
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
        ~wektorInt ();
    private:
        T *p_table;
        bool *p_allocated_table;                    // utility table to inform if a given index in the vector stores a value
        int current_size;
        void extend_table();
        void move_values();                         // utility function that moves every assigned value to an upper index (index + 1)
        void copy_utility(const wektorInt &other);  // utility function to use with copy constructor and assignment operator

    };
}

using namespace moj_wektor;

template <typename T>
wektorInt<T>::wektorInt()
{
    p_table = new T[32];
    p_allocated_table = new bool[32];
    for (int i = 0; i < 32; i++)
    {
        p_allocated_table[i] = false;
    }
    current_size = 32;
}

template <typename T>
wektorInt<T>::wektorInt(int initial_size)
{
    // place an error definition here

    if (initial_size == 0)
    {
        initial_size = 1;
    }

    p_table = new T[initial_size];
    p_allocated_table = new bool[initial_size];
    for (int i = 0; i < initial_size; i++)
    {
        p_allocated_table[i] = false;
    }
    current_size = initial_size;
}

template <typename T>
void wektorInt<T>::extend_table()
{
    T *p_table_temp = new T[2 * current_size];
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

template <typename T>
void wektorInt<T>::move_values()
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

template <typename T>
T wektorInt<T>::get_value(int index)
{
    // place an error definition here

    if (p_allocated_table[index] == true)
    {
        return p_table[index];
    }
}

template <typename T>
void wektorInt<T>::set_at_index(int index, T value)
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

template <typename T>
void wektorInt<T>::set_at_end(T value)
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

template <typename T>
void wektorInt<T>::set_at_beginning(T value)
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

template <typename T>
void wektorInt<T>::copy_utility(const wektorInt &other)
{
    current_size = other.current_size;
    p_table = new T[current_size];
    p_allocated_table = new bool[current_size];

    for (int i = 0; i < current_size; i++)
    {
        p_table[i] = other.p_table[i];
        p_allocated_table[i] = other.p_allocated_table[i];
    }
}

template <typename T>
wektorInt<T>::wektorInt(const wektorInt &other)
{
    copy_utility(other);
}

/*template <typename T>
wektorInt &wektorInt::operator= (const wektorInt<T> &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] p_table;
    delete[] p_allocated_table;

    copy_utility(other);
    return *this;
}*/

template <typename T>
wektorInt<T>::~wektorInt()
{
    delete[] p_table;
    delete[] p_allocated_table;
}



#endif // HEADER_H_INCLUDED
