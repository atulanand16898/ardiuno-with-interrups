const int relay1fwd=37;
const int relay1bckwd=35;
const int relay1lowspeed=31;
const int relay1midspeed=33;
const int relay2up=27;
const int relay2down=29;
const int relay2lowspeed=23;
const int relay2midspeed=25;
const int sensor1=39;
const int sensor2=41;
const int sensor3=43;
const int sensor4=45;
const int sensor5=47;
int sensor1val;
int sensor2val;
int sensor3val;
int q=1;
volatile int i=0;


void setup()

{
 Serial.begin(9600);
 pinMode(relay1fwd,OUTPUT);
 pinMode(relay1bckwd,OUTPUT);
 pinMode(relay1lowspeed,OUTPUT);
 pinMode(relay1midspeed,OUTPUT);
 pinMode(relay2up,OUTPUT); // up direction
 pinMode(relay2down,OUTPUT); // down direction
 pinMode(relay2lowspeed,OUTPUT); //updown low speed
 pinMode(relay2midspeed,OUTPUT); //updown high speed
 pinMode(sensor4,INPUT); //up sensor
 pinMode(sensor5,INPUT); //bottom sensor
 pinMode(sensor1,INPUT);
 pinMode(sensor2,INPUT);
 pinMode(sensor3,INPUT);
 pinMode(49,INPUT);
 attachInterrupt(2,count,RISING);
}


int forward(int x)
{
  i=0;
  int latch=1;
  digitalWrite(relay1fwd,HIGH); // move forward
  digitalWrite(relay1midspeed,HIGH);
  digitalWrite(relay1lowspeed,LOW);
  digitalWrite(relay1bckwd,LOW);
  digitalWrite(relay2up,LOW);
  digitalWrite(relay2down,LOW);
  digitalWrite(relay2midspeed,LOW);
  digitalWrite(relay2lowspeed,LOW);
  delay(200);
  while(i<x)
  {
    Serial.println(i);
  }
  if(i==x)
  {
    while(digitalRead(sensor2)==LOW)
    {
    digitalWrite(relay1midspeed,LOW);
    digitalWrite(relay1lowspeed,HIGH);
    Serial.println("forward slow NON-STOP done..!!");
    }
    digitalWrite(relay1fwd,LOW);
    digitalWrite(relay1lowspeed,LOW);
    Serial.println("STOP");
    return 1;
  }
}
void count()
{
  i++;
}
void loop()
{
  forward(4);
}

