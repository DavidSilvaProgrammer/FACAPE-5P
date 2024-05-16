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
        
        System.out.println("Índices dos elementos que possuem o 1:");
        for (Integer[] indice : indicesDosUns) {
            System.out.println("(" + indice[0] + ", " + indice[1] + ")");
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
