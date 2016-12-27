// Kaynak: http://arduinotik.blogspot.com.tr/2014/03/arduino-7-segmentli-gosterge-0-9-sayc.html?view=sidebar#!
int buton=12;

int a=2; // her pine displaydeki bir led bağlı
int b=6;
int c=8;
int d=9;
int e=4;
int f=3;
int g=7;
int x=5;  //Displaydeki nokta led

int sayi=0; // Modu alınacak sayi

void setup () {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(x,OUTPUT);
  pinMode(buton,INPUT_PULLUP);
  Serial.begin (9600); // Sayi değerini monitörde görmek için
}

void loop () {
    int butondurumu=digitalRead(buton); // buton durumu okuyoruz
    if (butondurumu==0)  //butona her basıldığında;
    {sayi=sayi+1;}       // sayi değeri 1 artacak

    if (sayi%10==0)         //sayinin moduna göre display ledleri
    {
      digitalWrite(a,HIGH);  //yanacak
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
     }
     else if (sayi%10==1)
     {
       digitalWrite(a,LOW);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
     }
     else if (sayi%10==2)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,LOW);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(f,LOW);
       digitalWrite(g,HIGH);
     }
     else if (sayi%10==3)
     {
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
     }
     else if (sayi%10==4)
     {
       digitalWrite(a,LOW);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
     }
     else if (sayi%10==5)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,LOW);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,LOW);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
     }
     else if (sayi%10==6)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,LOW);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
     }
     else if (sayi%10==7)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
     }
     else if (sayi%10==8)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
     }
     else if (sayi%10==9)
     {
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,LOW);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
     }

     delay(100);
     Serial.println(sayi);  //Bilgisayardaki değere bakarak
     delay(10);             //displayin doğru olup olmadığını
                            //anlayabiliriz.
}
