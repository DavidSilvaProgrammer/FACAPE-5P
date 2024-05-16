import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Matriz de exemplo
        int[][] matriz = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 0, 1, 1},
            {1, 0, 0, 0}
        };

        List<Integer[]> indicesDosUns = encontrarIndicesDosUns(matriz);
        
        // Tamanho da matriz
        int tamanhoMatriz = (int) Math.sqrt(indicesDosUns.size());
        
        // Criar uma matriz com o tamanho adequado e preenchê-la com zeros
        int[][] novaMatriz = new int[tamanhoMatriz][tamanhoMatriz];
        for (int i = 0; i < tamanhoMatriz; i++) {
            for (int j = 0; j < tamanhoMatriz; j++) {
                novaMatriz[i][j] = 0;
            }
        }
        
        // Preencher a nova matriz com os valores dos índicesDosUns
        for (Integer[] indice : indicesDosUns) {
            novaMatriz[indice[0]][indice[1]] = 1;
        }
        
        // Imprimir a matriz com os índices nas laterais
        System.out.print("    ");
        for (int i = 0; i < tamanhoMatriz; i++) {
            System.out.print("A(" + (i+1) + ")");
            if (i < tamanhoMatriz - 1) {
                System.out.print("    ");
            }
        }
        System.out.println();
        for (int i = 0; i < tamanhoMatriz; i++) {
            System.out.print("A(" + (i+1) + ")  ");
            for (int j = 0; j < tamanhoMatriz; j++) {
                System.out.print(novaMatriz[i][j] + "        ");
            }
            System.out.println();
        }
    }

    public static List<Integer[]> encontrarIndicesDosUns(int[][] matriz) {
        List<Integer[]> indicesDosUns = new ArrayList<>();
        int tamanho = matriz.length;

        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                if (matriz[i][j] == 1) {
                    Integer[] indice = {i, j};
                    indicesDosUns.add(indice);
                }
            }
        }

        return indicesDosUns;
    }
}
