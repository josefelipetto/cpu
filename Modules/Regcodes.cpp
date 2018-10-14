//
// Created by josefelipetto on 14/10/18.
//

#include "Regcodes.h"
#include "Helpers/StringHelper.h"

map<string,unsigned int> Regcodes::getRegisters() {
    return registers;
}

Regcodes::Regcodes(string filename) {

    ifstream infile(filename);

    string line;

    StringHelper stringHelper;

    while (getline(infile,line)) {
        vector<string> params = stringHelper.split(line, '|');

        registers.insert(pair<string,unsigned int>(params[0],stoi(params[1])));
    }

}
