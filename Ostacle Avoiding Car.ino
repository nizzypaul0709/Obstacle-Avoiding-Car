
int pwm1 = 3;                               //pwm pin for motor 1
int pwm2 = 5;                               //pwm pin for motor 2
const int trig = 12;
const int echo = 11;

long duration ;
int distance ;
void setup()
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig , HIGH);
  delay(10);
  digitalWrite(trig , LOW);
 
 
  duration = pulseIn(echo , HIGH);
  distance = duration*0.034/2;
  Serial.print("distance");
  Serial.println(distance);
  delay(100);
  
  analogWrite(pwm1,200);
  analogWrite(pwm2,200);

  if ( distance < 140 )
  {
    analogWrite(pwm1,100);
    analogWrite(pwm2,0);
  }
}
