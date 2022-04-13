#ifndef CPP_PISCINE_EASYFIND_HPP
#define CPP_PISCINE_EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T & vec, int n)
{
    return (std::find(vec.begin(), vec.end(), n));
}

#endif //CPP_PISCINE_EASYFIND_HPP
