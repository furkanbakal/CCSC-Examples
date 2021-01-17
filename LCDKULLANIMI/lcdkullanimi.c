#include <lcdkullanimi.h>
#define LCD_ENABLE_PIN PIN_A4
#define LCD_RS_PIN PIN_A5
#define LCD_RW_PIN PIN_C6
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7
#include <lcd.c>
void main()
{
   int8 x;
   lcd_init();
   while(TRUE)
   {    
     for(x=1;x<=7;x++)
     {         
     printf(lcd_putc,"\f");
     lcd_gotoxy(x,1);
     printf(lcd_putc,"BÝLGÝSAYAR");
     lcd_gotoxy(8-x,2);
     printf(lcd_putc," MUHENDIS ");
     delay_ms(200);
     }
     for(x=7;x>=1;x--)
     {         
     printf(lcd_putc,"\f");
     lcd_gotoxy(x,1);
     printf(lcd_putc,"BÝLGÝSAYAR");
     lcd_gotoxy(8-x,2);
     printf(lcd_putc," MUHENDIS ");
     delay_ms(200);
     }
   }

}
