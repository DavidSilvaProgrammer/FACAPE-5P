import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Matriz de exemplo
        int[][] matriz = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 0, 1, 1},
            {1, 0, 0, 0}
        };

        List<Integer[]> indicesDosUns = encontrarIndicesDosUns(matriz);
        
        System.out.println("Índices dos elementos que possuem o 1:");
        for (Integer[] indice : indicesDosUns) {
            System.out.println("(" + indice[0] + ", " + indice[1] + ")");
        }
    }

    public static List<Integer[]> encontrarIndicesDosUns(int[][] matriz) {
        List<Integer[]> indicesDosUns = new ArrayList<>();
        int linhas = matriz.length;
        int colunas = matriz[0].length;

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (matriz[i][j] == 1) {
                    Integer[] indice = {i, j};
                    indicesDosUns.add(indice);
                }
            }
        }

        return indicesDosUns;
    }
}


/*

Explicação do enhanced for loop:

for (Integer[] indice : indicesDosUns) {
    System.out.println("(" + indice[0] + ", " + indice[1] + ")");
}


    Integer[] indice : indicesDosUns: Este é o formato do enhanced for loop. 
    Ele declara uma variável indice do tipo Integer[] (um array de inteiros) que 
    á percorrer cada elemento da coleção indicesDosUns.

    System.out.println("(" + indice[0] + ", " + indice[1] + ")"): Dentro do loop, 
    estamos utilizando System.out.println para imprimir na tela os índices (i, j) 
    de cada elemento da coleção indicesDosUns. Aqui indice[0] representa a linha (i) e 
    indice[1] representa a coluna (j) do elemento da matriz que contém o valor 1.

Portanto, esse loop itera sobre cada array de inteiros na lista indicesDosUns, 
que contém os índices dos elementos que possuem o valor 1 na matriz, e imprime 
esses índices na tela no formato (i, j).

*/

?*
