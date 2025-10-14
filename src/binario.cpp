#include "../include/binario.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

    string binario::dec_to_bin(int n) {
        verificar.testarValorDecimal(n); // verificar negativos ou valores iguais a 0.
        string resultadoString;

        while (n >= 1) { // roda até "n" chegar em 1, que seria o último dígito binário.
            resultadoString.insert(0, to_string(n % 2)); // insere na posição 0 da string o resto da divisão entre o número de entrada e 2.
            n /= 2; // divide por meio, para entrar o novo valor no loop.
        }
        return resultadoString; // retorna uma string, como solicitado.
    }

    int binario::bin_to_dec(string b) {
        if (!verificar.testarBinario(b)) { // testa a entrada binária, verifica se não possui caracteres diferentes de 0, 1 e '-'.
            cout << "ERRO: VALOR INVALIDO! ";
            return -1; // caso possua, "-1" é retornado juntamente a um erro.
        }

        int valorInteiro = 0;
        int resultadoInteiro = 0;
        int aux = 0;

        valorInteiro = stoi(b);

        while (valorInteiro > 0){
            resultadoInteiro += valorInteiro  % 10 * static_cast<int>(pow(2, aux)); // pega o último digito e multiplica por 2 elevado a aux, que vai de 0 até o tamanho do número.
            valorInteiro /= 10;
            aux += 1;
        }
        return resultadoInteiro; // retorna um int, como solicitado.
    }