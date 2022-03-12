#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial Blue(2, 3);
long int data;
Servo myservo; 

int LEDGreen = 13;
int LEDRed = 12;
int Buzzer = A0;
long int password1 = 92;
long int password2 = 79;
char state = 0;

void setup(){
 myservo.attach(9);
 pinMode(LEDGreen, OUTPUT);
 pinMode(LEDRed, OUTPUT);
 pinMode(Buzzer,OUTPUT);
 digitalWrite(LEDGreen, LOW);
 digitalWrite(LEDRed, LOW);
 digitalWrite(Buzzer,HIGH);
 Serial.begin(9600);
 Blue.begin(9600);
}

void loop(){
 while(Blue.available()==0) ;
 if(Blue.available()>0) {
 data = Blue.parseInt();
 } 

delay(50);
 
if (data == password1){
  myservo.write(0);
  digitalWrite(LEDRed,HIGH);
  digitalWrite(LEDGreen,LOW);
  digitalWrite(Buzzer,HIGH);
  Serial.println("Tempat sampah terbuka.");
  }
   
if( data == password2){
  myservo.write(120);
  digitalWrite(LEDRed,LOW);
  digitalWrite(LEDGreen,HIGH);
  digitalWrite(Buzzer,LOW);
  Serial.println("Tempat sampah tertutup.");
   }

}
