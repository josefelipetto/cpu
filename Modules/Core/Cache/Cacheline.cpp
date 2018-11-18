//
// Created by josefelipetto on 31/10/18.
//

#include "Cacheline.h"

vector<word> Cacheline::getLine() {
    return line;
}

int Cacheline::getTag() {
    return tag;
}

void Cacheline::setLine(vector <word> aux) {
    line = aux;
}

void Cacheline::setTag(int aTag) {
    tag = aTag;
}

