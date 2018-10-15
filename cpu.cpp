//
// Created by josefelipetto on 08/10/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM/RAM.h"
#include "Modules/Loader/Loader.h"
#include "Modules/Helpers/Opcodes.h"
#include "Modules/Core/Registers.h"
#include "Modules/Core/PC.h"

using namespace std;

// RAM
typedef int word;


int main(){

    // Initialize components;
    RAM ram;

    unsigned int INIT_ADDR = 0;
    unsigned int HALT = 1000;

    // Load the executable file to the main memory
    Loader loader(INIT_ADDR,"output.run", &ram);

    Opcodes opcodes("OPCODES.esym");

    // Container that holds user registers and it's values
    Registers registers("REGCODES.esym");

    PC pc((unsigned int)INIT_ADDR);

    // start executing main workflow
    unsigned int currentCommand = ram.get(INIT_ADDR);

    do{

        // Decode
        string command = opcodes.getCommand(currentCommand);

        if(command.compare("MOV_RR") == 0)
        {
            // fetch
            word R1 = ram.get(pc.next());

            word R2 = ram.get(pc.next());

            // handle
            registers.set((unsigned int)R1,registers.get((unsigned int) R2));

        }
        else if(command.compare("MOV_RM") == 0)
        {

            // fetch
            word R1 = ram.get(pc.next());

            word R2 = ram.get(pc.next());

            //handle
            registers.set(R1,ram.get((unsigned int)R2));
        }

        currentCommand = ram.get( pc.next() );

    } while ( currentCommand != 1 );

    return 0;
}

