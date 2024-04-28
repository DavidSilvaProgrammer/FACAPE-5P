public class Main {
    public static void main(String[] args) {
        // String de exemplo
        String conteudoDoArquivo = "Esta é uma string de exemplo    com múltiplos espaços em branco.";

        // Usando split("\\s+")
        String[] substringsComEspacosMultiplos = conteudoDoArquivo.split("\\s+");
        System.out.println("Usando split(\"\\\\s+\"):");
        for (String substring : substringsComEspacosMultiplos) {
            System.out.println(substring);
        }

        System.out.println(); // Adiciona uma linha em branco

        // Usando split(" ")
        String[] substringsComEspacoSimples = conteudoDoArquivo.split(" ");
        System.out.println("Usando split(\" \"):");
        for (String substring : substringsComEspacoSimples) {
            System.out.println(substring);
        }
    }
}
