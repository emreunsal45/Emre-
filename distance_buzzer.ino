int led_pin=11;
int buzz_pin=10;
int dist_pin=9;
int trig_pin=12;
long time_;
int distance;
void setup() {
pinMode(led_pin,OUTPUT);
pinMode(buzz_pin,OUTPUT);
pinMode(dist_pin,INPUT);
pinMode(trig_pin,OUTPUT);
Serial.begin(9600);

}

void loop() {
 digitalWrite(trig_pin,LOW);
 delayMicroseconds(2);
 digitalWrite(trig_pin,HIGH);
 delayMicroseconds(10);
time_=pulseIn(dist_pin,HIGH);
 distance=time_*0.034/2;
 Serial.print(distance);
if(distance>=30)
{noTone(buzz_pin);}
else if (distance>=20 && distance<30)
{tone(buzz_pin,500);}
else if (distance>=10 && distance<20)
{tone(buzz_pin,1000);}
else if (distance>=5 && distance<10)
{tone(buzz_pin,2000);}
else if(distance<5)
{tone(buzz_pin,3000);}
if(distance<=15)
{
  digitalWrite(led_pin,HIGH);
}
else if (distance>=16)
{
  digitalWrite(led_pin,LOW);
}
delay(100);
}
