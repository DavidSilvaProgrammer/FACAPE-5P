#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int screenWidth = 800;
int screenHeight = 500;

int x1 = 100, y1 = 100; // Coordenadas do canto superior esquerdo do quadrado
int size = 50; // Tamanho do quadrado

int gameState = 0; // 0 para tela inicial, 1 para controle do quadrado
int collisionCount = 0; // Contador de colisões com as paredes
int lives = 3; // Número inicial de vidas do jogador

void init(void);
void display(void);
void keyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void drawInitialScreen(void);
void drawSquare(void);
void drawWalls(void);

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ghost Square");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard); // Usando glutSpecialFunc para teclas especiais
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1); // Ajustando a projeção ortogonal para uma janela de 800x500 pixels
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    if (gameState == 0)
        drawInitialScreen();
    else if (gameState == 1) {
        drawSquare();
        drawWalls(); // Desenhar as paredes
    }

    // Desenhar contador de vida
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(10, screenHeight - 20);
    char lifeStr[20];
    sprintf(lifeStr, "Lives: %d", lives);
    int len = strlen(lifeStr);
    int i; // Declaração do contador do for aqui
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, lifeStr[i]);
    }

    glFlush();
}

void keyboard(int key, int x, int y) {
    if (gameState == 1) {
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

        // Verificar colisão com as paredes
        if (x1 < 0 || x1 + size > screenWidth || y1 < 0 || y1 + size > screenHeight) {
            // Se houver colisão, fazer o quadrado voltar ao início
            x1 = 100;
            y1 = 100;
            collisionCount++;
            if (collisionCount >= 3) {
                // Se o número de colisões exceder 3, encerrar o jogo
                gameState = 0;
                lives = 0; // Definir vidas como 0 para indicar game over
            } else {
                // Decrementar uma vida
                lives--;
                if (lives <= 0) {
                    // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
                    gameState = 0;
                    lives = 3;
                }
            }
        }

        // Redesenha a janela
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && gameState == 0) {
        gameState = 1;
        glutPostRedisplay();
    }
}

void drawInitialScreen(void) {
    // Desenha a tela inicial
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f((GLfloat)screenWidth/2 - 60, (GLfloat)screenHeight/2);
    char *message = "GhostSquare";
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f((GLfloat)screenWidth/2 - 30, (GLfloat)screenHeight/2 - 20);
    message = "Clique com o botao direito para comecar";
    len = strlen(message);

    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, message[i]);
    }
}

void drawSquare(void) {
    // Desenhar o quadrado
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x1 + size, y1);
    glVertex2i(x1 + size, y1 + size);
    glVertex2i(x1, y1 + size);
    glEnd();
}

void drawWalls(void) {
    // Desenhar as paredes no meio da tela
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(screenWidth / 2, 0);
    glVertex2i(screenWidth / 2, screenHeight);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(0, screenHeight / 2);
    glVertex2i(screenWidth, screenHeight / 2);
    glEnd();
}
