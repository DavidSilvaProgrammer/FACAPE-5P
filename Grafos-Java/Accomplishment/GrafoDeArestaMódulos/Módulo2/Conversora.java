import java.util.ArrayList;
import java.util.List;

public class Conversora {
    public static String conversorGrafoDeAresta(int[][] matriz) {
        List<Aresta> indicesDosUns = achaIndicesDosUns(matriz);
        List<List<String>> matrizDeZeros = geradorMatriz(indicesDosUns);

        StringBuilder matrizString = new StringBuilder();
        for (List<String> linha : matrizDeZeros) {
            for (String elemento : linha) {
                matrizString.append(elemento).append(" ");
            }
            matrizString.append("\n");
        }
        return matrizString.toString();
    }

    private static List<Aresta> achaIndicesDosUns(int[][] matriz) {
        List<Aresta> indicesDosUns = new ArrayList<>();
        int tamanho = matriz.length;

        for (int i = 0; i < tamanho; i++) {
            for (int j = i; j < tamanho; j++) {
                if (matriz[i][j] == 1) {
                    Aresta aresta = new Aresta(i, j);
                    indicesDosUns.add(aresta);
                }
            }
        }

        return indicesDosUns;
    }

    private static List<List<String>> geradorMatriz(List<Aresta> indicesDosUns) {
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
