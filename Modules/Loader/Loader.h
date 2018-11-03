//
// Created by josefelipetto on 14/10/18.
//

#ifndef CPU_LOADER_H

#define CPU_LOADER_H

#include "../RAM/RAM.h"
#include <iostream>
#include <string>
#include <fstream>

typedef int word;

using namespace std;

class Loader final{

public:

    Loader(unsigned int addr, string run_file_location, RAM * memory);

    void load();

    unsigned int getEndCodeAddr();

private:

    unsigned int init_addr;

    RAM *ram;

    string run_file;

    unsigned int endCodeAddr;

};

#endif //CPU_LOADER_H
