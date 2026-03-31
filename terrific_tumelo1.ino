#include <Servo.h>

Servo servo_6;

int trigPin = 12;
int echoPin = 11;
int buzzerPin = 8;

long duration;
float Distance;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  return pulseIn(echoPin, HIGH, 30000); // timeout added
}

void setup()
{
  servo_6.attach(6, 500, 2500);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  servo_6.write(0);
}

void loop()
{
  duration = readUltrasonicDistance(trigPin, echoPin);

  Distance = (0.0343 * duration) / 2;

  if (Distance > 0 && Distance <= 10)
  {
    servo_6.write(90);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);
    delay(200);

    servo_6.write(0);
    delay(2000);
  }
  else
  {
    servo_6.write(0);
    digitalWrite(buzzerPin, LOW);
  }
}