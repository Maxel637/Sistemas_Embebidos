int jX=300, jY=490;
int jXD=0, jYD=0;
int lazerX=jX,lazerY=jY,lazerSPD=0;
int b1X=0, b1Y=50, b2X=10,b2Y=25,b3X=20,b3Y=25;
int ball1S=3, ball2S=5,ball3S=7;
int puntuacion=0;
boolean FIN_DE_JUEGO = false;
boolean ball1=true,ball2=true,ball3=true;
PImage fondo;
void setup(){
size(500,550);
fondo = loadImage("fondo1.png");
textSize(40);
}
void draw(){
  if(FIN_DE_JUEGO==false){

  fill(255);
  rect(0,0,displayWidth,displayHeight);
  fill(50,200);
 background(fondo);
  rect(jX,jY,25,25);
  fill(0,255,0);
  rect(lazerX,lazerY,4,10);
  fill(255,0,0);
  
if(ball1==true){
        ellipse(b1X,b1Y,30,30);
} 
if(ball2 == true){
        ellipse(b2X,b2Y,30,30);
} 
if(ball3==true){
        ellipse(b3X,b3Y,30,30);
}
jX+=jXD;
jY+=jYD;
lazerX=jX;
lazerY+=lazerSPD;
b1X+=ball1S;
b2X+=ball2S;
b3X+=ball3S;
if(lazerY<0){
lazerX=jX;
lazerY=jY;
lazerSPD=0;
}
if(b1X>500||b1X<0){
  ball1S=-ball1S;
}else if(b2X>500||b2X<10){
  ball2S=-ball2S;
}else if(b3X>500||b3X<10){
  ball3S=-ball3S;
}
if(lazerX>b1X && lazerX < b1X+25 && lazerY < b1Y){
        ball1=false;
        ball1S=0;
        puntuacion++;
}
if(lazerX>b2X && lazerX <b2X+25 && lazerY<b2Y){
        ball2=false;
        ball2S=0;
        puntuacion++;
}
if(lazerX>b3X && lazerX <b3X+25 && lazerY<b3Y){
        ball3=false;
        ball3S=0;
        puntuacion++;
}
if(puntuacion>3){
        FIN_DE_JUEGO=true;
}
}
if(FIN_DE_JUEGO==true){
        FIN();
}
 if(mousePressed){
    lazerSPD=-20;
    }
}
void FIN(){
text("GANASTE",150,200);
}
void keyReleased(){
  jXD=0;
  jYD=0;
}
void keyPressed(){
    if(keyCode==RIGHT){
      jXD=5;
    }
    else if(keyCode==LEFT){
    jXD=-5;
    }
}
