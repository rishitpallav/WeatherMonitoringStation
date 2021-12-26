#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7
int pin=8;
int pinLed=9;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pin, INPUT);
  pinMode(pinLed,OUTPUT);
}
int rain=0;
int measurement=0;

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  Serial.println("Temp: ");
  lcd.print(DHT.temperature);
  Serial.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umid: ");
  Serial.println("Umid: ");
  lcd.print(DHT.humidity);
  Serial.println(DHT.humidity);
  lcd.print("%");
  delay(1000);
  rain = digitalRead(pin); 
  if(rain==1) 
    digitalWrite(pinLed,LOW);
  if(rain==0)
    digitalWrite(pinLed,HIGH);
    measurement = analogRead(A0);
    Serial.println(measurement);
  
  delay(1000);
  }
