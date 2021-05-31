#include <Wire.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int a=100,b=1,c=0,d=0;
int p,q,count = 0;
int detect();
void setup()
{
 Wire.begin(9); 
 lcd.begin(16, 2); 
 Serial.begin(9600);
 Wire.onReceive(receiveEvent);
 pinMode(10,OUTPUT);
 digitalWrite(10,LOW);
}
void receiveEvent(int bytes) {
  p = Wire.read();    // read one character from the I2C
  q = Wire.read();    // read one character from the I2C
}
void loop()
{
  Serial.print(p);
  Serial.print(" ");
  Serial.println(q);
  
  if(digitalRead(10)!=HIGH){
  	detect();
  }
  }
int detect(){
  if((p!=0) && (p!=c)){
    lcd.clear();
    lcd.setCursor(0,0); 
  if((a==p && b==q) && (p!=0)){
    
    lcd.print("Authenticated");
    count = 0;
  }
  else{
    lcd.print("wrong sign");
    lcd.setCursor(0,1);
    count += 1;
    lcd.print("Try");  
    lcd.setCursor(4,1);
    lcd.print(count);
    if(count == 3)
      digitalWrite(10,HIGH); 
 }
 c = p;
 return 0;     
}
}