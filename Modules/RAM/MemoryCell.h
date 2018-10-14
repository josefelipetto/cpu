//
// Created by josefelipetto on 13/10/18.
//

#ifndef CPU_MEMORYCELL_H
#define CPU_MEMORYCELL_H

typedef int word;

class MemoryCell final {

public:

    unsigned int getAddr();

    word getContent();

    MemoryCell(unsigned int inputAddr, word inputContent);

    void set(word value);

private:

    unsigned int addr;

    word content;
};

#endif //CPU_MEMORYCELL_H


