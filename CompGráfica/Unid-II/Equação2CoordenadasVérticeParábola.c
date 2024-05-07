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
