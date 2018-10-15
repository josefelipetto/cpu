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

        cout << pc.get() << " " << command << " ";

        if(command.compare("MOV_RR") == 0)
        {
            // fetch
            word R1 = ram.get(pc.next());

            word R2 = ram.get(pc.next());

            // handle
            registers.set((unsigned int)R1,registers.get((unsigned int) R2));

            cout << R1 << " " << R2 << endl;

        }
        else if(command.compare("MOV_RM") == 0)
        {

            // fetch
            word R1 = ram.get(pc.next());

            word memoryAddress = ram.get(pc.next());

            //handle
            registers.set(R1,ram.get((unsigned int)memoryAddress));

            cout << R1 << " " << "[" << memoryAddress << "]" << endl;
        }
        else if(command.compare("MOV_MR") == 0 )
        {
            unsigned int destination = ram.get(pc.next());

            word sourceRegister = ram.get(pc.next());

            ram.set(destination, registers.get(sourceRegister));

            cout << "[" << destination << "] " << sourceRegister << endl;
        }
        else if(command.compare("MOV_RI") == 0)
        {
            word destinationRegister = ram.get(pc.next());

            word value = ram.get(pc.next());

            registers.set(destinationRegister,value);

            cout << destinationRegister << " " << value << endl;
        }
        else if(command.compare("MOV_MI") == 0)
        {
            unsigned int destination = ram.get(pc.next());

            word value = ram.get(pc.next());

            ram.set(destination,value);

            cout << "[" << destination << "] " << value << endl;
        }
        else if(command.compare("NOP") == 0)
        {
            cout << endl;
        }

        currentCommand = ram.get( pc.next() );

    } while ( currentCommand != 1 );

    return 0;
}

