#include<TimerOne.h>
#include <MsTimer2.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include<avr/wdt.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int leds[]={7,6,5};
int sensores=4;
int n;
int i;
int min;
int guardado;
int hora=0;
int ON=0;
int per=0;
String clave;
int clave1;
int cont=0;
int tiempo=20;
void setup() {
   min=EEPROM.read(2);
   hora=EEPROM.read(4);
   pinMode(sensores,INPUT);
  for(i=0;i<3;i++){
    pinMode(leds[i],OUTPUT);
    randomSeed(analogRead(0));

  }
    MsTimer2::set(1000,reloj);
    Serial.begin(9600);
    lcd.begin(16,2);
    attachInterrupt(0, SistemaON,LOW);
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(Respaldo);  
}

void loop() {
  if(ON==2){
    clave=Serial.readString();
    clave1=clave.toInt();
    lcd.setCursor(1,0);
    lcd.print("ESPERANDO CLAVE");
    
  }
}
void SistemaON(){
  switch(ON){
          case 0:
          lcd.clear();
            Serial.println("INICIO");
            ON ++;
          break;
          case 1:
             Serial.println("DIGITE CLAVE");
            ON ++;
          break;
          case 2:
             if(clave1==8956){        
             Serial.println("CLAVE CORRECTA");
             ON ++;
             }else{
              ON=0;
             }
          break;
          case 3:
            Serial.println("CONTEO REGRESIVO");
            MsTimer2::start();
            lcd.clear();
          ON++;
          break;
          case 4:
            Serial.println("ALARMA TERMINADA");
            MsTimer2::stop();
          ON=0;
          cont=0;
          per=0;
          break;
  }
  
}
void reloj(){
  cont++;
  if(tiempo>0){
     if(digitalRead(sensores)==HIGH){
      per=per+1;
      Serial.println(String("PERSONAS FUERA: ")+String(per));
     }
    for(i=0;i<3;i++){
    n=random(0,4);
    digitalWrite(leds[n],HIGH);
    digitalWrite(leds[n-1],LOW);
    }
  }
   lcd.setCursor(1,0);
   lcd.print("TIEMPO DE ESCAPE :");
   lcd.setCursor(1,1);
   lcd.print(tiempo-cont);
   if(tiempo-cont==0){
        MsTimer2::stop();
        Serial.println("ALARMA TERMINADA");
        lcd.setCursor(1,0);
        lcd.print("ALARMA TERMINADA");
        ON=0;
        cont=0;
        per=0;
   }
   
}
void Respaldo(){
  min++;
  if(min>59){
    min=0;
    if(min==0){
      hora++;
      if(hora>23){
        hora==0;
      }
    }
  }
   if(min==55){
    EEPROM.write(2,min);
    EEPROM.write(4,hora);
  }

  lcd.setCursor(13,1);
  lcd.print(min);
  lcd.setCursor(12,1);
  lcd.print(":");
  lcd.setCursor(10,1);
  lcd.print(hora);
}
