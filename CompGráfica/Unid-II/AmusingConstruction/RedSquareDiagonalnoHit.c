#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int screenWidth = 800;
int screenHeight = 500;
int squarePosX = 0;
int squarePosY = 0;
int phaseTextStatus = 1;
int plusghostfase = 0;
int squareX = 100, squareY = 100; // Coordenadas do canto superior esquerdo do quadrado
int size = 30; // Tamanho do quadrado

int gameState = 0; // 0 para tela inicial, 1 para controle do quadrado
int collisionCount = 0; // Contador de colisões com as paredes
int lives = 3; // Número inicial de vidas do jogador

int isGhostMode = 0; // Indicador de modo fantasma
int ghostModeUsed = 0; // Indicador se o modo fantasma já foi usado na vida atual
int ghostModeAvailable = 1; // Indicador se o modo fantasma está disponível

clock_t ghostModeStartTime; // Tempo de início do modo fantasma
double ghostModeDuration = 5.0; // Duração do modo fantasma em segundos

// Coordenadas do quadrado verde
int greenSquareX = 700;
int greenSquareY = 400;
int greenSquareSize = 20;

// Coordenadas e tamanho dos obstáculos adicionais
int obstacle1X = 400;
int obstacle1Y = 300;
int obstacle1Size = 50;

int obstacle2X = 200;
int obstacle2Y = 100;
int obstacle2Size = 40;

int redSquareX = 400; // Posição inicial X do quadrado vermelho
int redSquareY = 250; // Posição inicial Y do quadrado vermelho
int redSquareSize = 20; // Tamanho do quadrado vermelho
int redSquareSpeedX = 2; // Velocidade horizontal do quadrado vermelho
int redSquareSpeedY = 1; // Velocidade vertical do quadrado vermelho


void init(void);
void display(void);
void keyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void drawInitialScreen(void);
void drawSquare(void);
void drawWalls(void);
void checkGhostMode(void);
void drawGreenSquare(void);

void drawRedSquare(void) {
    glColor3f(1.0, 0.0, 0.0); // Cor vermelha
    glBegin(GL_POLYGON);
    glVertex2i(redSquareX, redSquareY);
    glVertex2i(redSquareX + redSquareSize, redSquareY);
    glVertex2i(redSquareX + redSquareSize, redSquareY + redSquareSize);
    glVertex2i(redSquareX, redSquareY + redSquareSize);
    glEnd();
}

