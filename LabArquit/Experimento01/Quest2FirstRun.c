#define DIP_SWITCH PORTB

void main() {
     bit calcular;
     unsigned char ok = 0xFF; // Inicializa todas as entradas como alteradas
     int entrada;
     int saida;
     float m = 5.0; // Coeficiente angular da equação da reta
     float b = -10.0; // Coeficiente linear da equação da reta

     int i; // Definindo i fora do loop

     TRISB = 0xFF; // Configura os pinos RB0-RB7 como entrada
     TRISD = 0x00; // Configura os pinos RD0-RD7 como saída

     while(1) {
        // Lê os valores do dip-switch de entrada
        entrada = DIP_SWITCH;

        // Verifica se alguma chave mudou e precisa calcular a saída
        for (i = 0; i < 8; i++) {
            if (ok & (1 << i) && !((entrada >> i) & 1)) {
                ok &= ~(1 << i); // Marca a entrada como já processada
                calcular = 1;
            }
        }

        // Calcula a saída apenas se houver alterações nas entradas
        if (calcular) {
           // Converte a entrada para a escala da equação da reta (16)
           float entrada_escala = entrada * 16.0 / 255.0;

           // Calcula a saída com base na equação da reta
           float saida_float = m * entrada_escala + b;

           // Converte a saída de volta para a escala dos LEDs (256)
           saida = saida_float * 255.0 / 16.0;

           // Garante que a saída esteja dentro do intervalo permitido
           if (saida > 255) {
               saida = 255;
           } else if (saida < 0) {
               saida = 0;
           }

           // Atualiza a saída nos LEDs
           PORTD = saida;

           // Reseta a flag de cálculo
           calcular = 0;
        }
     }
}
