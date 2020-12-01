// Includes the Servo library
#include <Servo.h>. 
# include "LiquidCrystal.h" 
const int trigPin = 10;
const int echoPin = 9;
long duration;
int distance;
LiquidCrystal lcd(2,3,4,5,6,7);
Servo myServo; 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(8); 
  lcd.begin(16, 4);
  lcd.setCursor(0, 0);
  lcd.clear(); 
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i); 
  distance = calculateDistance();
  lcd.setCursor(0, 0);
  lcd.print("angle |distance"); 
  lcd.setCursor(0,1);  
  lcd.print(i); 
  lcd.print("   |    ");
  lcd.print(distance);
    if(distance<5) // minimum resistance provided by pot is 4ohm
    {
      
      lcd.setCursor(0,3);
      lcd.print("no object");
    }
    else
    {
      lcd.setCursor(0,3);
      lcd.print("objct detected");
    } 
  } 
  for(int i=165;i>15;i--){  
  myServo.write(i); 
  distance = calculateDistance();
  lcd.setCursor(0, 0);
  lcd.print("angle|distance"); 
  lcd.setCursor(0,1);  
  lcd.print(i);
  lcd.print("   |    ");
  lcd.print(distance);
  lcd.setCursor(0,3);
    if(distance<5)               //minimum resistance provided by pot is 4ohm
    {
      lcd.setCursor(0,3);
      lcd.print("no object");
    }
    else
    {
      
      lcd.setCursor(0,3);
      lcd.print("objct detected");
    }
  }
} 
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  distance= duration*0.034/2;
  return distance;
}
