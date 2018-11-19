//
// Created by josefelipetto on 18/11/18.
//

#ifndef CPU_CPU_H
#define CPU_CPU_H

#include "../RAM/RAM.h"
#include "../Helpers/Opcodes.h"
#include "Registers/Registers.h"
#include "Registers/PC.h"
#include "../Loader/Loader.h"
#include "Flag.h"
#include "Cache/Cache.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// RAM
typedef int word;

class CPU final{

public:

    CPU(RAM * _ram, unsigned int initAddr, Opcodes * _opcodes, string regCodesFile, ifstream * program, int cpuNumber);

    int init();

    int getId();
private:

    unsigned int INIT_ADDR;

    Opcodes * opcodes;

    Registers * registers;

    PC * pc;

    Flag * flag;

    Cache * cache;

    int id;

};
#endif //CPU_CPU_H
