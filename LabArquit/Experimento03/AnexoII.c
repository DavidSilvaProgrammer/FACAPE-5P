//Anexo II
//Programa que usa interrup��o pelo timer0 para gerar uma
//base de tempo e faz um LED piscar a cada 1s.

unsigned int cont = 0;
//FreqCM= FreCC/4 20MHz/4 = 5MHz
//T=1/F=1/5MHz= 0,2us =200ns.

void interrupt(){
     if(TMR0IF_bit){
                    TMR0IF_bit=0; //limpa esta flag pra evitar interrup��o
                   //nesse momento
                   cont++; //1s=1.000.00us /200us = 5.000
                   if (cont == 5000){//se for verdade, ent�o ses passou 1s
                      RD0_bit= !RD0_bit;
                      cont=0;
                   }
           TMR0L=6; //reinicializa��o de contagem do Timer 0
           }
     }
     //TE=(256- TMR0) * Prescale + CM
     //200.000ns = (256 - TMR0) * 4 * 200ns
     
void main(){
     TrisD= 0x00; //PortD configurado como sa�da
     PortD= 0xFE; //n�vel baixo no PortD (LEDs apagados)
     CMCON=7; //desabilita comparadores anal�gicos
     ADCON1= 0x0F; //define todos os canis como I/0 digital
     T0CON= 0xD1; //prescale = 4 ==> TE = 200us
     GIE_bit = 1; //habilita interrup��o global
     TMR0L=6; // obtido por meio da equa��o
     TMR0IE_bit=1;
     while(1);// n�o h� nada executado no la�o infinito

           
}
