#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

// Variáveis para controlar a exibição do gráfico
int mostrarGrafico = 0;
int tipoGrafico = 0; // 0 para Astroide, 1 para Cardióide

// Função responsável por inicializar parâmetros e variáveis
void Inicializa(){
    // Define a janela de visualização 2D
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

void GraficoCardioide(){
    float x, y, a = 25, t; // a reduzido para 25 para tornar o Cardióide menor
    
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        for(t = 0; t <= 2*M_PI; t+= 0.001){
            x = a * (2 * cos(t) - cos(2*t));
            y = a * (2 * sin(t) - sin(2*t));
            glVertex3f(x, y, 0.0);
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
        if (tipoGrafico == 0)
            GraficoAstroide();
        else if (tipoGrafico == 1)
            GraficoCardioide();
    }
    glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y){
    if (key == 27){
        exit(0);    
    }    
}

// Função callback para gerenciar eventos do menu
void MenuJanela(int opcao)
{
    switch(opcao){
        case 0:
            tipoGrafico = 0;
            mostrarGrafico = 1;
            break;
        case 1:
            tipoGrafico = 1;
            mostrarGrafico = 1;
            break;
    }
    glutPostRedisplay();
}

// Função para criar o menu
void CriarMenu()
{
    int menu;
    
    menu = glutCreateMenu(MenuJanela);
    glutAddMenuEntry("Mostrar Astroide", 0);
    glutAddMenuEntry("Mostrar Cardióide", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);         
}

// Programa Principal 
int main(void){
    // Define o modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(600,600); 
    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Grafico");
    // Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Desenha);
    // Registra a função callback para tratamento das teclas ASCII
    glutKeyboardFunc (Teclado);
    // Chama a função responsável por fazer as inicializações 
    Inicializa();
    // Cria o menu
    CriarMenu();
    // Inicia o processamento e aguarda interações do usuário
    glutMainLoop();
    return 0;
}