void moveRedSquare(void) {
    // Atualiza a posição do quadrado vermelho
    redSquareX += redSquareSpeedX / 2; // Reduzindo a velocidade pela metade
    redSquareY += redSquareSpeedY / 2; // Reduzindo a velocidade pela metade

    // Verifica colisões com as bordas da janela
    if (redSquareX <= 0 || redSquareX + redSquareSize >= screenWidth) {
        redSquareSpeedX = -redSquareSpeedX; // Inverte a direção horizontal ao atingir a borda
    }
    if (redSquareY <= 0 || redSquareY + redSquareSize >= screenHeight) {
        redSquareSpeedY = -redSquareSpeedY; // Inverte a direção vertical ao atingir a borda
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ghost Square");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard); // Usando glutSpecialFunc para teclas especiais
    glutMouseFunc(mouse);
    glutIdleFunc(checkGhostMode); // Função de idle para verificar o modo fantasma

    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1); // Ajustando a projeção ortogonal para uma janela de 800x500 pixels
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    if (gameState == 0)
    {
        drawInitialScreen();
        // Reiniciar as vidas quando voltar para a tela inicial
        lives = 3;
        collisionCount = 0;
        squarePosX = 100;
        squarePosY = 100;
        isGhostMode = 0; // Desativar o modo fantasma na tela inicial
        ghostModeUsed = 0; // Reiniciar o indicador de modo fantasma usado
    }
    else if (gameState == 1)
    {

        if (phaseTextStatus == 1)
        {
            // Adicione o texto "Fase 1" ao canto superior direito da janela em vermelho e negrito
            glColor3f(1.0, 0.0, 0.0); // Cor vermelha
            glLineWidth(2.0);          // Defina a largura da linha para tornar o texto mais grosso
            glRasterPos2f(screenWidth - 80, screenHeight - 20); // Posição do texto (ajustada para o canto superior direito)
            char phaseText[20] = "Fase 1";                        // Texto a ser exibido
            int phaseTextLen = strlen(phaseText);                // Comprimento do texto
            int i;
            for (i = 0; i < phaseTextLen; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, phaseText[i]); // Desenha cada caractere do texto em negrito
            }
        }
        else
        {
            // Adicione o texto "Fase 2" ao canto superior direito da janela em vermelho e negrito
            glColor3f(1.0, 0.0, 0.0); // Cor vermelha
            glLineWidth(2.0);          // Defina a largura da linha para tornar o texto mais grosso
            glRasterPos2f(screenWidth - 80, screenHeight - 20); // Posição do texto (ajustada para o canto superior direito)
            char phaseText[20] = "Fase 2";                        // Texto a ser exibido
            int phaseTextLen = strlen(phaseText);                // Comprimento do texto
            int i;
            for (i = 0; i < phaseTextLen; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, phaseText[i]); // Desenha cada caractere do texto em negrito
            }
        }

        drawSquare();
        drawWalls();            // Desenhar as paredes
        drawGreenSquare();      // Desenhar o quadrado verde
        
        // Desenhar os obstáculos adicionais
        glColor3f(0.0, 0.0, 0.0); // Cor preta
        glBegin(GL_POLYGON);
        glVertex2i(obstacle1X, obstacle1Y);
        glVertex2i(obstacle1X + obstacle1Size, obstacle1Y);
        glVertex2i(obstacle1X + obstacle1Size, obstacle1Y + obstacle1Size);
        glVertex2i(obstacle1X, obstacle1Y + obstacle1Size);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2i(obstacle2X, obstacle2Y);
        glVertex2i(obstacle2X + obstacle2Size, obstacle2Y);
        glVertex2i(obstacle2X + obstacle2Size, obstacle2Y + obstacle2Size);
        glVertex2i(obstacle2X, obstacle2Y + obstacle2Size);
        glEnd();

        // Exibir o contador de tempo do modo fantasma
        if (isGhostMode) {
            glColor3f(0.0, 1.0, 0.0); // Cor verde
            glRasterPos2f(10, 20);
            char ghostModeTimer[50];
            double remainingTime = ghostModeDuration - ((double)(clock() - ghostModeStartTime) / CLOCKS_PER_SEC);
            sprintf(ghostModeTimer, "Modo Fantasma: %.1f segundos restantes", remainingTime);
            int len = strlen(ghostModeTimer);
            int i;
            for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ghostModeTimer[i]);
            }
        }
        // Exibir o contador de espera após o término do modo fantasma
        else {
            glColor3f(1.0, 0.0, 0.0); // Cor vermelha
            glRasterPos2f(10, 40);
            char cooldownTimer[50];
            double elapsedTime = ((double)(clock() - ghostModeStartTime) / CLOCKS_PER_SEC);
            double cooldownTime = elapsedTime >= ghostModeDuration ? 10.0 : ghostModeDuration - elapsedTime;
            sprintf(cooldownTimer, "Modo fantasma: botao direito do mouse uma vez por vida");
            int len = strlen(cooldownTimer);
            int i;
            for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, cooldownTimer[i]);
            }
        }

        // Movimento do quadrado vermelho na diagonal
        redSquareX += redSquareSpeedX;
        redSquareY += redSquareSpeedY;

        // Verificar colisões com as bordas da janela
        if (redSquareX <= 0 || redSquareX + redSquareSize >= screenWidth) {
            redSquareSpeedX = -redSquareSpeedX; // Inverte a direção horizontal ao atingir a borda
        }
        if (redSquareY <= 0 || redSquareY + redSquareSize >= screenHeight) {
            redSquareSpeedY = -redSquareSpeedY; // Inverte a direção vertical ao atingir a borda
        }

        // Desenhar o quadrado vermelho
        drawRedSquare();
    }

    // Desenhar contador de vida
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(10, screenHeight - 20);
    char lifeStr[20];
    sprintf(lifeStr, "Vidas: %d", lives);
    int len = strlen(lifeStr);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, lifeStr[i]);
    }

    glFlush();
}




void keyboard(int key, int x, int y) {
    if (gameState == 1) {
        switch (key) {
            case GLUT_KEY_UP:
                squareY += 10; // Movendo para cima
                break;
            case GLUT_KEY_DOWN:
                squareY -= 10; // Movendo para baixo
                break;
            case GLUT_KEY_LEFT:
                squareX -= 10; // Movendo para a esquerda
                break;
            case GLUT_KEY_RIGHT:
                squareX += 10; // Movendo para a direita
                break;
            case 27: // Tecla Esc
                exit(0);
                break;
        }

        // Distância de segurança para a colisão com as bordas da janela
        int safetyDistance = 5;

        // Verificar colisão com as bordas da janela
        if (squareX < -size / 2 + safetyDistance || squareX + size > screenWidth + size / 2 - safetyDistance || squareY < -size / 2 + safetyDistance || squareY + size > screenHeight + size / 2 - safetyDistance) {
            // Se houver colisão, fazer o quadrado perder vida
            lives--;

            // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
            if (lives <= 0) {
                gameState = 0;
                lives = 3;
            } else {
                // Se perder uma vida, voltar o quadrado para o ponto inicial
                squareX = 100;
                squareY = 100;
            }
        }

        // Verificar colisão com as linhas pretas que cruzam a tela
        if (!isGhostMode && ((squareY <= screenHeight / 2 + size - safetyDistance && squareY >= screenHeight / 2 - size + safetyDistance) ||
            (squareX <= screenWidth / 2 + size - safetyDistance && squareX >= screenWidth / 2 - size + safetyDistance))) {
            // Se houver colisão e não estiver no modo fantasma, decrementar uma vida
            lives--;
            ghostModeUsed = 0;
            if (lives <= 0) {
                // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
                gameState = 0;
                lives = 3;
            } else {
                // Se perder uma vida, voltar o quadrado para o ponto inicial
                squareX = 100;
                squareY = 100;
            }
        }

        // Verificar colisão com as paredes da tela (aumentar a área de colisão)
        if (squareX <= -size / 2 + safetyDistance || squareX + size >= screenWidth + size / 2 - safetyDistance || squareY <= -size / 2 + safetyDistance || squareY + size >= screenHeight + size / 2 - safetyDistance) {
            // Se houver colisão, decrementar uma vida
            lives--;
            if (lives <= 0) {
                // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
                gameState = 0;
                lives = 3;
            } else {
                // Se perder uma vida, voltar o quadrado para o ponto inicial
                squareX = 100;
                squareY = 100;
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
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameState == 1 && (!ghostModeUsed ) || plusghostfase == 1){
        // Ativar o modo fantasma quando o botão esquerdo for clicado
        isGhostMode = 1;
        ghostModeUsed = 1; // Marcar o modo fantasma como usado na vida atual
        ghostModeStartTime = clock(); // Registrar o tempo de início do modo fantasma
    	plusghostfase =0;
		
        
    }
}

void drawInitialScreen(void) {
    // Desenha a tela inicial
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f((GLfloat)screenWidth / 2 - 60, (GLfloat)screenHeight / 2);
    char *message = "GhostSquare";
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f((GLfloat)screenWidth / 2 - 30, (GLfloat)screenHeight / 2 - 20);
    message = "Clique com o botao direito para comecar";
    len = strlen(message);

    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, message[i]);
    }
}

