/*
 * TAREA 4 Contador de numeros primos desde el cero hasta 100
 * ACOSTA CHACA MAXEL DAVID
 * En el cual para dar solucion declare 3 variables nuevas al codigo hecho en clase
 * ge seria numero ascendente hasta 100
 * c seria nuestro contador 
 * nu un comparador para realizar una division que no devuelva residuo
 */
int A = 11;
int B = 10;
int C = 9;
int D = 8;
int uni = 12;
int dec = 13;
int uniS;
int decS;
int ge=1;
int nu;
int c;
void setup() {
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(uni, OUTPUT);
  pinMode(dec, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
}

void loop(){
    while(ge<=100){//Mientras nuestra ge sea menor a 100 entra al ciclo donde las variables valdrian 1 y 0
      nu=1;
      c=0;
          while(nu<=ge){
            if(ge%nu==0){//realiza la division y si esta devuelve un residuo igual a cero, c valdria a c+1
            c=c+1;
          }
          nu=nu+1;
          }
          if(c==2){
           encendido(); // si el contador es divisible solo para 2 cantidades nos mandaria al void establecido que es encendido
          }
          ge=ge+1;
          delay(500);
    }
}

void disp (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}

void encendido() {
  decS = ge/ 10;
  if (ge< 10) {
    uniS = ge;
  } else {
    uniS = ge - (decS * 10);
  }
  
  digitalWrite(dec, HIGH);
  digitalWrite(uni, LOW);
  disp(decS);
  delay(150);
  digitalWrite(dec, LOW);
  digitalWrite(uni, HIGH);
  disp(uniS);
  delay(150);
}
