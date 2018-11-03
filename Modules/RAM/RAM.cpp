#include "RAM.h"

RAM::RAM(unsigned int aRamSize) {

    ramSize = aRamSize;

    for (unsigned int i = 0; i < ramSize ; ++i){

        MemoryCell aux(i,1);

        memoryCells.push_back(aux);
    }
}

word RAM::get(unsigned int memoryAddress) {

    return memoryCells.at(memoryAddress).getContent();
}

void RAM::set(unsigned int memoryAddress, word content) {

    memoryCells[memoryAddress].set(content);
}

void RAM::debug(unsigned int begin, unsigned int iEnd) {

    for(unsigned int i = begin; i < iEnd; ++i){
        cout << memoryCells[i].getAddr() << "," << memoryCells[i].getContent() << "|" ;
    }

}

unsigned int RAM::getRamSize() {

    return ramSize;
}