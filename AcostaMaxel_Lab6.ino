#include "datos.h"
float test[5]={5.6,2.7,4.2,1.3};
String k;
int k1;
int KNN (int FilaK, int ColumnaK, int Neigh, int Tags){
int columna; 
int fila=0; 
float distancia=0.0;
float distancia1;
float etiqueta;
float m_k [2][Neigh];
float m_etiquetas [2][Tags];
int i=0; 
int j;
float Min=0;
float ordenV;
float ordenV1;
//===========VECINOS ALMACENADOS==============================//
for(;i<Neigh;i++){
     m_k[0][i]=3000+i; 
     m_k[1][i]=0;   
  }
  i=0;
 //================ETIQUETAS ALMACENADAS=========================//
  for(;i<Tags;i++){
    m_etiquetas[0][i]= i+1; 
    m_etiquetas[1][i]= 0;  
    }
   i=0; 
//===============ALGORITMO KNN==========================//
   for(;fila<90;fila++){
   for(columna=0;columna<4;columna++){
   distancia=distancia+pow(matriz[fila][columna]-test[columna],2);
          }
   distancia1=sqrt(distancia);
   distancia=0;
   if(distancia1<m_k[0][Neigh-1]){
   m_k[0][Neigh-1]=distancia1;
   m_k[1][Neigh-1]=matriz[fila][4];
                        }
    for(i=0;i<Neigh;i++){
    for(j=i+1;j<Neigh;j++){
    if(m_k[0][i]>m_k[0][j]){
    ordenV=m_k[0][i];
      m_k[0][i] = m_k[0][j];
      m_k[0][j] = ordenV;
      ordenV1 = m_k[1][i];
      m_k[1][i] = m_k[1][j];
      m_k[1][j] = ordenV1;
                      } } }  }
              for(i=0;i<Tags;i++){
              for(j=0;j<Neigh;j++){
              if(m_etiquetas[0][i]  ==  m_k[1][j]){
              m_etiquetas[1][i] = 1+m_etiquetas[1][i];
                }}}
       for(i=0;i<Tags;i++){
       if(m_etiquetas[1][i]>Min){
          Min = m_etiquetas[1][i];
          etiqueta  = m_etiquetas[0][i];
        }
    }
   return etiqueta; 
}
void setup() {
  Serial.begin (9600) ;
}
void loop() {
  k=Serial.readString();
  k1=k.toInt();
  int respuesta=KNN (90,5,k1,3);
  if (respuesta==1) {
      Serial.println ("Pertenece a la etiqueta : ") ; 
      Serial.println ("1") ; 
      delay (2000) ;
    } else if (respuesta==2) {
      Serial.println ("Pertenece a la etiqueta : ") ; 
      Serial.println ("2") ; 
      delay (2000) ;
    }else if (respuesta==3) {
      Serial.println ("Pertenece a la etiqueta : ") ; 
      Serial.println ("3") ; 
      delay (2000) ;
      
      }
}
