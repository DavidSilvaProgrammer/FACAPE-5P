public class Main
{
	public static void main(String[] args) {
		String[] vetor = {"elemento1", "elemento2", "elemento3"};
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < vetor.length; i++) {
        sb.append(vetor[i]);
        if (i < vetor.length - 1) {
            sb.append(", "); // Adiciona uma vírgula e um espaço entre os elementos, exceto para o último elemento
    }
}

String resultado = sb.toString();
System.out.println(resultado);


	}
}


/*

Criamos um objeto StringBuilder chamado sb. O StringBuilder é uma classe em Java que nos permite 
construir e manipular strings de forma eficiente.


Percorremos o vetor de strings vetor usando um loop for. Para cada elemento do vetor, usamos o método append() 
do StringBuilder para adicionar o elemento à string sendo construída (sb). Em seguida, verificamos se o elemento 
é o último do vetor. Se não for, adicionamos uma vírgula e um espaço após o elemento. Isso é feito para garantir 
que os elementos sejam separados corretamente na string final.

Depois de adicionar todos os elementos do vetor à string sb, usamos o método toString() 
do StringBuilder para obter a string final e atribuímos a uma variável chamada resultado.



a verdade, sb não é uma string, é um objeto da classe StringBuilder. O StringBuilder 
é uma classe que permite construir e manipular strings mutáveis em Java. Enquanto você usa 
sb.append() dentro do loop, você está adicionando caracteres ao objeto StringBuilder.

Quando você precisa converter um objeto StringBuilder em uma string convencional (do tipo java.lang.String), 
você utiliza o método toString(). Este método cria uma nova string que contém os mesmos caracteres que o StringBuilder 
atual. Isso é necessário porque StringBuilder e String são tipos de dados diferentes em Java, e você precisa de uma 
string convencional para armazenar ou manipular os dados de uma forma que seja mais comum em Java.

Então, sb.toString() retorna uma representação da sequência de caracteres atual contida em StringBuilder 
como uma string comum do tipo String.

Por isso, quando você faz String resultado = sb.toString();, você está essencialmente convertendo o conteúdo do 
StringBuilder sb em uma string convencional resultado, que agora pode ser tratada como uma string comum em Java.


*/
