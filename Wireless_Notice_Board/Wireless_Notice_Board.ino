#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd (4, 5, 6, 7, 8, 9);
SoftwareSerial mySerial (2, 3);   //(RX, TX);

String val = "No Data";
String oldval;
String newval = "No Data";
int i = 0;

void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(16,2);
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Wireless Notice");
  lcd.setCursor(0, 1);
  lcd.print("     Board     ");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome!");
}

void loop() 
{
  val = mySerial.readString();
  val.trim();
  Serial.println(val);
  if(val != oldval)
  {
    newval = val;
  }
  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print(newval);
  i++;
  if(i >= 15)
  {
    i = 0;
  }
  val = oldval;
}
