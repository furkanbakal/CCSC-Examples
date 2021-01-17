#include <main.h>
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
   int16 xdata, ydata, xxdata, yydata;
   lcd_init();
   setup_adc(ADC_CLOCK_DIV_2);  //fOSC/2 ayarland�
   setup_adc_ports(ALL_ANALOG); //t�m B kanal analog giri� modunda---NO_ANALOGS yaz�lsayd� tamam� dijital olurdu
   set_adc_channel(5);  // AN5-RE0-JOYSTIK Y EKSEN� AKTIF
   while(TRUE)
   {  setup_adc_ports(ALL_ANALOG);
      set_adc_channel(5);  // AN5-RE0-JOYSTIK Y EKSEN� AKTIF
      ydata=read_adc();
      delay_ms(1);
      set_adc_channel(6);  // AN6-RE1-JOYSTIK x EKSEN� AKTIF
      xdata=read_adc();
      delay_ms(1);
      if(xdata==512) xxdata=0;
      if(ydata==512) yydata=0;
      if(xdata>512) xxdata=(xdata-512)*2+1;
      if(ydata<512) yydata=(512-xdata)*2+1;
      if(xdata<512) xxdata=(511-xdata)*2+1;
      if(ydata<512) yydata=(511-ydata)*2+1;
      
      setup_adc_ports(NO_ANALOGS);
      printf(lcd_putc,"\f (  x  ,  y  )  \n  %04Lu , %04Lu",xxdata,yydata);
      delay_ms(30);
   }

}
