#ifndef CPP_PISCINE_ITER_HPP
#define CPP_PISCINE_ITER_HPP

#include <iostream>
#include <string>

//template <typename point, typename func>
//void iter(point *arr, size_t size, func f)
//{
//    size_t i = 0;
//
//    while (i < size)
//    {
//        f(arr[i]);
//        i++;
//    }
//};

template <typename T>
void iter(T *arr, size_t size, void(*f)(T const &))
{
    size_t i = 0;

    while (i < size)
    {
        f(arr[i]);
        i++;
    }
};

#endif //CPP_PISCINE_ITER_HPP
