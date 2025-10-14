#pragma once
#include <iostream>
#include <string>
#include "verificaEntrada.h"

using namespace std;

class binario {
    verificaEntrada verificar;
public:
    string dec_to_bin(int n);
    int bin_to_dec(string b);
};