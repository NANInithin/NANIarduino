#include <Stepper.h>
int in1pin = 12;
int in2pin = 14;
int in3pin = 27;
int in4pin = 26;
Stepper motor(16, in1pin, in2pin, in3pin, in4pin);

void setup() {
  // put your setup code here, to run once:
pinMode(in1pin, OUTPUT);
pinMode(in2pin, OUTPUT);
pinMode(in3pin, OUTPUT);
pinMode(in4pin, OUTPUT);

Serial.begin(115200);
motor.setSpeed(20);
}

void loop() {
  // put your main code here, to run repeatedly:
motor.step(5);
delay(600);
motor.step(-10);
delay(600);
}
