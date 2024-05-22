    // Método para encontrar os índices dos "uns" na matriz
    private static List<Aresta> achaIndicesDosUns(int[][] matriz) {
        // Lista para armazenar os índices das arestas
        List<Aresta> indicesDosUns = new ArrayList<>();
        // Obtém o tamanho da matriz (número de linhas)
        int tamanho = matriz.length;

        // Percorre todas as linhas da matriz
        for (int i = 0; i < tamanho; i++) {
            // Percorre todas as colunas a partir da diagonal principal
            for (int j = i; j < tamanho; j++) {
                // Se o elemento for 1, cria uma aresta e a adiciona à lista
                if (matriz[i][j] == 1) {
                    Aresta aresta = new Aresta(i, j);
                    indicesDosUns.add(aresta);
                }
            }
        }

        // Retorna a lista de índices das arestas
        return indicesDosUns;
    }

/*
Método achaIndicesDosUns:

Este método é projetado para encontrar os índices dos elementos que têm o valor 1 em uma matriz quadrada de inteiros. 
Aqui está uma explicação linha por linha:

    private static List<Aresta> achaIndicesDosUns(int[][] matriz) {: Este é o cabeçalho do método. Ele declara o método como private 
    (apenas acessível dentro da classe atual), static (pertence à classe e não a instâncias individuais) e retorna uma lista de objetos 
    Aresta. Ele recebe uma matriz de inteiros como parâmetro.

    List<Aresta> indicesDosUns = new ArrayList<>();: Aqui é criada uma lista para armazenar os índices das arestas que contêm o 
    valor 1. A lista é inicializada como uma ArrayList vazia.

    int tamanho = matriz.length;: O tamanho da matriz (número de linhas) é armazenado em uma variável chamada tamanho.

    for (int i = 0; i < tamanho; i++) {: Este loop externo itera sobre as linhas da matriz.

    for (int j = i; j < tamanho; j++) {: Este loop interno itera sobre as colunas da matriz, começando da diagonal principal (onde j é igual a i).

    if (matriz[i][j] == 1) {: Se o elemento da matriz na posição [i][j] for igual a 1, isso significa que encontramos uma aresta. 
    Um objeto Aresta é criado com os índices i e j e é adicionado à lista indicesDosUns.

*/
