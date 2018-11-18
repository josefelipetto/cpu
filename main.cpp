//
// Created by josefelipetto on 18/11/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM/RAM.h"
#include "Modules/Helpers/Opcodes.h"
#include "Modules/Core/CPU.h"
#include <string>
using namespace std;

// RAM
typedef int word;

int main() {

    RAM ram((unsigned int)16*1024*1024);

    unsigned int INIT_ADDR = 0;

    unsigned int HALT = 1;

    Opcodes opcodes("OPCODES.esym");

    ifstream * code = new ifstream("./output.run");

    CPU cpu(&ram,INIT_ADDR,&opcodes,"REGCODES.esym",code,0);

    cpu.init();

}

