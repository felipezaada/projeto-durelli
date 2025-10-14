# Conversor de Bases Numéricas em C++

## Descrição

Este programa implementa um **conversor de bases numéricas**, permitindo conversões entre **binário, octal, decimal e hexadecimal**, incluindo suporte a **números fracionários** e endereços **IPv4**.

O código é organizado em **classes**, com funções específicas para cada tipo de conversão, garantindo modularidade e reutilização. Há também uma classe de **validação de entradas**, que garante que os valores informados pelo usuário sejam válidos antes da conversão.

---

## Funcionalidades

O programa oferece as seguintes opções no menu:

1. Decimal → Binário
2. Binário → Decimal
3. Decimal → Octal
4. Octal → Decimal
5. Decimal → Hexadecimal
6. Hexadecimal → Decimal
7. Base N → Base M
8. Binário Fracionário → Decimal Fracionário
9. Decimal Fracionário → Binário Fracionário
10. IPv4 → Binário
11. Binário → IPv4
0. Sair

---

## Exemplos de Conversão

| Conversão                     | Exemplo de Entrada                    | Saída Esperada                        |
| ----------------------------- | ------------------------------------- | ------------------------------------- |
| Decimal → Binário             | `13`                                  | `1101`                                |
| Binário → Decimal             | `1011`                                | `11`                                  |
| Decimal → Octal               | `25`                                  | `31`                                  |
| Octal → Decimal               | `17`                                  | `15`                                  |
| Decimal → Hexadecimal         | `255`                                 | `FF`                                  |
| Hexadecimal → Decimal         | `1F`                                  | `31`                                  |
| Binário Fracionário → Decimal | `101.101`                             | `5.625`                               |
| Decimal Fracionário → Binário | `5.625`                               | `101.101`                             |
| IPv4 → Binário                | `192.168.0.1`                         | `11000000.10101000.00000000.00000001` |
| Binário → IPv4                | `11000000.10101000.00000000.00000001` | `192.168.0.1`                         |

---

### Precisão nas Conversões Fracionárias

Na conversão **Decimal Fracionário → Binário Fracionário**, o usuário pode definir **quantos bits após o ponto** deseja obter. Isso é útil para limitar ou expandir a precisão da parte fracionária.

**Exemplo:**

| Entrada | Bits Fracionários | Saída Esperada |
| ------- | ----------------- | -------------- |
| `0.625` | 3                 | `0.101`        |
| `0.625` | 5                 | `0.10100`      |
| `0.1`   | 8                 | `0.00011001`   |

> ⚙️ **Dica:** quanto mais bits fracionários forem usados, maior a precisão — porém também aumenta o tamanho da representação binária.

## Estrutura do Código

O código é organizado em **funções e classes**:

### Funções de conversão

```cpp
string dec_to_bin(int n);
int bin_to_dec(string b);
float binfrac_to_dec(string b);
string decfraq_to_bin(float n, int bits);
string dec_to_hex(int n);
int hex_to_dec(string h);
string dec_to_oct(int n);
int oct_to_dec(string o);
string ipv4_to_bin(const string& ip);
string bin_to_ipv4(const string& bits);
```

### Classe de validação (`verificaEntrada`)

* `testarValorString`, `testarValorDecimal`, `testarDecimalFracional` → tratam valores negativos e zero
* `testarEntradaIpv4` → valida formato IPv4
* `testarBinario` → valida binário simples
* `testarBinarioFracional` → valida binário fracionário
* `testarHexadecimal` → valida valores hexadecimais
* `testarOctal` → valida valores octais

---

## Funções e Métodos do C++ Utilizados

* **`stoi` e `to_string`**

    * `stoi` converte string para inteiro.
    * `to_string` converte inteiro ou float para string.
    * Usados em conversões entre tipos de dados.

* **`length()`**

    * Retorna o tamanho de uma string.
    * Usado em loops de validação ou para percorrer caracteres.

* **`toupper`**

    * Converte caracteres minúsculos em maiúsculos.
    * Usado para normalizar entradas hexadecimais (`a-f` → `A-F`).

* **`string.insert(pos, valor)`**

    * Insere um valor em uma posição específica da string.
    * Fundamental ao construir representações binárias, hexadecimais ou octais **de trás para frente**, mantendo a ordem correta.

* **`const`**

    * Define variáveis **constantes** cujo valor não pode ser alterado.
    * Exemplo:

```cpp
const string valores = "0123456789ABCDEF";
```

* Utilizado para armazenar os caracteres válidos de conversão hexadecimal, garantindo segurança e legibilidade do código.

* **`#pragma once`**

    * Diretiva usada em **arquivos de cabeçalho (.h)**.
    * Garante que o arquivo seja incluído **apenas uma vez** durante a compilação, evitando **redefinições** e **conflitos de múltiplas inclusões**.

* **`return -1`**

    * Utilizado para **indicar erros** e interromper a execução da função atual.
    * Exemplo:

```cpp
if (!verificar.testarBinario(b)) {
    cout << "Erro: entrada inválida!" << endl;
    return -1;
}
```

---

## Requisitos

* Compilador C++ (recomendado g++ 9.0+)
* Sistema operacional compatível (Windows, Linux e Mac OS)
* Bibliotecas padrão: `<iostream>`, `<string>`, `<cmath>`

## Execução

Antes de executar, é necessário ter instalado:

* **CMake**
* **Compilador C++** (g++, clang ou Visual Studio)

---

## Como Compilar e Executar (CMake)

### 1. Criar a pasta de build

```bash
cd projeto
mkdir build
cd build
```

### 2. Gerar arquivos de compilação

```bash
cmake ..
```

### 3. Compilar o projeto

```bash
cmake --build .
```

Isso criará o executável dentro da pasta `build/`.

### 4. Executar o programa

```bash
./nome_do_executavel   # Linux/macOS
nome_do_executavel.exe # Windows
```

O programa exibirá o menu interativo com as opções de conversão.

---

## Autor

**Felipe Eduardo e Pedro Castro**
Outubro de 2025
Projeto de prática em C++ — Conversões de Bases Numéricas

---

## Agradecimentos

Durante o desenvolvimento do projeto, tivemos que utilizar a criatividade para buscar soluções limpas e funcionais para os problemas. Foi muito interessante aprofundar nossos conhecimentos na linguagem de programação C++ (escolhida por nós) e aprimorar nossa lógica de programação, uma vez que ela também é cobrada em outras disciplinas do curso. Agradecemos pelo conhecimento transmitido em aula, que foi fundamental para transformar a lógica do papel em código executável. Pedimos desculpas por não conseguirmos resolver o desafio bônus; nossa dupla teve pouco tempo devido ao trabalho, mas nos esforçamos para, dentro das limitações, entregar um código funcional e bem estruturado. Abraços, Felipe e Pedro.