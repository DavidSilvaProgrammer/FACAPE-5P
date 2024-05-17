public void realizarAcao() {
    String nomeArquivo = transmissor; // Supondo que transmissor contenha o nome do arquivo
    projeto.projetografos.LerArquivo lerArquivo = new projeto.projetografos.LerArquivo(nomeArquivo);

    // Obtém o conteúdo do arquivo
    String conteudoArquivo = lerArquivo.getConteudoArquivo();

    // Define o conteúdo na caixa de saída
    caixaSaida.setText(conteudoArquivo);
}
