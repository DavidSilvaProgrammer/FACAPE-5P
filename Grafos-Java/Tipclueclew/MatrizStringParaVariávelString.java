public class Main {
    public static void main(String[] args) {
        // Matriz de strings
        String[][] matriz = {
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"}
        };

        // Obtém o tamanho da matriz
        int linhas = matriz.length;
        int colunas = (linhas > 0) ? matriz[0].length : 0;
        for (int i = 1; i < linhas; i++) {
            if (matriz[i].length != colunas) {
                System.err.println("A matriz não tem o mesmo número de colunas em todas as linhas.");
                return;
            }
        }

        // Converte a matriz de strings para uma variável de string
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
