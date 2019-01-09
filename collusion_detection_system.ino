const int trigPin = 9;
const int echoPin = 10;
int buzzer = 11;
int ledPin = 13;
int PIR_output=5;


long duration;
int distance;
int safetyDistance; 
int warningDistance;
void setup () {

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(PIR_output, INPUT);
Serial.begin(9600);
}


void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration= pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
safetyDistance = distance ;
warningDistance = distance ;

if(safetyDistance <= 10 && digitalRead (5) == HIGH){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  Serial.print("distance: Danger");

}
if((warningDistance <= 18 && warningDistance >10) && (digitalRead(5) == HIGH)){
  digitalWrite(buzzer, LOW);
  delay(80);
  digitalWrite(ledPin, HIGH);
  delay(100);
  Serial.print("distance: Warning ");
}
else
{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin,LOW); 
}
Serial.print("distance: ");
Serial.println(distance);
}
