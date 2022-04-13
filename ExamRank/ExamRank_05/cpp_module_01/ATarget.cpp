#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) {
    this->type = type;
}

ATarget::ATarget(ATarget &copy) {
    *this = copy;
}

ATarget & ATarget::operator=(ATarget &other) {
    this->type = other.type;
	return (*this);
}

std::string const & ATarget::getType() const {return (type);}

void ATarget::getHitBySpell(ASpell const &obj) const {
    std::cout << this->type << " has been " << obj.getEffects() <<"!"<< std::endl;
}