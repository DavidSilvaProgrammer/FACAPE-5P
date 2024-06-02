// Definição da função keyboard 

/*
Use glutKeyboardFunc para teclas regulares: Para lidar com teclas regulares, 
como 'a' ou 'A', você deve usar glutKeyboardFunc em vez de glutSpecialFunc
*/




void keyboard(unsigned char key, int x, int y) {
    if (gameState == 1) {
        switch (key) {
            case 'a':
            case 'A':
                // Ação associada à tecla 'a' ou 'A'
                // Por exemplo, fechar o programa
                exit(0);
                break;
            // Adicione casos para outras teclas conforme necessário
        }
    }
}

int main(int argc, char **argv) {
    // Inicialização do GLUT e criação da janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ghost Square");

    // Configuração da função de teclado
    glutKeyboardFunc(keyboard);

    // Outras configurações e funções de inicialização

    glutMainLoop(); // Loop principal do GLUT
    return 0;
}
