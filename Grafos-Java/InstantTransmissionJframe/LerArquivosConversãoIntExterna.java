package projeto.projetografos;

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
        Conversora conversora = new Conversora(); // Instanciando a classe Conversor
        return conversora.conversorGrafoDeAresta(transformaEmStr); // Usando o método da classe Conversor
    }
}
