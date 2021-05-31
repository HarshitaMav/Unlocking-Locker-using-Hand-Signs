#include <Wire.h>


#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int x,lim=500;
int p,q,z,y;
int handsign();
void setup()
{
 Wire.begin();
 lcd.begin(16, 2); 
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(6,INPUT);
   
}

void loop()
{
  q,p = handsign();
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(q);              // sends p 
  Wire.write(p);
  Wire.endTransmission();    // stop transmitting
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.clear();
  }

int handsign(){
  
  y:
  z = millis();
  p = digitalRead(6);
  q = analogRead(A0);
  Serial.println(q);
  q = map(q,877,993,1,100);
  lcd.setCursor(0,0);          
  lcd.print("Flex Read = ");
  lcd.print(q);
  lcd.setCursor(0,1);           
  lcd.print("Tilt Read = ");
  lcd.print(p);
  if(z>lim){
    lim += 500;
    return q,p;
  }
  else{
    goto y;
  }
}