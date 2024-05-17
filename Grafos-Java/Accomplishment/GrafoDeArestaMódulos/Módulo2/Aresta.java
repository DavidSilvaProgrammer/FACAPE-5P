public class Aresta {
    private int aresta_esquerda;
    private int aresta_direita;

    public Aresta(int aresta_esquerda, int aresta_direita) {
        this.aresta_esquerda = aresta_esquerda + 1;
        this.aresta_direita = aresta_direita + 1;
    }

    public String getAresta() {
        return "A(" + aresta_esquerda + "," + aresta_direita + ")";
    }
}
