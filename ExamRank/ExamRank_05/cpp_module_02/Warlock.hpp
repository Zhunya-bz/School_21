#ifndef EXAMRANK05_WARLOCK_HPP
#define EXAMRANK05_WARLOCK_HPP

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
    std::string name;
    std::string title;
    SpellBook spellBook;

    Warlock(){};
    Warlock(Warlock const & copy) {
        *this = copy;
    }
    Warlock & operator=(Warlock const & other){
        name = other.name;
        title = other.title;
        return *this;
    };

	std::vector<ASpell*> spells;

public:
    Warlock(std::string const &names, std::string const &titles);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const &title);

    void introduce() const;

    void learnSpell(ASpell * spell_ptr);
    void forgetSpell(std::string const &name);
    void launchSpell(std::string const &name, ATarget const & ref);

};


#endif //EXAMRANK05_WARLOCK_HPP
