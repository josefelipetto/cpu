#ifndef CPU_FLAG_H
#define CPU_FLAG_H


class Flag final{

public:

    Flag();

    void set(int addr);

    int get();

private:

    int value;
};

#endif
