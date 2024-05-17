    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {                                         


this.tela2.setVisible(true); 
this.tela2.transmissor = this.caixaEntrada1.getText();

//LerArquivo lerArquivo = new LerArquivo(this.tela2.transmissor);
//this.tela2.transmissor = lerArquivo.getConteudoArquivo();

this.tela2.realizarAcao();

        
    


    }    
