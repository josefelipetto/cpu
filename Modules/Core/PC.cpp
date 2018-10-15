//
// Created by josefelipetto on 14/10/18.
//

#include "PC.h"

PC::PC(unsigned int init_addr) {
    value = init_addr;
}

unsigned int PC::next() {
    value += 1;
    return value;
}

void PC::set(unsigned int addr) {
    value = addr;
}

