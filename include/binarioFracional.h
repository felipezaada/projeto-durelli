#pragma once
#include <string>
#include "verificaEntrada.h"
#include "binario.h"

using namespace std;

class binarioFracional {
    verificaEntrada verificar;
    binario b;
public:
    float binfrac_to_dec(string b);
    string decfraq_to_bin(float n, int bits);
};