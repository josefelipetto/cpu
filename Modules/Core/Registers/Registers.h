//
// Created by josefelipetto on 14/10/18.
//

#ifndef CPU_REGCODES_H
#define CPU_REGCODES_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>

typedef int word;

using namespace std;

class Registers final{

public:

    map<unsigned int,word> getRegisters();

    Registers(string filename);

    word get(unsigned int reg);

    void set(unsigned int memAddr, word value);
private:

    map<unsigned int,word> registers;

};

#endif //CPU_REGCODES_H
