//
// Created by josefelipetto on 14/10/18.
//

#include "Loader.h"
#include "../Helpers/StringHelper.h"

Loader::Loader(unsigned int addr, string run_file_location, RAM * memory) {

    init_addr = addr;

    run_file = run_file_location;

    ram = memory;

    load();
}

void Loader::load() {

    ifstream infile(run_file);

    string line;

    string code = "";

    while (getline(infile,line)){

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
