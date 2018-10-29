//
// Created by josefelipetto on 27/10/18.
//

#ifndef CPU_CACHE_H
#define CPU_CACHE_H

#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include "../RAM/RAM.h";

typedef int word;

using namespace std;

class Cache final {

public:

    Cache(int aCacheSize, int aCacheLineSize, RAM * mainMemory, unsigned int init_addr);

    word get(unsigned int memoryAddress );

    void set(unsigned int memoryAddress, word content);

private:

    vector< map<unsigned int, vector<word> > > lines;

    int cacheSize;

    int cacheLineSize;

    Ram * ram;

    unsigned int s;

    unsigned int r;

    unsigned int t;

    unsigned int w;

    void decodeAddress( unsigned int memoryAddress );

};

#endif //CPU_CACHE_H