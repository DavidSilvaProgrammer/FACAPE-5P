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
        
        // Primeiro loop para imprimir os índices na mesma linha
        for (Integer[] indice : indicesDosUns) {
            System.out.print("(" + indice[0] + ", " + indice[1] + ")");
        }
        
        // Adiciona uma nova linha após o primeiro loop
        
        
        // Segundo loop para imprimir os índices em uma nova linha
        for (Integer[] indice : indicesDosUns) {
            System.out.print("(" + indice[0] + ", " + indice[1] + ")\n");
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
