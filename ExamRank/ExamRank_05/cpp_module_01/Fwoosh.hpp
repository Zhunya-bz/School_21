#ifndef EXAMRANK05_FWOOSH_HPP
#define EXAMRANK05_FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
public:
    Fwoosh();
    virtual ~Fwoosh(){};

    virtual ASpell *clone() const;
};


#endif //EXAMRANK05_FWOOSH_HPP
