//
// Created by josefelipetto on 14/10/18.
//

#include "Opcodes.h"
#include "Helpers/StringHelper.h"

map<string,unsigned int> Opcodes::getCodes(){

    return codes;
}

Opcodes::Opcodes(string opcodes_file) {

    ifstream infile(opcodes_file);

    string line;

    StringHelper stringHelper;

    while (getline(infile,line)) {
        vector<string> params = stringHelper.split(line, '|');

        codes.insert(pair<string,unsigned int>(params[0],stoi(params[1])));
    }
}