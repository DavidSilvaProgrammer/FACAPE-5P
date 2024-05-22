import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Criando uma lista de objetos (tipo genérico)
        List<Object> lista = new ArrayList<>();
        
        // Adicionando inteiros à lista
        lista.add(10);
        lista.add(20);
        
        // Adicionando strings à lista
        lista.add("Java");
        lista.add("é");
        lista.add("divertido");

        // Imprimindo a lista
        System.out.println("Lista de objetos:");
        for (Object elemento : lista) {
            // Verifica o tipo do elemento
            if (elemento instanceof Integer) {
                int numero = (Integer) elemento;
                System.out.println("Número: " + numero);
            } else if (elemento instanceof String) {
                String palavra = (String) elemento;
                System.out.println("Palavra: " + palavra);
            }
        }
    }
}

/*
Em Java, não é possível criar uma única lista que possa conter tanto objetos do tipo Integer quanto objetos 
do tipo String, porque as listas em Java são homogêneas, ou seja, elas devem conter apenas um tipo de elemento.

No entanto, você pode criar uma lista que contenha elementos de um tipo genérico, como Object, que é a 
superclasse de todas as classes em Java. Isso permitirá que você adicione tanto objetos do tipo Integer 
quanto objetos do tipo String à lista, mas você precisará fazer o casting para recuperar os elementos e 
usar os métodos específicos desses tipos.


Neste exemplo, criamos uma lista do tipo Object e adicionamos tanto inteiros quanto strings a ela. 
No entanto, ao recuperar os elementos da lista, precisamos verificar o tipo de cada elemento usando 
o operador instanceof e fazer o casting para o tipo apropriado (Integer ou String) antes de usá-lo. 
Isso torna o código mais complexo e propenso a erros. Geralmente, é preferível usar listas homogêneas 
sempre que possível.

*/
