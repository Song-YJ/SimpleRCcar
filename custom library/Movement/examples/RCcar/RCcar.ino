#include <Movement.h>
#include <SoftwareSerial.h>

#define RM1 11
#define RM2 3 
#define LM1 6
#define LM2 5 

SoftwareSerial BT(8,7);
Movement mv(RM1, RM2, LM1, LM2);

void setup(){
  //저속주행이 가능하도록 모터 PWM 주파수 변경
  //TCCR0B = TCCR0B & 0b11111000 | 0x05;
  //TCCR2B = TCCR2B & 0b11111000 | 0x07;
  
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);

  mv.setsp(85);
}

void loop(){ 
  while(BT.available())
  {
    char c = BT.read();

    switch(c)
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
  }
}
