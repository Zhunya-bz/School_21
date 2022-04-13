#ifndef EXAMRANK05_ATARGET_HPP
#define EXAMRANK05_ATARGET_HPP

#include "ASpell.hpp"

class ATarget {
private:
    std::string type;

public:
    ATarget(){};
    ATarget(std::string const & type);
    virtual ~ATarget(){};

    ATarget(ATarget & copy);
    ATarget &operator= (ATarget & other);

    std::string const & getType() const;

    virtual ATarget * clone() const = 0;

    void getHitBySpell(ASpell const & obj) const;
};


#endif //EXAMRANK05_ATARGET_HPP
