//
// Created by josefelipetto on 13/10/18.
//

#ifndef CPU_RAM_H

#define CPU_RAM_H

#define RAM_SIZE 16 * 1024 * 1024

#include "MemoryCell.h"
#include <vector>
#include <iostream>

using namespace std;

class RAM final{

public:

    RAM();

    void debug(unsigned int begin, unsigned int iEnd);

    word get(unsigned int memoryAddress );

    void set(unsigned int memoryAddress, word content);

private:

    std::vector<MemoryCell> memoryCells;

    unsigned int ramSize;
};

#endif //CPU_RAM_H



