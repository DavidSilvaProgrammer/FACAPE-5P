import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<List<Integer>> matrizDinamica = new ArrayList<>();

        // Adicionando elementos às linhas da matriz dinâmica
        matrizDinamica.add(new ArrayList<>());
        matrizDinamica.get(0).add(1);
        matrizDinamica.get(0).add(2);

        matrizDinamica.add(new ArrayList<>());
        matrizDinamica.get(1).add(3);
        matrizDinamica.get(1).add(4);
        matrizDinamica.get(1).add(5);

        // Imprimindo a matriz dinâmica
        for (List<Integer> linha : matrizDinamica) {
            for (int elemento : linha) {
                System.out.print(elemento + " ");
            }
            System.out.println();
        }
    }
}


/*
Em linguagens como Java, isso pode ser implementado usando listas (como ArrayList) em vez de arrays simples 
para representar cada linha da matriz. Dessa forma, você pode ter uma lista para cada linha da matriz e 
cada uma dessas listas pode ter um tamanho diferente.

Neste exemplo, matrizDinamica é uma lista de listas, onde cada lista interna representa uma linha da matriz. 
A primeira linha contém os elementos 1 e 2, enquanto a segunda linha contém os elementos 3, 4 e 5. 
Isso demonstra como você pode ter linhas de diferentes tamanhos em uma matriz dinâmica.

*/
