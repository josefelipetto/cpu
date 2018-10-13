//
// Created by josefelipetto on 08/10/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM.h"

using namespace std;

// RAM
typedef int word;


//void initializeMemory(){
//
//   int addr = 0;
//
//   for( memoryCell cell : RAM){
//      cell.addr = addr;
//      cell.content = 0;
//      addr++;
//   }
//
//}

void initializeOpCodes(){

   ifstream infile("OPCODES.esym");
   string line;

   while (getline(infile,line)){

   }

}


int main(){

    RAM ram;

    ram.debug();
    return 0;
}

