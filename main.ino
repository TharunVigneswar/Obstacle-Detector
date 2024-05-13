const int trig = 4;
const int echo = 5;
const int motor1 = 2;
const int motor2 = 3;
const int green = 6;
const int red = 7;

long distance;
int duration;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.0343 / 2;

  Serial.println(distance);

  if (distance >= 50) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(motor2, HIGH);
    digitalWrite(motor1, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
 }
