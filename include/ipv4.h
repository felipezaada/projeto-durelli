#pragma once
#include <string>
#include "verificaEntrada.h"
#include "binario.h"

using namespace std;

class ipv4 {
    verificaEntrada verificar;
    binario b;
public:
    static string to_fixed_width(int num, const int &bits);
    string ipv4_to_bin(const string& ip);
    string bin_to_ipv4(const string& bits);
};