/*
Programa em C que implementa o algoritmo de Bresenham para desenhar uma linha em uma matriz bidimensional 
por meio de zeros e uns.
*/

#include <stdio.h>

//LINHAS e COLUNAS definem o tamanho da matriz que representa a tela onde a linha será traçada

#define LINHAS 10
#define COLUNAS 20



/*

Variáveis e seus propósitos na função do algoritmo:
    dx (diferença em x): Diferença entre as coordenadas x do ponto final e do ponto inicial.
    dy (diferença em y): Diferença entre as coordenadas y do ponto final e do ponto inicial.
    sx (incremento em x): Determina se o próximo pixel na direção x deve ser incrementado ou decrementado.
    sy (incremento em y): Determina se o próximo pixel na direção y deve ser incrementado ou decrementado.
    
        (Exemplo do uso de sx e sy:
         Se dy for negativo, significa que a linha está inclinada para baixo (de cima para baixo). 
        Nesse caso, inverte-se o sinal de dy e define sy = -1.
        Caso contrário, a linha está inclinada para cima (de baixo para cima), então sy é definido como 1.
            O mesmo raciocínio é aplicado para dx e sx.)
    
    
    erro: É uma variável usada como parâmetro para acompanhar o erro acumulado durante o desenho da linha.
    e2: É uma variável auxiliar usada para otimizar o cálculo do erro.
*/

void bresenham(int x0, int y0, int x1, int y1, int matriz[LINHAS][COLUNAS]) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int sx, sy, erro, e2;

    if (dy < 0) {
        dy = -dy;
        sy = -1;
    } else {
        sy = 1;
    }

    if (dx < 0) {
        dx = -dx;
        sx = -1;
    } else {
        sx = 1;
    }

    erro = dx - dy;
    
    
    /*Loop while  continua enquanto as coordenadas atuais (x0, y0) não coincidirem com as coordenadas 
    do ponto final (x1, y1).
    */
    while (x0 != x1 || y0 != y1) {
        
        /*O primeiro if verifica se as coordenadas atuais 
        (x0, y0) estão dentro dos limites da matriz.
        Se estiverem, o pixel correspondente na matriz é definido como parte da linha, ou seja, atribuído o valor 1.
        */
        if (x0 >= 0 && x0 < COLUNAS && y0 >= 0 && y0 < LINHAS) {
            matriz[y0][x0] = 1; // Define o pixel como parte da linha
        }
        
        /*
        Calcula-se o dobro do valor atual de erro e armazena em e2. 
        e2 é usado para tomar decisão sobre qual direção seguir (horizontal ou vertical) ao desenhar a linha.
        */
        e2 = 2 * erro;
        
        /*
        O segundo if verifica se e2 é maior que o negativo da diferença em y, se for, o próximo pixel a ser 
        pintado será na direção horizontal. Desse modo, é subtraído dy do valor de erro com o objetivo de ajustar 
        essa variável para as próximas rodadas e depois é incrementado x0 na direção especificada por sx.
        */
        if (e2 > -dy) {
            erro -= dy;
            x0 += sx;
        }
           
        /* O terceiro if verifica se e2 é menor que a diferença em x, se for, o próximo pixel a ser pintado será na 
        direção vertical. Nesse caso, adiciona-se dx ao valor de erro e incrementa y0 na direção especificada por sy.
        */
        if (e2 < dx) {
            erro += dx;
            y0 += sy;
        }
    }
}

int main() {
    int matriz[LINHAS][COLUNAS] = {0}; // Inicializa a matriz com zeros

    // Solicita os pontos inicial e final da linha ao usuário
    int x0, y0, x1, y1;
    printf("OBS: Limite de x: 0 a 19\n\tLimite de y: 0 a 9\n");
    printf("\tx pontos horizontais e y pontos verticais\n\n");
    printf("Digite as coordenadas do ponto inicial (x0 y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Digite as coordenadas do ponto final (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("\n");
    
    // Desenha a linha usando o algoritmo de Bresenham
    bresenham(x0, y0, x1, y1, matriz);

    // Imprime a matriz
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
