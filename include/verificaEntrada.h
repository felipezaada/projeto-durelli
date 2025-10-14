#pragma once
#include <iostream>
#include <string>

using namespace std;

class verificaEntrada {
    unsigned tamanho = 0;
public:
    void testarValorString(string &stringTeste);
    void testarValorDecimal(int &decimal);
    void testarDecimalFracional(float &decimal);
    bool testarEntradaIpv4(const string &ipv4Entrada);
    bool testarBinario(string &binario);
    bool testarBinarioFracional(string &binario);
    bool testarHexadecimal(string &testarString);
    bool testarOctal(string &octal);
};