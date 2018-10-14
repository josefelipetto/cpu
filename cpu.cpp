//
// Created by josefelipetto on 08/10/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM/RAM.h"

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

//    word aux = 83;
//
//    ram.set( (unsigned int) 15999,aux);
//
//    cout << (ram.get( (unsigned int) 15999)).getAddr() << endl;


    return 0;
}

