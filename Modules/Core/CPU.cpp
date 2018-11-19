//
// Created by josefelipetto on 18/11/18.
//

#include "CPU.h"

CPU::CPU(RAM *_ram, unsigned int initAddr, Opcodes * _opcodes, string regCodesFile, ifstream * program,int cpuNumber) {

    INIT_ADDR = initAddr;

    Loader loader(initAddr,program,_ram);

    opcodes = _opcodes;

    registers = new Registers(regCodesFile);

    pc = new PC(initAddr);

    flag = new Flag;

    cache = new Cache(_ram,cpuNumber);

    id = cpuNumber;
}

int CPU::init() {

    // start executing main workflow
    unsigned int currentCommand = cache->get(INIT_ADDR);

    do {

        // Decode
        string command = opcodes->getCommand(currentCommand);

        // cout << pc->get() << " " << command << " ";

        if(command.compare("MOV_RR") == 0)
        {
            // fetch
            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            // handle
            registers->set((unsigned int)R1,registers->get((unsigned int) R2));

            // cout << R1 << " " << R2 << endl;

        }
        else if(command.compare("MOV_RM") == 0)
        {

            // fetch
            word R1 = cache->get(pc->next());

            word memoryAddress = cache->get(pc->next());

            //handle
            registers->set(R1,cache->get( (unsigned int) memoryAddress ));

            // cout << R1 << " " << "[" << memoryAddress << "]" << endl;
        }
        else if(command.compare("MOV_MR") == 0 )
        {
            unsigned int destination = cache->get(pc->next());

            word sourceRegister = cache->get(pc->next());

            cache->set(destination, registers->get(sourceRegister));

            // cout << "[" << destination << "] " << sourceRegister << endl;
        }
        else if(command.compare("MOV_RI") == 0)
        {
            word destinationRegister = cache->get(pc->next());

            word value = cache->get(pc->next());

            registers->set(destinationRegister,value);

            // cout << destinationRegister << " " << value << endl;
        }
        else if(command.compare("MOV_MI") == 0)
        {
            unsigned int destination = cache->get(pc->next());

            word value = cache->get(pc->next());

            cache->set(destination,value);

            // cout << "[" << destination << "] " << value << endl;
        }
        else if(command.compare("ADD") == 0){

            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            int value = registers->get((unsigned int)R1)+registers->get((unsigned int)R2);

            registers->set((int)R1,value);

            //print the result of the sum
            // cout << R1 << " " << registers->get(R1) << endl;
        }
        else if(command.compare("SUB") == 0){

            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            // cout << R1 << " " << R2 << endl;

            int value = registers->get((unsigned int)R1)-registers->get((unsigned int)R2);

            registers->set((int)R1,value);

        }
        else if(command.compare("CMP") == 0){

            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            int value = registers->get((unsigned int)R1)-registers->get((unsigned int)R2);

            flag->set(value);

            // cout << R1 << " " << R2 << endl;
        }
        else if(command.compare("JMP") == 0){

            unsigned int jumpValue = cache->get(pc->next());

            // jump a specific number of commands
            pc->set(jumpValue-1);

            // cout << jumpValue << endl;

        }
        else if(command.compare("JZ") == 0){

            word offset = cache->get(pc->next());

            int flagChecker = flag->get();

            // cout << offset << endl;

            // conditional jump
            if(flagChecker==0)
                pc->set( offset - 1 );

            // cout << pc->get() << endl;
        }
        else if(command.compare("JG") == 0){

            word offset = cache->get(pc->next());

            int flagChecker = flag->get();

            // cout << offset << endl;

            if(flagChecker>0)
                pc->set( offset - 1 );

            // cout << pc->get() << endl;
        }
        else if (command.compare("JL") == 0){

            word offset = cache->get(pc->next());

            int flagChecker = flag->get();

            // cout << offset << endl;

            if(flagChecker < 0)
                pc->set( offset - 1 );

        }
        else if (command.compare("OUT") == 0){

            word destinationRegister = cache->get(pc->next());

            int regValue = registers->get(destinationRegister);

            // cout << (unsigned int)destinationRegister << endl;

            cout << " \n CPU " <<  id << " -> OUT " << regValue << endl;

        }
        else if (command.compare("INC") == 0){

            word destinationRegister = cache->get(pc->next());

            int value = registers->get((unsigned int)destinationRegister)+1;

            registers->set(destinationRegister,value);

            // cout << destinationRegister << " " << value << endl;

        }
        else if (command.compare("DEC") == 0){

            word destinationRegister = cache->get(pc->next());

            int value = registers->get((unsigned int)destinationRegister)-1;

            registers->set(destinationRegister,value);

            // cout << destinationRegister << " " << value << endl;

        }
        else if (command.compare("MUL") == 0){

            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            // cout << R1 << " " << R2 << endl;

            int value = ((unsigned int)registers->get(R1)*registers->get((unsigned int)R2));

            registers->set((int)R1,value);

        }
        else if ( command.compare("DIV") == 0 ){

            word R1 = cache->get(pc->next());

            word R2 = cache->get(pc->next());

            // cout << R1 << " " << R2 << endl;

            int value = ((unsigned int)registers->get(R1)/registers->get((unsigned int)R2));

            registers->set((int)R1,value);

        }
        else if(command.compare("NOP") == 0)
        {

        }

        currentCommand = cache->get( pc->next() );


    } while ( currentCommand != 1 );

    return 0;
}

int CPU::getId() {
    return id;
}