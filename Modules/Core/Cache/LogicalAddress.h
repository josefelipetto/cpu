//
// Created by josefelipetto on 05/11/18.
//

#ifndef CPU_LOGICALADDRESS_H
#define CPU_LOGICALADDRESS_H

#include <cmath>

class LogicalAddress final{

public:

    LogicalAddress(unsigned int memoryAddress);

    unsigned int S();

    unsigned int R();

    unsigned int T();

    unsigned int W();


private:

    unsigned int s;

    unsigned int r;

    unsigned int t;

    unsigned int w;
};
#endif //CPU_LOGICALADDRESS_H
