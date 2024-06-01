#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

int main() {
    // Nome do arquivo de áudio WAV
    const char* audioFile = "mystery.wav";

    // Tocar o arquivo de áudio
    if (!PlaySound(TEXT(audioFile), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
        fprintf(stderr, "Erro ao reproduzir o arquivo de áudio.\n");
        return 1;
    }

    printf("Reproduzindo o arquivo de áudio %s\n", audioFile);

    // Aguardar até que o usuário pressione uma tecla para encerrar o programa
    printf("Pressione qualquer tecla para encerrar o programa...\n");
    getchar();

    // Parar a reprodução do áudio
    PlaySound(NULL, 0, 0);

    printf("Fim da reprodução.\n");

    return 0;
}
