//
// Created by josefelipetto on 14/10/18.
//

#ifndef CPU_STRINGHELPER_H
#define CPU_STRINGHELPER_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class StringHelper final{

public:
    vector<string> split(const string &s, char delimeter);

};

#endif //CPU_STRINGHELPER_H
