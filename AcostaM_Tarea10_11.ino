 /*
  * ACOSTA CHACA MAXEL DAVID
Realizar un sistema que tenga un reloj despertardor. La forma de ingresar la alarma queda sujeto a su idea de solución.
Saludos.
  */
 #include<TimerOne.h>
 #include<LiquidCrystal.h>
 LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int seg=0;
int min=0;
int hora=0;
int conversor;
int conversor1;
int alm1;
int alm2;
const int ALARMA=7;
void setup() {
  pinMode(7,OUTPUT);
  lcd.begin(16,2);
  //ALARMA
  lcd.setCursor(1,0);
  lcd.print("ALM");
  lcd.setCursor(9,0);
  lcd.print(":");
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(RELOJ);
}

void loop() {
    conversor=analogRead(0);
    alm1=conversor/42.625;
    delay(100);
    lcd.setCursor(7,0);
    lcd.print(alm1);
    conversor1=analogRead(1);
    alm2=conversor1/17.05;
    delay(100);
    lcd.setCursor(10,0);
    lcd.print(alm2);
    if(alm1=hora){
      if(alm2=min){
        digitalWrite(ALARMA,HIGH);
      }
      else
       digitalWrite(ALARMA,LOW);
    }

}
  void RELOJ(){
    seg++;
    if(seg>59){
      seg=0;
      if(seg==0){
        min++;
        if(min>59){
          min==0;
          if(min==0){
              hora++;
          if(hora>23){
            hora==0;
          }
          }
          }
        }
        }
    
    lcd.setCursor(1,2);
    lcd.print(" ");
    lcd.setCursor(3,2);
    lcd.print(seg);
    lcd.setCursor(5,2);
    lcd.print(":");
    lcd.setCursor(6,2);
    lcd.print(min);
    lcd.setCursor(8,2);
    lcd.print(":");
    lcd.setCursor(9,2);
    lcd.print(hora);
  }
