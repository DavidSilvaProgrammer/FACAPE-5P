#include <GL/glut.h> // Inclusão da biblioteca GLUT
#include <stdlib.h>  // Inclusão da biblioteca padrão

// Declarações das funções
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
    glutInit(&argc, argv); // Inicializa o GLUT e processa qualquer parâmetro passado pela linha de comandos. Deve ser chamada antes de qualquer outra rotina GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Indica se vamos usar cores no modo RGBA ou Indexado. Também especificamos se usaremos um ou dois buffers para a geração das imagens e se vamos associar buffers de profundidade, estêncil e/ou acumulador à janela que estamos usando.
    glutInitWindowSize(150, 150); // Especifica as dimensões da janela em pixels.
    glutInitWindowPosition(100, 100); // Especifica a coordenada superior esquerda da janela
    glutCreateWindow("Desenha uma linha"); // Cria a janela e devolve um identificador

    init();
    glutDisplayFunc(display); // Toda vez que o GLUT determinar que a janela tem de ser redesenhada, ele chama esta função
    glutKeyboardFunc(keyboard); // Determina a função que será chamada para ler o teclado

    glutMainLoop(); // Entra no loop de eventos do GLUT, não retorna
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de limpeza do buffer de cor no modo RGBA
    glOrtho(0, 256, 0, 256, -1, 1); // Seleciona o modo de projeção Ortogonal.
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela com a cor definida em glClearColor
    glColor3f(0.0, 0.0, 0.0); // Seleciona a cor preta para a linha

    glBegin(GL_LINES);
    glVertex2i(100, 80); 
    glVertex2i(20, 50); // Define as coordenadas dos pontos iniciais e finais da linha
    glEnd();

    glFlush(); // Garante que todos os comandos OpenGL serão executados o mais rápido possível
}

// A rotina a seguir termina o programa quando a tecla Esc é pressionada
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // Código ASCII para a tecla Esc
            exit(0);
            break;
    }
}
