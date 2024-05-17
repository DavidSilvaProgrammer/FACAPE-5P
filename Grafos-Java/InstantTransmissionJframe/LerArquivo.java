package projeto.projetografos;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author usuario
 */


import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class LerArquivo {

    public String transformaEmStr;
    public int[] grafo;

    public LerArquivo(String nomeArquivo) {
        Path caminho = Paths.get("C:\\Users\\david\\OneDrive\\Área de Trabalho\\InterfaceIntegração\\src\\main\\resources\\entradaTxt\\" + nomeArquivo + ".txt");
        try {
            byte[] bytesDoArquivo = Files.readAllBytes(caminho);
            transformaEmStr = new String(bytesDoArquivo);
            
            
            //transformar os numeros em um vetor de inteiros
            String[] transformaStrEmInt = transformaEmStr.split("\\s+"); //divide a string utilizando espaços como parametro
            grafo = new int[transformaStrEmInt.length]; //criando um vetor do tamanho de transformaStrEmInt
            for(int i = 0; i < transformaStrEmInt.length; i++){
                    grafo[i] = Integer.parseInt(transformaStrEmInt[i]); //Transporta os STR para o novo vetor e transforma em INT
                } 
            int linhacoluna = (int) Math.sqrt(transformaStrEmInt.length);/*pegando o tamanho de linhas e colunas usando a raiz da matriz*/
            int linhacoluna1 = linhacoluna; /*cópia de linhacoluna para não ter problema nos loops encadiados*/
            int[][] matriz = new int[linhacoluna][linhacoluna]; /*nova matriz criada com o tamanho total de linhas e colunas geradas pela raiz da matriz original)*/
            int index = 0;
            
            for(int i =0; i < linhacoluna; i++){
                for(int j = 0; j < linhacoluna1;  j++){
                matriz[i][j] = grafo[index];
                index++;
                }
            }
        } catch (Exception e) {
            // Em caso de exceção, definimos transformaEmStr como uma mensagem de erro
            transformaEmStr = "Erro inesperado: " + e.getMessage();
        }
    }
    
    int[][] matriz = {
    {0, 1, 0, 1, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 1}
};


        // Chama o método de conversão da classe Conversora para converter a matriz de adjacência em um grafo de aresta
        String matrizString = Conversora.conversorGrafoDeAresta(matriz);
    
    // Método para retornar a string com o conteúdo do arquivo
    public String getConteudoArquivo() {
        return matrizString;
    }
}
