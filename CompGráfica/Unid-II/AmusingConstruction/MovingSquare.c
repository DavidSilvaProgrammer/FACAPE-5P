#include <GL/glut.h>
#include <stdlib.h>

int x1 = 100, y1 = 100; // Coordenadas do canto superior esquerdo do quadrado
int size = 50; // Tamanho do quadrado

void init(void);
void display(void);
void keyboard(int key, int x, int y);

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Move Quadrado com Teclado");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard); // Usando glutSpecialFunc para teclas especiais

    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 800, 0, 500, -1, 1); // Ajustando a projeção ortogonal para uma janela de 800x500 pixels
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // Desenhar o quadrado
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x1 + size, y1);
    glVertex2i(x1 + size, y1 + size);
    glVertex2i(x1, y1 + size);
    glEnd();

    glFlush();
}

void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            y1 += 10; // Movendo para cima
            break;
        case GLUT_KEY_DOWN:
            y1 -= 10; // Movendo para baixo
            break;
        case GLUT_KEY_LEFT:
            x1 -= 10; // Movendo para a esquerda
            break;
        case GLUT_KEY_RIGHT:
            x1 += 10; // Movendo para a direita
            break;
        case 27: // Tecla Esc
            exit(0);
            break;
    }

    // Redesenha a janela
    glutPostRedisplay();
}
