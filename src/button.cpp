#include <Arduino.h>

const int buttonPin = 4;
const int ledPin = 13;
boolean onoff = HIGH;

void state2switch(int pin, boolean *onoff_addr)
{

  if (digitalRead(pin) == LOW)
  {
    Serial.println(*onoff_addr);
    *onoff_addr = (!*onoff_addr);
    delay(100); // this delay cannot be too short
  }
  else
  {
    Serial.println(*onoff_addr);
  }
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  // put your main code here, to run repeatedly:

  state2switch(buttonPin, &onoff);
  digitalWrite(ledPin, onoff);

  delay(100); // this delay cannot be too short
}