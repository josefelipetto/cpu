//
// Created by josefelipetto on 14/10/18.
//

#include "Registers.h"
#include "../Helpers/StringHelper.h"

map<unsigned int,word > Registers::getRegisters() {

    return registers;
}

Registers::Registers(string filename) {

    ifstream infile(filename);

    string line;

    StringHelper stringHelper;

    while (getline(infile,line)) {

        vector<string> params = stringHelper.split(line, '|');

        registers.insert(pair<unsigned int,word>(stoi(params[1]),0));
    }

}

word Registers::get(unsigned int reg) {
    return registers.find(reg)->second;
}

void Registers::set(unsigned int memAddr, word value) {
    registers[memAddr] = value;
}
