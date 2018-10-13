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

#define CW_KEY 12
#define BUZZER 11
#define FREC 700 //Frecuencia en Hertz

//Setup inicial
void setup ()
{
  pinMode(CW_KEY,INPUT);
  digitalWrite(CW_KEY,HIGH);
  pinMode(BUZZER,OUTPUT); 
  digitalWrite(BUZZER,LOW);
  
}

// Main
void loop()
{
  if (digitalRead(CW_KEY) == 0)
  {
    Oscilador();
  }
  
}

//Funcion de oscilador
void Oscilador ()
{
    unsigned char periodo = 100000/FREC;
    digitalWrite(BUZZER,HIGH);
    delayMicroseconds(periodo/2);
    digitalWrite(BUZZER,LOW);
    delayMicroseconds(periodo/2);
}
