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
#include "Modules/Core/Flag.h"

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

    Flag flag((unsigned int)INIT_ADDR);

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
        else if(command.compare("ADD") == 0){

          word R1 = ram.get(pc.next());

          word R2 = ram.get(pc.next());

          int value = registers.get((unsigned int)R1)+registers.get((unsigned int)R2);

          registers.set((int)R1,value);

          //print the result of the sum
          cout << R1 << " " << registers.get(R1) << endl;
        }
        else if(command.compare("SUB") == 0){

          word R1 = ram.get(pc.next());

          word R2 = ram.get(pc.next());

          int value = registers.get((unsigned int)R1)-registers.get((unsigned int)R2);

          registers.set((int)R1,value);


          //print the result of the subtraction
          cout << R1 << " " << registers.get(R1) << endl;
        }
        else if(command.compare("CMP") == 0){

          word R1 = ram.get(pc.next());

          word R2 = ram.get(pc.next());

          int value = registers.get((unsigned int)R1)-registers.get((unsigned int)R2);

          flag.set(value);


          // print the flag state (signed int)
          cout << flag.get() << endl;
        }
        else if(command.compare("JMP") == 0){

          unsigned int jumpValue = ram.get(pc.next());

          // jump a specific number of commands
          pc.set((unsigned int)jumpValue-1);

          cout << "JMP" << jumpValue << endl;

          // print the cicle of the program counter
          // cout << pc.get() << endl;
        }
        else if(command.compare("JZ") == 0){

          word offset = ram.get(pc.next());

          int flagChecker = flag.get();

          int pcJump = pc.get();

          cout << offset << endl;

          // conditional jump
          if(flagChecker==0)
            pc.set((pcJump+offset)-1);

          // cout << pc.get() << endl;
        }
        else if(command.compare("JG") == 0){

          word offset = ram.get(pc.next());

          int flagChecker = flag.get();

          int pcJump = pc.get();

          cout << offset << endl;

          if(flagChecker>0)
             pc.set((pcJump+offset)-1);

          // cout << pc.get() << endl;
        } 
        else if (command.compare("JL") == 0){
            
            word offset = ram.get(pc.next());

            int flagChecker = flag.get();

            int pcJump = pc.get();

            cout << offset << endl;

            if(flagChecker < 0)
                pc.set((pcJump+offset)-1);

        }  
        else if (command.compare("OUT") == 0){
            
            word destinationRegister = ram.get(pc.next());

            int regValue = registers.get(destinationRegister);

            cout << regValue << endl;

        } 
        else if (command.compare("INC") == 0){
            
            word destinationRegister = ram.get(pc.next());

            int value = registers.get((unsigned int)destinationRegister)+1;

            registers.set(destinationRegister,value);

            cout << destinationRegister << " " << value << endl;

        } 
        else if (command.compare("DEC") == 0){
            
            word destinationRegister = ram.get(pc.next());

            int value = registers.get((unsigned int)destinationRegister)-1;

            registers.set(destinationRegister,value);

            cout << destinationRegister << " " << value << endl;

        }  
        else if (command.compare("MUL") == 0){
            
            word R1 = ram.get(pc.next());

            word R2 = ram.get(pc.next());

            int value = ((unsigned int)registers.get(R1)*registers.get((unsigned int)R2));

            registers.set((int)R1,value);

            cout << R1 << " " << value << endl;

        }  
        else if (command.compare("DIV") == 0){
            
            word R1 = ram.get(pc.next());

            word R2 = ram.get(pc.next());

            int value = ((unsigned int)registers.get(R1)/registers.get((unsigned int)R2));

            registers.set((int)R1,value);

            cout << R1 << " " << value << endl;

        }  
        else if(command.compare("NOP") == 0)
        {
            cout << endl;
        }

        currentCommand = ram.get( pc.next() );

    } while ( currentCommand != 13 );

    return 0;
}
