/* Developed by ATIE: Kevin Prakash, Akshit Bhalla, Goutham Swaminathan, Mohit Ashwath
 * 
 * Arduino program for 4 wheel RC Car
 * 
 * speedecifications:
 * 1. Bluetooth Module HC-05
 * 2. Motor Driver L293 - Qt. 2
 * 3. AAA Batteries - Qt. 6
 * 
 */

int leftMotorPin1=3;
int leftMotorPin0=5;
int rightMotorPin1=6;
int rightMotorPin0=9;
int direction=0;
int speed=0;
int extra=0;

void setup()
{
  Serial.begin(9600);
  delay(500);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin0,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin0,OUTPUT);
}
void loop() 
{
      if(Serial.available() > 0)
      {     
        if(int num=Serial.read()<60)
        {
            direction = num%10;
            speed=num/10;
        }
        else
            extra=num;
           
      }  
      switch(direction)
      {
        case 1 :
            leftforward();
            rightforward();
            Serial.println("N");
        break;

        case 2:
            leftstop();
            rightforward();
            Serial.println("NW");
        break;

        case 3:
            leftreverse();
            rightforward();
            Serial.println("W");
        break;
        
        case 4:
            leftstop();
            rightreverse();
            Serial.println("SW");
        break;
        
        case 5:
            leftreverse();
            rightreverse();
            Serial.println("S");
        break;

        case 6:
           rightstop();
           leftreverse();
        Serial.println("SE");
        break;

       case 7:
            leftforward();
            rightreverse();
        Serial.println("E");
        break;

        case 8:
            leftforward();
            rightstop();
        Serial.println("NE");
        break;

        default:
            leftstop();
            rightstop();
        Serial.println("OFF");
        break;
      }
       delay(500);  
}

void leftforward(void)
{
    analogWrite(leftMotorPin0,0);
    analogWrite(leftMotorPin1,0);
    delay(100);
    analogWrite(leftMotorPin0,speed);
    analogWrite(leftMotorPin1,0);
}

void leftreverse(void)
{
    analogWrite(leftMotorPin0,0);
    analogWrite(leftMotorPin1,0);
    delay(100);
    analogWrite(leftMotorPin0,0);
    analogWrite(leftMotorPin1,speed);
}
void leftstop(void)
{
    analogWrite(leftMotorPin0,0);
    analogWrite(leftMotorPin1,0);
}

void rightforward(void)
{
    analogWrite(rightMotorPin0,0);
    analogWrite(rightMotorPin1,0);
    delay(100);
    analogWrite(rightMotorPin0,speed);
    analogWrite(rightMotorPin1,0);
}
void rightreverse(void)
{
    analogWrite(rightMotorPin0,0);
    analogWrite(rightMotorPin1,0);
    delay(100);
    analogWrite(rightMotorPin0,0);
    analogWrite(rightMotorPin1,speed);
}
void rightstop(void)
{
    analogWrite(rightMotorPin0,0);
    analogWrite(rightMotorPin1,0);
}
