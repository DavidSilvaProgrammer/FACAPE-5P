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


/*

O comando matriz[0].length retorna o comprimento da primeira linha da matriz, 
ou seja, o número de elementos na primeira linha.

Vamos explicar em detalhes:

    matriz[0]: Isso acessa a primeira linha da matriz. No Java, a indexação de arrays 
    começa em 0, então matriz[0] representa a primeira linha da matriz matriz.

    matriz[0].length: Isso retorna o comprimento da primeira linha da matriz. No Java, o 
    buto length de um array multidimensional retorna o número de elementos na dimensão especificada. 
    No caso de um array bidimensional como matriz, matriz[0].length retorna o número de elementos 
    na primeira dimensão, ou seja, o número de colunas na primeira linha da matriz.

Então, em resumo, matriz[0].length retorna o número de colunas na primeira linha da matriz. 
Isso é útil quando você quer saber quantas colunas a matriz tem.

*/


*/
