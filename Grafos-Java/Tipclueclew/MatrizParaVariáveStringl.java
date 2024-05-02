public class Main {
    public static void main(String[] args) {
        // Matriz de bits
        int[][] matriz = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 1, 0}
        };

        // Obtém o tamanho da matriz
        int linhas = matriz.length;
        int colunas = matriz[0].length;

        // Converte a matriz de bits para uma variável de string
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                sb.append(matriz[i][j]);
            }
        }

        // Obtém a string resultante
        String resultado = sb.toString();

        // Imprime o tamanho da matriz e a variável de string resultante
        System.out.println("Tamanho da matriz: " + linhas + "x" + colunas);
        System.out.println("Matriz como string: " + resultado);
    }
}
