//
// Created by josefelipetto on 13/10/18.
//

#ifndef CPU_RAM_H

#define CPU_RAM_H

#define RAM_SIZE 16000

#include "MemoryCell.h"
#include <vector>
#include <iostream>

using namespace std;

class RAM final{

public:

    RAM();

    void debug();

private:

    std::vector<MemoryCell> memoryCells;
};

#endif //CPU_RAM_H


