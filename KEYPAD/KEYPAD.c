#include <KEYPAD.h>
void goster(int8, int8, int1);   //SEMBOLÝK TANIM
int8 tusalgila();   //SEMBOLÝK TANIM

void main()
{

   while(TRUE)
   {
      goster(0,tusalgila(),0); //en saðdaki deðer 1 olsaydý sondan 2.displayin sað alt köþesinde nokta þeklinde led yanardý. 0 oldugu için yanmaz.
   }

}

int8 tusalgila()
{

int8 key;   //key=0 olsaydý basýlý tutulan butonun sayýsý gösterirdi. sadece key yazýlýnca son basýlan butonun sayýsýný gösteriyor //int8 key=0; yada 1....16 deðerlerinden farklý bir deðer key=20
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

void goster(int8 saat, int8 dakika, int1 k)
{
int8 sonlar,sbirler,donlar,dbirler;
static int8 sayac;
sayac++;
if(sayac>=250) sayac=0;
sonlar=saat/10;
sbirler=saat%10;
donlar=dakika/10;
dbirler=dakika%10;
output_b(0b00000001);
output_d(sonlar);
delay_ms(1);
output_b(0b00000010);
if(sayac<=125 && k) sbirler=sbirler|0b00010000;
output_d(sbirler);
delay_ms(1);
output_b(0b00000100);
output_d(donlar);
delay_ms(1);
output_b(0b00001000);
output_d(dbirler);
delay_ms(1);
output_b(0);
}
