#include <pwmmotor.h>
#define LCD_ENABLE_PIN PIN_A4
#define LCD_RS_PIN PIN_A5
#define LCD_RW_PIN PIN_C6
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7
#include <lcd.c>

void main()
{  int16 data, ydata;
   lcd_init();
   setup_adc(ADC_CLOCK_DIV_2);  // fOSC/2 ayarlandý
   setup_adc_ports(ALL_ANALOG);  // tüm 8 kanal analog giriþ modunda
   set_adc_channel(5);  //ANS- RE0 - joystik y ekseni aktif
   output_c(0);

   while(TRUE)
   {
    setup_ccp1(CCP_PWM);  //PWM modu aktif hale geldi
    setup_timer_2(T2_DIV_BY_4,255,1);  //TMR2Prescale Value=4 oldu PR2=255 oldu
    set_pwm1_duty(0);
    setup_adc_ports(ALL_ANALOG);
    set_adc_channel(5);  // AN5 RE0 joystic y ekseni aktif
    data=read_adc();
    delay_ms(1);
    if(data==512)
    {
       ydata=0;
       setup_adc_ports(NO_ANALOGS);
       printf(lcd_putc,"\f ORTA \n %04Lu",ydata);
       set_pwm1_duty(ydata);
    }
    if(data>512)
    {
       output_high(PIN_C0);  // RC0=1 oldu NPN iletimi ileri yön aktif
       ydata=(ydata-512)*2+1;
       setup_adc_ports(NO_ANALOGS);
       printf(lcd_putc,"\f ILERI \n %04Lu",ydata);
       set_pwm1_duty(ydata);
    }
    if(data<512)
    {
       output_high(PIN_C0);  // RC0=0 oldu PNP iletimde geri yön aktif
       ydata=(511-ydata)*2+1;
       setup_adc_ports(NO_ANALOGS);
       printf(lcd_putc,"\f GERI \n %04Lu",ydata);
       set_pwm1_duty(ydata);
    }
       delay_ms(5);
   }

}



