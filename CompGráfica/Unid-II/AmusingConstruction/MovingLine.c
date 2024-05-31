#include <GL/glut.h>
#include <stdlib.h>

int x1 = 100, y1 = 80; // Coordenadas iniciais da linha
int x2 = 20, y2 = 50;  // Coordenadas finais da linha

void init(void);
void display(void);
void keyboard(int key, int x, int y);

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenha uma linha");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard); // Agora estamos usando glutSpecialFunc para as teclas especiais

    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 256, 0, 256, -1, 1);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();

    glFlush();
}

void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            y1 += 10;
            y2 += 10;
            glutPostRedisplay(); // Indica ao GLUT que a janela precisa ser redesenhada
            break;
        case GLUT_KEY_DOWN:
            y1 -= 10;
            y2 -= 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            x1 -= 10;
            x2 -= 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            x1 += 10;
            x2 += 10;
            glutPostRedisplay();
            break;
        case 27: // Tecla Esc
            exit(0);
            break;
    }
}
