#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero;

    // Solicita ao usuário que digite um número inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Calcula o dobro do número digitado
    int dobro = numero * 2;

    // Imprime o dobro do número
    printf("O dobro de %d é: %d\n", numero, dobro);
    
    
    system("PAUSE");
    return 0;
}


/*

Pode colocar também:
system("pause");
*/
