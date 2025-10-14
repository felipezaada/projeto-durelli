#include <iostream>
#include <cmath>
#include <string>
#include "../include/octal.h"

using namespace std;

    string octal::dec_to_oct(int n) {
        verificar.testarValorDecimal(n); // verificar negativos ou valores iguais a 0.
        string resultadoString;

        while (n >= 1) {
            resultadoString.insert(0, to_string(n % 8)); // utiliza a mesma lógica do dec to bin, adicionando os valores na posição 0 da string.
            n /= 8; // divide por 8 para entrar o novo valor no loop.
        }
        return resultadoString;
    }

    int octal::oct_to_dec(string o) {
        if (!verificar.testarOctal(o)) { // verificar se não possuem diferentes e 0-7 e '-', pois '8' não existe na base octal.
            cout << "ERRO: VALOR INVALIDO! ";
            return -1;
        }

        int resultadoInteiro = 0;
        int valorInteiro = 0;
        int aux = 0;

        valorInteiro = stoi(o);

        while (valorInteiro > 0){
            resultadoInteiro += valorInteiro % 10 * static_cast<int>(pow(8, aux)); // mesma lógica do bin to dec.
            valorInteiro /= 10;
            aux += 1;
        }
        return resultadoInteiro;
    }