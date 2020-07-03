/*
 * ***************************ESCLAVO******************************
 * LEE EL DATO ENVIADO DEL MASTER EN ESTE CASO SERA TIPO ENTERO INDICANDO QUE ESTADO
 * ESTA ACTIVO Y QUE LED ENCENDER
 */
#include<Wire.h>
int dato;//VARIABLE PARA ALMACENAR EL ESTADO
const int D=11;
const int C=10;//DECLARACION DE LAS VARIABLES PARA LOS PINES
const int B=9;
const int A=8;
void setup() {
Wire.begin(6);//DECLARA QUE PODEMOS RECIBIR DATOS QUE SEAN ENVIADOS AL PUERTO 6
Wire.onReceive(Captura);//CREA UN EVENTO PARA RECIBIR LOS DATOS Y LEERLOS
pinMode(D,OUTPUT);
pinMode(C,OUTPUT);//PINES DE SALIDA A LOS LEDS
pinMode(B,OUTPUT);
pinMode(A,OUTPUT);
}

void loop() {}
void Captura(){//EVENTO DE LECTURA DE DATOS Y COMPARACION
if(Wire.available()){
  dato=Wire.read();//LEEMOS EL DATO ENVIADO Y LO ALMACENAMOS EN LA VARIABLE DATO
  switch(dato){
    case 1://CASOS PARA SEGUN EL ESTADO ENVIADO
     digitalWrite(D,HIGH);
     digitalWrite(C,LOW);
     digitalWrite(B,LOW);
     digitalWrite(A,LOW);
    break;
     case 2:
      digitalWrite(D,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(A,LOW);
    break;
    case 3:
      digitalWrite(D,LOW);
      digitalWrite(C,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(A,LOW);
    break;
     case 4:
      digitalWrite(D,LOW);
      digitalWrite(C,LOW);
      digitalWrite(B,LOW);
      digitalWrite(A,HIGH);
    break;
  }
}
}
