#include "Warlock.hpp"

Warlock::Warlock(std::string const &names, std::string const &titles): name(names), title(titles) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName() const { return (name);}

std::string const & Warlock::getTitle() const {return (title);}

void Warlock::setTitle(std::string const &title) {
    this->title = title;
}

Warlock::~Warlock() {
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end(); it++)
	{
		delete *it;
	}
    std::cout << name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" <<std::endl;
}

void Warlock::learnSpell(ASpell *spell_ptr) {
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end(); it++)
	{
		if ((*it)->getName() == spell_ptr->getName())
			return;
	}
	this->spells.push_back(spell_ptr->clone());
}

void Warlock::forgetSpell(std::string const &name)
{
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == name) {
			delete *it;
			it = this->spells.erase(it);
		}
	}
}

void Warlock::launchSpell(const std::string &name, ATarget const &ref)
{
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			(*it)->launch(ref);
			return;
		}
	}
}