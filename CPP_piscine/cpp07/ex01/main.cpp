#include "iter.hpp"

template <typename T>
void plus(T &arr)
{
    arr++;
    std::cout << arr << " ";
}

void hight(char &s)
{
    std::cout << static_cast<char>(toupper(s));
}

void wr(std::string &str)
{
    str = "vjuh";
}

//void wr2(char &str)
//{
//    str = 'Z';
//}

int main()
{
    int arr[10] = {0 , 1 , 2, 3, 4, 5, 6, 7, 8, 9};
    double d[5] = {2.0, 5.55, 10.10, 0.951236, 3};
    char s[6] = "hello";
    std::string str[5]{};
//    char *s2 = NULL;
//    s2 = (char *)calloc(10, 1);

    ::iter(arr, 10, plus<int>);
    std::cout << std::endl;
    ::iter(d, 5, plus<double>);
    std::cout << std::endl;
    ::iter(s, 6, hight);
    std::cout << std::endl;
    ::iter(str, 5, wr);
    for (int i = 0; i < 5; i++)
        std::cout << str[i]<< std::endl;
//    ::iter(s2, 3, wr2);
//    for (int i = 0; i < 5; i++)
//        std::cout << s2[i]<< std::endl;

    return (0);
}
