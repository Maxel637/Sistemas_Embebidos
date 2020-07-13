#include<TimerOne.h>
#include<LiquidCrystal.h>
#include<avr/wdt.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int seg=0;
void setup() {
lcd.begin(16,2);
Timer1.initialize(1000000);
Timer1.attachInterrupt(CONTADOR28);
}

void loop() {
}
void CONTADOR28(){
  seg++;
  lcd.setCursor(1,2);
  lcd.print(seg);
  if(seg==28){
      wdt_disable();
      wdt_enable(WDTO_15MS);
  }
}
