#pragma once
#include <string>
#include "verificaEntrada.h"

using namespace std;

class hexadecimal {
    verificaEntrada verificar;
public:
    string dec_to_hex(int n);
    int hex_to_dec(string h);
};