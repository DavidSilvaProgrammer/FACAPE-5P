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



/*
O método geradorMatriz tem como objetivo criar e preencher uma matriz que representa um grafo de arestas, com base nas informações contidas na lista indicesDosUns. 
  Aqui está uma explicação detalhada do que o método faz:

    Cálculo do tamanho da matriz:
        
O método calcula o tamanho da matriz com base no número de arestas presentes na lista indicesDosUns acrescido de 1. 
  Isso ocorre porque o método usará essa informação para determinar o número de linhas e colunas da matriz.

    Inicialização da matriz:
        Uma lista de listas de strings, chamada matriz, é criada para armazenar a representação da matriz de adjacências do grafo de arestas.

    Preenchimento da matriz:
        O método itera sobre as linhas da matriz usando um loop for externo, onde i representa o índice da linha.
        Para cada linha, é criada uma nova lista chamada linha, que armazenará os elementos dessa linha.
        Dentro do loop externo, há outro loop for interno que itera sobre as colunas da matriz, onde j representa o índice da coluna.
        Dentro do loop interno, o método verifica em qual posição da matriz está:
            Se (i, j) é o canto superior esquerdo da matriz (primeira linha e primeira coluna), adiciona um espaço em branco à linha.
            Se (i, j) está na primeira linha (exceto o canto superior esquerdo), adiciona a representação da aresta correspondente à coluna j à linha.
            Se (i, j) está na primeira coluna (exceto o canto superior esquerdo), adiciona a representação da aresta correspondente à linha i à linha.
            Para todas as outras células da matriz, o método verifica se as arestas representadas pelos índices i - 1 e j - 1 
  (devido à indexação zero) são adjacentes. Se forem, adiciona "0" à linha; caso contrário, verifica se são adjacentes ou não e adiciona "1" ou "0", respectivamente.

    Construção da matriz completa:
        Após preencher uma linha completa, essa linha é adicionada à matriz.
        Esse processo é repetido para cada linha da matriz, resultando na construção completa da matriz de adjacências do grafo.

    Retorno da matriz:
        Por fim, o método retorna a matriz completa.

Portanto, o método geradorMatriz realiza todas as etapas necessárias para criar e preencher corretamente a matriz 
  de adjacências que representa o grafo de arestas com base nas informações fornecidas pela lista indicesDosUns.
  */

/*
linha.add("\t" + indicesDosUns.get(j - 1).getAresta());

  Na linha linha.add("\t" + indicesDosUns.get(j - 1).getAresta());, o índice j - 1 está sendo usado porque a matriz começa com a 
      representação das arestas a partir da segunda coluna.

Vamos analisar cada parte dessa expressão:

    indicesDosUns.get(j - 1): Aqui, j - 1 é usado para acessar os elementos da lista indicesDosUns. Lembre-se de que os índices 
      em Java começam em 0, então, se j for 1 (primeira coluna), queremos acessar o primeiro elemento da lista, que está no índice 0. 
      Se j for 2 (segunda coluna), queremos acessar o segundo elemento da lista, que está no índice 1, e assim por diante.

    .getAresta(): Após acessar o elemento correto da lista indicesDosUns, o método getAresta() é chamado para obter 
      a representação da aresta correspondente a essa posição.

Portanto, j - 1 é usado para garantir que estejamos acessando os elementos corretos da lista indicesDosUns de acordo com 
      os índices das colunas da matriz, considerando que os índices da lista começam em 0.

      */
