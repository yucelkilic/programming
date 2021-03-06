/*******************************************************
Uygulama Adi: PIC16F877 ile Led Yakma-Sondurme Programi
Programin Amaci: RB0 pini ile LED'i belirli araliklarla
yakip sondurmek
*******************************************************/


// Kullanilacak PIC'in baslik dosyasi tanitiliyor
#include <16f877.h> 

//PIC konfigurasyon ayarlari:
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

// Osilator frekansi seciliyor:
#use delay(clock=4000000)

// Port yonlendirme komutlari PORT(B) icin ayarlaniyor
#use fast_io(b)

void main()
{

   setup_adc_ports(NO_ANALOGS); // Analog giris yok
   setup_adc(ADC_OFF); // ADC birimi devre disi
   setup_psp(PSP_DISABLED); // PSP birimi devre disi
   setup_spi(SPI_SS_DISABLED); //SPI interface birimi devre disi
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);// CCP birimi devre disi
   setup_timer_1(T1_DISABLED); // Timer 1 birimi devre disi
   setup_timer_2(T2_DISABLED,0,1); // Timer 2 birimi devre disi

   set_tris_b(0x00); // PORT(B) komple cikis (output) olarak ayarlaniyor
   output_b(0x00); // PORT(B) komple cikisi sifir (low) yapiliyor
   while(1)
   {
      output_high(pin_b0); //RB0 pin cikisi lojik 1 (high) yapiliyor
      delay_ms(500); // 500ms gecikme yapiliyor
      output_low(pin_b0); //RB0 pin cikisi lojik 0 (low) yapiliyor
      delay_ms(500); // 500ms gecikme yapiliyor
   }

}
