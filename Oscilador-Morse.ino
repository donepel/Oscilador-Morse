/************************************************************
*****      Oscilador para practicas en CW                ****                        
*****                 by Don_Epel                        ****
*************************************************************/

/* ***************************************************
version 1, 12 Oct 2018

Typical pin layout used:
*-------------------------------------
*                   Arduino
* Signal            Pin 
* -----------------------------------
* CW Key            12
* Buzzer            11
* 
*/

#define CW_KEY 12 //defino el pin 12 como CW_KEY
#define BUZZER 11 //Defino el pin 11 como BUZZER
#define FREC 700 //Frecuencia en Hertz defino la frecuencia FREC y su correspondiente valor en 700

//Setup inicial
void setup ()
{
  pinMode(CW_KEY,INPUT);  //defino el pin CW_KEY como entrada
  digitalWrite(CW_KEY,HIGH); //Activo la resistencia de pull-up por software
  pinMode(BUZZER,OUTPUT);  //Defino el pin BUZZER como salida
  digitalWrite(BUZZER,LOW); //Activo la resistencia de pull-down por software
  
}

// Main
void loop()
{
  if (digitalRead(CW_KEY) == LOW) //Si la CW_KEY se pone en 0, es porque se pulsó
  {
    Oscilador(); //llamo a la funcion oscilador
  }
  
}

//Funcion de oscilador
//Recibe: Nada
//Retorna: Nada
//Nota: Se genera una señal cuadrada por el puerto BUZZER  de una frecuencia dada (FREC)
void Oscilador ()
{
    unsigned char periodo = 100000/FREC; //Defino el periodo con la formula de T=1seg/frec en  ms
    //Armo un oscilador de la mitad del periodo calculado, mitad del ciclo en alto, mitad den bajo
    digitalWrite(BUZZER,HIGH);
    delayMicroseconds(periodo/2);
    digitalWrite(BUZZER,LOW);
    delayMicroseconds(periodo/2);
}
