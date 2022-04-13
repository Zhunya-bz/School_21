#ifndef EXAMRANK05_ASPELL_HPP
#define EXAMRANK05_ASPELL_HPP

#include <string>
#include <iostream>

class ATarget;

class ASpell {
private:
    std::string name;
    std::string effects;

public:
    ASpell(){};
    ASpell(std::string const & name, std::string const & effects);
    virtual ~ASpell(){}; // virtual

    ASpell(ASpell &copy);
    ASpell & operator= (ASpell & other);

    std::string const & getName() const;
    std::string const & getEffects() const;

    virtual ASpell *clone() const = 0; // virtual
    void launch(ATarget const & target_ref) const;
};


#endif //EXAMRANK05_ASPELL_HPP
