const int pingPin = 7;
const int echoPin = 6;
const int ledGreen = 13;
void setup() {
Serial.begin(9600);
pinMode(ledGreen, OUTPUT);

}

void loop() {
long duration;
long cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);

pinMode(echoPin, INPUT);
duration=pulseIn(echoPin, HIGH);
cm=microsecondsToCentimeters(duration);

if(cm<=200)
{
digitalWrite(ledGreen, HIGH);
}
else
{
digitalWrite(ledGreen, LOW);
}
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds*0.034/2;
}
