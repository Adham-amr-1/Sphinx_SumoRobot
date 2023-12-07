//------------------ Sphinx Sumo ------------------//
//  Front Driver
# define n1 13
# define n2 12
# define ENA1 9
# define n3 11
# define n4 8
# define ENB1 10

// Back
# define n5 7 //in1
# define n6 4 //in2
# define ENA2 5
# define n7 3 //in3
# define n8 2 //in4
# define ENB2 6

// IR Front
# define irf1 A0
int irf = HIGH;

// IR Back
# define irb1 A1
int irb = HIGH;

// ultra Front
#define echf  A2
#define trgf  A3

//ULTRA b--------------------------------------
#define echb  A4
#define trgb  A5

//-------------------
int frontdis;
int backdis ;
int Highspeed = 250;
int mediumspeed = 200;
int distant = 35;
//---------------------
void forward();
void Back();
void Left();
void Right();
void stope();
int readSensor(int, int);
//------------------------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ---------------- Front Motor
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(ENA1,OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4,OUTPUT);
  pinMode(ENB1,OUTPUT);
  // ---------------- Back Motor
  pinMode(n5, OUTPUT);
  pinMode(n6, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(n7, OUTPUT);
  pinMode(n8,OUTPUT);
  pinMode(ENB2,OUTPUT);
  //-----------------------IR front
  pinMode(irf1,INPUT);
  //-----------------------IR back
  pinMode(irb1,INPUT);
  //------------------------ULRA front
   pinMode(trgf , OUTPUT);
   pinMode(echf , INPUT);
  //------------------------ ULTRA back
  pinMode(trgb , OUTPUT);
  pinMode(echb , INPUT);

  delay(5000);
  rotateRight(Highspeed);
  // rotate 180 degree
  delay(1350);
  forward(Highspeed);
  delay(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Ir Reading
  irf=digitalRead(irf1);
  irb=digitalRead(irb1);
  // ultra reading
  frontdis = readSensor(trgf , echf);
  backdis  = readSensor(trgb , echb);
  // Conditions
  //-----------------------------------------------------------
  if(irf == LOW && irb == LOW && frontdis < distant){ // In 7alba
      forward(Highspeed);
  }
  //---
  else if(irf == LOW && irb == LOW && backdis < distant){
      Back(Highspeed);
  }
  //---
  else if(irf == HIGH && irb == LOW && backdis < distant){
      Back(Highspeed);
  }
  //---
  else if(irf == HIGH && irb == LOW){
      rotateRight(Highspeed);
  }
  //---
  else if(irf == LOW && irb == HIGH && frontdis < distant){
      forward(Highspeed);
  }
  //---
  else if(irf == LOW && irb == HIGH){
    forward(Highspeed);
    //--------
  }
  else if(irf == LOW && irb == LOW && frontdis > distant && backdis > distant){
    forward(Highspeed);
    delay(200);
    rotateRight(Highspeed);
    delay(150);
    Back(Highspeed);
    delay(150);
  }
//-------rrr
else if(irf == HIGH && irb == LOW && frontdis < distant){
      forward(Highspeed);
  }
  //--------
  else if(irf == LOW && irb == HIGH && backdis < distant){
      Back(Highspeed);
      }
  //---
  else{
    stope();
  }
//----------------------------------------------------------------------------------
}
void forward(int speed)
{  
 digitalWrite(n1,LOW);
 digitalWrite(n2,HIGH);
 digitalWrite(n3,HIGH);
 digitalWrite(n4,LOW);
 digitalWrite(n5,HIGH);
 digitalWrite(n6,LOW);
 digitalWrite(n7,HIGH);
 digitalWrite(n8,LOW);
 analogWrite(ENA1,speed );
 analogWrite(ENB1,speed ); 
 analogWrite(ENA2,speed );
 analogWrite(ENB2,speed ); 
} 
void Back(int speed)
{  
 digitalWrite(n1,HIGH);
 digitalWrite(n2,LOW);
 digitalWrite(n3,LOW);
 digitalWrite(n4,HIGH);
 digitalWrite(n5,LOW);
 digitalWrite(n6,HIGH);
 digitalWrite(n7,LOW);
 digitalWrite(n8,HIGH);
 analogWrite(ENA1,speed );
 analogWrite(ENB1,speed ); 
 analogWrite(ENA2,speed );
 analogWrite(ENB2,speed ); 
} 
void rotateRight(int speed)
{  
 digitalWrite(n1,HIGH);
 digitalWrite(n2,LOW);
 digitalWrite(n3,HIGH);
 digitalWrite(n4,LOW);
 digitalWrite(n5,LOW);
 digitalWrite(n6,HIGH);
 digitalWrite(n7,HIGH);
 digitalWrite(n8,LOW);
 analogWrite(ENA1,speed );
 analogWrite(ENB1,speed ); 
 analogWrite(ENA2,speed );
 analogWrite(ENB2,speed ); 
} 
void rotateLeft(int speed)
{  
 digitalWrite(n1,LOW);
 digitalWrite(n2,HIGH);
 digitalWrite(n3,LOW);
 digitalWrite(n4,HIGH);
 digitalWrite(n5,HIGH);
 digitalWrite(n6,LOW);
 digitalWrite(n7,LOW);
 digitalWrite(n8,HIGH);
 analogWrite(ENA1,speed);
 analogWrite(ENB1,speed); 
 analogWrite(ENA2,speed);
 analogWrite(ENB2,speed); 
} 
void stope()
{
 digitalWrite(n1,LOW);
 digitalWrite(n2,LOW);
 digitalWrite(n3,LOW);
 digitalWrite(n4,LOW);
 digitalWrite(n5,LOW);
 digitalWrite(n6,LOW);
 digitalWrite(n7,LOW);
 digitalWrite(n8,LOW);
} 
int readSensor(int trig_pin, int echo_pin) {
  // Send ultrasonic pulse
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  
  // Convert duration to distance in cm
  int distance = duration * 0.034 / 2;

  return distance;
  }