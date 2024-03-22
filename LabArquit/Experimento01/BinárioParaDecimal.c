#include <stdio.h>
#include <math.h> // Incluindo a biblioteca math para usar a função pow()

// Função para converter um número binário para decimal
int binario_para_decimal(const char *binario) {
    int decimal = 0;
    int tamanho = 0;

    // Calcula o tamanho da string binária
    while (binario[tamanho] != '\0') {
        tamanho++;
    }

    // Converte cada dígito binário para decimal e soma
    for (int i = 0; i < tamanho; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, tamanho - 1 - i);
        } else if (binario[i] != '0') {
            printf("Número binário inválido.\n");
            return -1; // Retorna -1 em caso de erro
        }
    }

    return decimal;
}

int main() {
    char binario[32]; // Array para armazenar o número binário
    int decimal;

    // Solicita ao usuário que insira o número binário
    printf("Digite um número binário: ");
    scanf("%s", binario);

    // Chama a função para converter binário para decimal
    decimal = binario_para_decimal(binario);

    // Verifica se a conversão foi bem-sucedida
    if (decimal != -1) {
        printf("O número decimal correspondente é: %d\n", decimal);
    }

    return 0;
}
