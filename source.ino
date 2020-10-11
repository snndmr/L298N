const int PIN_IN3 = 5;
const int PIN_IN4 = 4;
const int PIN_ENB = 3;
const int PIN_SW  = 2;
const int PIN_VRx = A0;
const int PIN_VRy = A1;

struct Joystick {
  int x;
  int y;
  bool isClick;
}

joystick = {
  .x = 0,
  .y = 0,
  .isClick = false
};

void setup() {
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);

  pinMode(PIN_VRx, INPUT);
  pinMode(PIN_VRy, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  joystick.x = analogRead(PIN_VRx);
  joystick.y = analogRead(PIN_VRy);
  joystick.isClick = !digitalRead(PIN_SW);

  joystick.x = map(joystick.x, 0, 1023, -255, 255);
  joystick.y = map(joystick.y, 0, 1023, -512, 512);

  analogWrite(PIN_ENB, (joystick.x > -20 && joystick.x < 20) ? 0 : abs(joystick.x));
  digitalWrite(PIN_IN3, (joystick.y > 20) ? HIGH : LOW);
  digitalWrite(PIN_IN4, (joystick.y < -20) ? HIGH : LOW);
  digitalWrite(LED_BUILTIN, (joystick.isClick) ? HIGH : LOW);

  Serial.print(" | Speed: ");
  Serial.print((joystick.x > -20 && joystick.x < 20) ? 0 : abs(joystick.x));
  Serial.print(" | Rotation: ");
  Serial.print(joystick.y > 20 ? "Right" : joystick.y < -20 ? "Left" : "Stop");
  Serial.print(" | Button: ");
  Serial.println(joystick.isClick);
}
