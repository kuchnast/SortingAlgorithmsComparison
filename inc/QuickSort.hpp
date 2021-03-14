#pragma once

#include <iostream>
#include <algorithm>
#include "Sorter.hpp"

template <class T>
class QuickSort : public Sorter<T>
{
private:
    void m_quickSort(T *array, int l, int r);
    int m_partition(T *array, int l, int r);

public:
    using Sorter<T>::Sorter;
    void sort(T *array, int l, int r) override;
};

template <class T>
void QuickSort<T>::m_quickSort(T *array, int l, int r)
{
    if(l < r)
    {
        int q = m_partition(array, l, r);
        m_quickSort(array, l, q - 1);
        m_quickSort(array, q + 1, r);
    }
}

template <class T> 
int QuickSort<T>::m_partition(T *array, int l, int r)
{
    int q = array[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        switch (this->m_type)
        {
        case ASC:
            if(array[j] <= q)
            {
                std::swap(array[++i], array[j]);
            }
            break;
        
        case DES:
            if(array[j] >= q)
            {
                std::swap(array[++i], array[j]);
            }
            break;
        }
    }

    std::swap(array[++i], array[r]);
    return i;
}

template <class T>
void QuickSort<T>::sort(T *array, int l, int r)
{
    m_quickSort(array, l, r);
}