#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


int gasValue = A0; // smoke / gas sensor connected with analog pin A1 of the arduino
int data = 0;

void setup()
{

randomSeed(analogRead(0));

Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)

lcd.begin(16,2);
pinMode(gasValue, INPUT);

lcd.print (" Gas Leakage ");
lcd.setCursor(0,1);
lcd.print (" Detector Alarm ");
delay(3000);
lcd.clear();

}

void loop()
{

data = analogRead(gasValue);

Serial.print("Gas Level: ");
Serial.println(data);
lcd.print ("Gas Scan is ON");
lcd.setCursor(0,1);
lcd.print("Gas Level: ");
lcd.print(data);
delay(1000);

if ( data > 500)
{

Serial.print("Gas detect alarm");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Gas Level Exceed");


}

else
{
Serial.print("Gas Level Low");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Gas Level Normal");
delay(1000);
}

lcd.clear();
}
