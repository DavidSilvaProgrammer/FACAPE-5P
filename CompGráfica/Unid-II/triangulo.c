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

// Função para configurar o ambiente OpenGL
void setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Define a cor de fundo como preto
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura o modo de exibição (buffer único e cores RGB)
    glutInitWindowSize(500, 500); // Define o tamanho da janela
    glutCreateWindow("Triângulo OpenGL"); // Cria a janela com o título especificado
    setup(); // Configura o ambiente OpenGL
    glutDisplayFunc(drawTriangle); // Define a função de desenho
    glutMainLoop(); // Inicia o loop principal do GLUT
    return 0;
}
