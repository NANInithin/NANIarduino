#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); // gsm module connected here
String textForSMS;
 
int flamePin = 4; // Flame Sensor
int buzzerPin = 11; // Alarm/light can be connected with this Buzzer
   
int Flame = HIGH;
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    
      Serial.println("ATD9849629439;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
    digitalWrite(buzzerPin, HIGH);
    
       Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(100);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+919849629439\"\r"); // Replace x with mobile number
     Serial.println("FIRE IN THE HOUSE");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);
     
    
  }
  else
  {

    digitalWrite(buzzerPin, LOW);
    
  }
}
