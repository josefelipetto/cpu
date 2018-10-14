//
// Created by josefelipetto on 13/10/18.
//

#include "MemoryCell.h"

MemoryCell::MemoryCell(unsigned int inputAddr, word inputContent) {
    addr = inputAddr;
    content = inputContent;
}

unsigned int MemoryCell::getAddr() {
    return addr;
}

word MemoryCell::getContent() {
    return content;
}

void MemoryCell::set(word value) {
    content = value;
}

