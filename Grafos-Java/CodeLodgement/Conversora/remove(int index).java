ArrayList<String> lista = new ArrayList<>();
lista.add("A");
lista.add("B");
lista.add("C");

String elementoRemovido = lista.remove(1); // Remove o elemento na posição 1 (B)
System.out.println(elementoRemovido); // Saída: B
System.out.println(lista); // Saída: [A, C]


/*
O método que remove elementos de uma lista em Java é remove(int index) da interface List. Aqui está como funciona:

    O método remove(int index) aceita um argumento do tipo inteiro index, que representa a posição do elemento 
    na lista que você deseja remover.
    Ele remove o elemento na posição especificada pelo índice na lista.
    Todos os elementos após o elemento removido são deslocados uma posição para a esquerda para preencher o espaço 
    deixado pelo elemento removido.
    Se o índice estiver dentro dos limites válidos da lista, o método removerá o elemento na posição especificada 
    pelo índice e retornará o elemento removido.
    Se o índice estiver fora dos limites da lista, uma exceção IndexOutOfBoundsException será lançada.

Este exemplo remove o elemento na posição 1 (o segundo elemento, "B") da lista e imprime o elemento removido e a lista resultante.
*/
