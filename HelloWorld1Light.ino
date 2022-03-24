void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);//LED
  pinMode(9, INPUT);//Button
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(9);
  if(val == LOW)
  {
    digitalWrite(8,HIGH);
    delay(1000);
  }
  digitalWrite(8,LOW);
  delay(1000);
}
