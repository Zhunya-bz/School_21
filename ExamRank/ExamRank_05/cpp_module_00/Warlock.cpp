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
    std::cout << name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" <<std::endl;
}