#include<Servo.h>
Servo servox;
Servo servoy;
Servo servoz;
Servo servog;

int posx=90;
int posy=90;
int posz=40;
int posg=0;
byte x=48;
int y=0;
int f=1;
void setup()
{
  servox.attach(9);
  servoy.attach(10);
  servoz.attach(6);
  servog.attach(11);

  servox.write(90);
  servoy.write(90);
  servoz.write(40);
  servog.write(0);

  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()) {
    x= Serial.read();
  }
  Serial.print(x);
  Serial.print("\n");
  if(x==97)
  {
    posx-=20;
    servox.write(posx);
  }
  if(x==100)
  {
    posx+=20;
    servox.write(posx);
  }
  if(x==122)
 {posy-=20;
    servoy.write(posy);}
 if(x==99)
 {posy+=20;
    servoy.write(posy);}
 if(x==113)
 {posz+=20;
    servoz.write(posz);}
 if(x==101)
 {posz-=20;
    servoz.write(posz);}
 if(x==32)
 { if(y==0)
 { 
  servog.write(135); y=135;}
  else{servog.write(0); y=0;}
   }
 if(x==114)
 {
  servog.write(0);
  delay(2000);
  servox.write(90);
  servoy.write(90);
  servoz.write(40);
  
 }
 x=0;
 
}
