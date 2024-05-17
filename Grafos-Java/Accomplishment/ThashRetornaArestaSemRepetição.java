import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GrafoAresta that = (GrafoAresta) o;
        return (aresta_esquerda == that.aresta_esquerda && aresta_direita == that.aresta_direita) ||
               (aresta_esquerda == that.aresta_direita && aresta_direita == that.aresta_esquerda);
    }

    @Override
    public int hashCode() {
        return aresta_esquerda + aresta_direita; // Simplified hash for this specific case
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
    }

    public static List<GrafoAresta> encontrarIndicesDosUns(int[][] matriz) {
        List<GrafoAresta> indicesDosUns = new ArrayList<>();
        Set<GrafoAresta> arestasVistas = new HashSet<>();
        int linhas = matriz.length;
        int colunas = matriz[0].length;

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (matriz[i][j] == 1) {
                    GrafoAresta aresta = new GrafoAresta(i, j);
                    if (!arestasVistas.contains(aresta)) {
                        indicesDosUns.add(aresta);
                        arestasVistas.add(aresta);
                    }
                }
            }
        }

        return indicesDosUns;
    }
}
