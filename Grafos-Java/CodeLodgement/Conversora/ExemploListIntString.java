import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Criando uma lista de inteiros
        List<Integer> listaInteiros = new ArrayList<>();
        listaInteiros.add(10);
        listaInteiros.add(20);
        listaInteiros.add(30);

        // Imprimindo a lista de inteiros
        System.out.println("Lista de inteiros:");
        for (Integer numero : listaInteiros) {
            System.out.println(numero);
        }

        // Criando uma lista de strings
        List<String> listaStrings = new ArrayList<>();
        listaStrings.add("Java");
        listaStrings.add("é");
        listaStrings.add("divertido");

        // Imprimindo a lista de strings
        System.out.println("\nLista de strings:");
        for (String palavra : listaStrings) {
            System.out.println(palavra);
        }
    }
}

/*
As setas <> em Java são usadas para especificar o tipo de dados que uma classe genérica (ou interface genérica) 
pode conter. Uma classe genérica é uma classe que pode ser parametrizada com um tipo específico. Isso permite criar 
classes que possam lidar com diferentes tipos de dados de maneira segura e flexível.

    List<Integer> indica que estamos criando uma lista que pode conter objetos do tipo Integer.
    List<String> indica que estamos criando uma lista que pode conter objetos do tipo String.

Esses são exemplos de uso de classes genéricas em Java. Eles fornecem segurança de tipo durante 
a compilação e facilitam o trabalho com diferentes tipos de dados em estruturas de dados como listas.


*/
