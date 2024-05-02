import java.util.Scanner;

public class PreencherVetorString {
	public static void main(String[] args) {
	    
	    Scanner scanner = new Scanner(System.in);
	    
	    String meuVetor[] = new String[10];
	    
	    
	    for (int i=0;i<10;i++){
	        System.out.println("Digite o "+(i+1)+"º nome do vetor:");
		    meuVetor[i] = scanner.nextLine();
	    }
	    
	    System.out.println("Processando os valores inseridos...");
	    
	    System.out.println("Valores no vetor:");
	    
	    for (int i=0;i<10;i++){
	        System.out.println((i+1)+": "+meuVetor[i]);
	    }
	}
}
