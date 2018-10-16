#ifndef CPU_FLAG_H
#define CPU_FLAG_H


class Flag final{

public:

    Flag(unsigned int init_addr);

    void set(unsigned int addr);

    int get();

private:

    unsigned int value;
};

#endif
