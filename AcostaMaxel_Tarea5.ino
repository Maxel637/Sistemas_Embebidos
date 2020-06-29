/*
 * TAREA 5 rEALIZAR ROTACION DE IZQUIERDA A DERECHA DE LA PALABRA ARDUINO VISTA EN LCD
 * CAPITULO 2 PUERTOS DIGITALES: LCD
 * OBJETIVO VIZUALIZAR DATOS EN LA LCD
 * ACOSTA MAXEL
 */
 #include <LiquidCrystal.h> //Incluye la libreria para la lcd
 LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //Crea el objeto de los parametros rs,enabre, D4,D5,D6,D7
void setup() {
  lcd.begin(16,2);//dimensiones de la lcd
  lcd.clear();//limpia la lcd
  lcd.setCursor(1,0);//nos pone el cursor en la fila 1 columna 0
  lcd.print("ARDUINO");//mandamos el mensaje
}

void loop() 
{
  lcd.setCursor(16,0); //pongo el cursor donde quiero que comience
  lcd.scrollDisplayRight();//Realiza el desplazamiento de izquieda a derecha
  lcd.print("");
  delay(100);//tiempo de movimiento

}
