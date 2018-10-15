//
// Created by josefelipetto on 14/10/18.
//

#include "Opcodes.h"
#include "StringHelper.h"

map<unsigned int,string> Opcodes::getCodes(){

    return codes;
}

Opcodes::Opcodes(string opcodes_file) {

    ifstream infile(opcodes_file);

    string line;

    StringHelper stringHelper;

    while (getline(infile,line)) {
        vector<string> params = stringHelper.split(line, '|');

        codes.insert(pair<unsigned int,string>(stoi(params[1]),params[0]));
    }
}

string Opcodes::getCommand(unsigned int opcode) {
    return codes.find(opcode)->second;
}