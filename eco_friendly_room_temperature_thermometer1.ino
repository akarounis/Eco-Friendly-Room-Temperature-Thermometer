#include <LiquidCrystal.h>

int outputpin= 0; //arxikopoiw to pin eksodou tou LM34 sensor
const int numRows= 2; //arxikopoiw ton arithmo stilwn kai grammwn tou lcd
const int numCols= 16;

//arxikopoiisi tis vivliothikis me tous arithmous twn pins tis diepafis
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//ekkinisi tis diepafis
void setup()
{
Serial.begin(9600);
lcd.begin(numCols, numRows);
lcd.print("Starting Up.....");
}

//main loop
void loop()
{
int rawvoltage= analogRead(outputpin);
float millivolts= (rawvoltage/1024.0) * 5000;
float celcius= millivolts/24.9836;
lcd.print("Temp: ");
lcd.print(celcius);
lcd.print(" C");
delay(5000);
lcd.clear();
}
