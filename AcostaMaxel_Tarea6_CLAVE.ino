/*
 * *********************************TAREA 6 VALIDACION DE CLAVE**************************
 * PARA SOLUCION DE ESTE EJERCICIO APLIQUE 2 LINEAS NUEVAS APRENDIDAS EN INTERNET
 * substring QUE DIVIDE AL VECTOR DESDE UNA POSICION ESTABLECIDA 
 * toInt QUE CONVIERTE EN ESTE CASO EL SUBSTRING OBTENIDO EN UN DATO ENTERO 
 * 
 */
const int led1=13;
const int led2=12;//VARIABLES DE LOS LEDS
String clave;//VARIABLE PARA ALMACENAR LA CLAVE INGRESADA
//LA CLAVE VALIDA ES***************** 1802**********************
int tam;//VARIABLE PARA ALMACENAR EL TAMAÑO DEL VECTOR
String d1; //ESTAS VARIABLES SON PARA ALMACENAR LOS SUBSTRINGS OBTENIDOS
String d2;
String d3;
String d4;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    delay(2000);//tiene un delay de 2 segundos antes de validar todo si pasan los 2 segundos 
    //el programa empieza a validar lo escrito
    clave=Serial.readString();//lEE LO QUE ESCRIBIMOS EN EL SERIAL
    tam=clave.length();//TOMA LA CLAVE Y OBTIENE EL TAMAÑO DEL VECTOR
    if(tam==4){//SI EL TAMAÑO ES IGUAL A CUATRO ENTRAMOS A DIVIDIR EL VECTOR EN PARTES
      //Y A VALIDAD CADA UNA DE ELLAS
        d1=clave.substring(0,1);
        if(d1.toInt()==1){
          d2=clave.substring(1,2);
          if(d2.toInt()==8){
            d3=clave.substring(2,3);
            if(d3.toInt()==0){
              d4=clave.substring(3,4);
              if(d4.toInt()==2){
                digitalWrite(led1,HIGH);
              }
               else{
          digitalWrite(led2,HIGH);
        }//END DEL ULTIMO IF
            }
            else{
          digitalWrite(led2,HIGH);
        }
        }//END DEL TERCER IF
         else{
          digitalWrite(led2,HIGH);
        }
        }//END DEL SEGUNDO IF
        else{
          digitalWrite(led2,HIGH);
        }
    }//FIN DEL PRIMER IF
    else{
      digitalWrite(led2,HIGH);
    }
    }
   }
  
  
