void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar fundo sombrio
    glColor3f(0.1, 0.1, 0.1); // Cor preta escura
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(screenWidth, 0);
    glVertex2i(screenWidth, screenHeight);
    glVertex2i(0, screenHeight);
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // Cor preta para outros elementos

    if (gameState == 0) {
        drawInitialScreen();
        // Reiniciar as vidas quando voltar para a tela inicial
        lives = 3;
        collisionCount = 0;
        squarePosX = 100;
        squarePosY = 100;
        isGhostMode = 0; // Desativar o modo fantasma na tela inicial
        ghostModeUsed = 0; // Reiniciar o indicador de modo fantasma usado
    } else if (gameState == 1) {
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

        drawSquare();
        drawWalls(); // Desenhar as paredes
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
