void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);//LED
  pinMode(7,OUTPUT);//LED
  pinMode(8,OUTPUT);//LED
  pinMode(9, INPUT);//Button
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(9);
  if(val == LOW)
  {
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(500);
    digitalWrite(6,HIGH);
    delay(500);
    digitalWrite(6,LOW);
    delay(500);
  }
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(1000);
}
//Stephanie da Costa was here
//Tim was also here
