#ifndef CPP_PISCINE_ARRAY_HPP
#define CPP_PISCINE_ARRAY_HPP

template <class T> // это шаблон класса с T вместо фактического (передаваемого) типа данных
class Array
{
private:
    unsigned int    _length;
    T               *_data;

public:
    Array() : _length(0), _data(nullptr){}

    Array(unsigned int n) : _length(n){
        _data = new T[n](); // сразу вызываем конструктор этого типа чтобы занулил все
    }

    Array(const Array & copy) : _data(nullptr){ (*this) = copy; }

    Array & operator= (const Array & copy)
    {
        if (this->_data && this->_length)
            delete[] this->_data;
        this->_length = copy._length;
        this->_data = new T[this->_length];
        for (unsigned int i = 0; i < this->_length; ++i)
            this->_data[i] = copy._data[i];

        return (*this);
    }

    ~Array() { delete[] _data; }

    class InvalidIndexEx : public std::exception {
    public:
        InvalidIndexEx(){};
        virtual ~InvalidIndexEx() throw (){};
        virtual const char* what() const throw(){
            return "Invalid index of array!";
        };
    };

    T& operator[] (unsigned int index)
    {
        if (index >= _length || index < 0)
            throw InvalidIndexEx();
        return (this->_data[index]);
    }

    unsigned int getLength(); // определяем метод и шаблон метода getLength() ниже
};

template <typename T> // метод, определенный вне тела класса, нуждается в собственном определении шаблона метода
unsigned int Array<T>::getLength() { return _length; } // обратите внимание, имя класса - Array<T>, а не просто Array

#endif //CPP_PISCINE_ARRAY_HPP
