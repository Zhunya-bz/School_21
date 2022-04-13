#include <iostream>
#include "Array.hpp"
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; // выход за пределы границы
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; // выход за пределы границы
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "-----------------------" << std::endl;

    Array<int> b(4);
    Array<int> a;
    Array<std::string> strings(5);

    std::cout << "Проверка есть ли мусорные значения?" << std::endl;

    for(unsigned int i = 0; i < b.getLength(); i++)
        std::cout << b[i] << " " << std::flush; //просто нули
    std::cout << std::endl;

    a = b;
    b[3] = 5;
    a[3] = 10;

    if (a[3] != b[3])
        std::cout << "Изменения в a не затронули пременные b" << std::endl;

    b[0] = 1324;
    b[1] = 999;

    Array<int> c(b); // конструктор копирования

    bool proof = true;
    for(unsigned int i = 0; i < b.getLength(); i++)
    {
        std::cout <<b[i] << " " << c[i] << std::endl;
        if (b[i] != c[i])
            proof = false;
    }
    if (proof)
        std::cout << "Верно c полная копия b" << std::endl;

    strings[0] = "One";
    strings[1] = "Two";
    strings[2] = "Three";
    strings[3] = "Four";
    strings[4] = "Five";

    try
    {
        for(int i = 0; i < 10; i++)
            std::cout << strings[i] << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << "Убежали за область выделенной памяти" << std::endl;
    }

    return 0;
}