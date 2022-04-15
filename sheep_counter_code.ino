int trigPin1 = 6, echoPin1 = 5; 
int trigPin2 = 11, echoPin2 = 10;
int count = 0;

void setup()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float duration1, duration2, distance1, distance2, gateWidth = 100;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  //to get rid of any junk waves in the trig pins
  
  //for sheeps entering
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);  
  duration1 = pulseIn(echoPin1, HIGH);  
  distance1 = 0.034*(duration1/2);
  
  //for sheeps leaving
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);  
  duration2 = pulseIn(echoPin2, HIGH);  
  distance2 = 0.034*(duration2/2);
  
  if(distance1<gateWidth){
    count+=1;
    delay(800); 
    //assuming this as the avg time a sheep takes to pass the gate
  }
  
  if(distance2<gateWidth){
    if(count>0){
      count-=1;
      delay(800);
    }  	
  }
  
  Serial.print("\nNumber of sheeps inside = ");
  Serial.println(count);
  delay(600);
}