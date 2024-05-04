#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846

float rotation = 0.0; // Variável para controlar a rotação

void Inicializa(void) {
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 10.0, 0.0, 10.0); 
}

// Função para desenhar um losango
void DesenhaLosango(float x, float y, float size, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
        glVertex2f(x - size / 2, y);
        glVertex2f(x, y + size / 2);
        glVertex2f(x + size / 2, y);
        glVertex2f(x, y - size / 2);
    glEnd();
}

// Função de desenho
void Desenha(void) {
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Define a cor de desenho: azul
    glColor3f(0, 0, 1);
    
    // Desenha o hexágono externo
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0, 7.0);
        glVertex2f(6.0, 7.0);
        glVertex2f(8.0, 5.0);
        glVertex2f(6.0, 3.0);
        glVertex2f(3.0, 3.0);
        glVertex2f(1.0, 5.0);
    glEnd();

    // Cores dos losangos
    float colors[6][3] = {
        {1.0, 0.0, 0.0}, // Vermelho
        {1.0, 1.0, 0.0}, // Amarelo
        {0.0, 1.0, 0.0}, // Verde
        {0.0, 1.0, 1.0}, // Ciano
        {0.0, 0.0, 1.0}, // Azul
        {1.0, 0.0, 1.0}  // Magenta
    };

    // Desenha os losangos internos
    float size = 1.0; // Tamanho do losango
    int i;
    for (i = 0; i < 6; ++i) {
        float theta = 2.0 * PI * (i * 60.0 + rotation) / 360.0;
        float x = 5.0 + 2.5 * cos(theta);
        float y = 5.0 + 2.5 * sin(theta);
        DesenhaLosango(x, y, size, colors[i][0], colors[i][1], colors[i][2]);
    }
    
    // Executa os comandos OpenGL
    glFlush();
}

// Função de controle do teclado
void Teclado (unsigned char key, int x, int y){
    switch(key) {
        case 'a':
        case 'A':
            rotation += 5.0; // Rotaciona para a esquerda
            break;
        case 'd':
        case 'D':
            rotation -= 5.0; // Rotaciona para a direita
            break;
        case 27: // Tecla Esc
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Hexágono com Losangos Animados");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
