//incluir -lopengl32 -lglu32 -lglut32 -lwinmm em "adicionar esses comando à linha
//de comando do linker" em ferramentas>opções do compilador

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")


int screenWidth = 800;
int screenHeight = 500;
int squarePosX = 0;
int squarePosY = 0;
int phaseTextStatus = 1;
int plusghostfase = 0;
int squareX = 100, squareY = 100; // Coordenadas do canto superior esquerdo do quadrado
int size = 30; // Tamanho do quadrado
int parabens = 0;
int plusghostfasecont =0;
int cor=1;
int fase = 0;
int gameOverCount = 0;



int gameState = 0; // 0 para tela inicial, 1 para controle do quadrado
int collisionCount = 0; // Contador de colisões com as paredes
int lives = 3; // Número inicial de vidas do jogador
int gameover=0;

int isGhostMode = 0; // Indicador de modo fantasma
int ghostModeUsed = 0; // Indicador se o modo fantasma já foi usado na vida atual
int ghostModeAvailable = 1; // Indicador se o modo fantasma está disponível

clock_t victoryMessageTime = 0; // Variável para rastrear o tempo de exibição da mensagem de vitória
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
int contMsgVitoria=0;

clock_t collisionTime = 0;

float redSquareX = 400; // Posição inicial X do quadrado vermelho
float redSquareY = 250; // Posição inicial Y do quadrado vermelho
float redSquareSize = 20; // Tamanho do quadrado vermelho
float  redSquareSpeedX = 1; // Velocidade horizontal do quadrado vermelho
float redSquareSpeedY = 1; // Velocidade vertical do quadrado vermelho
callred=0;


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
    // Fator de redução da velocidade
    float slowFactor = 0.3; // Ajuste esse valor para controlar a velocidade

    // Movimento do quadrado vermelho com velocidade reduzida
    redSquareX += redSquareSpeedX * slowFactor; // Atualiza a posição X
    redSquareY += redSquareSpeedY * slowFactor; // Atualiza a posição Y

    // Verifica colisões com as bordas da janela
    if (redSquareX <= 0 || redSquareX + redSquareSize >= screenWidth) {
        redSquareSpeedX = -redSquareSpeedX; // Inverte a direção horizontal ao atingir a borda
    }
    if (redSquareY <= 0 || redSquareY + redSquareSize >= screenHeight) {
        redSquareSpeedY = -redSquareSpeedY; // Inverte a direção vertical ao atingir a borda
    }
    
    
    // Verificar colisão com o quadrado vermelho
        if (!isGhostMode && (squareX + size >= redSquareX && squareX <= redSquareX + redSquareSize &&
            squareY + size >= redSquareY && squareY <= redSquareY + redSquareSize )){
            // Se houver colisão com o quadrado vermelho, o jogador perde uma vida
            lives--;
            ghostModeUsed = 0;

            // Verificar se o jogador perdeu todas as vidas
            
            if(lives<0){
            	lives=3;
                parabens=2;
                gameOverCount++;
                phaseTextStatus = 1;
                callred = 0; // Reinicia o contador do quadrado vermelho
                gameState = 0;
			}else{
			
				if (lives == 0) {
                // Se sim, retornar à tela inicial e reiniciar as vidas
            
                lives=3;
                parabens=2;
                gameOverCount++;
                phaseTextStatus = 1;
                callred = 0; // Reinicia o contador do quadrado vermelho
                gameState = 0;
                
            } else {
                // Se não, voltar o quadrado para a posição inicial
                squareX = 100;
                squareY = 100;
            }
        }
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
    glutKeyboardFunc(keyboard); // teclas comuns
    glutSpecialFunc(keyboard); // Usando glutSpecialFunc para teclas especiais
    glutMouseFunc(mouse);
    glutIdleFunc(checkGhostMode); // Função de idle para verificar o modo fantasma
    
     // Nome do arquivo de áudio WAV
    const char* audioFile = "mystery.wav";

    // Tocar o arquivo de áudio
    if (!PlaySound(TEXT(audioFile), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
        fprintf(stderr, "Erro ao reproduzir o arquivo de áudio.\n");
        return 1;
    }

    printf(audioFile);




    glutMainLoop();
    
   
    
    return 0;
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, screenWidth, 0, screenHeight, -1, 1); // Ajustando a projeção ortogonal para uma janela de 800x500 pixels
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    if (gameState == 0) {
        drawInitialScreen();
        // Reiniciar as vidas quando voltar para a tela inicial
        lives = 3;
        collisionCount = 0;
        squarePosX = 100;
        squarePosY = 100;
        isGhostMode = 0; // Desativar o modo fantasma na tela inicial
        ghostModeUsed = 0; // Reiniciar o indicador de modo fantasma usado
       
     // Dentro da função display()
	if (gameState == 0 && parabens==1 && fase == 2) {
    // Exibir a mensagem de vitória na tela inicial
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(120, 300);
    char message[100]; // Definindo um buffer para armazenar a mensagem formatada
    sprintf(message, "Parabens, jogador %d! Voce venceu o jogo! Pontuacao: 10.0", gameOverCount);
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    
}if (gameState == 0 && parabens == 2 && fase == 2) {
	lives=3;
    // Exibir a mensagem de derrota na tela inicial
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(120, 300);
    char message[100]; // Definindo um buffer para armazenar a mensagem formatada
    sprintf(message, "Game over, jogador %d! Voce perdeu o jogo! Pontuacao: 5.0", gameOverCount);
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}	
if (gameState == 0 && parabens == 2 && fase == 1) {
	lives=3;
    // Exibir a mensagem de derrota na tela inicial
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(120, 300);
    char message[100]; // Definindo um buffer para armazenar a mensagem formatada
    sprintf(message, "Game over, jogador %d! Voce perdeu o jogo! Pontuacao: 0.0", gameOverCount);
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}




		
		phaseTextStatus = 1;
        callred =0;
        plusghostfasecont=0;
        clock_t collisionTime = 0;
    } else if (gameState == 1) {
    	parabens=1;
    	fase=1;
    	
    	 if (phaseTextStatus ==2){
    	 	parabens=1;
    	 	
		 }
    	
    	
    	
    	if (phaseTextStatus ==2 && cor == 1){
    		
    	// Código para desenhar a fase 2
        glClearColor(0.5, 0.5, 0.5, 1.0); // Define a cor de fundo para cinza
        glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor com a nova cor de fundo
        glutPostRedisplay(); // Redesenha a janela com a nova cor de fundo
    		
    		
		}
    	
    	if (phaseTextStatus == 1){
    		parabens=1;
    	// Código para desenhar a fase 2
        /*glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo para cinza
        glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor com a nova cor de fundo
        glutPostRedisplay(); // Redesenha a janela com a nova cor de fundo
        */
		
        // Adicione o texto "Fase 1" ao canto superior direito da janela em vermelho e negrito
        glColor3f(1.0, 0.0, 0.0); // Cor vermelha
        glLineWidth(2.0); // Defina a largura da linha para tornar o texto mais grosso
        glRasterPos2f(screenWidth - 80, screenHeight - 20); // Posição do texto (ajustada para o canto superior direito)
        char phaseText[20] = "Fase 1"; // Texto a ser exibido
        int phaseTextLen = strlen(phaseText); // Comprimento do texto
        int i;
        for (i = 0; i < phaseTextLen; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, phaseText[i]); // Desenha cada caractere do texto em negrito
        }
    }else{
    	parabens =1;
    	fase=2;
    	// Adicione o texto "Fase 1" ao canto superior direito da janela em vermelho e negrito
        glColor3f(1.0, 0.0, 0.0); // Cor vermelha
        glLineWidth(2.0); // Defina a largura da linha para tornar o texto mais grosso
        glRasterPos2f(screenWidth - 80, screenHeight - 20); // Posição do texto (ajustada para o canto superior direito)
        char phaseText[20] = "Fase 2"; // Texto a ser exibido
        int phaseTextLen = strlen(phaseText); // Comprimento do texto
        int i;
        for (i = 0; i < phaseTextLen; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, phaseText[i]); // Desenha cada caractere do texto em negrito
        }
        plusghostfase=1;
        
    	
	}

        drawSquare();
        drawWalls(); // Desenhar as paredes
        drawGreenSquare(); // Desenhar o quadrado verde

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

        // Verificar colisão com o quadrado verde
        if (squareX + size >= greenSquareX && squareX <= greenSquareX + greenSquareSize &&
    squareY + size >= greenSquareY && squareY <= greenSquareY + greenSquareSize) {
    // Se houver colisão, definir o tempo de início da mensagem
    
    if (collisionTime == 0) {
        collisionTime = clock();
    }
	parabens=1;
    // Exibir "Fase Concluída" na tela
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(screenWidth / 2 - 50, screenHeight / 2);
    char *message = "Fase Concluida";
    int len = strlen(message);
    int i;
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    // Se passaram mais de 0.2 segundos desde a colisão, voltar o quadrado para a posição inicial
    if (((double)(clock() - collisionTime) / CLOCKS_PER_SEC) > 2) {
        squareX = 100;
        squareY = 100;
        collisionTime = 0; // Reiniciar o temporizador
        phaseTextStatus = 2;
        callred +=1;
        plusghostfasecont=1;
        parabens=1;
        fase=2;
         
    } 
    
    
    
    
}




