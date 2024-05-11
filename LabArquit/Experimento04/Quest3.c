sbit LCD_RS at RE0_bit;
sbit LCD_RW at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D0 at RD0_bit;
sbit LCD_D1 at RD1_bit;
sbit LCD_D2 at RD2_bit;
sbit LCD_D3 at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE0_bit;
sbit LCD_RW_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D0_Direction at TRISD0_bit;
sbit LCD_D1_Direction at TRISD1_bit;
sbit LCD_D2_Direction at TRISD2_bit;
sbit LCD_D3_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

unsigned tecla = -1;
unsigned entrar = 0;
char senha[4];

void varredura(void);
void verificar_senha(void);


void interrupt(){
     if(RBIF_bit){
         RBIF_bit = 0;
         if(entrar < 2){
             entrar++;
         }else if(entrar == 2){ // Evitar o problema das interrupcoes da borda de subida e de descida (quando pressiona e solta o botao, e gerada duas interrupcoes).
             entrar = 0;
             if(RB3_bit == 0 && RB4_bit == 0){ // Tecla 1
                 tecla = 1;
             }else if(RB3_bit == 0 && RB5_bit == 0){ // Tecla 4
                 tecla = 4;
             }else if(RB3_bit == 0 && RB6_bit == 0){ // Tecla 7
                 tecla = 7;
             }else if(RB2_bit == 0 && RB4_bit == 0){ // Tecla 2
                 tecla = 2;
             }else if(RB2_bit == 0 && RB5_bit == 0){ // Tecla 5
                 tecla = 5;
             }else if(RB2_bit == 0 && RB6_bit == 0){ // Tecla 8
                 tecla = 8;
             }else if(RB2_bit == 0 && RB7_bit == 0){ // Tecla 0
                 tecla = 0;
             }else if(RB1_bit == 0 && RB4_bit == 0){ // Tecla 3
                 tecla = 3;
             }else if(RB1_bit == 0 && RB5_bit == 0){ // Tecla 6
                 tecla = 6;
             }else if(RB1_bit == 0 && RB6_bit == 0){ // Tecla 9
                 tecla = 9;
             }
         }
     }
}

void varredura(void){
     RB0_bit = 0;
     RB1_bit = 1;
     RB2_bit = 1;
     RB3_bit = 1;
     delay_ms(10);
     RB0_bit = 1;
     RB1_bit = 0;
     RB2_bit = 1;
     RB3_bit = 1;
     delay_ms(10);
     RB0_bit = 1;
     RB1_bit = 1;
     RB2_bit = 0;
     RB3_bit = 1;
     delay_ms(10);
     RB0_bit = 1;
     RB1_bit = 1;
     RB2_bit = 1;
     RB3_bit = 0;
     delay_ms(10);
}

void verificar_senha(void){
     if(senha[0] == '1' && senha[1] == '2' && senha[2] == '3' && senha[3] == '4'){
         RD0_bit = 0;
         RD3_bit = 1;
     }else{
         RD0_bit = 1;
         RD3_bit = 0;
     }
     delay_ms(5000);
     RD0_bit = 1;
     RD3_bit = 1;
     Lcd_Cmd(_LCD_CLEAR);
}


void main() {
     unsigned posicao = 1;
     unsigned quantidade_teclas = 0;
     char mensagem[] = {"Digite a senha:"};
     bit msg;
     TrisB = 0xF0;
     TrisD = 0x00;
     TrisE = 0x00;
     PortB = 0xF0;
     PortD = 0xFF;
     PortE = 0x00;
     RBPU_bit = 0;
     ADCON1 = 0x0F;
     CMCON = 7;
     GIE_bit = 1;
     RBIE_bit = 1;
     Lcd_Init();
     msg = 1;
     // RBIF_bit = 0;
     while(1){
         varredura();
         if(msg){
             Lcd_Out(1, 1, mensagem);
             msg = 0;
         }
         if(tecla == 1){
             Lcd_Out(2, posicao, "1");
             senha[quantidade_teclas] = '1';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 2){
             Lcd_Out(2, posicao, "2");
             senha[quantidade_teclas] = '2';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 3){
             Lcd_Out(2, posicao, "3");
             senha[quantidade_teclas] = '3';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 4){
             Lcd_Out(2, posicao, "4");
             senha[quantidade_teclas] = '4';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 5){
             Lcd_Out(2, posicao, "5");
             senha[quantidade_teclas] = '5';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 6){
             Lcd_Out(2, posicao, "6");
             senha[quantidade_teclas] = '6';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 7){
             Lcd_Out(2, posicao, "7");
             senha[quantidade_teclas] = '7';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 8){
             Lcd_Out(2, posicao, "8");
             senha[quantidade_teclas] = '8';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 9){
             Lcd_Out(2, posicao, "9");
             senha[quantidade_teclas] = '9';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }else if(tecla == 0){
             Lcd_Out(2, posicao, "0");
             senha[quantidade_teclas] = '0';
             tecla = -1;
             posicao++;
             quantidade_teclas++;
         }
         
         if(quantidade_teclas == 4){
             quantidade_teclas = 0;
             posicao = 1;
             msg = 1;
             verificar_senha();
         }
     }
}
