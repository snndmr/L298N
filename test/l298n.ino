const int IN3 = 5;
const int IN4 = 4;
const int ENB = 3;

void setup() {
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);
}

void loop() {
//control speed 
  analogWrite(ENB, 0); 
//control direction 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
