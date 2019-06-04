
#include "SoftwareSerial.h"
#include "Servo.h"
#include "MsTimer2.h"

//port 번호
#define LED 9
#define TRIG 8
#define ECHO 7
#define DC_F 3
#define DC_B 4
#define SERVO 10

//소나센서
#define COUNT 10
#define MAXRANGE 30
#define DURATION 200
#define MINRANGE 10

#define ANGLE 1
unsigned long distance = 0;
unsigned long prevTime = 0;
unsigned long currenTime = 0;

boolean state = LOW;

//모터
int forward = 88;
int backward = 99; 
int pos = 90;  //서보모터 각도
float k = 0;
Servo myservo;


void setup() {
  Serial.begin(9600);
  
  pinMode(ECHO,INPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(LED,OUTPUT);

  pinMode(DC_F, OUTPUT);
  pinMode(DC_B, OUTPUT);
  myservo.attach(SERVO);
  digitalWrite(LED,LOW);
}

unsigned long distanceMeas (){  //소나센서 작동 함수
    unsigned long distance;
    unsigned long meanDistance=0;

    for(int i=0;i<COUNT;i++)
    {
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG,LOW);
    distance = pulseIn(ECHO,HIGH)/58.2;
    meanDistance += distance;
    }
    meanDistance /= COUNT;
    
    if(meanDistance >= MAXRANGE) meanDistance = MAXRANGE;
    
    return meanDistance;
}

void sornor(){ //소나센서
  currenTime = millis();
  if(currenTime - prevTime >= DURATION){
  //  DURATION[ms]마다 실행
  distance = distanceMeas();
  Serial.print(distance);
  Serial.println("cm");
  prevTime = currenTime;
  }
}

void dcDrive(int m_fwd, int m_bwd, int choose_fb){  //모터 작동 함수    
  if(choose_fb == 0){                  
     digitalWrite(m_fwd,HIGH);
     digitalWrite(m_bwd,LOW);
   
  if(choose_fb == 1){
      digitalWrite(m_fwd,LOW);
      digitalWrite(m_bwd,HIGH);
    }
    }
  } 


void motor_test(){  //모터 TEST
  dcDrive(DC_F,DC_B,0);
  myservo.write(pos);
}
void loop() {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    distance = distanceMeas();
    Serial.println(distance);
    
    if(distance < MINRANGE)
    {
      digitalWrite(LED,HIGH);
      k += 0.1;
      if(k ==1000){
        if(pos <= 180) pos += 10;
        myservo.write(pos);
        k = 0;
      }
    } 
    else if(distance > 2*MINRANGE)
    {
      digitalWrite(LED,LOW);
      k += 0.1;
      if(k==1000){
        if(pos >= 90) pos -= 10;
        myservo.write(pos);
        k = 0;
      }
    } 
  }
