#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846

void Inicializa(void) {
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Define a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 10.0, 0.0, 10.0); 
}

// Função para desenhar um losango
void DesenhaLosango(float x, float y, float size) {
    glBegin(GL_POLYGON);
        glVertex2f(x - size / 2, y);
        glVertex2f(x, y + size / 2);
        glVertex2f(x + size / 2, y);
        glVertex2f(x, y - size / 2);
    glEnd();
}

// Função callback chamada para fazer desenho
void Desenha(void) {
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Define a cor de desenho: azul
    glColor3f(0, 0, 1);
    
    // Desenha o hexágono externo
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.0, 5.0);
        glVertex2f(6.0, 7.0);
        glVertex2f(3.0, 7.0);
        glVertex2f(1.0, 5.0);
        glVertex2f(3.0, 3.0);
        glVertex2f(6.0, 3.0);
    glEnd();

    // Define a cor de desenho: verde
    glColor3f(0, 1, 0);

    // Desenha os losangos internos
    float size = 2.0; // Tamanho do losango
    DesenhaLosango(8.0, 5.0, size);
    DesenhaLosango(6.0, 7.0, size);
    DesenhaLosango(3.0, 7.0, size);
    DesenhaLosango(1.0, 5.0, size);
    DesenhaLosango(3.0, 3.0, size);
    DesenhaLosango(6.0, 3.0, size);
    
    // Executa os comandos OpenGL
    glFlush();
}

void Teclado (unsigned char key, int x, int y){
	if(key == 27){
		exit(0);
	}
}

// Programa Principal
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Hexágono com Flor");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
