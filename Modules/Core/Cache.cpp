//
// Created by josefelipetto on 27/10/18.
//

#include "Cache.h"

Cache::Cache(RAM * mainMemory, unsigned int init_addr) {

    ram = mainMemory;

    init_addr = initAddr;

    for (unsigned int i = 0; i < (cacheSize/cacheLineSize); ++i)
    {
        vector < word > aux(cacheLineSize,0);

        Cacheline cacheline;
        cacheline.setTag(-1);
        cacheline.setLine(aux);

        lines.push_back(cacheline);
    }

}

word Cache::get(unsigned int memoryAddress) {

    decodeAddress(memoryAddress);

    Cacheline cacheLine = lines[r];

    if(cacheLine.getTag() == t) // Cache hit!
    {
        return cacheLine.getLine()[w];
    }

    // Cache miss :(

    cout << " \n Cache miss" << endl;

    // copiar o que está na cache para a memória principal
    copyToMem();

    // Independente se é a primeira vez ou não, depois de copiar o que está na cache para memória principal,
    // temos que copiar um bloco de memória para a cache e retornar para o usuário a palavra.

    return memToCache();

}

void Cache::decodeAddress(unsigned int memoryAddress) {

    s = memoryAddress & 0b1111111111111111111111111111111111111111111111111111111111000000;

    r = s & 0b0000000000000000000000000000000000000000000000000001111111000000;

    r /= (pow(2,6));

    t = s & 0b1111111111111111111111111111111111111111111111111110000000000000;

    t /= pow(2,13);

    w = memoryAddress & 0b0000000000000000000000000000000000000000000000000000000000111111;
}

void Cache::set(unsigned int memoryAddress, word content) {

    decodeAddress(memoryAddress);

    Cacheline cacheline = lines[r];

    if(cacheline.getTag() != t)
    {
        cout << "Cache miss" << endl;

        copyToMem();

        memToCache();
    }

    vector < word > aux = lines[r].getLine();

    aux[w] = content;

    lines[r].setTag(t);

    lines[r].setLine(aux);

}

Cacheline Cache::findT(unsigned int t) {

    for(Cacheline line : lines)
    {
        if (line.getTag() == t)
            return line;
    }

    Cacheline aux;

    aux.found = false;

    return aux;
}

void Cache::debug() {

    for(Cacheline line : lines){
        cout << "T : " << line.getTag() << " \t ";
        for(word content : line.getLine())
            cout << content << " | ";
        cout << "\n ==================================================================================== " << endl;
    }
}

void Cache::showBinary(int number) {
    bitset<32> binary(number);

    cout << binary << endl;
}

void Cache::copyToMem() {

    Cacheline cacheToMem = lines[r];

    if(cacheToMem.getTag() != -1) // Se o conteúdo da cache não foi setado, não transfere
    {
        unsigned int memAddr = t;

        showBinary(memAddr);

        memAddr = ( memAddr  << 6 ) | r;

        showBinary(memAddr);

        memAddr = ( memAddr << 7 );

        showBinary(memAddr);

        for(unsigned int i = memAddr, x = 0; i < memAddr + cacheLineSize - 1; ++i, ++x )
        {
            ram->set(i,cacheToMem.getLine()[x]);
        }
    }

}

word Cache::memToCache() {

    vector<word> aux;

    for(unsigned int i = s; i < s + cacheLineSize - 1; ++i)
    {
        aux.push_back(ram->get(i));
    }

    lines[r].setTag(t);
    lines[r].setLine(aux);

    return lines[r].getLine()[w];

}
