//
// Created by josefelipetto on 14/10/18.
//

#include "Loader.h"
#include "../Helpers/StringHelper.h"

Loader::Loader(unsigned int addr, ifstream *_file, RAM *memory) {

    init_addr = addr;

    file = _file;

    ram = memory;

    load();
}


void Loader::load() {

    string line;

    string code = "";

    while (getline(*file,line)){

        code.append(line);
    }

    StringHelper stringHelper;

    vector<string> tokens = stringHelper.split(code, ' ');

    unsigned int memoryPosition = init_addr;

    for(string x : tokens){

        word value = stoi(x);

        ram->set(memoryPosition, value);

        memoryPosition++;
    }

    endCodeAddr = memoryPosition;
}

unsigned int Loader::getEndCodeAddr() {
    return endCodeAddr;
}
