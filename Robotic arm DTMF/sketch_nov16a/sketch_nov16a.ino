#include<Servo.h>
#define D0 A0
#define D1 A1
#define D2 A2
#define D3 A3

Servo servox;
Servo servoy;
Servo servoz;
Servo servog;

int posx=90;
int posy=90;
int posz=40;
int posg=0;

void setup() {
pinMode(D0,INPUT);
pinMode(D1,INPUT);
pinMode(D2,INPUT);
pinMode(D3,INPUT);

servox.attach(9);
servoy.attach(10);
servoz.attach(11);
servog.attach(6);

Serial.begin(9600);
}
int temp1=analogRead(D0);
int temp2=analogRead(D1);
int temp3=analogRead(D2);
int temp4=analogRead(D3);


void loop() 
{
  Serial.println(temp1);
  Serial.println(temp2);
  Serial.println(temp3);
  Serial.println(temp4);
  servog.write(0);
 if(temp1==1&&temp2==0&&temp3==0&&temp4==0)
 {posy-=5;
    servoy.write(posy);}
 if(temp1==1&&temp2==1&&temp3==0&&temp4==0)
 {posy+=5;
    servoy.write(posy);}
 if(temp1==0&&temp2==0&&temp3==1&&temp4==0)
 { posx+=5;
    servox.write(posx);}
 if(temp1==0&&temp2==1&&temp3==1&&temp4==0)
 { posx-=5;
    servox.write(posx);}
 if(temp1==1&&temp2==1&&temp3==2&&temp4==0)
 {posz+=5;
    servoz.write(posz);}
 if(temp1==1&&temp2==0&&temp3==0&&temp4==1)
 {posz-=5;
    servoz.write(posz);}
 if(temp1==1&&temp2==0&&temp3==1&&temp4==0)
 {  servog.write(180);}
}
