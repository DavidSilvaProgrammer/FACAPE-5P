#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void Inicializa(void) {
    //Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    
}

//Função callback chamada para fazer desenho
void Desenha(void) {
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Executa os comandos OpenGL
    glFlush();
}

//Programa Principal
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Primeiro Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
    
    return 0;
}
