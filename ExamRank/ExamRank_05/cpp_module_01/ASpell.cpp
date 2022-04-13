#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string const & name, std::string const & effects) {
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell &copy){
    *this = copy;
}

ASpell & ASpell::operator= (ASpell & other){
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

const std::string & ASpell::getName() const {return (name);}

const std::string & ASpell::getEffects() const {return (effects);}

void ASpell::launch(ATarget const &target_ref) const {
    target_ref.getHitBySpell((*this));
}