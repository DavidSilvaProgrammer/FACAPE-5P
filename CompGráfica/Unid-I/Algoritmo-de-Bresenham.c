#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Definição das dimensões da tela
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Função para desenhar uma linha usando o algoritmo de Bresenham
void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        SDL_RenderDrawPoint(renderer, x1, y1);
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Inicialização da SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar a SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Criação da janela
    window = SDL_CreateWindow("Algoritmo de Bresenham", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro ao criar a janela: %s\n", SDL_GetError());
        return 1;
    }

    // Criação do renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Preenchimento da tela com branco
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Definição das coordenadas dos pontos inicial e final da linha
    int x1 = 100, y1 = 100;
    int x2 = 700, y2 = 500;

    // Desenho da linha usando o algoritmo de Bresenham
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    drawLine(renderer, x1, y1, x2, y2);

    // Atualização da tela
    SDL_RenderPresent(renderer);

    // Loop principal do programa
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Liberação de recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