void drawSquare(void) {
    // Engrossar as bordas do quadrado e garantir que elas apareçam em todos os lados
    glLineWidth(2.0); // Define a largura da linha para 2 pixels

    if (isGhostMode) {
        // Desenhar o quadrado branco com bordas pretas no modo fantasma
        glColor3f(0.0, 0.0, 0.0); // Cor preta para bordas
        glBegin(GL_LINE_LOOP); // Usando GL_LINE_LOOP para desenhar apenas as bordas
        glVertex2i(squareX - 1, squareY - 1); // Adiciona -1 para garantir que as bordas apareçam completamente
        glVertex2i(squareX + size + 1, squareY - 1);
        glVertex2i(squareX + size + 1, squareY + size + 1);
        glVertex2i(squareX - 1, squareY + size + 1);
        glEnd();

        // Definir a cor do preenchimento do quadrado como branco
        glColor3f(1.0, 1.0, 1.0); // R, G, B - valores para cor branca

        // Desenhar o preenchimento do quadrado
        glBegin(GL_POLYGON);
        glVertex2i(squareX, squareY);
        glVertex2i(squareX + size, squareY);
        glVertex2i(squareX + size, squareY + size);
        glVertex2i(squareX, squareY + size);
        glEnd();
    } else {
        // Desenhar as bordas do quadrado com cor preta
        glColor3f(0.0, 0.0, 0.0); // Cor preta
		        glBegin(GL_LINE_LOOP); // Usando GL_LINE_LOOP para desenhar apenas as bordas
        glVertex2i(squareX - 1, squareY - 1); // Adiciona -1 para garantir que as bordas apareçam completamente
        glVertex2i(squareX + size + 1, squareY - 1);
        glVertex2i(squareX + size + 1, squareY + size + 1);
        glVertex2i(squareX - 1, squareY + size + 1);
        glEnd();

        // Definir a cor do preenchimento do quadrado como cinza claro
        glColor3f(0.8, 0.8, 0.8); // R, G, B - valores entre 0.0 e 1.0 para tons de cinza claro

        // Desenhar o preenchimento do quadrado
        glBegin(GL_POLYGON);
        glVertex2i(squareX, squareY);
        glVertex2i(squareX + size, squareY);
        glVertex2i(squareX + size, squareY + size);
        glVertex2i(squareX, squareY + size);
        glEnd();
    }
}

void drawWalls(void) {
    // Desenhar as paredes no meio da tela
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(screenWidth / 2, 0);
    glVertex2i(screenWidth / 2, screenHeight);
    glVertex2i(0, screenHeight / 2);
    glVertex2i(screenWidth, screenHeight / 2);
    glEnd();
}

void checkGhostMode(void) {
    // Verifica se o modo fantasma está ativado e se o tempo de duração já passou
    if (isGhostMode) {
        clock_t currentTime = clock();
        double timeDiff = (double)(currentTime - ghostModeStartTime) / CLOCKS_PER_SEC;

        // Se o tempo de duração do modo fantasma passou, desativa o modo fantasma
        if (timeDiff >= ghostModeDuration) {
            isGhostMode = 0;
        }
    }
    glutPostRedisplay();
}

void drawGreenSquare(void) {
    // Desenha o quadrado verde
    glColor3f(0.0, 1.0, 0.0); // Cor verde
    glBegin(GL_POLYGON);
    glVertex2i(greenSquareX, greenSquareY);
    glVertex2i(greenSquareX + greenSquareSize, greenSquareY);
    glVertex2i(greenSquareX + greenSquareSize, greenSquareY + greenSquareSize);
    glVertex2i(greenSquareX, greenSquareY + greenSquareSize);
    glEnd();
}
