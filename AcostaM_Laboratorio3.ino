 /*
  * LABORATORIO 3 ACOSTA CHACA MAXEL
  * Realice un sistema domotico que cumpla las siguientes condiciones:
    Se tiene un reloj visualizado en una LCD donde se observa el horero y minutero. Sin embargo, por
    razones de simulacion, el minutero cambia su valor cada segundo y el horero en consecuencia, cada
    minuto
    El sistema domotico cuenta con una interrupcion de encencido, seleccion de modo y pagado. Con
    otra interrupcion, se elige el modo de funcionamiento. El primer modo, es la activacion 4 luces de
    forma aletaria con un mnimo de activacion de 20 minutos. El segundo modo es el cambio de hora
    del reloj. Donde un conversor analogo digital cambia el horero y otro conversor el minutero.
  */
 #include<TimerOne.h>
 #include<MsTimer2.h>
 #include<LiquidCrystal.h>
 LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int led1=7;
const int led2=6;
const int led3=5;
const int led4=4;
int on=0;
int j=0;
int cont;
int reloj=0;
int min=0;
int hora=0;
int conversor;
int conversor1;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("RELOJ");
  lcd.setCursor(0,1);
  lcd.print("MIN:");
  lcd.setCursor(9,1);
  lcd.print("HORA:");
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(RELOJ);
  MsTimer2::set(1000,LUZ);
  MsTimer2::start();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);
  attachInterrupt(1,contador,LOW);

}

void loop() {
}
void activacion(){
  switch(on){
    case 0:
      Serial.println("Inicio de Sistema");
      Serial.println("Seleccione MODO");
      on++;
    break;
    case 1:
      Serial.println("Inicio de MODO");
      on++;
    break;
    case 2:
      Serial.println("Fin de modo");
      cont=0;
      on=0;
     break;
  }
}
void contador(){
  if(on==1){
    cont++;
    Serial.println(String("MODO SELECCIONADO" )+String(cont));
  }
  }
  void RELOJ(){
    min++;
    if(min>59){
      min=0;
      if(min==0){
        hora++;
        }
    }
    lcd.setCursor(5,2);
    lcd.print(" ");
    lcd.setCursor(5,2);
    lcd.print(min);
    lcd.setCursor(14,2);
    lcd.print(hora);
  }
void LUZ(){
  if(on==2){
    if(cont==1){
  if(reloj<20){
    reloj++;
    switch(reloj){
    case 1:
        digitalWrite(led1,HIGH);
    break;
    case 3:
        digitalWrite(led4,HIGH);
    break;
    case 5:
        digitalWrite(led2,HIGH);
    break;
    case 7:
        digitalWrite(led3,HIGH);
    break;
    case 9:
        digitalWrite(led1,LOW);
    break;
    case 11:
        digitalWrite(led4,LOW);
    break;
    case 13:
        digitalWrite(led2,LOW);
    break;
    case 15:
        digitalWrite(led3,LOW);
    break;
    case 17:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
    break;
    case 19:
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
    break;
    }
  }
  else
    reloj=0;
  }
  if(cont==2){
    conversor=analogRead(0);
    hora=conversor/42.625;
    conversor1=analogRead(1);
    min=conversor1/17.05;
  }
  
  }
  else{
    if(on==3){
  hora++;
  min++;
  cont=0;
    }
  }
}
