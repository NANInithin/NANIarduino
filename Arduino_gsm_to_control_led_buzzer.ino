    
 #include <SoftwareSerial.h> 

SoftwareSerial mySerial(9, 10);
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

String message;


void setup()
{
  mySerial.begin(9600);   
  Serial.begin(9600);    
  delay(100);

  mySerial.println("AT+CNMI=2,2,0,0,0"); 
  delay(1000);
  pinMode(led1,OUTPUT);
  digitalWrite(led1,LOW);
  pinMode(led2,OUTPUT);
  digitalWrite(led2,LOW);
   pinMode(led3,OUTPUT);
  digitalWrite(led3,LOW);
   pinMode(led4,OUTPUT);
  digitalWrite(led4,LOW);
  
}

void loop()
{
  if (mySerial.available()>0){
  message = mySerial.readString();
  }

  if(message.indexOf("LED1ON") > -1){
      Serial.println("LED ON");
     digitalWrite(led1,HIGH);
     }
      else if(message.indexOf("LED2ON") > -1){
      Serial.println("LED ON");
     digitalWrite(led2,HIGH);
     }
    else if(message.indexOf("LED1OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led1,LOW);    

  }
   else if(message.indexOf("LED2OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led2,LOW);

  }
  else if(message.indexOf("ALLOFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led2,LOW);
      digitalWrite(led1,LOW);
       digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
  }
  else if(message.indexOf("ALLON") > -1){

      Serial.println("LED ON");
      digitalWrite(led2,HIGH);
      digitalWrite(led1,HIGH);
       digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
  }
   else if(message.indexOf("LED3OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led3,LOW);    

  }
   else if(message.indexOf("LED3ON") > -1){

      Serial.println("LED OFF");
      digitalWrite(led3,HIGH);    

  }
   else if(message.indexOf("LED4OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led4,LOW);    

  }
   else if(message.indexOf("LED4ON") > -1){

      Serial.println("LED OFF");
      digitalWrite(led4,HIGH);    

  }
  

  delay(10);
}
