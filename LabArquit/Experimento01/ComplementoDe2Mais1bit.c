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


/*
Ambas as operações complemento += 1 e complemento <<= 1 são utilizadas para alterar o valor da variável 
complemento. No entanto, elas realizam operações diferentes:

    complemento += 1: Esta operação adiciona 1 ao valor atual de complemento. 
    Em termos de bits, isso equivale a adicionar 1 ao valor binário representado por complemento. 
    Por exemplo, se complemento for 5, então complemento += 1 resultará em complemento sendo igual a 6.

    complemento <<= 1: Esta operação faz um deslocamento de bits para a esquerda em complemento em uma 
    posição. Isso é equivalente a multiplicar o valor atual de complemento por 2. Em termos de bits, cada 
    bit em complemento é movido uma posição para a esquerda, e um novo bit é adicionado à direita, com 
    um valor de 0. Por exemplo, se complemento for 5 (binário: 00000101), então complemento <<= 1 resultará 
    em complemento sendo igual a 10 (binário: 00001010).

No contexto da conversão para complemento de dois, ambas as operações são comumente usadas para ajustar o 
valor do número negativo conforme necessário. A operação += 1 é usada para adicionar o 1 ao número invertido, 
enquanto <<= 1 é usada para adicionar o bit de sinal.

*/
