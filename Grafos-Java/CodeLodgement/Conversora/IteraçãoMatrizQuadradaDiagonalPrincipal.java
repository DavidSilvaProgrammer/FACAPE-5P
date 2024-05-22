public class Main {
    public static void main(String[] args) {
        int tamanho = 3; // Tamanho da matriz
        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                System.out.println("Índices: (" + i + ", " + j + ")");
            }
        }
    }
}

/*Este código imprimirá os índices das células em uma matriz quadrada de tamanho 3x3 começando da diagonal principal:

Índices: (0, 0)
Índices: (0, 1)
Índices: (0, 2)
Índices: (1, 1)
Índices: (1, 2)
Índices: (2, 2)
*/

public class Main {
    public static void main(String[] args) {
        int tamanho = 3; // Tamanho da matriz
        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                System.out.println("Índices: (" + i + ", " + j + ")");
            }
        }
    }
}

/*
Programa que preenche uma matriz com zeros e, em seguida, itera sobre ela a partir da diagonal principal para um lado, 
preenchendo com 1 onde o loop passou e deixando com zero onde o loop não passou.

Este programa criará uma matriz 5x5 preenchida com zeros. Em seguida, itera sobre a matriz a partir da diagonal 
principal e preenche com 1 onde o loop passou. O restante da matriz permanecerá com zeros. Ao final, 
imprime a matriz resultante.

1 1 1 1 1 
0 1 1 1 1 
0 0 1 1 1 
0 0 0 1 1 
0 0 0 0 1 
*/

public class Main {
    public static void main(String[] args) {
        int tamanho = 5; // Tamanho da matriz
        int[][] matriz = new int[tamanho][tamanho]; // Cria uma matriz de tamanho 5x5 inicialmente preenchida com zeros

        // Itera sobre a matriz
        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                // Preenche com 1 onde o loop passou
                matriz[i][j] = 1;

                // Imprime a matriz após cada rodada do loop
                System.out.println("Iteração " + (i * tamanho + j + 1) + ":");
                imprimirMatriz(matriz);
                System.out.println();
            }
        }
    }

    // Método para imprimir a matriz
    public static void imprimirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}


/*Com lista sendo atualizada e impressa cada roda dos dois loop for principais por meio da função imprimirMatriz*/
