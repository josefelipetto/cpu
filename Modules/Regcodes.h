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

using namespace std;

class Regcodes final{

public:

    map<string,unsigned int> getRegisters();

    Regcodes(string filename);

private:

    map<string, unsigned int> registers;

};

#endif //CPU_REGCODES_H
