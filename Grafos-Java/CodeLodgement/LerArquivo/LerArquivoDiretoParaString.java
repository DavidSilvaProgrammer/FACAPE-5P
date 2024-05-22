public LerArquivo(String nomeArquivo) {
    Path caminho = Paths.get("\\src\\main\\resources\\entradaTxt\\" + nomeArquivo + ".txt");        
    try {
        List<String> linhasDoArquivo = Files.readAllLines(caminho);
        transformaEmStr = String.join(" ", linhasDoArquivo);
        
        String[] transformaStrEmInt = transformaEmStr.split("\\s+");
        grafo = new int[transformaStrEmInt.length];
        for(int i = 0; i < transformaStrEmInt.length; i++){
            grafo[i] = Integer.parseInt(transformaStrEmInt[i]);
        } 
        
        // Restante do código para inicializar a matriz...
    } catch (IOException e) {
        transformaEmStr = "Erro inesperado: " + e.getMessage();
    }
}
