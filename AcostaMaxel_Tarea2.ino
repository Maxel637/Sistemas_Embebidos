/*
 * TAREA 2
 * Realice un programa que al presionar un pulsador, active un juego de 6 luces led que solo se enciendan. Este juego se ejecutará 8 veces cada vez que se presione el pulsador. 

Con otro pulsador, active un juego de 6 luces led que encienda  y apague  en grupos de dos en dos de la forma:

1 y 6, 2 y 5 , 3 y 4

Este juego se ejecutará 10 veces cada vez que se presione este pulsador.

UTILICE LOS CONDICIONANTES IF Y WHILE PARA RESOLVERLO
 */
const int led1=9;
const int led2=8;
const int led3=7;
const int led4=6;
const int led5=5;
const int led6=4;
const int btn2=3;
const int btn1=2;
int i=0;
int j=0;
//DECLARE LAS VARIABLES ENTERAS PARA REALIZAR EL BUCLE DEL WHILE
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  // DECLARE LOS PINS DE LOS PUERTOS DIGITALES DE ENTRADA Y LOS DE SALIDA

}

void loop() {
  //PARA RESOLVER EL PRIMERO PLANTEE UN IF PARA CUANDO EL BOTON SE CIERRE EN BAJO ESTE ENTRE A UN CICLO WHILE
  //Y COMO LA VARIABLE EMPIEZA EN ALTO SE ENTENDERA QUE SI PONGO EL CONTADOR HASTA 8 ME DARA 9 REPETICIONES
  //POR LO CUAL DECIDI PONERLE EN 7 PARA REALIZAR LAS 8 REPETICIONES REQUERIDAS
  //ENTONCES SE REALIZARA EL ENCENDIDO Y APAGADO DE LOS LEDS CON UN DELAY DE 400ms HASTA CUMPLIR LAS 8 REPETICIONES
  if(digitalRead(btn1)==LOW){
    while(i<=7){
      i++;
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,HIGH);
      delay(400);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      delay(400);
      
      }
    }
    // DE LA MISMA MANERA EN EL SEGUNDO BOTON LEERA EL ESTADO PARA ACTIVARSE Y ENTRARA A UN CICLO WHILE
    // Y DE ESTE MODO SOLO HAY QUE ORDENAR BIEN EL ENCENDIDO Y APAGADO CORRECTO DE LOS LEDS
    //HASTA QUE EL CONDICIONANTE LLEGUE A 10 REPETICIONES
     if(digitalRead(btn2)==LOW){
      while(j<=9){
        j++;
        digitalWrite(led1,HIGH);
        digitalWrite(led6,HIGH);
        delay(400);
        digitalWrite(led1,LOW);
        digitalWrite(led6,LOW);
        delay(400);
        digitalWrite(led2,HIGH);
        digitalWrite(led5,HIGH);
        delay(400);
        digitalWrite(led2,LOW);
        digitalWrite(led5,LOW);
        delay(400);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        delay(400);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        delay(400);
        }
      }
      
  
  // put your main code here, to run repeatedly:

}
