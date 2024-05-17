public class Main {
    public static void main(String[] args) {
        // Criando uma matriz de exemplo
        int[][] matrizExemplo = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
        };

        // Instanciando a classe Conversora
        Conversora conversora = new Conversora();

        // Chamando o método conversorGrafoDeAresta para converter a matriz de exemplo
        String resultado = conversora.conversorGrafoDeAresta(matrizExemplo);

        // Exibindo o resultado
        System.out.println("Matriz de arestas:");
        System.out.println(resultado);
    }
}
