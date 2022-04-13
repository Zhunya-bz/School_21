#ifndef EXAMRANK_BRICKWALL_HPP
#define EXAMRANK_BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall :public ATarget
{
public:
    BrickWall();
    virtual ~BrickWall(){};

    virtual ATarget * clone() const;
};


#endif //EXAMRANK_BRICKWALL_HPP
