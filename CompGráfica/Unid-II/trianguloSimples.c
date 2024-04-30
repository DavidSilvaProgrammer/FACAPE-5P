#include <GL/glut.h>

// Função para desenhar o triângulo
void drawTriangle() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor
    glBegin(GL_TRIANGLES); // Começa a desenhar triângulos
    // Define os vértices do triângulo
    glVertex2f(0.0f, 0.5f);    // Vértice superior
    glVertex2f(-0.5f, -0.5f);  // Vértice inferior esquerdo
    glVertex2f(0.5f, -0.5f);   // Vértice inferior direito
    glEnd(); // Termina de desenhar triângulos
    glFlush(); // Força a execução dos comandos OpenGL
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutCreateWindow("Triângulo OpenGL"); // Cria a janela com o título especificado
    glutDisplayFunc(drawTriangle); // Define a função de desenho
    glutMainLoop(); // Inicia o loop principal do GLUT
    return 0;
}
