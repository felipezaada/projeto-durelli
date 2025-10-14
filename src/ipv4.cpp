#include <string>
#include "../include/ipv4.h"

using namespace std;

    string ipv4::to_fixed_width(int num, const int &bits) {

        string binario;

        while (num > 0) { // enquanto o número for maior de "0".
            if (num % 2 == 0) {
                binario.insert(0, "0");; // verifica se o número divido resulta em "0", caso for verdadeiro adiciona "0".
            } else {
                binario.insert(0, "1");; // caso for falso, adiciona "1".
            }
            num /= 2; // divide o quociente pro 2 e atribui o resto.
        }

        while (binario.size() < bits) { // se o tamanho de binario não for igual o tamanho de bits.
            binario.insert(0, "0");; // adiciona "0", ate que os valores se igualar.
        }

        return binario; // retorna o valor de binario.
    }

    string ipv4::ipv4_to_bin(const string& ip) { // o parâmetro é passado como constante por referência, pois não sofre alterações e, assim, evita-se a cópia desnecessária do valor.
        if (!verificar.testarEntradaIpv4(ip)) {
            return "ERRO: ENDERECO IPV4 INVALIDO! ";
        }

        string resultado;
        string parte;

        for (char c : ip) { // percorre cada caractere c da string ip.
            if (c == '.') { // verifica se o caractere atual é um ponto.
                if (stoi(parte) < 0 || stoi(parte) > 255) { // verificação se não estoura 256 ou se o valor é negativo.
                    return "ERRO: ENDERECO IPV4 INVALIDO!";
                }
                resultado += to_fixed_width(stoi(parte), 8) + "."; // converte a parte atual para binário com 8 bits e adiciona ao resultado, seguido de um ponto.
                parte = "";
            } else {
                parte += c;
            }
        }

        resultado += to_fixed_width(stoi(parte), 8);

        return resultado;
    }

    string ipv4::bin_to_ipv4(const string& bits){
        if (!verificar.testarEntradaIpv4(bits)) {
            return "ERRO: ENDERECO BINARIO INVALIDO! ";
        }

        string resultado;
        string parte;
        for(char c : bits){
            if(c == '.'){
                resultado += to_string(b.bin_to_dec(parte)) + "."; // converte a parte binária para decimal, transforma em string e adiciona ao resultado com um ponto no final.
                parte = "";
            } else {
                parte += c;
            }
        }
        resultado += to_string(b.bin_to_dec(parte)); // usamos a bin to dec para realizar a conversão sem repetir código.
        return resultado;
    }