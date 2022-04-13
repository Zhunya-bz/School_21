#ifndef EXAMRANK_TARGETGENERATOR_HPP
#define EXAMRANK_TARGETGENERATOR_HPP

#include <vector>
#include "ATarget.hpp"


class TargetGenerator {
private:
    std::vector<ATarget*> types;

    TargetGenerator(TargetGenerator & copy);
    TargetGenerator & operator=(TargetGenerator & other);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* type);
    void forgetTargetType(std::string const & Tname);
    ATarget* createTarget(std::string const & Tname);

};


#endif //EXAMRANK_TARGETGENERATOR_HPP
