#include "datos.h"

int ejecutar = 1;
float promedios[nEtiquetas][cols];
float distancias[filas];
float distanciasMayores[nEtiquetas] ;
float bdd [filas][cols];
int muestras = 0;
/**
 * 1. buscar el número mas negativo en cada columna
 * 2. buscar el promedio de cada columna por etiqueta
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ejecutar == 1){
    Serial.println("##############  PARTE 1 ###############");
    for (int j = 0; j < cols; j++){
      negativoPorColumna(j);
      
    }
    for(int j = 1; j <= nEtiquetas; j++){
      promedioPorEtiqueta(j);
    }
    Serial.println("##############  PARTE 2 ###############");
    for (int i = 0 ; i < nEtiquetas; i++){
      Serial.print("Promedios etiqueta "+ String(i+1)+ ": ");
      for (int j = 0 ; j < cols; j++){
        Serial.print(promedios[i][j]);
        Serial.print(";");
      }
      Serial.println();
    } 

    Serial.println("##############  PARTE 3 ###############");
    // aqui se imprimen las distancias de cada muestra con el promedio de su etiqueta
    calcularDistancias();

    Serial.println("##############  PARTE 4 ###############");
    // aqui se imprimen las distancias anteriores, normalizadas en base a la distancia mayor de su etiqueta
    normalizarDistancias();
    Serial.println("##############  PARTE 5 ###############");
    // aqui se elijen los valores de distancias que esten entre 0.40 y 0.65 ; Esta será la nueva BDD de entrenamiento
    nuevaBDD();

    Serial.println("##############  PARTE 6 ###############");
    // aqui se realizará knn 1 a cada registro de matriz
    knn1();
    
    ejecutar = 0;
  }
}

void negativoPorColumna(int columna){
  int minValue = 0;
  // se obtiene el valor más negativo de la columna
  for (int i = 0 ; i < filas; i++){
    if(matriz[i][columna]<minValue){
      minValue = matriz[i][columna];
    }
  }
  // se imprime el valor más negativo
  Serial.println("El menor valor de la columna "+String(columna)+" es: "+String(minValue));
  // si el valor es menor que cero se procede a restar dicho valor a toda la columna
  if(minValue<0){
    for (int i = 0 ; i < filas; i++){
      matriz[i][columna] = matriz[i][columna] - minValue;
      Serial.println(matriz[i][columna]);
    }  
  }
}

void promedioPorEtiqueta(int etiqueta){
  for (int j = 0; j < cols ; j++){
    promedios[etiqueta-1][j] = 0; 
  }
  for(int i = 0; i < filas; i++){
    int etiquetaAux = matriz[i][cols - 1];
    if(etiquetaAux == etiqueta){
      for (int j = 0; j < cols -1; j++){
        promedios[etiqueta-1][j] = promedios[etiqueta-1][j] + matriz[i][j];
      }
      promedios[etiqueta-1][cols - 1]++;
    }
  }
  for (int j = 0; j < cols - 1; j++){
    promedios[etiqueta-1][j] = promedios[etiqueta-1][j]/promedios[etiqueta-1][cols-1]; 
  }
}

void calcularDistancias(){
  for (int i = 0; i < nEtiquetas; i++){
    distanciasMayores[i] = -1;
  }
  for(int i = 0; i < filas; i++){
    int etiqueta = matriz[i][cols -1 ];
    float distancia = 0;
    for (int j = 0; j < cols-1; j++){
      distancia = distancia + pow(promedios[etiqueta-1][j] - matriz[i][j], 2);
    }
    distancia = sqrt(distancia);
    Serial.println(distancia);
    distancias[i] = distancia;
    // aqui se guarda las distancias mas grandes de cada etiqueta
    if(distancia > distanciasMayores[etiqueta - 1]){
      distanciasMayores[etiqueta - 1] = distancia;
    }
  }
}

void normalizarDistancias(){
  for(int i = 0; i < filas; i++){
    int etiqueta = matriz[i][cols -1 ];
    distancias[i] = distancias[i]/distanciasMayores[etiqueta - 1];
    Serial.println(distancias[i]);
  }
}

void nuevaBDD(){
  
  for(int i = 0; i < filas; i++){
    if(distancias[i]>= 0.4 && distancias[i] <= 0.65){
      muestras++;
    }
  }
  int cont = 0;
  for(int i = 0; i < filas; i++){
    if(distancias[i]>= 0.4 && distancias[i] <= 0.65){
      for(int j = 0; j < cols; j++){
        bdd[cont][j] =  matriz[i][j];
        Serial.print(bdd[cont][j]);
        Serial.print(";");
      }
      Serial.println();
      cont ++;
    }
  }
  Serial.println("EL NUEVO TAMANO DE LA BDD ES : " +String(muestras));
  
  
}

void knn1(){
  // asumiremos los datos de matriz como datos de prueba y los datos de bdd como datos de entrenamiento
  int filasPrueba = 10;
  float distancia_menor = 0;
  int aciertos = 0;
  int errores = 0;
  // el primer for recorrera toda la matriz
   for(int i = 0;i < filas ; i++){
     // el segundo for recorre la nueva bdd
      int etiqueta = 0;
      for(int j = 0; j < muestras; j++){
        // el tercer for recorre las columnas de matriz y bdd
        // aqui se debe calcular la distancia desde el registro i de matriz hacia cada uno de los registros j de bdd
        float distancia=0;
        for(int k = 0; k < cols - 1; k++){
          distancia=distancia+pow(matriz[i][k]-bdd[j][k],2);
        }
        // esta es la distancia del registro i de matriz hacia el registro j de bdd
        distancia=sqrt(distancia);
        //Serial.println(distancia);
        if(j == 0 ) {
          distancia_menor = distancia;
          etiqueta=bdd[j][cols -1];
        }else{
          if(distancia<distancia_menor){
            distancia_menor=distancia;
            etiqueta=bdd[j][cols -1];
          }
        }
      }
      // aqui determinamos en base a la distancia menor si se acerto o no 
      Serial.println(String("datos son de etiqueta: ")+String(etiqueta));
      if(etiqueta==matriz[i][cols-1]){
        aciertos++;
        Serial.println("Acierto");
      }else{
        errores++;
        Serial.println("Error");
      }
    }
    Serial.println("TOTAL ACIERTOS: "+String(aciertos));
    Serial.println("TOTAL ERRORES: "+String(errores));
    float rendimiento = (aciertos/filas)*100.00;
    Serial.println("Rendimiento %: "+String(rendimiento));
}
