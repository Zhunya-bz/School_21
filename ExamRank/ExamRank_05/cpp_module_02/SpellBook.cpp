#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end(); it++)
    {
        delete *it;
    }
}

void SpellBook::learnSpell(ASpell *ptr) {
    for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end(); it++)
    {
        if ((*it)->getName() == ptr->getName())
            return;
    }
    this->spells.push_back(ptr->clone());
}

void SpellBook::forgetSpell(std::string const &name)
{
    std::vector<ASpell*>::iterator ite = this->spells.end();
    for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
        if ((*it)->getName() == name) {
            delete *it;
            it = this->spells.erase(it);
        }
    }
}

ASpell * SpellBook::createSpell(const std::string &name) {
    std::vector<ASpell *>::iterator ite = this->spells.end();
    for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != ite; ++it) {
        if ((*it)->getName() == name) {
            return (*it);
        }
    }
    return (nullptr);
}