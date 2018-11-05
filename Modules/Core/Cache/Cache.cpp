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

    LogicalAddress logicalAddress(memoryAddress);

    Cacheline cacheLine = lines[logicalAddress.R()];

    if(cacheLine.getTag() == logicalAddress.T()) // Cache hit!
    {
        return cacheLine.getLine()[logicalAddress.W()];
    }

    cout << "\nCache miss" << endl;

    copyToMemory(logicalAddress);

    return memoryToCache(logicalAddress);

}

void Cache::set(unsigned int memoryAddress, word content) {

    LogicalAddress logicalAddress(memoryAddress);

    Cacheline cacheline = lines[logicalAddress.R()];

    if(cacheline.getTag() != logicalAddress.T())
    {
        cout << "\nCache miss" << endl;

        copyToMemory(logicalAddress);

        memoryToCache(logicalAddress);
    }

    vector < word > aux = lines[logicalAddress.R()].getLine();

    aux[logicalAddress.W()] = content;

    lines[logicalAddress.R()].setTag(logicalAddress.T());

    lines[logicalAddress.R()].setLine(aux);

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

void Cache::copyToMemory(LogicalAddress logicalAddress) {

    Cacheline cacheToMem = lines[logicalAddress.R()];

    if( cacheToMem.getTag() != -1 ) // Se o conteúdo da cache não foi setado, não transfere
    {
        unsigned int memAddr = logicalAddress.T();

        showBinary(memAddr);

        memAddr = ( memAddr  << 6 ) | logicalAddress.R();

        showBinary(memAddr);

        memAddr = ( memAddr << 7 );

        showBinary(memAddr);

        for(unsigned int i = memAddr, x = 0; i < memAddr + cacheLineSize - 1; ++i, ++x )
        {
            ram->set(i,cacheToMem.getLine()[x]);
        }
    }

}

word Cache::memoryToCache(LogicalAddress logicalAddress) {

    vector<word> aux;

    for(unsigned int i = logicalAddress.S(); i < logicalAddress.S() + cacheLineSize - 1; ++i)
    {
        aux.push_back(ram->get(i));
    }

    lines[logicalAddress.R()].setTag(logicalAddress.T());

    lines[logicalAddress.R()].setLine(aux);

    return lines[logicalAddress.R()].getLine()[logicalAddress.W()];

}
