#include <STEPMOTOR.h>
#define LCD_ENABLE_PIN PIN_A4
#define LCD_RS_PIN PIN_A5
#define LCD_RW_PIN PIN_C6
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7
#include <lcd.c>

void saga(int16);
void sola(int16);
int tusalgila();

void main()
{
   int8 x=50;
   int1 k1=0, k2=0;
   lcd_init();
   while(TRUE)
   {    
    switch (tusalgila())  // 4 ms zaman alýr
     {
     case 2:  //step motor hýz arttýr
     x=x+5;
     if(x>=100) x=100;
     printf(lcd_putc,"\fHIZ BILGISI:%u",x);
     delay_ms(120);
     k1=0;
     k2=0;
     break;
     case 6:  //step motor hýz azalt
     x=x-5;
     if(x<=5) x=5;
     printf(lcd_putc,"\fHIZ BILGISI:%u",x);
     delay_ms(120);
     k1=0;
     k2=0;     
     break;
     case 3:  //saga dondur
     saga(x);
     if(k1==0)
     printf(lcd_putc,"\fSAGA DONUYOR\n HIZI:%u",x);    
     k1=1;
     k2=0;    
     break;
     case 7:  //sola dondur
     if(k2==0)
     printf(lcd_putc,"\fSOLA DONUYOR\n HIZI:%u",x);
     k2=1;
     k1=0;
     sola(x);
     break;     
     }             
     }
   }

void saga(int16 x)
{
output_a(0b00001010);
delay_ms(x);
output_a(0b00000110);
delay_ms(x);
output_a(0b00000101);
delay_ms(x);
output_a(0b00001001);
delay_ms(x);
output_a(0);
}
void sola(int16 x)
{
output_a(0b00001001);
delay_ms(x);
output_a(0b00000101);
delay_ms(x);
output_a(0b00000110);
delay_ms(x);
output_a(0b00001010);
delay_ms(x);
output_a(0);
}

int8 tusalgila()
{

int8 key=0;   //key=0 olsaydý basýlý tutulan butonun sayýsý gösterirdi. sadece key yazýlýnca son basýlan butonun sayýsýný gösteriyor //int8 key=0; yada 1....16 deðerlerinden farklý bir deðer key=20
  output_d(0b11110111);
delay_ms(1);
if(input(PIN_D4)==0) key=1;
if(input(PIN_D5)==0) key=2;
if(input(PIN_D6)==0) key=3;
if(input(PIN_D7)==0) key=4;
  output_d(0b11111011);
delay_ms(1);
if(input(PIN_D4)==0) key=5;
if(input(PIN_D5)==0) key=6;
if(input(PIN_D6)==0) key=7;
if(input(PIN_D7)==0) key=8;
  output_d(0b11111101);
delay_ms(1);
if(input(PIN_D4)==0) key=9;
if(input(PIN_D5)==0) key=10;
if(input(PIN_D6)==0) key=11;
if(input(PIN_D7)==0) key=12;
  output_d(0b11111110);
delay_ms(1);
if(input(PIN_D4)==0) key=13;
if(input(PIN_D5)==0) key=14;
if(input(PIN_D6)==0) key=15;
if(input(PIN_D7)==0) key=16;

return key;

}










