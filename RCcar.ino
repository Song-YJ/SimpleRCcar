#include <Movement.h>
#include <SoftwareSerial.h>

#define RM1 11
#define RM2 3 
#define LM1 6
#define LM2 5 

SoftwareSerial BT(8,7);
Movement mv(RM1, RM2, LM1, LM2);
int delaytime = 0;

void setup(){
  //저속주행이 가능하도록 모터 PWM 주파수 변경
  TCCR0B = TCCR0B & 0b11111000 | 0x05;
  TCCR2B = TCCR2B & 0b11111000 | 0x07;
  
  BT.begin(9600);

  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
}

void loop(){
  while(BT.available())
  {
    char c = BT.read();
    char v;

    switch(c)
    {
      case 'F':
      delaytime = 90;
      v = c + 32;
      break;

      case 'B':
      case 'L':
      case 'R':
      delaytime = 10;
      v = c + 32;
      break;

      default:
      v = c;
    }

    switch(v)
    { 
      case 'f':
      mv.forward();
      break;

      case 'b':
      mv.backward();
      break;

      case 'l':
      mv.left();
      break;

      case 'r':
      mv.right();
      break;

      default:
      mv.stop_();
    }

    if(delaytime != 0)
    {
      delay(delaytime);
      mv.stop_();
    }

    delaytime = 0;
  }
}
