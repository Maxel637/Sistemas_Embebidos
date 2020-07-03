/*
 * *******************************MASTER****************************
 * EL USUARIO PRESIONA UN SWITCH Y EL MASTER ENVIA UN DATO AL ESCLAVO 
 * Y SEGUN QUE SSWITCH SE PRESIONE SE ACTIVARÁ UN LED
 */
 #include<Wire.h>
 const int sw1=13;
 const int sw2=12;
 const int sw3=11;
 const int sw4=9;//VARIABLES PARA CADA PIN DE SWITCH
 int dato;// VARAIBAL QUE SE UTILIZA PARA ALMACENAR CADA DATO TIPO ENTERO
void setup() {
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);//PINES DE ENTRADA PARA LOS SWITCHS
  Wire.begin();//COMIENZA LA COMUNICACION 12C

}

void loop() {//VERIFICA SI ESTA DISPONIBLE EL PUERTO DE COMUNICACIÓN
   if(digitalRead(sw1)==HIGH){
    dato=1; //LEE LOS DATOS Y LOS ALMACENA EN UN ESTADO LLAMADO 1
  }
  if(digitalRead(sw2)==HIGH){
    dato=2;
  }
  if(digitalRead(sw3)==HIGH){
    dato=3;
  }
  if(digitalRead(sw4)==HIGH){
    dato=4;
  
  }
 Wire.beginTransmission(6);//TRANSMITE OS DATOS HACIA EL INDICADOR 6 PARA QUE ESTE LO RECIBA SIEMPRE Y CUANDO HAYA UN ESCLAVO 6
  Wire.write(dato);
  Wire.endTransmission();
}
