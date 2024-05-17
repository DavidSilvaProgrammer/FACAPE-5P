for (GrafoAresta aresta : indicesDosUns) {
    System.out.println(aresta.getAresta());
}


/*

é um loop for-each em Java. Este tipo de loop é usado para iterar sobre elementos de uma coleção, como uma lista ou um array. Vamos detalhar o que ele faz no contexto do código fornecido:
Detalhes do Loop for-each

    Iteração Sobre a Lista indicesDosUns:
        A variável indicesDosUns é uma lista de objetos GrafoAresta que foi retornada pelo método encontrarIndicesDosUns.
        Cada elemento da lista indicesDosUns é um objeto do tipo GrafoAresta, representando uma aresta encontrada na matriz de adjacência.

    Variável aresta:
        Em cada iteração do loop, a variável aresta é atribuída ao próximo objeto GrafoAresta na lista indicesDosUns.

    Chamada ao Método getAresta:
        Dentro do loop, o método getAresta é chamado no objeto aresta.
        O método getAresta retorna uma String no formato "A(aresta_esquerda,aresta_direita)", onde aresta_esquerda e aresta_direita são os vértices da aresta.

    Impressão da String:
        A String retornada pelo método getAresta é então impressa no console usando System.out.println.

Propósito do Loop

O propósito desse loop é iterar sobre todas as arestas encontradas (representadas pelos objetos GrafoAresta na lista indicesDosUns) e imprimir uma representação legível de cada aresta. 
Aqui está um exemplo ilustrativo do que esse loop faz:

    Suponha que a lista indicesDosUns contém três objetos GrafoAresta representando as seguintes arestas:
        Aresta entre os vértices 0 e 1 (GrafoAresta(0, 1))
        Aresta entre os vértices 0 e 3 (GrafoAresta(0, 3))
        Aresta entre os vértices 1 e 2 (GrafoAresta(1, 2))

    O loop for-each iterará sobre esses três objetos.

    Na primeira iteração:
        aresta é GrafoAresta(0, 1)
        aresta.getAresta() retorna "A(0,1)"
        System.out.println("A(0,1)") imprime A(0,1)

    Na segunda iteração:
        aresta é GrafoAresta(0, 3)
        aresta.getAresta() retorna "A(0,3)"
        System.out.println("A(0,3)") imprime A(0,3)

    Na terceira iteração:
        aresta é GrafoAresta(1, 2)
        aresta.getAresta() retorna "A(1,2)"
        System.out.println("A(1,2)") imprime A(1,2)

Conclusão

Portanto, o loop for-each é usado para percorrer todos os objetos GrafoAresta na lista indicesDosUns e imprimir uma representação de cada 
  aresta no formato "A(x,y)" para cada aresta presente na matriz de adjacência original.

  */
