ArrayList<String> lista = new ArrayList<>();
lista.add("A");
lista.add("B");
lista.add("C");

String elemento = lista.get(1);
System.out.println(elemento);  // Saída: B

/*
O método get(int index) da classe ArrayList retorna o elemento na posição especificada pelo índice na lista. Aqui está como funciona:

    O método get(int index) aceita um argumento do tipo inteiro index, que representa a posição do elemento 
    na lista que você deseja recuperar.
    Ele retorna o elemento na posição especificada pelo índice na lista.
    Se o índice estiver dentro dos limites válidos da lista (ou seja, entre 0 e o tamanho da lista menos um), 
    o método retornará o elemento na posição especificada pelo índice.
    Se o índice estiver fora dos limites da lista, uma exceção IndexOutOfBoundsException será lançada.
  */