if (callred == 1) {
    drawRedSquare(); // Desenha o quadrado vermelho
    moveRedSquare(); // Move o quadrado vermelho
    
} else if (callred > 1) {
	lives=3;
    callred = 0; // Reinicia o contador do quadrado vermelho
    parabens = 1;
    phaseTextStatus=1;
    gameOverCount++;
    gameState = 0; // Retorna à tela inicial
}



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
            case 'A':
            case 'a':
            	cor=1;
                glClearColor(0.5, 0.5, 0.5, 1.0); // Define a cor de fundo para cinza
                glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor com a nova cor de fundo
                glutPostRedisplay(); // Redesenha a janela com a nova cor de fundo
                break;
            case 'S':
            case 's':
            	cor=0;
                glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo para cinza
                glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor com a nova cor de fundo
                glutPostRedisplay(); // Redesenha a janela com a nova cor de fundo
                break;
            case ' ':
                if ((!ghostModeUsed) || (plusghostfase == 1 && plusghostfasecont == 1)) {
                    // Ativar o modo fantasma quando o botão esquerdo for clicado
                    isGhostMode = 1;
                    ghostModeUsed = 1; // Marcar o modo fantasma como usado na vida atual
                    ghostModeStartTime = clock(); // Registrar o tempo de início do modo fantasma
                    if (plusghostfase) {
                        plusghostfasecont = 0;
                    }
                }	
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
            if (lives == 0) {
                gameState = 0;
                lives = 3;
                parabens=2;
                gameOverCount++;
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
            if (lives == 0) {
                // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
                gameState = 0;
                lives = 3;
                parabens=2;
                gameOverCount++;
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
            if (lives == 0) {
                // Se as vidas acabarem, voltar para a tela inicial e reiniciar as vidas
                gameState = 0;
                lives = 3;
                parabens=2;
                gameOverCount++;
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
        parabens==1;
        glutPostRedisplay();
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameState == 1 && (!ghostModeUsed ) || (plusghostfase == 1 && plusghostfasecont == 1)){
        // Ativar o modo fantasma quando o botão esquerdo for clicado
        isGhostMode = 1;
        ghostModeUsed = 1; // Marcar o modo fantasma como usado na vida atual
        ghostModeStartTime = clock(); // Registrar o tempo de início do modo fantasma
        if (plusghostfase){
            plusghostfasecont =0;
        }
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameState == 1 && ghostModeUsed) {
        // Desativar o modo fantasma quando o botão esquerdo for clicado novamente
        isGhostMode = 0;
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
        glColor3f(0.5, 0.6, 0.9); // R, G, B - valores entre 0.0 e 1.0 para tons de cinza claro

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
