
//ARDUINO CAR CREATED BY MADAN R//

// Include this libary
#include <AFMotor.h>
#include <Servo.h>

#define light_FF  14     
#define light_BB  15  
#define leftlight 16
#define rightlight 17  
#define HORN 18
#define blink 19 
#define time 1000
#define verificationPin 2

Servo myServo1;
Servo myServo2;

int ServPos = 0;

int timer = 500;
int timer2 = 50;           
int ledPins[] ={14,15,16,17};     
int pinCount = 4;       

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int command; //Int to store app command state.

int speedCar = 255; // Initial car speed set 0 to 255.
boolean lightFront = false;
boolean lightBack = false;
boolean horn = false;
boolean lightExtra= false;
boolean Emlight=false;
boolean indicator=false;

void setup(){
    
    pinMode(light_FF, OUTPUT);
    pinMode(light_BB, OUTPUT);
    pinMode(leftlight, OUTPUT);
    pinMode(rightlight, OUTPUT);
    pinMode(HORN, OUTPUT);
    pinMode(blink,OUTPUT);
    pinMode(verificationPin, INPUT);
    
    
  myServo1.attach(9);
  myServo2.attach(10);
    
  digitalWrite(HORN,HIGH);
  delay(50);
  digitalWrite(HORN,LOW);
  delay(50);
  digitalWrite(HORN,HIGH);
  delay(50);
  digitalWrite(HORN,LOW);
  delay(50);

    
  //SERVO MOTOR
    
{
            
for (int step = 45; step <= 135; step++) { 
        if (myServo1.read() < 135) { 
            myServo1.write(myServo1.read() + 1); 
        }
        if (myServo2.read() > 45) { 
            myServo2.write(myServo2.read() - 1);
        }
        delay(10);
}
//break;

  for (int step = 45; step <= 135; step++) { 
        if (myServo1.read() > 45) {
            myServo1.write(myServo1.read() - 1); 
        }
        if (myServo2.read() < 135) { 
            myServo2.write(myServo2.read() + 1);
        }
        delay(10);
    } 
}      
                    
{

for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
}

for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    digitalWrite(ledPins[thisPin], LOW);}
                       
for (int thisPin = 0; thisPin <pinCount; thisPin++) {
    
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer2);
    digitalWrite(ledPins[thisPin], LOW);}               
              
  }
 
  Serial.begin(9600);
    
       
Stop();
}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}

void left()
{  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);       
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
    
}

void right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
        
}

void forwardRight()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}

void forwardLeft()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void backwardRight()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  //motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void backwardLeft()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  motor1.setSpeed(speedCar);
  //motor2.setSpeed(speedCar);
  motor3.setSpeed(speedCar);
  motor4.setSpeed(speedCar);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
       
}

void loop(){      
if (Serial.available() > 0) {
  command = Serial.read();
  Stop();       //Initialize with motors stopped.

if (lightFront){digitalWrite(light_FF,
HIGH);}
if (!lightFront){digitalWrite(light_FF, LOW);}
        
if (lightBack) {digitalWrite(light_BB, HIGH);}
if (!lightBack) {digitalWrite(light_BB, LOW);}
        
if (horn) {digitalWrite(HORN, HIGH);}
if (!horn) {digitalWrite(HORN, LOW);}
        
if (indicator) {

  unsigned long currentMillis = millis();

  static unsigned long previousMillis = 0;

  static bool buzzerState = false;

  

  if (currentMillis - previousMillis >= 300) { // Toggle every 500ms

    previousMillis = currentMillis;

    buzzerState = !buzzerState;

    digitalWrite(blink, buzzerState);

  }

}

if (digitalRead(verificationPin) == HIGH) {            
               
switch (command) {
case'F':forward(),digitalWrite(leftlight, LOW),digitalWrite(rightlight,LOW),digitalWrite(light_BB, LOW);break;

case'B':backward(),digitalWrite(light_BB,   HIGH);indicator = true;break;
                        
//case'L':left(),digitalWrite(leftlight,HIGH),digitalWrite(rightlight,LOW);horn = true;break;
            
case 'L': {
    left();
    digitalWrite(rightlight, LOW);
    //digitalWrite(HORN, LOW);
    indicator = true;

    static unsigned long previousMillis = 0;
    static bool ledState = false;

    if (millis() - previousMillis >= 300) { 
        previousMillis = millis();
        ledState = !ledState;
        digitalWrite(leftlight,ledState);
}
break; 
}        
                      

case 'R': {
    right();
    digitalWrite(leftlight, LOW);
    //digitalWrite(HORN, LOW);            
    indicator = true;

    static unsigned long previousMillis = 0;
    static bool ledState = false;

    if (millis() - previousMillis >= 300) { 
        previousMillis = millis();
        ledState = !ledState;
       digitalWrite(rightlight,ledState);
}
break;
}                       

                                              
case'I':forwardRight(),digitalWrite(rightlight,HIGH),digitalWrite(leftlight,LOW);break;
            
case 'G':forwardLeft(),digitalWrite(leftlight, HIGH),digitalWrite(rightlight,LOW);break;
                                    
case 'J':backwardRight();break;
case 'H':backwardLeft();break;
            
            
case 'S':Stop(),digitalWrite(leftlight, LOW),digitalWrite(rightlight,LOW);
indicator = false;digitalWrite(blink, LOW);break;
                                                             
case '0':speedCar = 0;break;
case '1':speedCar = 25;break;
case '2':speedCar = 50;break;
case '3':speedCar = 75;break;
case '4':speedCar = 100;break;
case '5':speedCar = 125;break;
case '6':speedCar = 150;break;
case '7':speedCar = 175;break;
case '8':speedCar = 200;break;
case '9':speedCar = 225;break;
case 'q':speedCar = 255;break;

case 'W':lightFront = true;break;
case 'w':lightFront = false;break;
case 'U':lightBack = true;break;
case 'u':lightBack = false;break;
 
case 'V':horn = true;break;
case 'v':horn = false;break;                       
                                                   
case 'X': 
    for (int step = 45; step <= 135; step++) { 
        if (myServo1.read() < 135) { 
            myServo1.write(myServo1.read() + 1); 
        }
        if (myServo2.read() > 45) { 
            myServo2.write(myServo2.read() - 1);
        }
        delay(10);
    }
break;

case 'x': 
    for (int step = 45; step <= 135; step++) { 
        if (myServo1.read() > 45) {
            myServo1.write(myServo1.read() - 1); 
        }
        if (myServo2.read() < 135) { 
            myServo2.write(myServo2.read() + 1); 
        }
        delay(10);
    }
break;
                                 
}
        } else {
            Stop(); 
        }
    }
}
