package projeto.projetografos;

import java.util.ArrayList;
import java.util.List;

public class Conversora {
    // Método para converter um grafo normal em um grafo de aresta
    public static String conversorGrafoDeAresta(String matrizString) {
        // Converte a string da matriz em uma matriz de inteiros
        int[][] matriz = converterStringParaMatriz(matrizString);

        // Encontra os índices dos "uns" na matriz de inteiros recebida como parâmetro
        List<Aresta> indicesDosUns = achaIndicesDosUns(matriz);

        if (indicesDosUns.isEmpty()) {
            // A lista está vazia
            return "O grafo de entrada não possui aresta";
        }

        // Se houver arestas, continua com a conversão

        // Gera a matriz final em forma de lista com as colunas e linhas sendo referenciadas por cada novo vértice
        // pertencente ao grafo de aresta com base nos índices encontrados anteriormente.
        List<List<String>> listaMatriz = geradorMatriz(indicesDosUns);

        // Cria uma instância de StringBuilder para construir a representação em formato de string da matriz finalizada.
        StringBuilder matrizFinal = new StringBuilder();

        // Itera sobre cada linha da matriz representada pela lista listaMatriz
        for (List<String> linha : listaMatriz) {
            // Itera sobre cada elemento dentro de uma linha específica da matriz
            for (String elemento : linha) {
                // Adiciona cada elemento à string matrizFinal, seguido de um espaço em branco
                matrizFinal.append(elemento).append(" ");
            }
            // Adiciona uma quebra de linha ao final de cada linha da matriz na representação em string
            matrizFinal.append("\n");
        }

        // Retorna a representação em formato de string da matriz finalizada e converte de StringBuilder para string de novo.
        return matrizFinal.toString();
    }

    // Método para converter a string da matriz em uma matriz de inteiros
    private static int[][] converterStringParaMatriz(String matrizString) {
        // Divide a string da matriz em linhas
        String[] linhas = matrizString.split("\n");

        // Obtém o número de linhas e colunas da matriz
        int numLinhas = linhas.length;
        int numColunas = linhas[0].trim().split("\\s+").length;

        // Cria a matriz de inteiros com base no número de linhas e colunas
        int[][] matriz = new int[numLinhas][numColunas];

        // Preenche a matriz com os valores da string
        for (int i = 0; i < numLinhas; i++) {
            // Divide a linha em elementos
            String[] elementos = linhas[i].trim().split("\\s+");
            for (int j = 0; j < numColunas; j++) {
                // Converte os elementos para inteiros e preenche a matriz
                matriz[i][j] = Integer.parseInt(elementos[j]);
            }
        }

        // Retorna a matriz de inteiros
        return matriz;
    }

    // Método para encontrar os índices dos "uns" na matriz
    private static List<Aresta> achaIndicesDosUns(int[][] matriz) {
        // Lista para armazenar os índices das arestas
        List<Aresta> indicesDosUns = new ArrayList<>();
        // Obtém o tamanho da matriz (número de linhas)
        int tamanho = matriz.length;

        // Percorre todas as linhas da matriz
        for (int i = 0; i < tamanho; i++) {
            // Percorre todas as colunas a partir da diagonal principal
            for (int j = i; j < tamanho; j++) {
                // Se o elemento for 1, cria uma aresta e a adiciona à lista
                if (matriz[i][j] == 1) {
                    Aresta aresta = new Aresta(i, j);
                    indicesDosUns.add(aresta);
                }
            }
        }

        // Retorna a lista de índices das arestas
        return indicesDosUns;
    }

    // Método para gerar a matriz de zeros com base nos índices das arestas
    private static List<List<String>> geradorMatriz(List<Aresta> indicesDosUns) {
        // Calcula o tamanho da matriz com base no número de arestas
        int tamanhoMatriz = indicesDosUns.size() + 1;

        // Lista para armazenar a matriz de zeros
        List<List<String>> matriz = new ArrayList<>();
        // Itera sobre as linhas da matriz
        for (int i = 0; i < tamanhoMatriz; i++) {
            // Lista para armazenar os elementos de cada linha
            List<String> linha = new ArrayList<>();
            // Itera sobre as colunas da matriz
            for (int j = 0; j < tamanhoMatriz; j++) {
                // Se for a primeira linha
                if (i == 0) {
                    // Se for a primeira coluna, adiciona um espaço em branco
                    if (j == 0) {
                        linha.add("       ");
                    }
                    // Senão, adiciona o elemento correspondente à aresta
                    else {
                        linha.add("\t"+indicesDosUns.get(j - 1).getAresta());
                    }
                }
                // Se não for a primeira linha
                else if (j == 0) {
                    // Adiciona o elemento correspondente à aresta na primeira coluna
                    linha.add(indicesDosUns.get(i - 1).getAresta());
                }
                // Para as demais células da matriz
                else {
                    // Chama as arestas do método getArestas() no formarto A(i,j) em string.
                    String arestaI = indicesDosUns.get(i - 1).getAresta();
                    String arestaJ = indicesDosUns.get(j - 1).getAresta();
                    // Verifica se as arestas são adjacentes
                    if (arestaI.charAt(2) == arestaJ.charAt(2) && arestaI.charAt(4) == arestaJ.charAt(4)) {
                        // Se forem totalmente iguais, adiciona "0"
                        linha.add("\t0");
                    } else {
                        // Senão, verifica se são adjacentes ou não
                        if (arestaI.charAt(2) == arestaJ.charAt(2) || arestaI.charAt(4) == arestaJ.charAt(4) ||
                                arestaI.charAt(2) == arestaJ.charAt(4) || arestaI.charAt(4) == arestaJ.charAt(2)) {
                            linha.add("\t1");
                        } else {
                            linha.add("\t0");
                        }
                    }
                }
            }
            // Adiciona a linha à matriz
            matriz.add(linha);
        }

        // Retorna a matriz com a conversão para grafo de aresta finalizado, faltando só colocar tudo em uma unica variável de sring.
        return matriz;
    }
}
