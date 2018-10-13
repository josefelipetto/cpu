#include "RAM.h"

RAM::RAM() {

    for (unsigned int i = 0; i < RAM_SIZE ; ++i){

        MemoryCell aux(i,0);

        memoryCells.push_back(aux);
    }
}

void RAM::debug() {

    for(auto x : memoryCells){
        cout << x.getContent() << "|" ;
    }

}