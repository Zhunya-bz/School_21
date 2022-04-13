#ifndef EXAMRANK_FIREBALL_HPP
#define EXAMRANK_FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
    Fireball();
    virtual ~Fireball(){};

    virtual ASpell *clone() const;
};


#endif //EXAMRANK_FIREBALL_HPP
