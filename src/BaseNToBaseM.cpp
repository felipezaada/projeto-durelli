#include <iostream>
#include <string>
#include "../include/BaseNToBaseM.h"

using namespace std;

    int baseNToBaseM::charToValue(char c) { // converte os valores de CHAR em inteiro (considera minúsculas).
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        return -1;
    }

    char baseNToBaseM::valueToChar(const int v) { // converte os valores de inteiro para CHAR.
        if (v < 10) return v + '0';
        return v - 10 + 'A';
    }

    int baseNToBaseM::toDecimal(string num, int base_from) {
        if (base_from < 2 || base_from > 36) { // testa se a base é válida.
            cout << "ERRO: BASE INVALIDA (MENOR QUE 2 OU MAIOR QUE 36) ";
            return -1;
        }

        verificar.testarValorString(num); // verifica se a string é negativa e trata a mesma.
        int decimal = 0;
        unsigned tamanho = 0;
        tamanho = num.length();

        for (int i = 0; i < tamanho; i++) {
            decimal = decimal * base_from + charToValue(num[i]);
            // forma incremental de cálculo incremental, abordamos apenas aqui, para testar.
            // calcula o valor decimal, considerando a base inserida pelo usuário.
        }

        return decimal;
    }

    string baseNToBaseM::fromDecimal(int decimal, int base_to) {
        verificar.testarValorDecimal(decimal); // verifica se o valor decimal é negativo e trata
        string resultado;

        while (decimal > 0) {
            int resto = decimal % base_to;
            resultado.insert(0, 1, valueToChar(resto)); // insere o resto na posição 0 da string
            decimal /= base_to;
        }

        return resultado;
    }

    string baseNToBaseM::convert_base(string num, int base_from, int base_to) {
        return fromDecimal(toDecimal(num, base_from), base_to);
        // chama a função toDecimal, que converte qualquer número de uma base qualquer para decimal,
        // passando como parâmetro a string "num" e a base de destino do número.
    }