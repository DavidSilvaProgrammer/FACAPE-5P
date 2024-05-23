#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

// Vari�veis para controlar a exibi��o do gr�fico
int mostrarGrafico = 0;

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa(){
    // Define a janela de visualiza��o 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void GraficoAstroide(){
    float x, y, a = 50, t;
    
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        for(t = 0; t <= 2*M_PI; t+= 0.001){
            x = a*cos(t)*cos(t)*cos(t);
            y = a*sin(t)*sin(t)*sin(t);
            glVertex3f(x,y,0.0);
        }
    glEnd();
}

void Linhas(){
    glLineWidth(1);
    glBegin(GL_LINES);
    // X
        glVertex3f(-100.0,0.0,0);
        glVertex3f(100.0,0.0,0);
    glEnd();
    // Y
    glBegin(GL_LINES);
        glVertex3f(0.0,-100.0,0);
        glVertex3f(0.0,100.0,0);
    glEnd();     
}

void Desenha(){   
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    Linhas();
    if (mostrarGrafico) {
        glColor3f(1.0, 0.0, 0.0);
        GraficoAstroide();
    }
    glFlush();
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y){
    if (key == 27){
        exit(0);    
    }    
}

// Fun��o callback para gerenciar eventos do menu
void MenuJanela(int opcao)
{
    switch(opcao){
        case 0:
            mostrarGrafico = 1;
            break;
    }
    glutPostRedisplay();
}

// Fun��o para criar o menu
void CriarMenu()
{
    int menu;
    
    menu = glutCreateMenu(MenuJanela);
    glutAddMenuEntry("Mostrar Gr�fico", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);         
}

// Programa Principal 
int main(void){
    // Define o modo de opera��o da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(600,600); 
    // Cria a janela passando como argumento o t�tulo da mesma
    glutCreateWindow("Grafico");
    // Registra a fun��o callback de redesenho da janela de visualiza��o
    glutDisplayFunc(Desenha);
    // Registra a fun��o callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);
    // Chama a fun��o respons�vel por fazer as inicializa��es 
    Inicializa();
    // Cria o menu
    CriarMenu();
    // Inicia o processamento e aguarda intera��es do usu�rio
    glutMainLoop();
    return 0;
}

