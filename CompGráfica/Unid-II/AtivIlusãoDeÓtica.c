include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float vermelho = 0.0f;
float verde = 1.0f;
float azul = 0.0f;
float posX = 0.0f;
float posY = 0.0f;

void Inicializa(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void Desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(vermelho, verde, azul);
    glBegin(GL_POLYGON);
        glVertex3f(55.0 + posX, 20.0 + posY, 0); //B
        glVertex3f(85.0 + posX, 20.0 + posY, 0); //A
        glVertex3f(100.0 + posX, 50.0 + posY, 0); //F
        glVertex3f(85.0 + posX, 80.0 + posY, 0); //E
        glVertex3f(55.0 + posX, 80.0 + posY, 0); //D
        glVertex3f(40.0 + posX, 50.0 + posY, 0); //C
    glEnd();

    glColor3f(azul, vermelho, verde);
    glBegin(GL_POLYGON);
        glVertex3f(60.0 + posX, 35.0 + posY, 0); //r
        glVertex3f(70.0 + posX, 20.0 + posY, 0); //g
        glVertex3f(80.0 + posX, 35.0 + posY, 0); //h
        glVertex3f(93.0 + posX, 38.0 + posY, 0); //i
        glVertex3f(85.0 + posX, 50.0 + posY, 0); //j
        glVertex3f(93.0 + posX, 62.5 + posY, 0); //k
        glVertex3f(80.0 + posX, 65.0 + posY, 0); //k
        glVertex3f(70.0 + posX, 80.0 + posY, 0); //m
        glVertex3f(60.0 + posX, 65.0 + posY, 0); //n
        glVertex3f(47.0 + posX, 62.5 + posY, 0); //o
        glVertex3f(63.0 + posX, 66.0 + posY, 0);  //p
        glVertex3f(47.0 + posX, 36.0 + posY, 0); //q
    glEnd();

    glColor3f(vermelho, verde, azul);
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex3f(60.0 + posX, 66.0 + posY, 0);
        glVertex3f(80.0 + posX, 34.0 + posY, 0);
    glEnd();
	
	//pontos n h
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex3f(60.0 + posX, 34.0 + posY, 0);
        glVertex3f(80.0 + posX, 67.0 + posY, 0);
    glEnd();
	
	//pontos r l
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex3f(50.5 + posX, 50.0 + posY, 0);
        glVertex3f(86.0 + posX, 50.0 + posY, 0);
    glEnd();
    
	//pontos p j 1
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex3f(53.0 + posX, 48.5 + posY, 0);
        glVertex3f(86.5 + posX, 49.0 + posY, 0);
    glEnd();
	
	//pontos p j 2
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex3f(53.0 + posX, 49.0 + posY, 0);
        glVertex3f(86.5 + posX, 49.0 + posY, 0);
    glEnd();
	
	//pontos p j 3
    glLineWidth(4.0);
    glBegin(GL_LINES);
        glVertex3f(52.0 + posX, 49.5 + posY, 0);
        glVertex3f(86.25 + posX, 49.5 + posY, 0);
    glEnd();
    
    //pontos p j 4
    glLineWidth(4.0);
    glBegin(GL_LINES);
        glVertex3f(52.0 + posX, 49.3 + posY, 0);
        glVertex3f(86.25 + posX, 49.5 + posY, 0);
    glEnd();
    
    //pontos p j 5
    glLineWidth(4.0);
    glBegin(GL_LINES);
        glVertex3f(52.0 + posX, 49.2 + posY, 0);
        glVertex3f(86.25 + posX, 49.5 + posY, 0);
    glEnd();
    
    //pontos p j 6
    glLineWidth(6.0);
    glBegin(GL_LINES);
        glVertex3f(52.0 + posX, 49.1 + posY, 0);
        glVertex3f(86.25 + posX, 49.5 + posY, 0);
    glEnd();

    glFlush();
}

void Teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            vermelho = 1.0f;
            verde = 0.0f;
            azul = 0.0f;
            posX -= 5.0f; // Move para a esquerda
            break;
        case 's':
            vermelho = 0.0f;
            verde = 0.0f;
            azul = 0.0f;
            break;
        case 'd':
            vermelho = 0.0f;
            verde = 0.0f;
            azul = 1.0f;
            posX += 5.0f; // Move para a direita
            break;
        case 'x':
            vermelho = 1.0f;
            verde = 1.0f;
            azul = 1.0f;
            posY -= 5.0f; // Move para baixo
            break;
        case 'w':
            vermelho = 0.0f;
            verde = 1.0f;
            azul = 0.0f;
            posY += 5.0f; // Move para cima
            break;
        
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Atividade Ilusão de Ótica: David Santana");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
