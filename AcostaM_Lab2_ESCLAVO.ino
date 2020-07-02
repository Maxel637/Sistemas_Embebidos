#include<Wire.h>
#include <LiquidCrystal.h>
char dato;
String MO;
String CO;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
Wire.begin(6);
Wire.onReceive(receiveEvent);
lcd.begin(16,2);
}

void loop() {}
void receiveEvent(){
while(Wire.available()){
  dato=Wire.read();
  switch(dato){
    case 'A':
      MO=MO+'A';
      CO=CO+'0';
    break;
     case 'B':
      MO=MO+'B';
      CO=CO+'1';
    break;
    case 'C':
      MO=MO+'C';
      CO=CO+'2';
    break;
     case 'D':
      MO=MO+'D';
      CO=CO+'3';
    break;
    case 'E':
      MO=MO+'E';
      CO=CO+'4';
    break;
    case 'F':
      MO=MO+'F';
      CO=CO+'5';
    break;
     case 'G':
      MO=MO+'G';
      CO=CO+'6';
    break;
    case 'H':
      MO=MO+'H';
      CO=CO+'7';
    break;
     case 'I':
      MO=MO+'I';
      CO=CO+'8';
    break;
    case 'J':
      MO=MO+'J';
      CO=CO+'9';
    break;
     case 'K':
      MO=MO+'K';
      CO=CO+'+';
    break;
    case 'L':
      MO=MO+'L';
      CO=CO+'-';
    break;
     case 'M':
      MO=MO+'M';
      CO=CO+'*';
    break;
    case 'N':
      MO=MO+'N';
      CO=CO+'/';
    break;
     case 'O':
      MO=MO+'O';
      CO=CO+'.';
    break;
    case 'P':
      MO=MO+'P';
      CO=CO+',';
    break;
     case 'Q':
      MO=MO+'Q';
      CO=CO+':';
    break;
    case 'R':
      MO=MO+'R';
      CO=CO+';';
    break;
     case 'S':
      MO=MO+'S';
      CO=CO+'(';
    break;
    case 'T':
      MO=MO+'T';
      CO=CO+')';
    break;
     case 'U':
      MO=MO+'U';
      CO=CO+'=';
    break;
    case 'V':
      MO=MO+'V';
      CO=CO+'_';
    break;
     case 'W':
      MO=MO+'W';
      CO=CO+'^';
    break;
    case 'X':
      MO=MO+'X';
      CO=CO+'¬';
    break;
     case 'Y':
      MO=MO+'Y';
      CO=CO+'%';
    break;
    case 'Z':
      MO=MO+'Z';
      CO=CO+'#';
    break;
    case ' ':
      MO=MO+' ';
      CO=CO+'&';
    break;
  }
  delay(2000);
  lcd.setCursor(1,0);
  lcd.print(MO);
  lcd.setCursor(1,1);
  lcd.print(CO);
}
}
