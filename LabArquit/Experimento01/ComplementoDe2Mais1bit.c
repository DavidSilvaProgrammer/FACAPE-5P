#include <stdio.h>

// Função para converter um número negativo para complemento de dois e aumentar um bit
int complemento_de_2(int numero) {
    // Inverte todos os bits do número
    int complemento = ~numero;
    
    // Adiciona 1 ao resultado
    complemento += 1;
    
    // Adiciona um bit ao número (bit de sinal)
    complemento <<= 1;

    return complemento;
}

int main() {
    int numero = -5; // Número negativo de exemplo

    // Converte o número para complemento de dois e aumenta um bit
    int resultado = complemento_de_2(numero);

    // Imprime o resultado
    printf("O número %d em complemento de dois e aumentado um bit é: %d\n", numero, resultado);

    return 0;
}
