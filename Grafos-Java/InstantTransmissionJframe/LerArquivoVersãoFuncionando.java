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

    private String transformaEmStr;

    public LerArquivo(String nomeArquivo) {
        Path caminho = Paths.get("C:\\Users\\david\\OneDrive\\Área de Trabalho\\InterfaceIntegração\\src\\main\\resources\\entradaTxt\\" + nomeArquivo + ".txt");
        try {
            byte[] bytesDoArquivo = Files.readAllBytes(caminho);
            transformaEmStr = new String(bytesDoArquivo);
        } catch (Exception e) {
            // Em caso de exceção, definimos transformaEmStr como uma mensagem de erro
            transformaEmStr = "Erro inesperado: " + e.getMessage();
        }
    }

    // Método para retornar a string com o conteúdo do arquivo
    public String getConteudoArquivo() {
        return transformaEmStr;
    }
}
