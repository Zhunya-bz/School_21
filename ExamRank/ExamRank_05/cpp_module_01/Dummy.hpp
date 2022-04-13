#ifndef EXAMRANK05_DUMMY_HPP
#define EXAMRANK05_DUMMY_HPP

#include "ATarget.hpp"

class Dummy: public ATarget
{
public:
    Dummy();
    virtual ~Dummy(){};

    virtual ATarget *clone() const;
};


#endif //EXAMRANK05_DUMMY_HPP
