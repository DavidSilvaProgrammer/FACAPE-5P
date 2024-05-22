import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

public class Main {
    public static void main(String[] args) {
        // Criando uma lista de listas de strings
        List<List<String>> listaDeListas = new ArrayList<>();
        List<String> lista1 = new ArrayList<>();
        lista1.add("A");
        lista1.add("B");
        lista1.add("C");
        listaDeListas.add(lista1);

        List<String> lista2 = new ArrayList<>();
        lista2.add("X");
        lista2.add("Y");
        listaDeListas.add(lista2);

        // Convertendo a lista de listas de strings para uma única string
        StringJoiner joiner = new StringJoiner(", ");
        for (List<String> lista : listaDeListas) {
            joiner.add(String.join(", ", lista));
        }
        String resultado = joiner.toString();

        // Imprimindo o resultado
        System.out.println(resultado);
    }
}

/*
Neste exemplo, String.join(", ", lista) é usado para converter cada lista interna para uma única string, 
onde os elementos são separados por , . Em seguida, usamos um StringJoiner para concatenar essas strings com , 
entre elas. O método joiner.toString() retorna a string resultante.
*/
