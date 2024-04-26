//programa com prioridade de interrupção
//faz piscar alguns LED's em função da interrupção gerada)

      //RTI(Rotina de Tratamento de Interrupção)
      
unsigned i, j;
void interrupt(){ //RTI para prioridade alta ao apertar
//tecla INT1
        if(INT1IF_bit){//este bit é setado pelo hardware.
                              //Aqui verifica se está setado.
               INT1IF_bit=0; //este bit deve ser limpo neste momento
               //para evitar chamadas indevidas
               for(i=0;i<20;i++){
                                 RD1_bit= ~RD1_bit; //faz o LED em D1 piscar a uma
                                 //frequência de 2Hz por 20 vezes
                            delay_ms(250);
               }
        }
}

void interrupt_low(){//RTI para pioridade baixa ao apertar
//a tecla IN2
    if(INT2IF_bit){//este bit é setado pelo hardware. Aqui
    //verifica-se se está setado
                  INT2IF_bit=0; //este bit deve ser limpo
                  //neste momento para evitar chamadas indevidas
                  for(j=0;j<20;j++){
                                    RD2_bit= ~RD2_bit; //faz o LED em D2
                                    //piscar a uma frequência de 2HZ por
                                    //20 vezes
                                    delay_ms(250);
                  
                  }
    }

}


void main() {

     TrisB=0xFF; //configura todo o port B  como entrada
     TrisD=0x00; //configura todo o port D como saída
     PortB=0xFF; //coloca todo o port B em nível alto
     //(chaves são baixo-ativos)
     PortD=0xFF; //coloca todo o port D em nível alto
     //(LEDs apagados)
     RBPU_bit=0; //ativa os pull-ups internos do port B.
     ADCON1= 0x0F; //configura todos os pinos I/O  digital
     IPEN_bit = 1; //habilita prioridade de interrrupção
     GIE_bit = 1; //habilitaa interrupção global
     PEIE_bit = 1; //habilita interrupção por periféricos
     INT1IE_bit = 1; //habilita interrupção externa 1(INT1)
     INT2IE_bit= 1; //habilita interrupção externa 2(INT2)
     INT1IP_bit = 1; //configura prioridade alta para INT1
     INT2IP_bit = 0; //configura prioridade alta para INT2
     INTEDG1_bit= 1; //torna INT1 sensível ao transbordo de subida
     INTEDG2_bit=1; //idem ao INT2. Isto faz a interrupção ocorrer
     //ao soltat a tecla 
     while(1); // laço infinito vazio. Todo o processamento
     //ocorre nas interrupções. Portanto, outras operações poderiam
     //ser adicionadas dentro do while
     
     
     
     
     





}