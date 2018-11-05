//
// Created by josefelipetto on 27/10/18.
//

#ifndef CPU_CACHE_H
#define CPU_CACHE_H

#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include "../RAM/RAM.h"
#include "Cacheline.h"
#include <bitset>

typedef int word;

using namespace std;

class Cache final {

public:

    Cache(RAM * mainMemory, unsigned int init_addr);

    word get(unsigned int memoryAddress );

    void set(unsigned int memoryAddress, word content);

    void debug();

private:

    vector< Cacheline > lines;

    int cacheSize = 8192;

    int cacheLineSize = 64;

    RAM * ram;

    unsigned int s;

    unsigned int r;

    unsigned int t;

    unsigned int w;

    void decodeAddress( unsigned int memoryAddress );

    Cacheline findT(unsigned int t);

    unsigned int initAddr;

    void showBinary(int number);

    void copyToMem();

    word memToCache();
};

#endif //CPU_CACHE_H