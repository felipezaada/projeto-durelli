#include <iostream>
#include "../include/binario.h"
#include "../include/octal.h"
#include "../include/hexadecimal.h"
#include "../include/BaseNToBaseM.h"
#include "../include/binarioFracional.h"
#include "../include/ipv4.h"

using namespace std;

int main() {
    binario b;
    octal o;
    hexadecimal h;
    baseNToBaseM baseConverter;
    binarioFracional binFrac;
    ipv4 ip;

    int escolhaOp;
    int valorInt;
    int nBits;
    int baseN, baseM;
    float valorFloat;
    string valorString;

    cout << "===== MENU DE CONVERSAO =====" << endl;
    cout << "1. Decimal para Binario" << endl;
    cout << "2. Binario para Decimal" << endl;
    cout << "3. Decimal para Octal" << endl;
    cout << "4. Octal para Decimal" << endl;
    cout << "5. Decimal para Hexadecimal" << endl;
    cout << "6. Hexadecimal para Decimal" << endl;
    cout << "7. Base N para Base M" << endl;
    cout << "8. Binario Fracionario para Decimal Fracionario" << endl;
    cout << "9. Decimal Fracionario para Binario Fracionario" << endl;
    cout << "10. IPV4 para Binario" << endl;
    cout << "11. Binario para IPV4" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao:" << endl;
    cin >> escolhaOp;

    switch (escolhaOp) {
        case 1:
            cout << "Decimal para Binario: " << endl;
            cin >> valorInt;
            cout << "Resultado: " << b.dec_to_bin(valorInt) << endl;
            break;

        case 2:
            cout << "Binario para Decimal: " << endl;
            cin >> valorString;
            cout << "Resultado: " << b.bin_to_dec(valorString) << endl;
            break;

        case 3:
            cout << "Decimal para Octal: " << endl;
            cin >> valorInt;
            cout << "Resultado: " << o.dec_to_oct(valorInt) << endl;
            break;

        case 4:
            cout << "Octal para Decimal: " << endl;
            cin >> valorString;
            cout << "Resultado: " << o.oct_to_dec(valorString) << endl;
            break;

        case 5:
            cout << "Decimal para Hexadecimal: " << endl;
            cin >> valorInt;
            cout << "Resultado: " << h.dec_to_hex(valorInt) << endl;
            break;

        case 6:
            cout << "Hexadecimal para Decimal: " << endl;
            cin >> valorString;
            cout << "Resultado: " << h.hex_to_dec(valorString) << endl;
            break;

        case 7:
            cout << "Conversao Geral, base N para M: " << endl;
            cout << "Digite o valor que quer converter: " << endl;
            cin >> valorString;
            cout << "Digite a base N: " << endl;
            cin >> baseN;
            cout << "Digite a base M: " << endl;
            cin >> baseM;
            cout << "Resultado: " << baseConverter.convert_base(valorString, baseN, baseM) << endl;
            break;

        case 8:
            cout << "Binario Fracionario para Decimal: " << endl;
            cin >> valorString;
            cout << "Resultado: " << binFrac.binfrac_to_dec(valorString) << endl;
            break;

        case 9:
            cout << "Decimal Fracionario para Binario Fracionario: " << endl;
            cin >> valorFloat;
            cout << "Precisao de Bits: " << endl;
            cin >> nBits;
            cout << "Resultado: " << binFrac.decfraq_to_bin(valorFloat, nBits) << endl;
            break;

        case 10:
            cout << "IPV4 para Binario: " << endl;
            cin >> valorString;
            cout << "Resultado: " << ip.ipv4_to_bin(valorString) << endl;
            break;

        case 11:
            cout << "Binario para IPV4: " << endl;
            cin >> valorString;
            cout << "Resultado: " << ip.bin_to_ipv4(valorString) << endl;
            break;

        case 0:
            cout << "Saindo..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
    }

    return 0;
};