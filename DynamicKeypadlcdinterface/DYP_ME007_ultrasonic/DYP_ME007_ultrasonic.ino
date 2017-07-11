const int pingPin = 7;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delay(60);                                    // Keep it LOW for at least 50 ms

  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);                   // 10 us is OK
  digitalWrite(pingPin, LOW);

  // max delay of 8 x 25 uSec for the 8 40 Khz pulses
  // you might be listening too fast
  delayMicroseconds(150); 

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  if (duration > 37500)  // 38000 plus some margin
  {
    Serial.println("no obstacles found");
  }

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(duration);
  Serial.print(", ");
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 148;
}

long microsecondsToCentimeters(long microseconds)
{
   return microseconds /58;
}


