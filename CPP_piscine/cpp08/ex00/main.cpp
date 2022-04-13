#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <deque>

int main()
{
    std::vector<int> A; // динамический массив

    for (int i = 10; i > 0; --i)
        A.push_back(i);

    std::vector<int>::iterator it;
    std::cout << "Vector: ";
    for (it = A.begin(); it < A.end(); it++)
        std::cout << *it << " ";

    if (easyfind(A, 2) != A.end())
        std::cout << std::endl << "OK" << std::endl;
    else
        std::cout << std::endl << "NOT OK" << std::endl;


    std::list<int>	L; // двусвязный список
    for (int i = 7; i > 0; --i)
        L.push_back(i);

    std::list<int>::iterator itl;
    std::cout << "List: ";
    for (itl = L.begin(); itl != L.end(); itl++)
        std::cout << *itl << " ";

    if (easyfind(L, 2) != L.end())
        std::cout << std::endl << "OK" << std::endl;
    else
        std::cout << std::endl << "NOT OK" << std::endl;

    std::deque<int> D; // двустороняя очередь
    for (int i = 12; i > 0; --i)
        D.push_back(i);

    std::deque<int>::iterator itd;
    std::cout << "Deque: ";
    for (itd = D.begin(); itd != D.end(); itd++)
        std::cout << *itd << " ";

    if (easyfind(D, 2) != D.end())
        std::cout << std::endl << "OK" << std::endl;
    else
        std::cout << std::endl << "NOT OK" << std::endl;

    std::set<int> Set; // множество, сортируется
    Set.insert(20);
    Set.insert(-2);
    Set.insert(1);
    Set.insert(-3);

    std::set<int>::iterator its;
    std::cout << "Set: ";
    for (its = Set.begin(); its != Set.end(); its++)
        std::cout << *its << " ";

    if (easyfind(Set, 2) != Set.end())
        std::cout << std::endl << "OK" << std::endl;
    else
        std::cout << std::endl << "NOT OK" << std::endl;

    return (0);
}