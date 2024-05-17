import java.util.ArrayList;
import java.util.List;

class GrafoAresta {
    private int aresta_esquerda;
    private int aresta_direita;

    public GrafoAresta(int aresta_esquerda, int aresta_direita) {
        this.aresta_esquerda = aresta_esquerda;
        this.aresta_direita = aresta_direita;
    }

    public String getAresta() {
        return "A(" + aresta_esquerda + "," + aresta_direita + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        // Matriz de exemplo
        int[][] matriz = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 0, 1, 1},
            {1, 0, 0, 0}
        };

        List<GrafoAresta> indicesDosUns = encontrarIndicesDosUns(matriz);
        
        System.out.println("Índices dos elementos que possuem o 1:");
        for (GrafoAresta aresta : indicesDosUns) {
            System.out.println(aresta.getAresta());
        }

        // Criar a matriz de zeros
        List<List<Integer>> matrizDeZeros = criarMatrizComZeros(indicesDosUns.size());

        // Exibir a matriz de zeros
        System.out.println("Matriz de zeros:");
        for (List<Integer> linha : matrizDeZeros) {
            for (Integer elemento : linha) {
                System.out.print(elemento + " ");
            }
            System.out.println();
        }
    }

    public static List<GrafoAresta> encontrarIndicesDosUns(int[][] matriz) {
        List<GrafoAresta> indicesDosUns = new ArrayList<>();
        int tamanho = matriz.length;

        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                if (matriz[i][j] == 1) {
                    GrafoAresta aresta = new GrafoAresta(i, j);
                    indicesDosUns.add(aresta);
                }
            }
        }

        return indicesDosUns;
    }

    public static List<List<Integer>> criarMatrizComZeros(int tamanhoLista) {
        // Calcular o quadrado do tamanho da lista e somar 1
        int tamanhoMatriz = (int) Math.pow(tamanhoLista, 2) + 1;

        // Criar a matriz de zeros
        List<List<Integer>> matriz = new ArrayList<>();
        for (int i = 0; i < tamanhoMatriz; i++) {
            List<Integer> linha = new ArrayList<>();
            for (int j = 0; j < tamanhoMatriz; j++) {
                linha.add(0);
            }
            matriz.add(linha);
        }

        return matriz;
    }
}
