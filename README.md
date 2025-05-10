# Rede Neural XOR - Implementação em C++

Esta é uma implementação simples de uma **rede neural artificial** utilizando **propagação para frente (feedforward)** e **retropropagação (backpropagation)** para aprender a função lógica XOR. A rede é composta por uma camada de entrada, uma camada oculta e uma camada de saída.

A rede utiliza a função de ativação **sigmoide** e foi treinada com o algoritmo de aprendizado **gradiente descendente**.

## Funcionalidades

- **Função XOR**: A rede neural é treinada para aprender a função XOR, que gera a seguinte tabela de verdade:

  | Entrada A | Entrada B | Saída (A XOR B) |
  |-----------|-----------|-----------------|
  | 0         | 0         | 0               |
  | 0         | 1         | 1               |
  | 1         | 0         | 1               |
  | 1         | 1         | 0               |

- **Estrutura da Rede Neural**:
  - 2 neurônios na camada de entrada.
  - 2 neurônios na camada oculta.
  - 1 neurônio na camada de saída.

- **Treinamento**: A rede é treinada por 10.000 épocas usando a **função de erro quadrático médio** e o **algoritmo de retropropagação**.
  
- **Função de Ativação**: A rede usa a função de ativação sigmoide, que é comumente utilizada em redes neurais para problemas de classificação binária.

## Como Usar

### Requisitos

- **Compilador C++**: O código foi escrito em C++ e usa a biblioteca [Eigen](https://eigen.tuxfamily.org/dox/) para álgebra linear.
- **Biblioteca Eigen**: Instale a biblioteca Eigen no seu sistema para compilar o código.

### Compilação

1. Baixe o código fonte e a biblioteca Eigen.
2. Compile o código utilizando um compilador C++ (por exemplo, `g++`):

   ```bash
   g++ -o rede_XOR rede_XOR.cpp -I /path/to/eigen
