//
// Created by josefelipetto on 14/10/18.
//

#ifndef CPU_PC_H
#define CPU_PC_H


class PC final{

public:

    unsigned int next();

    PC(unsigned int init_addr);

    void set(unsigned int addr);

    unsigned int get();

private:

    unsigned int value;
};

#endif //CPU_PC_H
