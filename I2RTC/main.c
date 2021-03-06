#include <main.h>
#include "DS1307.C"
#include "ds18b20.c"
#define LCD_ENABLE_PIN PIN_A4
#define LCD_RS_PIN PIN_A5
#define LCD_RW_PIN PIN_C6
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7
#include <lcd.c>
int8 tusalgila();   //SEMBOL�K TANIM
float sicaklik;
void main()
{ signed int8 day,mth,year,dow,hr,min,sec,i, k=0;
   ds1307_init();
   lcd_init();
   ds1307_set_date_time(13,8,20,4,10,20,0);   
   while(TRUE)
   { k++;
     ds1307_get_date(day,mth,year,dow);
     ds1307_get_time(hr,min,sec);
     sicaklik=ds1820_read();
     if(k<=7)
     printf(lcd_putc,"\f   %02u/%02u/20%02u    \n    %02u:%02u:%02u:",day,mth,year,hr,min,sec);
     else
     {
     printf(lcd_putc,"\f   SICAKLIK \n      %3.1f %cC",sicaklik/10+3,223);
     if(k>=14) k=0;
     }
     delay_ms(150);
     switch (tusalgila())  // 4 ms zaman al�r
     {
     case 2:  //saat artt�r
     hr++;
     if(hr>=24) hr=0;    
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 1:  //saat azalt
     hr--;
     if(hr<=-1) hr=23;    
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 4:  //dakika artt�r
     min++;
     if(min>=60) min=0;     
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);     
     break;
     case 3:  //dakika azalt
     min--;
     if(min<=-1) min=59;    
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 5:  //g�n azalt
     day--;
     if(day<=0) year=31;
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 6:  //g�n artt�r
     day++;
     if(min>=32) min=1;     
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 7:  //ay azalt
     mth--;
     if(mth<=0) mth=12;
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 8:  //ay artt�r
     mth++;
     if(mth>=13) mth=1;     
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 9:  //y�l azalt
     year--;
     if(year<=19) year=99;
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
     case 10:  //y�l artt�r
     year++;
     if(year>=100) year=20;     
     sec=0;  // ayarlardan sonra saniyeyi resetler
     ds1307_set_date_time(day,mth,year,dow,hr,min,sec);
     break;
        
     } 
   }

}


int8 tusalgila()
{
int8 key=0;   //key=0 olsayd� bas�l� tutulan butonun say�s� g�sterirdi. sadece key yaz�l�nca son bas�lan butonun say�s�n� g�steriyor //int8 key=0; yada 1....16 de�erlerinden farkl� bir de�er key=20
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
