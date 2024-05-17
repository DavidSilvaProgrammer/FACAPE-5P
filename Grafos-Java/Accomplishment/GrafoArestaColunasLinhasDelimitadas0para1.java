import java.util.ArrayList;
import java.util.List;

class GrafoAresta {
    private int aresta_esquerda;
    private int aresta_direita;

    public GrafoAresta(int aresta_esquerda, int aresta_direita) {
        this.aresta_esquerda = aresta_esquerda+1;
        this.aresta_direita = aresta_direita+1;
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
        List<List<String>> matrizDeZeros = criarMatrizComZeros(indicesDosUns);

        // Exibir a matriz de zeros com as linhas e colunas preenchidas
        System.out.println("Matriz de zeros:");
        for (List<String> linha : matrizDeZeros) {
            for (String elemento : linha) {
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

    public static List<List<String>> criarMatrizComZeros(List<GrafoAresta> indicesDosUns) {
        // Calcular o tamanho da matriz
        int tamanhoMatriz = indicesDosUns.size() + 1;

        // Criar a matriz de zeros
        List<List<String>> matriz = new ArrayList<>();
        for (int i = 0; i < tamanhoMatriz; i++) {
            List<String> linha = new ArrayList<>();
            for (int j = 0; j < tamanhoMatriz; j++) {
                // Preencher a linha 0 com os valores do método getAresta()
                if (i == 0) {
                    if (j == 0) {
                        linha.add("\t"); // Espaço em branco para o elemento 0,0
                    } else {
                        linha.add("\t"+indicesDosUns.get(j - 1).getAresta());
                    }
                }
                // Preencher a coluna 0 com os valores do método getAresta()
                else if (j == 0) {
                    linha.add("\t"+indicesDosUns.get(i - 1).getAresta());
                }
                // Preencher o restante da matriz com zeros
                else {
                    
                    linha.add("\t  "+i+" "+j);
                }
            }
            matriz.add(linha);
        }

        return matriz;
    }
}
