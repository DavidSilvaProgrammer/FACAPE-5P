import java.util.ArrayList;
import java.util.List;

public class MatrizDeZeros {
    public static String gerarMatrizDeZeros(int[][] matriz) {
        List<GrafoAresta> indicesDosUns = encontrarIndicesDosUns(matriz);
        List<List<String>> matrizDeZeros = criarMatrizComZeros(indicesDosUns);

        StringBuilder matrizString = new StringBuilder();
        matrizString.append("Listas de adjacências do grafo de arestas:\n\n");
        for (List<String> linha : matrizDeZeros) {
            for (String elemento : linha) {
                matrizString.append(elemento).append(" ");
            }
            matrizString.append("\n");
        }
        return matrizString.toString();
    }

    private static List<GrafoAresta> encontrarIndicesDosUns(int[][] matriz) {
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

    private static List<List<String>> criarMatrizComZeros(List<GrafoAresta> indicesDosUns) {
        int tamanhoMatriz = indicesDosUns.size() + 1;

        List<List<String>> matriz = new ArrayList<>();
        for (int i = 0; i < tamanhoMatriz; i++) {
            List<String> linha = new ArrayList<>();
            for (int j = 0; j < tamanhoMatriz; j++) {
                if (i == 0) {
                    if (j == 0) {
                        linha.add("       ");
                    } else {
                        linha.add(indicesDosUns.get(j - 1).getAresta());
                    }
                } else if (j == 0) {
                    linha.add(indicesDosUns.get(i - 1).getAresta());
                } else {
                    String arestaI = indicesDosUns.get(i - 1).getAresta();
                    String arestaJ = indicesDosUns.get(j - 1).getAresta();
                    if (arestaI.charAt(2) == arestaJ.charAt(2) && arestaI.charAt(4) == arestaJ.charAt(4)) {
                        linha.add("\t0");
                    } else {
                        if (arestaI.charAt(2) == arestaJ.charAt(2) || arestaI.charAt(4) == arestaJ.charAt(4) ||
                                arestaI.charAt(2) == arestaJ.charAt(4) || arestaI.charAt(4) == arestaJ.charAt(2)) {
                            linha.add("\t1");
                        } else {
                            linha.add("\t0");
                        }
                    }
                }
            }
            matriz.add(linha);
        }

        return matriz;
    }
}
