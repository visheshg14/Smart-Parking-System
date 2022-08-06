int dur_1, dur_2;
long dist_1, dist_2;
int max=10;
long currState1=0, lastState1=0, currState2=0, lastState2=0, counter=0;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(2, LOW);
  dur_1=pulseIn(3,HIGH);
  dist_1=dur_1*0.034/2;
  
  digitalWrite(4, LOW);
  delayMicroseconds(2);
  digitalWrite(4, HIGH);
  delayMicroseconds(10); 
  digitalWrite(4, LOW);
  dur_2=pulseIn(5,HIGH);
  dist_2=dur_2*0.034/2;
  
  if (dist_1 <= 200) 
  {
    currState1= 1;
  }
  else
  {
    currState1 = 0;
  }
 
  if(currState1 == 1 && lastState1 == 0) 
  {
      counter++;
	  if(counter<=max)
	  {
        Serial.print("Count = ");
    	Serial.println(counter);
      }     
  }
  lastState1 = currState1;
  delay(30);

  if (dist_2 <= 200) 
  {
    currState2= 1;
  }
  else 
  {
    currState2 = 0;
  }
 
  if(currState2 == 1 && lastState2 == 0) 
  {
      counter--;
	  if(counter>=0)
	  { 
        Serial.print("Count = ");
    	Serial.println(counter);
      }     
   }
  lastState2 = currState2;
  delay(30);
}
  



