#include <iostream>
#include <cmath>
#include <string>
#include "../include/hexadecimal.h"

using namespace std;

    string hexadecimal::dec_to_hex(int n) {
        verificar.testarValorDecimal(n); // verifica entradas negativas.
        const string valoresH = "0123456789ABCDEF";
        // valores constantes para serem usados conforme o resto da divisão por 16.
        string resultadoString;

        while (n > 0) {
            resultadoString.insert(0, string(1, valoresH[n % 16])); // insere o caractere referente ao resto de "n" % 16, podendo ser 0-9 ou A-F.
            n /= 16;
        }
        return resultadoString;
    }

    int hexadecimal::hex_to_dec(string h) {
        if (!verificar.testarHexadecimal(h)){ // testa as entradas e faz tratamento, caso sejam letras minúsculas ou negativos.
            cout << "ERRO: VALOR INVALIDO! ";
            return -1;
        }

        unsigned int tamanhoString = 0;
        // utilizamos unsigned, visando tratar um warning (.length() é sempre >= 0).
        int resultadoInteiro = 0;

        tamanhoString = h.length();

        for (int i = 0 ; i < tamanhoString; i++) {
            if (h[i] >= '0' && h[i] <= '9') {
                resultadoInteiro += (h[i] - '0') * static_cast<int>(pow(16, tamanhoString - i - 1));
                // adiciona valores conforme o valor real do char na posição h[i] (h[0] - '0') * 16 elevado a posição
                // em que o número se encontra (usamos esse índice, pois contamos da direita para esquerda, além de tratar de um vetor).
            }else if (h[i] >= 'A' && h[i] <= 'F') {
                resultadoInteiro += (h[i] - 'A' + 10) * static_cast<int>(pow(16, tamanhoString - i - 1));
            }
        }
        return resultadoInteiro;
    }