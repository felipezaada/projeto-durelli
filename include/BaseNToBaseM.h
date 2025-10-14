#pragma once
#include <iostream>
#include <string>
#include "verificaEntrada.h"

using namespace std;

class baseNToBaseM {
    verificaEntrada verificar;
public:
    int charToValue(char c);
    char valueToChar(const int v);
    int toDecimal(string num, int base_from);
    string fromDecimal(int decimal, int base_to);
    string convert_base(string num, int base_from, int base_to);
};