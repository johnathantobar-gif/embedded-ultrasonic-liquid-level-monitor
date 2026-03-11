#include  <Wire.h>
#include <LiquidCrystal_I2C.h>

//ULTRASONIC PINS 
const int trigPin = 9;
const int echoPin = 10;

//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//LED
const int led1 = 2; //0-25% (blinking warning!)
const int led2 = 3; //25-50% (led)
const int led3 = 4; //50-75% (led)
const int led4 = 5; //75-100% (led)

//TANK HEIGHT
//DISTANCE FROM SENSOR TO THE BOTTOM
float fullDistance = 2.7; // DSITANCE OF CUP FULL TO SENSOR
float emptyDistance = 13.6; // DISTANCE OF CUP EMPTY TO SENSOR

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ultrasonic...");
}

void loop()
{
//ULTRASONIC SENSOR MEASUREMENTS
float distanceCm = readDistanceCm();

//CALCULATE WATRE LEVEL AND PERCENT FULL
float percentFull = ((emptyDistance - distanceCm) / (emptyDistance - fullDistance)) * 100.0;

if(percentFull < 0 ) percentFull = 0;
if(percentFull > 100 ) percentFull = 100;

//SERIAL OUTPUT 
Serial.print("Distance: ");
Serial.print(distanceCm);
Serial.print(" cm   level:  ");
Serial.print(percentFull);
Serial.print("%");

//LCD  DISPLAY
lcd.setCursor(0, 0);
lcd.print("Dist:");
lcd.print(distanceCm,1);
lcd.print("cm,  ");

lcd.setCursor(0,1);
lcd.print("level:");
lcd.print(percentFull, 1);
lcd.println("%  ");

//LED LOGIC
if(percentFull < 25)
{
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  delay(300);
}

else if (percentFull < 50)
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

else if (percentFull < 75)
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
}
else
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

delay(200);
}

// ULTRASONIC SENSOR FUNCTION

float readDistanceCm()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout

  if (duration == 0)
  {
    return -1;
  }

  return (duration * 0.0343) / 2.0;
}