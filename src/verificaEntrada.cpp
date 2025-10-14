#include <iostream>
#include <string>
#include "../include/verificaEntrada.h"

using namespace std;

    void verificaEntrada::testarValorString(string &stringTeste) {
        // usado para verificar se é uma string negativa, caso seja, remove o '-' para facilitar a conta, e escreve um '-'.
        if (stringTeste[0] == '-') {
            cout << '-';
            stringTeste.erase(0, 1);
        }
    }

    void verificaEntrada::testarValorDecimal(int &decimal) {
        //verifica se o decimal é negativo ou igual a 0, retornado o decimal positivo, caso seja menor que 0, e escrevendo
        //'-', e escrevendo 0, caso decimal = 0.
        if (decimal < 0) {
            cout << '-';
            decimal *= -1;
        }else if (decimal == 0) {
            cout << '0';
        }
    }

    void verificaEntrada::testarDecimalFracional(float &decimal) {
        // mesma função da anterior, fizemos separada para fins didáticos, e essa recebeu float, ao invés de int.
        if (decimal < 0) {
            cout << '-';
            decimal *= -1;
        }
    }

    bool verificaEntrada::testarEntradaIpv4(const string &ipv4Entrada) {
        // utilizamos const e referência para evitar um warning, esse valor não é altero
        tamanho = ipv4Entrada.length();
        int contador = 0;

        for (int i = 0; i < tamanho; i++) {
            if (ipv4Entrada[i] == '.') {
                contador += 1; // conta quantos pontos possui o ipv4 informado.
            }
        }
        if (contador < 3 || contador > 3) { // caso tenham menos 3 pontos (1.1.1.1), é um ipv4 inválido.
            return false;
        }
        return true;
    }

    bool verificaEntrada::testarBinario(string &binario) {
        tamanho = binario.length();

        for (int i = 0; i < tamanho; i++) { // verifica se tem '-' em outra parte da string, sem ser como primeiro dígito.
            if (binario[i] == '-' && i != 0) {
                return false;
            }

            if (binario[i] != '0' && binario[i] != '1' && binario[i] != '-') { // verifica se é um binário válido.
                return false;
            }
        }
        testarValorString(binario); // serve para converter a string em positiva e escrever o '-'.
        return true;
    }

    bool verificaEntrada::testarBinarioFracional(string &binario) {
        tamanho = binario.length();

        for (int i = 0; i < tamanho; i++) { // verifica se tem '-' em outra parte da string, sem ser como primeiro dígito.
            if (binario[i] == '-' && i != 0) {
                return false;
            }

            if (binario[i] != '0' && binario[i] != '1' && binario[i] != '.' && binario[i] != '-') {
                // tem a mesma função do if do método anterior, que verifica se o número binário é válido,
                // porém este também aceita a entrada do caractere '.', para permitir números fracionários.
                return false;
            }
        }
        testarValorString(binario); // serve para converter a string em positiva e escrever o '-'.
        return true;
    }

    bool verificaEntrada::testarHexadecimal(string &testarString) {
        testarValorString(testarString); // serve para converter a string em positiva e escrever o '-'.
        tamanho = testarString.length();

        for (int i = 0; i < tamanho; i++) { // converte minúscula em maiúscula.
            if (testarString[i] >= 'a' && testarString[i] <= 'f') {
                testarString[i] = static_cast<char>(toupper(testarString[i])); // função toupper (maiúsculas).
            }

            if (!((testarString[i] >= '0' && testarString[i] <= '9') ||
                (testarString[i] >= 'A' && testarString[i] <= 'F'))) { // testa se entra dentro de 0-9 e A-F.
                return false;
            }
        }
        return true;
    }

    bool verificaEntrada::testarOctal(string &octal) {
        tamanho = octal.length();

        for (int i = 0; i < tamanho; i++) { // verifica se tem '-' em outra parte da string, sem ser como primeiro dígito
            if (octal[i] == '-' && i != 0) {
                return false;
            }

            if (!(octal[i] >= '0' && octal[i] <= '7') && octal[i] != '-') { // testa se entra dentro de 0-7, ou se é um '-'.
                return false;
            }
        }
        testarValorString(octal); // serve para converter a string em positiva e escrever o '-'.
        return true;
    }

/* alguns warnings que não tratei são aqueles que reclamam de não usarmos static em métodos que não compartilham de
atributos do objeto */