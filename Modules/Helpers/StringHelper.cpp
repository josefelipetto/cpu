//
// Created by josefelipetto on 14/10/18.
//

#include "StringHelper.h"

vector<string> StringHelper::split(const string &s, char delimeter) {

    vector<string> tokens;

    string token;

    istringstream tokenStream(s);

    while(getline(tokenStream, token, delimeter)){
        tokens.push_back(token);
    }

    return tokens;
}
