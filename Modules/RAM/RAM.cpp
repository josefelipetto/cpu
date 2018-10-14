#include "RAM.h"

RAM::RAM() {

    for (unsigned int i = 0; i < RAM_SIZE ; ++i){

        MemoryCell aux(i,0);

        memoryCells.push_back(aux);
    }
}

MemoryCell RAM::get(unsigned int memoryAddress) {
    return memoryCells.at(memoryAddress);
}

void RAM::set(unsigned int memoryAddress, word content) {

    memoryCells[memoryAddress].set(content);

}

void RAM::debug() {

    for(auto x : memoryCells){
        cout << x.getAddr() << "," << x.getContent() << "|" ;
    }

}