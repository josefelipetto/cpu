//
// Created by josefelipetto on 08/10/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM/RAM.h"
#include "Modules/Loader/Loader.h"
#include "Modules/Opcodes.h"
#include "Modules/Regcodes.h"

using namespace std;

// RAM
typedef int word;


int main(){

    // Initialize components;
    RAM ram;

    Loader loader(0,"output.run", &ram);
    loader.load();

    Opcodes opcodes("OPCODES.esym");
    Regcodes regcodes("REGCODES.esym");

    return 0;
}

