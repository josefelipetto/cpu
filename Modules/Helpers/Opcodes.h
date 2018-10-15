//
// Created by josefelipetto on 14/10/18.
//

#ifndef CPU_OPCODES_H
#define CPU_OPCODES_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

class Opcodes final{

public:

    map<unsigned int,string> getCodes();

    Opcodes(string opcodes_file);

    string getCommand(unsigned int opcode);

private:

    map<unsigned int,string> codes;
};

#endif //CPU_OPCODES_H
