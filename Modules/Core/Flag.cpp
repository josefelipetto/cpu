#include "Flag.h"

Flag::Flag() {
    value = 0;
}

void Flag::set(int val) {
    value = val;
}

int Flag::get() {
    return value;
}
