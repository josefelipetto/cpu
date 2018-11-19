//
// Created by josefelipetto on 18/11/18.
//

#include <iostream>
#include <fstream>
#include "Modules/RAM/RAM.h"
#include "Modules/Helpers/Opcodes.h"
#include "Modules/Core/CPU.h"
#include <string>
#include <thread>
#include <vector>

using namespace std;

// RAM
typedef int word;

int main() {

    Opcodes opcodes("OPCODES.esym");

    RAM ram((unsigned int)16*1024*1024);

    unsigned int INIT_ADDR = 0;

    unsigned int HALT = 1;

    unsigned int numberOfCores = 0;

    cout << "Digite o número de CPUs desejado:( Valor entre 1 e 32) " << endl;

    cin >> numberOfCores;

    if(numberOfCores < 1 || numberOfCores > 32)
    {
        cout << " Numero de CPUs deve estar entre 1 e 32" << endl;
        return -1;
    }

    vector<thread> cores;

    vector<CPU> cpus;

    // Basic cores setup
    for(unsigned int i = 0; i < numberOfCores; ++i)
    {
        string codeName;
        unsigned int INIT_ADDR;

        cout << " =============== SETUP CORE " << i << " ====================== " << endl;
        cout <<  " Code file : ";
        cin >> codeName;
        cout << "\n Init address : ";
        cin >> INIT_ADDR;
        cout << " =================================================== \n " << endl;

        ifstream * code = new ifstream(codeName);

        CPU cpu(&ram,INIT_ADDR,&opcodes,"REGCODES.esym",code,i);

        cpus.push_back(cpu);
    }

    for(auto& cpu : cpus)
    {
        cores.push_back(thread(&CPU::init,&cpu));
    }

    for(auto& core : cores)
    {
        core.join();
    }




}

