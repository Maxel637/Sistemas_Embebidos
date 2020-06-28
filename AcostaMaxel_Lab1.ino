int S1 = 6;
int S2 = 7;
int A = 11;
int B = 10;
int C = 9;
int D = 8;
int uni = 12;
int dec = 13;
int uniS;
int decS;
int i = 0;
int cont = 0;
int j;
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
  if (digitalRead(S1) == HIGH && digitalRead(S2) == LOW){
    delay(500);
    if(digitalRead(S2)==HIGH){
      delay(50);
          if(i<30){
            i = i + 1;
          }else{
                i=50;
           }
    }
    }
  if (digitalRead(S2) == HIGH&& digitalRead(S1) == LOW){
    delay(500);
    if(digitalRead(S1)==HIGH){
    delay(50);
    if (i <= 0 ) {
      i = 0;
      } else {
      i = i - 1;
        }
    }
   }
  encendido();
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
  decS = i / 10;
  if (i < 10) {
    uniS = i;
  } else {
    uniS = i - (decS * 10);
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
