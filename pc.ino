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
    posx--;
    servox.write(posx);
  }
  if(x==100)
  {
    posx++;
    servox.write(posx);
  }
  if(x==122)
 {posy--;
    servoy.write(posy);}
 if(x==99)
 {posy++;
    servoy.write(posy);}
 if(x==113)
 {posz++;
    servoz.write(posz);}
 if(x==101)
 {posz--;
    servoz.write(posz);}
 if(x==32)
 {  servog.write(180);
 }
 if(x==114)
 {
  servox.write(90);
  servoy.write(90);
  servoz.write(40);
  servog.write(0);
 }
 
 
}
