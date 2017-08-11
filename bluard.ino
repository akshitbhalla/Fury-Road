/* Developed by ATIE: Kevin Prakash, Akshit Bhalla, Goutham Swaminathan, Mohit Ashwath
 * 
 * Arduino UNO program for 4 wheel RC Car
 * 
 * Components:
 * 1. Bluetooth Module HC-05
 * 2. Motor Driver L293 - Qt. 2
 * 3. AAA Batteries - Qt. 6
 * 
 */





// 1 :: left side
// 2 :: right side
// m#0# pin 1 motor driver
// m#1# pin 2 motor driver

int mf01=3; //mf :: front motor
int mf02=4;
int mb01=5; //mb :: back motor
int mb02=6;
int dir=0; // direction
int mf11=7;
int mf12=8;
int mb11=9;
int mb12=10;

void setup()
{
  Serial.begin(9600);
  delay(500);
  pinMode(mf01,OUTPUT);
  pinMode(mf02,OUTPUT);
  pinMode(mb01,OUTPUT);
  pinMode(mb02,OUTPUT);
  pinMode(mf11,OUTPUT);
  pinMode(mf12,OUTPUT);
  pinMode(mb11,OUTPUT);
  pinMode(mb12,OUTPUT);
}

void loop() 
{
      if(Serial.available() > 0)
      {     
        dir = Serial.read();   
      }  
      switch(dir)
      {
        case 1 :
        digitalWrite(mf01,HIGH);
        digitalWrite(mf02,HIGH);
        digitalWrite(mb01,HIGH);
        digitalWrite(mb02,HIGH);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,LOW);
        Serial.println("N");
        break;

        case 2:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,HIGH);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,HIGH);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,LOW);
        Serial.println("NW");
        break;

        case 3:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,HIGH);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,HIGH);
        digitalWrite(mf11,HIGH);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,HIGH);
        digitalWrite(mb12,LOW);
        Serial.println("W");
        break;
        
        case 4:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,HIGH);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,HIGH);
        Serial.println("SW");
        break;
        
        case 5:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,HIGH);
        digitalWrite(mf12,HIGH);
        digitalWrite(mb11,HIGH);
        digitalWrite(mb12,HIGH);
        Serial.println("S");
        break;

        case 6:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,HIGH);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,HIGH);
        digitalWrite(mb12,LOW);
        Serial.println("SE");
        break;

       case 7:
        digitalWrite(mf01,HIGH);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,HIGH);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,LOW);
        Serial.println("E");
        break;

        case 8:
        digitalWrite(mf01,HIGH);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,HIGH);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,HIGH);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,HIGH);
        Serial.println("NE");
        break;

        default:
        digitalWrite(mf01,LOW);
        digitalWrite(mf02,LOW);
        digitalWrite(mb01,LOW);
        digitalWrite(mb02,LOW);
        digitalWrite(mf11,LOW);
        digitalWrite(mf12,LOW);
        digitalWrite(mb11,LOW);
        digitalWrite(mb12,LOW);
        Serial.println("OFF");
        break;
      }
       delay(500);  
}

