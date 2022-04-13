#ifndef EXAMRANK_SPELLBOOK_HPP
#define EXAMRANK_SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"

class SpellBook {
private:
    std::vector<ASpell*> spells;

    SpellBook(SpellBook & copy);
    SpellBook & operator= (SpellBook & other);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* ptr);
    void forgetSpell(std::string const & name);
    ASpell* createSpell(std::string const & name);

};


#endif //EXAMRANK_SPELLBOOK_HPP
