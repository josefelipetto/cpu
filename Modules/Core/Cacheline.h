//
// Created by josefelipetto on 31/10/18.
//

#ifndef CPU_CACHELINE_H
#define CPU_CACHELINE_H

#include <vector>

typedef int word;

using namespace std;

class Cacheline final{

public:

    int getTag();

    vector < word> getLine();

    void setTag(int aTag);

    void setLine(vector<word> aux);

    bool found = true;

private:

    int tag;

    vector < word > line;

    unsigned int K = 64;

};
#endif //CPU_CACHELINE_H
