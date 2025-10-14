#pragma once
#include <string>
#include "verificaEntrada.h"

using namespace std;

class octal {
    verificaEntrada verificar;
public:
    string dec_to_oct(int n);
    int oct_to_dec(string o);
};