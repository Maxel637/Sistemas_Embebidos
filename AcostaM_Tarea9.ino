/*
 ACOSTA CHACA MAXEL DAVID
 Realizar un sumador/restador donde el usuario ingrese los datos 
 por comunicación serial y el proceso sea controlado por interrupciones.
 */

 int on=0;
 int cont;
 int suma;
 int resta;
 String ter1;
 int ter2;
 String ter3;
 int ter4;
void setup() {
      Serial.begin(9600);
      attachInterrupt(0,cambio,LOW);
      attachInterrupt(1,contador,LOW);
}

void loop() {
    if(on==2){
      ter1=Serial.readString();
      ter2=ter1.toInt();
    }
     if(on==3){
      ter3=Serial.readString();
      ter4=ter3.toInt();
    }
}

void cambio(){

    switch(on){
      case 0:
        Serial.println("Inicio de Sistema");
        Serial.println("Seleccione operacion (SUMA OPERACION1, RESTA OPERACION2)");
        on ++;
       break;
       case 1:
        Serial.println("Ingrese Valor 1");
        on++;
       break;
       case 2:
       Serial.println("Ingrese Valor 2");
        on++;
       break;
       case 3:
          if(cont==1){
            suma=ter2+ter4;
            Serial.println("OPERACION FINALIZADA");
            Serial.println(suma);
          }
            if(cont==2){
              resta=ter2-ter4;
            Serial.println("OPERACION FINALIZADA");
            Serial.println(resta);
          }
          on=0;
          cont=0;
       break;

    }
}
void contador(){
  if(on==1){
    cont++;
    Serial.println(String("OPERACION SELECCIONADA" )+String(cont));
  }
}
