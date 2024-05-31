#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "Winmm.lib")

int main() {
    // Nome do arquivo de áudio WAV
    const char* audioFile = "ost.wav";

    // Tocar o arquivo de áudio
    if (!PlaySound(TEXT(audioFile), NULL, SND_FILENAME | SND_ASYNC)) {
        fprintf(stderr, "Erro ao reproduzir o arquivo de áudio.\n");
        return 1;
    }

    printf("Reproduzindo o arquivo de áudio %s\n", audioFile);

    // Aguardar até que a música termine de tocar
    Sleep(50000000); // Aguarda 5 segundos, você pode ajustar conforme necessário

    printf("Fim da reprodução.\n");

    return 0;
}


//incluir -lopengl32 -lglu32 -lglut32 -lwinmm em "adicionar esses comando à linha
//de comando do linker" em ferramentas>opções do compilador
