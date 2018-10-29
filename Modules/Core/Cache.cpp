//
// Created by josefelipetto on 27/10/18.
//

#include "Cache.h"

#include <bitset>

Cache::Cache(int aCacheSize, int aCacheLineSize, RAM * mainMemory, unsigned int init_addr) {

    cacheSize = aCacheSize;

    cacheLineSize = aCacheLineSize;

    ram = *mainMemory;

}

word Cache::get(unsigned int memoryAddress) {

    decodeAddress(memoryAddress);

    if( r < lines.size() )
    {

        map< unsigned int, vector<word> >::iterator cacheLine = lines[r].find(t);

        cout << "IT: First, second " << cacheLine->first << " " << cacheLine->second << endl;

        if(cacheLine != lines.end()) // Cache hit!
        {
            return cacheLine->second[w];
        }

        // Cache miss :(

        // Se a cache já tiver dados, ou seja, senão for a primeira vez que ta rodando,
        // copiar o que está na cache para a memória principal

        if( ! cacheLines.empty() )
        {

            unsigned int memAddr = cacheLine->first;

            memAddr = ( memAddr  << 53 ) | r;

            memAddr = ( memAddr << 46 ) | 0b0000;

            for(unsigned int i = memAddr, x = 0; i < memAddr + cacheLineSize - 1; ++i, ++x )
            {
                ram->set(i, cacheLines[r].second[x]);
            }
        }

    }

    // Independente se é a primeira vez ou não, depois de copiar o que está na cache para memória principal,
    // temos que copiar um bloco de memória para a cache e retornar para o usuário a palavra.

}

void Cache::decodeAddress(unsigned int memoryAddress) {

    s = memoryAddress & 0b1111111111111111111111111111111111111111111111111111111111000000;

    r = s & 0b0000000000000000000000000000000000000000000000000001111111000000;

    r /= (pow(2,6));

    t = s & 0b1111111111111111111111111111111111111111111111111110000000000000;

    t /= pow(2,13);

    w = x & 0b0000000000000000000000000000000000000000000000000000000000111111;

}
