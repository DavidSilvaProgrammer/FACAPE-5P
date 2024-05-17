package projeto.projetografos;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class LerArquivo {
    
    private int[] grafo; // Vetor de inteiros para armazenar os números do arquivo
    private String transformaEmStr; // String para armazenar o conteúdo do arquivo
    private int[][] matriz; // Matriz de inteiros para representar o grafo

    // Construtor da classe LerArquivo
    public LerArquivo(String nomeArquivo) {
        // Define o caminho do arquivo
        Path caminho = Paths.get("Caminho para o arquivo" + nomeArquivo + ".txt");        
        try {
            // Lê todos os bytes do arquivo
            byte[] bytesDoArquivo = Files.readAllBytes(caminho);
            // Converte os bytes em uma string
            transformaEmStr = new String(bytesDoArquivo);
            
            // Converte a string em um vetor de inteiros
            String[] transformaStrEmInt = transformaEmStr.split("\\s+");
            grafo = new int[transformaStrEmInt.length];
            for(int i = 0; i < transformaStrEmInt.length; i++){
                grafo[i] = Integer.parseInt(transformaStrEmInt[i]);
            } 
            
            // Cria a matriz de inteiros a partir do vetor
            int linhacoluna = (int) Math.sqrt(transformaStrEmInt.length);
            int linhacoluna1 = linhacoluna;
            matriz = new int[linhacoluna][linhacoluna];
            int index = 0;
            
            for(int i =0; i < linhacoluna; i++){
                for(int j = 0; j < linhacoluna1;  j++){
                    matriz[i][j] = grafo[index];
                    index++;
                }
            }
        } catch (IOException e) {
            // Em caso de exceção, define transformaEmStr como uma mensagem de erro
            transformaEmStr = "Erro inesperado: " + e.getMessage();
        }
    }
    
    // Método para retornar a representação do grafo em formato de string
    public String getConteudoArquivo() {
        // Instancia a classe Conversora
        Conversora conversora = new Conversora();
        // Converte a matriz de adjacência em uma representação de grafo de aresta
        return conversora.conversorGrafoDeAresta(matriz);
    }
}
