public class Main {
    public static void main(String[] args) {
        int[][] matriz = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 0, 1, 1},
                {1, 0, 0, 0}
        };

        String matrizString = MatrizDeZeros.gerarMatrizDeZeros(matriz);
        System.out.println(matrizString);
    }
}
