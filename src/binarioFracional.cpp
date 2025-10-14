#include <iostream>
#include <cmath>
#include <string>
#include "../include/binarioFracional.h"

using namespace std;

    float binarioFracional::binfrac_to_dec(string b) {
        if (!verificar.testarBinarioFracional(b)) { // verifica se possue valores diferentes de '1', '0', '.' e '-'.
            cout << "ERRO: VALOR INVALIDO! ";
            return -1;
        }

        int posicaoPonto = 0;
        unsigned tamanhoString = 0;
        float resultadoAntesPonto = 0;
        float resultadoDepoisPonto = 0;

        tamanhoString = b.length();

        for (int i = 0; i < tamanhoString; i++) {
            if (b[i] == '.') {
                posicaoPonto = i;
            }
        }

        for (int i = 0; i < tamanhoString; i++) {
            if (i < posicaoPonto) {
                resultadoAntesPonto += static_cast<float>((b[i] - '0') * pow(2, posicaoPonto - i - 1));
                // mesma lógica que os hexadecimais, porém usamos esse casting para evitar um warning (pois b[i] - '0' retorna int).
            }else if (i > posicaoPonto) {
                resultadoDepoisPonto += static_cast<float>((b[i] - '0') * pow(2, posicaoPonto - i));
            }
        }

        return resultadoAntesPonto + resultadoDepoisPonto;
    }

    string binarioFracional::decfraq_to_bin(float n, int bits) {
        verificar.testarDecimalFracional(n); // verificar negativos ou valores iguais a 0.
        int parteInteira = static_cast<int>(n); // casting usando para pegar só a parte inteira.
        float parteDecimal = n - static_cast<float>(parteInteira);
        string decimalConvertido;

        while (bits > 0 && parteDecimal != 0.0) { // usado para só realizar as contas até o limite definido por precisão (ou até o fim do número).
            decimalConvertido += to_string(static_cast<int>(parteDecimal * 2));
            parteDecimal = parteDecimal * 2 - static_cast<float>(static_cast<int>(parteDecimal * 2));
            bits -= 1;
        }

        return b.dec_to_bin(parteInteira) + '.' + decimalConvertido;
    }
