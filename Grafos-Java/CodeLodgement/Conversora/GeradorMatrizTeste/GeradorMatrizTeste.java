import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // Criando a lista de arestas
        List<Aresta> arestas = new ArrayList<>();
        arestas.add(new Aresta(1, 2));
        arestas.add(new Aresta(2, 2));
        arestas.add(new Aresta(2, 4));
        arestas.add(new Aresta(3, 4));
        arestas.add(new Aresta(3, 6));
        arestas.add(new Aresta(4, 6));

        // Chamando o método geradorMatriz e armazenando o resultado
        List<List<String>> matrizGerada = geradorMatriz(arestas);

        // Imprimindo a matriz gerada na tela
        for (List<String> linha : matrizGerada) {
            for (String elemento : linha) {
                System.out.print(elemento + " ");
            }
            System.out.println(); // Quebra de linha ao final de cada linha da matriz
        }
    }

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
                        linha.add("\t" + indicesDosUns.get(j - 1).getAresta());
                    }
                }
                // Se não for a primeira linha
                else if (j == 0) {
                    // Adiciona o elemento correspondente à aresta na primeira coluna
                    linha.add(indicesDosUns.get(i - 1).getAresta());
                }
                // Para as demais células da matriz
                else {
                    // Chama as arestas do método getArestas() no formato A(i,j) em string.
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

        // Retorna a matriz com a conversão para grafo de aresta finalizado
        return matriz;
    }

}
