#include "MutantStack.hpp"
#include <time.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout <<"size after pop: "<< mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    srand(time(NULL));
    std::cout << RED << "|============================|\n" << RESET;
    std::cout << CYAN << "Testing iterator...\n" << RESET;
    MutantStack<int> st_1;
    for (size_t i = 0; i < 30; i++)
        st_1.push(rand() % 100);
    std::cout << YELLOW << "[On top]: " << CYAN << st_1.top() << RESET << std::endl;
    MutantStack<int>::iterator it_1 = st_1.begin();
    MutantStack<int>::iterator ite_1 = st_1.end();
    std::cout << YELLOW << "[STACK]: " << CYAN;
    while(it_1 != ite_1)
    {
        std::cout << *it_1 << " ";
        ++it_1;
    }
    std::cout << RESET << std::endl;

    std::cout << RED << "|============================|\n" << RESET;
    std::cout << CYAN << "Testing const_iterator...\n" << RESET;
    MutantStack<int> st_2;
    for (size_t i = 0; i < 30; i++)
        st_2.push(rand() % 100);
    std::cout << YELLOW << "[On top]: " << CYAN << st_2.top() << RESET << std::endl;
    MutantStack<int>::const_iterator it_2 = st_2.begin();
    MutantStack<int>::const_iterator ite_2 = st_2.end();
    std::cout << YELLOW << "[STACK]: " << CYAN;
    while(it_2 != ite_2)
    {
        std::cout << *it_2 << " ";
        ++it_2;
    }
    std::cout << RESET << std::endl;

    std::cout << RED << "|============================|\n" << RESET;
    std::cout << CYAN << "Testing reverse_iterator...\n" << RESET;
    MutantStack<int> st_3;
    for (size_t i = 0; i < 30; i++)
        st_3.push(rand() % 100);
    std::cout << YELLOW << "[On top]: " << CYAN << st_3.top() << RESET << std::endl;
    MutantStack<int>::reverse_iterator it_3 = st_3.rbegin();
    MutantStack<int>::reverse_iterator ite_3 = st_3.rend();
    std::cout << YELLOW << "[STACK]: " << CYAN;
    while(it_3 != ite_3)
    {
        std::cout << *it_3 << " ";
        ++it_3;
    }
    std::cout << RESET << std::endl;

    std::cout << RED << "|============================|\n" << RESET;
    std::cout << CYAN << "Testing const_reverse_iterator...\n" << RESET;
    MutantStack<int> st_4;
    for (size_t i = 0; i < 30; i++)
        st_4.push(rand() % 100);
    std::cout << YELLOW << "[On top]: " << CYAN << st_4.top() << RESET << std::endl;
    MutantStack<int>::const_reverse_iterator it_4 = st_4.rbegin();
    MutantStack<int>::const_reverse_iterator ite_4 = st_4.rend();
    std::cout << YELLOW << "[STACK]: " << CYAN;
    while(it_4 != ite_4)
    {
        std::cout << *it_4 << " ";
        ++it_4;
    }
    std::cout << RESET << std::endl;

    std::cout << RED << "|============================|\n" << RESET;

    return 0;
}