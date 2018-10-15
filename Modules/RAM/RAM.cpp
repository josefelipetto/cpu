#include "RAM.h"

RAM::RAM() {

    for (unsigned int i = 0; i < RAM_SIZE ; ++i){

        MemoryCell aux(i,0);

        memoryCells.push_back(aux);
    }
}

word RAM::get(unsigned int memoryAddress) {
//    cout << memoryCells.at(memoryAddress).getAddr() << "," << memoryCells.at(memoryAddress).getContent() << endl;
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