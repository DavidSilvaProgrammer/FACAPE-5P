/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package projeto.grafos;

/**
 *
 * @author usuario
 */
public class Tela2 extends javax.swing.JFrame {
    
    
    public String transmissor = "VALOR INICIAL DO STRING";
    
    /**
     * @return the transmissor
     */
    public String getTransmissor() {
        return transmissor;
        
    }
    
    
    

    /**
     * Creates new form Tela1
     */
    
    
    public Tela2() {
        initComponents();
        
        

    }
    
    public void realizarAcao(){
        caixaSaida.setText(transmissor);
        
}
    
    


    
  

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        caixaEntrada2 = new javax.swing.JFormattedTextField();
        jButton1 = new javax.swing.JButton();
        caixaSaida = new javax.swing.JTextField();
        label3 = new javax.swing.JLabel();

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(700, 700));
        setSize(new java.awt.Dimension(700, 700));
        getContentPane().setLayout(null);

        jLabel1.setFont(new java.awt.Font("Cantarell", 0, 24)); // NOI18N
        jLabel1.setText("** RESULTADO **");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(250, 40, 200, 50);

        jLabel2.setFont(new java.awt.Font("Cantarell", 1, 18)); // NOI18N
        jLabel2.setText("Digite o nome do novo arquivo:");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(140, 420, 310, 19);

        caixaEntrada2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                caixaEntrada2ActionPerformed(evt);
            }
        });
        getContentPane().add(caixaEntrada2);
        caixaEntrada2.setBounds(140, 450, 470, 40);

        jButton1.setText("Converter");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(480, 500, 130, 40);

        caixaSaida.setText("Imprimindo"+this.getTransmissor());
        caixaSaida.addContainerListener(new java.awt.event.ContainerAdapter() {
            public void componentAdded(java.awt.event.ContainerEvent evt) {
                caixaSaidaComponentAdded(evt);
            }
        });
        caixaSaida.addAncestorListener(new javax.swing.event.AncestorListener() {
            public void ancestorAdded(javax.swing.event.AncestorEvent evt) {
                caixaSaidaAncestorAdded(evt);
            }
            public void ancestorMoved(javax.swing.event.AncestorEvent evt) {
            }
            public void ancestorRemoved(javax.swing.event.AncestorEvent evt) {
            }
        });
        caixaSaida.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseMoved(java.awt.event.MouseEvent evt) {
                caixaSaidaMouseMoved(evt);
            }
        });
        caixaSaida.addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                caixaSaidaComponentShown(evt);
            }
        });
        caixaSaida.addInputMethodListener(new java.awt.event.InputMethodListener() {
            public void caretPositionChanged(java.awt.event.InputMethodEvent evt) {
            }
            public void inputMethodTextChanged(java.awt.event.InputMethodEvent evt) {
                caixaSaidaInputMethodTextChanged(evt);
            }
        });
        caixaSaida.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                caixaSaidaActionPerformed(evt);
            }
        });
        getContentPane().add(caixaSaida);
        caixaSaida.setBounds(120, 120, 500, 270);
        getContentPane().add(label3);
        label3.setBounds(520, 10, 110, 60);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    
    private void caixaEntrada2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_caixaEntrada2ActionPerformed
        // TODO add your handling code here:
        
          

    }//GEN-LAST:event_caixaEntrada2ActionPerformed

    private void caixaSaidaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_caixaSaidaActionPerformed
       
      

    }//GEN-LAST:event_caixaSaidaActionPerformed

    private void caixaSaidaInputMethodTextChanged(java.awt.event.InputMethodEvent evt) {//GEN-FIRST:event_caixaSaidaInputMethodTextChanged
        
        
    }//GEN-LAST:event_caixaSaidaInputMethodTextChanged

    private void caixaSaidaComponentAdded(java.awt.event.ContainerEvent evt) {//GEN-FIRST:event_caixaSaidaComponentAdded
        
        
    }//GEN-LAST:event_caixaSaidaComponentAdded

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        
        

    realizarAcao();
    
    }//GEN-LAST:event_jButton1ActionPerformed

    private void caixaSaidaComponentShown(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_caixaSaidaComponentShown

        
        

// TODO add your handling code here:
    }//GEN-LAST:event_caixaSaidaComponentShown

    private void caixaSaidaMouseMoved(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_caixaSaidaMouseMoved
            // TODO add your handling code here:
    }//GEN-LAST:event_caixaSaidaMouseMoved

    private void caixaSaidaAncestorAdded(javax.swing.event.AncestorEvent evt) {//GEN-FIRST:event_caixaSaidaAncestorAdded
    realizarAcao();        // TODO add your handling code here:
    }//GEN-LAST:event_caixaSaidaAncestorAdded
    
    
    /**
     * @param args the command line arguments
     */
    
    
    
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Tela2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Tela2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Tela2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Tela2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
            new Tela2().setVisible(true);
            
            
        
            }
        });
    }
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JFormattedTextField caixaEntrada2;
    private javax.swing.JTextField caixaSaida;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JLabel label3;
    // End of variables declaration//GEN-END:variables

    
    



}
