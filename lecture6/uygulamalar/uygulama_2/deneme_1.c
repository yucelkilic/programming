/*******************************************************
Uygulama Adi: PIC16F877 ile Led Yakma-Sondurme Programi
Programin Amaci: RB0 pini ile LED'i RA0 girisine bagli 
buton üzerinden yakip sondurmek
*******************************************************/


// Kullanilacak PIC'in baslik dosyasi tanitiliyor
#include <16f877.h> 

//PIC konfigurasyon ayarlari:
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

// Osilator frekansi seciliyor:
#use delay(clock=4000000)

// Port yonlendirme komutlari PORT(B) icin ayarlaniyor
#use fast_io(b)

int x;

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
   set_tris_a(0x01); // PORT(A.0) pini komple giris (input) olarak ayarlaniyor
   output_b(0x00); // PORT(B) komple cikisi sifir (low) yapiliyor
   while(1)
   {
      x=input(pin_a0); // PORT(A.0) pini okunuyor x degiskenine ataniyor
      output_bit(pin_b0,x); // x degiskeni RB0 pini cikisina akratiriliyor
   }

}
