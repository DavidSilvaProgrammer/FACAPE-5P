#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float hexX = 5.0, hexY = 5.0;
float hexSize = 2.0;
float losSize = 0.6;
float angleOffset = 0.0;

void Inicializa() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void DesenhaLosango(float x, float y, float size, float angle, float r, float g, float b) {
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(angle * 180 / M_PI, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-size / 2, 0);
    glVertex2f(0, -size / 2);
    glVertex2f(size / 2, 0);
    glVertex2f(0, size / 2);
    glEnd();
    glPopMatrix();
}

void DesenhaCena() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(1.0, 1.0, 1.0, 0.5);
    glBegin(GL_POLYGON);
    int i;
    for (i = 0; i < 6; i++) {
        float angle = 2.0 * M_PI * i / 6 + angleOffset;
        glVertex2f(hexX + hexSize * cos(angle), hexY + hexSize * sin(angle));
    }
    glEnd();

    float losOffset = losSize / 5;
    float angles[] = {0.0, M_PI / 3, 2 * M_PI / 3, M_PI, 4 * M_PI / 3, 5 * M_PI / 3};
    float colors[][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
        {1.0, 0.0, 1.0},
        {0.0, 1.0, 1.0}
    };

    for (i = 0; i < 6; i++) {
        float angle = angles[i] + angleOffset;
        float losX = hexX + (hexSize - losSize + losOffset) * cos(angle);
        float losY = hexY + (hexSize - losSize + losOffset) * sin(angle);
        float *color = colors[i];
        DesenhaLosango(losX, losY, losSize, angle, color[0], color[1], color[2]);
    }

    glFlush();
}

void Atualiza(int valor) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Atualiza, 0);
}

void Teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            hexY += 0.1;
            break;
        case 's':
            hexY -= 0.1;
            break;
        case 'a':
            hexX -= 0.1;
            break;
        case 'd':
            hexX += 0.1;
            break;
        case '+':
            hexSize += 0.1;
            break;
        case '-':
            hexSize -= 0.1;
            break;
        case '[':
            losSize -= 0.1;
            break;
        case ']':
            losSize += 0.1;
            break;
        case 'q':
            angleOffset += 0.1;
            break;
        case 'e':
            angleOffset -= 0.1;
            break;
        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Hexagono");
    glutDisplayFunc(DesenhaCena);
    glutKeyboardFunc(Teclado);
    Inicializa();
    glutTimerFunc(0, Atualiza, 0);
    glutMainLoop();
    return 0;
}

AtivPontuada.c
Exibindo AtivPontuada.c…
