#ifndef EXAMRANK_POLYMORPH_HPP
#define EXAMRANK_POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
    Polymorph();
    virtual ~Polymorph(){};

    virtual ASpell *clone() const;
};


#endif //EXAMRANK_POLYMORPH_HPP
