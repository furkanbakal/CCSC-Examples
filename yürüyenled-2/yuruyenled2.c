#include <yuruyenled2.h>

void main()
{
int8 i,data, data1=1, data2=128;
data=data1 | data2;
output_c(0);

   while(TRUE)
   {
     for(i=1;i<=7;i++)
     {
     output_c(data);
     delay_ms(250);                    // LEDLER ORTADA AYRILIP TEKRAR BİRLEŞİYOR
     data1=data1<<1;
     data2=data2>>1;
     data=data1 | data2;
   }
   for(i=1;i<=7;i++)
   {
     output_c(data);
     delay_ms(250);
     data1=data1>>1;
     data2=data2<<1;
     data=data1 | data2;

}
   }
}
