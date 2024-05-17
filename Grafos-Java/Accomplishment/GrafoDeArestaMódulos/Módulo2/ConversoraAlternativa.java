import java.util.ArrayList;
import java.util.List;

public class Conversora {
    // Método para converter um grafo normal em um grafo de aresta
    public static String conversorGrafoDeAresta(int[][] matriz) {
        // Encontra os índices dos "uns" na matriz de inteiros recebida como parâmetro
        String indicesDosUns = achaIndicesDosUns(matriz);
        
        // Se não houver arestas, retorna a mensagem de aviso
        if (indicesDosUns.startsWith("O grafo de entrada não possui aresta.")) {
            return indicesDosUns;
        }
        
        // Gera a matriz final  em forma de lista com as colunas e linhas sendo referenciadas por cada novo vértice
        // pertencente ao grafo de aresta com base nos índices encontrados anteriormente.
        List<List<String>> listaMatriz = geradorMatriz(indicesDosUns);

        // Cria uma instância de StringBuilder para construir a representação em formato de string da matriz de finalizada.
        StringBuilder matrizString = new StringBuilder();

        // Itera sobre cada linha da matriz representada pela lista listaMatriz
        for (List<String> linha : listaMatriz) {
            // Itera sobre cada elemento dentro de uma linha específica da matriz
            for (String elemento : linha) {
                // Adiciona cada elemento à string matrizString, seguido de um espaço em branco
                matrizString.append(elemento).append(" ");
            }
            // Adiciona uma quebra de linha ao final de cada linha da matriz na representação em string
            matrizString.append("\n");
        }

        // Retorna a representação em formato de string da matriz finalizada e converte de StringBuilder para string de novo.
        return matrizString.toString();
    }

    // Método para encontrar os índices dos "uns" na matriz
    private static String achaIndicesDosUns(int[][] matriz) {
        // Lista para armazenar os índices das arestas
        List<Aresta> indicesDosUns = new ArrayList<>();
        // Obtém o tamanho da matriz (número de linhas)
        int tamanho = matriz.length;
        boolean found = false; // Variável para verificar se alguma aresta foi encontrada

        // Percorre todas as linhas da matriz
        for (int i = 0; i < tamanho; i++) {
            // Percorre todas as colunas a partir da diagonal principal
            for (int j = i; j < tamanho; j++) {
                // Se o elemento for 1, cria uma aresta e a adiciona à lista
                if (matriz[i][j] == 1) {
                    Aresta aresta = new Aresta(i, j);
                    indicesDosUns.add(aresta);
                    found = true;
                }
            }
        }

        // Se nenhuma aresta foi encontrada, retorna uma mensagem de aviso
        if (!found) {
            return "O grafo de entrada não possui aresta.";
        }

        // Retorna a lista de índices das arestas convertida para String
        return indicesDosUns.toString();
    }

    // Método para gerar a matriz de zeros com base nos índices das arestas
    private static List<List<String>> geradorMatriz(String indicesDosUns) {
        // Extrai os índices das arestas da string e converte para lista de Aresta
        List<Aresta> arestas = extrairArestas(indicesDosUns);
        
        // Calcula o tamanho da matriz com base no número de arestas
        int tamanhoMatriz = arestas.size() + 1;

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
                        linha.add(arestas.get(j - 1).getAresta());
                    }
                }
                // Se não for a primeira linha
                else if (j == 0) {
                    // Adiciona o elemento correspondente à aresta na primeira coluna
                    linha.add(arestas.get(i - 1).getAresta());
                }
                // Para as demais células da matriz
                else {
                    // Obtém as informações das arestas das células
                    String arestaI = arestas.get(i - 1).getAresta();
                    String arestaJ = arestas.get(j - 1).getAresta();
                    // Verifica se as arestas são adjacentes
                    if (arestaI.charAt(2) == arestaJ.charAt(2) && arestaI.charAt(4) == arestaJ.charAt(4)) {
                        // Se forem iguais, adiciona "0"
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

        // Retorna a matriz com a conversão para grafo de aresta finalizado
        return matriz;
    }

    // Método para extrair as arestas da string de índices
    private static List<Aresta> extrairArestas(String indicesDosUns) {
        List<Aresta> arestas = new ArrayList<>();
        // Remove os caracteres "[" e "]" da string e divide pelos caracteres ", "
        String[] indices = indicesDosUns.substring(1, indicesDosUns.length() - 1).split(", ");
        // Para cada índice, cria uma aresta e adiciona à lista
        for (String indice : indices) {
            String[] coords = indice.split(" ");
            int x = Integer.parseInt(coords[0]);
            int y = Integer.parseInt(coords[1]);
            arestas.add(new Aresta(x, y));
        }
        return arest
