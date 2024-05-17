public class Main {
    public static void main(String[] args) {
        // Define uma matriz de adjacência representando um grafo
        int[][] matriz = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 0, 1, 1},
                {1, 0, 0, 0}
        };

        // Chama o método de conversão da classe Conversora para converter a matriz de adjacência em um grafo de aresta
        String matrizString = Conversora.conversorGrafoDeAresta(matriz);
        
        // Imprime a representação em string do grafo de aresta
        System.out.println(matrizString);
    }
}
