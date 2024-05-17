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
                // Preencher o restante da matriz com 1 se os últimos 4 caracteres das strings forem iguais, senão com 0
                else {
                    String arestaI = indicesDosUns.get(i - 1).getAresta();
                    String arestaJ = indicesDosUns.get(j - 1).getAresta();
                    if (arestaI.substring(arestaI.length() - 4).equals(arestaJ.substring(arestaJ.length() - 4))) {
                        linha.add("\t1");
                    } else {
                        linha.add("\t0");
                    }
                }
            }
            matriz.add(linha);
        }

        return matriz;
    }
}


/*

Este trecho de código está comparando os últimos quatro caracteres das strings arestaI e arestaJ. Vamos analisar cada parte:

    arestaI.substring(arestaI.length() - 4): Este trecho extrai os últimos quatro caracteres da string arestaI. arestaI.length() retorna o 
    comprimento total da string arestaI, e substring() é usado para extrair uma parte da string, começando no índice especificado (arestaI.length() - 4) até o final da string.

    .equals(: Este é um método que compara se duas strings são iguais. Ele retorna true se as strings forem iguais e false caso contrário.

    arestaJ.substring(arestaJ.length() - 4): Este trecho faz o mesmo que o primeiro, extrai os últimos quatro caracteres da string arestaJ.

Em resumo, esse if está verificando se os últimos quatro caracteres das strings arestaI e arestaJ são iguais. Isso pode ser útil, por exemplo, se você estiver 
trabalhando com strings que seguem um padrão e deseja verificar se os últimos quatro caracteres dessas strings são idênticos.

*/
