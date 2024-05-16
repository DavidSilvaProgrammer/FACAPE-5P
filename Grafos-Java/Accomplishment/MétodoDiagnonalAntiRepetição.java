/*Método diagonal*/

public static List<Integer[]> encontrarIndicesDosUns(int[][] matriz) {
    List<Integer[]> indicesDosUns = new ArrayList<>();
    int tamanho = matriz.length;

    for (int i = 0; i < tamanho; i++) {
        for (int j = i; j < tamanho; j++) {
            if (matriz[i][j] == 1) {
                Integer[] indice = {i, j};
                indicesDosUns.add(indice);
            }
        }
    }

    return indicesDosUns;
}

/*
Neste método, o segundo loop (for) é iniciado a partir do índice i, em vez de começar de 0 como 
na segunda função. Isso significa que, para cada linha, ele começa da coluna cujo índice é igual 
ao índice da linha (j = i). Isso implica que ele verifica apenas os elementos na diagonal principal 
da matriz. Portanto, ele encontra os índices dos elementos que possuem o valor 1 apenas na diagonal 
principal ou abaixo dela.
*/

/*Método com repetição*/

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

/*
Nesta função, os dois loops (for) percorrem todas as linhas e colunas da matriz. 
Ele verifica cada elemento da matriz e adiciona os índices dos elementos que possuem 
o valor 1 à lista indicesDosUns. Isso inclui todos os elementos da matriz, independentemente 
de estarem na diagonal principal ou em qualquer outra posição.

Portanto, a diferença principal entre as duas funções está na abordagem de iteração 
sobre os elementos da matriz: a primeira função verifica apenas a diagonal principal e 
abaixo dela, enquanto a segunda função verifica todos os elementos da matriz.
*/
