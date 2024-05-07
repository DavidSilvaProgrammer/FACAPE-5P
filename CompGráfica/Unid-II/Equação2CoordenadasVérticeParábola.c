
#include <stdio.h>
#include <math.h>

void calcularCoordenadas(double a, double b, double c, double *x, double *y, char *direcao) {
    // Calcula as coordenadas do vértice da parábola
    *x = -b / (2 * a);
    *y = a * (*x) * (*x) + b * (*x) + c;

    // Verifica a direção da parábola
    if (a > 0) {
        *direcao = 'P'; // Positiva
    } else if (a < 0) {
        *direcao = 'N'; // Negativa
    } else {
        *direcao = 'H'; // Horizontal
    }
}

int main() {
    double a, b, c, x, y;
    char direcao;

    // Recebe os coeficientes da equação de segundo grau
    printf("Digite o coeficiente a: ");
    scanf("%lf", &a);
    printf("Digite o coeficiente b: ");
    scanf("%lf", &b);
    printf("Digite o coeficiente c: ");
    scanf("%lf", &c);

    // Calcula as coordenadas do vértice da parábola e sua direção
    calcularCoordenadas(a, b, c, &x, &y, &direcao);

    // Exibe as coordenadas do vértice e a direção da parábola
    printf("As coordenadas do vértice da parábola são: (%.2lf, %.2lf)\n", x, y);
    printf("A parábola é %s\n", direcao == 'P' ? "positiva" : direcao == 'N' ? "negativa" : "horizontal");

    return 0;
}


/*

No código fornecido, são utilizados ponteiros porque a função calcularCoordenadas 
precisa modificar múltiplos valores e retorná-los para o chamador (a função main()). 
Os ponteiros permitem que esses valores sejam passados por referência, ou seja, 
eles apontam para a localização da memória onde as variáveis estão armazenadas, 
permitindo que a função modifique esses valores diretamente.

Aqui estão os motivos pelos quais os ponteiros são usados neste caso específico:

Modificar múltiplos valores: A função calcularCoordenadas precisa calcular e retornar duas 
coordenadas (x e y) e a direção da parábola (direcao). Se apenas os valores fossem passados 
como argumentos normais, a função só seria capaz de retornar um único valor. Portanto, usar 
ponteiros permite que a função retorne múltiplos valores.
Passagem por referência: Quando você passa os valores das variáveis como ponteiros, você está 
passando a referência (o endereço de memória) onde esses valores estão armazenados, em vez de 
fazer uma cópia dos valores. Isso significa que qualquer alteração feita nos valores dessas 
variáveis dentro da função será refletida nas variáveis originais fora da função.
Eficiência: Ao passar ponteiros, você está economizando recursos de memória e tempo de execução, 
especialmente quando lidando com grandes conjuntos de dados, já que não é necessário copiar 
grandes blocos de dados.
Flexibilidade: O uso de ponteiros permite que a função seja mais flexível e reutilizável, pois 
ela pode ser usada para modificar variáveis de qualquer tipo de dados, não apenas os tipos 
específicos usados neste exemplo.
Em resumo, o uso de ponteiros neste código permite uma comunicação eficiente e flexível 
entre a função calcularCoordenadas e a função main(), garantindo que os valores calculados 
pela função sejam retornados corretamente para o programa principal.

*/
