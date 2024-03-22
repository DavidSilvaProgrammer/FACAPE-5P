#include <stdio.h>

// Função para converter um número inteiro para sua representação binária
void int_para_binario(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int bits[32]; // Array para armazenar os bits
    int i = 0;
    while (n > 0) {
        bits[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
}

// Função para calcular o complemento de dois de um número inteiro
void complemento_de_dois(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int bits[32]; // Array para armazenar os bits
    int i = 0;
    // Converter o número para sua representação binária normal
    while (n != 0) {
        bits[i] = n % 2;
        n = n / 2;
        i++;
    }
    // Inverter os bits
    for (int j = 0; j < i; j++) {
        bits[j] = (bits[j] == 0) ? 1 : 0;
    }
    // Adicionar 1 ao complemento invertido
    int carry = 1;
    for (int j = 0; j < i; j++) {
        bits[j] += carry;
        if (bits[j] > 1) {
            bits[j] = 0;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    // Imprimir o complemento de dois
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
}

int main() {
    int numero = 10;
    printf("Representação binária de %d: ", numero);
    int_para_binario(numero);
    printf("\nComplemento de dois de %d: ", numero);
    complemento_de_dois(numero);
    printf("\n");
    return 0;
}
