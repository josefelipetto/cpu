#include "Flag.h"

Flag::Flag(int init_addr) {
    value = init_addr;
}

void Flag::set(int addr) {
    value = addr;
}

int Flag::get() {
    return value;
}
