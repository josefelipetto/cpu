//
// Created by josefelipetto on 05/11/18.
//

#include "LogicalAddress.h"

LogicalAddress::LogicalAddress(unsigned int memoryAddress) {

    s = memoryAddress & 0b1111111111111111111111111111111111111111111111111111111111000000;

    r = s & 0b0000000000000000000000000000000000000000000000000001111111000000;

    r /= (pow(2,6));

    t = s & 0b1111111111111111111111111111111111111111111111111110000000000000;

    t /= pow(2,13);

    w = memoryAddress & 0b0000000000000000000000000000000000000000000000000000000000111111;

}

unsigned int LogicalAddress::R() {
    return r;
}

unsigned int LogicalAddress::S() {
    return s;
}

unsigned int LogicalAddress::T() {
    return t;
}

unsigned int LogicalAddress::W() {
    return w;
}
