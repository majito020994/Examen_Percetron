/*EXAMEN
NOMBRE: MARIA JOSE CAUJA
PERCEPTRON DE UNA SOLA CAPA
sumatoria =x0*w0+x1*w1+x2*w2+x3*w3+x4*w4
Si la sumatoria es mayor o igual a 0.5 se calificara como 0 caso contrario como1
if umbral>=suma 
n es la salida que se obtiene 0 o 1
Calcular el error seria las salida deseada- n
Este se realiza con 10 repeticiones para verificar el aprendizaje del sistema
*/
#include "datos.h"
float w0=0.1; //pesos
float w1=0.1;
float w2=0.1;
float w3=0.1;
float w4=0.1;
float umbral=0.5; //umbral o bias
float r=0.05; //contante de aprendizaje 
float error; // encontrar el error entre la salida deseada y la salida que se genera
int contador; 
int repeticiones=0; // el numero de repeticiones que da el sistema
int i=0;  //recorrer en filas la matriz
int l=0;
int j=0;
float y; // Salida deseada
float n; //guardar la condicion si es 0 o 1
float suma;
int errortotal=0;
int filas=100;
void setup() {
Serial.begin(9600);
}
void loop() {
for(i=0;i<filas;i++){
   //sumatoria de las salidas con los pesos iniciales
   //suma=x*w0+x1*w1+x2*w2+x3*w3+x4*w4
   suma=((datos[i][0]*w0)+(datos[i][1]*w1)+(datos[i][2]*w2)+(datos[i][3]*w3)+(datos[i][4]*w4));
 //guardamos en y la etiqueta de nuestra matriz
   y=datos[i][5];
}
  //###############################################################
   //condicional si suma mayor o igual al umbral sera 1 caso contrario 0
for(l=0;l<filas;l++){
if(suma>=umbral){
  n=1;  }
else{
  n=0;  }
}
 //##################################################################
for(j=0;j<filas;j++){
if(repeticiones<8){
//calculo del error y-n
if (y!= n){
  // valor que se debe corregir entrenando el sistema
  //salida-error*coeficiente de aprendizaje
  //correccion de los pesos se utiliza la formula 
  //correccion=constante de apredizaje(r)*el error
  error=(y-n)*r;
   Serial.print("Los errores Generados");
  Serial.println(error);
  
}

  //para generar los nuevos pesos se prosigue a reemplazar w0=w0+(salida esperada-salida generada)*constante de aprendizaje
 w0=(datos[j][0])*((y-n)*r);
 w1=(datos[j][1])*((y-n)*r);
 w2=(datos[j][2])*((y-n)*r);
 w3=(datos[j][3])*((y-n)*r);
 w4=(datos[j][4])*((y-n)*r);
    repeticiones++;
}     
   
    Serial.print("Repeticiones: ");
    Serial.println(repeticiones);
    Serial.print("Peso W0: ");
    Serial.println(w0);
    Serial.print(" Peso W1: ");
    Serial.println(w1);
    Serial.print(" Peso W2: ");
    Serial.println(w2);
     Serial.print(" Peso W3: ");
    Serial.println(w3);
     Serial.print(" Peso W4: ");
    Serial.println(w4);
    Serial.print(" ERRORES: ");
    Serial.println(errortotal); 
  
    }
 
    
   }
  


