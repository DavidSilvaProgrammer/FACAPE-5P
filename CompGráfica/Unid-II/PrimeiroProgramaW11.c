#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>

void Inicializa (void)
{
// Define a cor de fundo da janela de visualização como preta
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

//Acrescentar na função inicializa:
// Define a janela de visualização 2D
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

// Função callback chamada para fazer o desenho

void Desenha(void)
{
/*

Acrescentar na função desenha entre:
glClear(GL_COLOR_BUFFER_BIT)
...
glFlush();

*/

//Limpa a janela de visualização com a cor de fundo especificada
glClear(GL_COLOR_BUFFER_BIT);

// Define a cor de desenho: vermelho
glColor3f(1,0,0);
// Desenha um triângulo no centro da janela
glBegin(GL_TRIANGLES);
glVertex3f(2.0, 2.0, 0);
glVertex3f(6.0, 2.0, 0);
glVertex3f(4.0, 6.0, 0);
glEnd();


//Executa os comandos OpenGL
glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
if (key == 27)
exit(0);

}


int main(void)
{
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("Primeiro Programa");
glutDisplayFunc(Desenha);
Inicializa();
glutKeyboardFunc (Teclado);
glutMainLoop();

}
