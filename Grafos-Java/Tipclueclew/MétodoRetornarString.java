public class LerArquivo {

    private String[] transformaEmStr;

    public LerArquivo(String nomeArquivo) {
        Path caminho = Paths.get("C:\\Users\\lucas\\Desktop\\codigos\\projeto tenorio\\" + nomeArquivo + ".txt");
        try {
            byte[] bytesDoArquivo = Files.readAllBytes(caminho);
            String conteudoDoArquivo = new String(bytesDoArquivo);
            transformaEmStr = conteudoDoArquivo.split("\\s+");
        } catch (Exception e) 

            transformaEmStr = "Erro inesperado: " + e.getMessage();
            return transformaEmStr;
        } 
    }

    // Método para retornar o vetor de strings
    public String[] getStr() {
        return transformaEmStr;
    }
}


/*

Agora, você pode instanciar a classe LerArquivo com o nome do arquivo desejado e usar 
o método getTransformaStrEmInt() para obter o vetor de strings correspondente ao 
conteúdo do arquivo. Por exemplo:

LerArquivo lerArquivo = new LerArquivo("nome_do_arquivo");
String[] vetorDeStrings = lerArquivo.getTransformaStrEmInt();

// Agora você pode usar o vetorDeStrings como desejar, por exemplo, em um JFrame
// JFrame meuFrame = new JFrame();
// meuFrame.setMeuArray(vetorDeStrings);


o método getMessage() retorna uma string.

No contexto de exceções em Java, o método getMessage() é usado para obter 
uma descrição textual da exceção que ocorreu. Ele retorna uma string que descreve a exceção. 
Se a exceção não tiver uma mensagem associada, getMessage() retornará null.

Por exemplo, se você tiver uma exceção IOException e ela for capturada em uma variável chamada e, 
você pode chamar e.getMessage() para obter uma descrição da exceção:

catch (IOException e) {
    String mensagemDeErro = e.getMessage();
    // Faça algo com a mensagem de erro...
}

Nesse caso, mensagemDeErro conterá a descrição textual da exceção IOException, se estiver disponível. 
Essa mensagem geralmente contém informações úteis sobre o que deu errado, ajudando 
a entender a causa da exceção.

*/
