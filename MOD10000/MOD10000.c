#include <MOD10000.h>
void goster(int8, int8, int1);   //SEMBOLÝK TANIM
void main()
{
int8 s,d;
int16 i;

   while(TRUE)
   {
     for(s=0;s<=59;s++)
      for(d=0;d<=59;d++)
       for(i=1;i<=250;i++)  //250 iken saniyede bir, 15000 iken dk da bir deðiþim yaklaþýk 40ms aralýklarla deðiþecek þekilde ayarlandý
         goster(s,d,1);   // yaklaþýk 4 ms zaman alýr
   }

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







