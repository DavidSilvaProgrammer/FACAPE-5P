import javax.swing.JFrame;
import javax.swing.JLabel;

public class MeuFrame extends JFrame {

    public MeuFrame(String[] valores) {
        setTitle("Valores do Arquivo");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Crie um JLabel para cada valor no vetor
        for (int i = 0; i < valores.length; i++) {
            JLabel label = new JLabel(valores[i]);
            label.setBounds(50, 50 + i * 20, 200, 20); // Define a posição e o tamanho do JLabel
            add(label); // Adiciona o JLabel ao JFrame
        }

        setSize(300, 300); // Define o tamanho do JFrame
        setLayout(null); // Desativa o layout automático para posicionar manualmente os componentes
        setVisible(true); // Torna o JFrame visível
    }

    public static void main(String[] args) {
        // Exemplo de utilização do JFrame com os valores do vetor
        String[] valores = {"Valor 1", "Valor 2", "Valor 3", "Valor 4"};
        MeuFrame meuFrame = new MeuFrame(valores);
    }
}


/*

Se você deseja exibir os valores do vetor de strings em um JFrame em Java, 
você pode fazer isso criando componentes de interface gráfica, 
como JLabels, para exibir os valores do vetor. Aqui está um exemplo 
básico de como você pode fazer isso:

Neste exemplo, criamos uma classe MeuFrame que estende JFrame. No construtor MeuFrame, 
recebemos o vetor de strings como parâmetro e criamos um JLabel para cada valor no vetor. 
Em seguida, definimos a posição e o tamanho de cada JLabel e os adicionamos ao JFrame. 
Finalmente, definimos o tamanho do JFrame, desativamos o layout automático e tornamos o JFrame visível.

Você pode substituir o vetor de strings de exemplo (valores) pelo vetor de strings que você obteve 
do seu arquivo, como o vetor transformaStrEmInt no seu caso. Isso exibirá os valores do vetor 
no JFrame quando o programa for executado.

*/
