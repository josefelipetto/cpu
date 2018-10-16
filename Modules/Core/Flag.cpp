#include "Flag.h"

Flag::Flag(unsigned int init_addr) {
    value = init_addr;
}

void Flag::set(unsigned int addr) {
    value = addr;
}

int Flag::get() {
    return value;
}
