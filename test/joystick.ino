const int PIN_VRx = A0;
const int PIN_VRy = A1;
const int PIN_SW = 2;

struct Joystick {
    int x: 10; // 2^10 = 1024, enough to represent 0-1023 values.
    int y: 10; // 2^10 = 1024, enough to represent 0-1023 values.
    bool isClick;
}

joystick = {
    .x = 0,
    .y = 0,
    .isClick = false
};

void setup() {
    Serial.begin(9600);

    pinMode(PIN_VRx, INPUT);
    pinMode(PIN_VRy, INPUT);
    pinMode(PIN_SW, INPUT_PULLUP);
}

void loop() {
    joystick.x = analogRead(PIN_VRx);
    joystick.y = analogRead(PIN_VRy);
    joystick.isClick = !digitalRead(PIN_SW);

    joystick.x = map(joystick.x, 0, 1023, -512, 512);
    joystick.y = map(joystick.y, 0, 1023, -512, 512);

    Serial.print("X: ");
    Serial.print(joystick.x);
    Serial.print(" | Y: ");
    Serial.print(joystick.y);
    Serial.print(" | Button: ");
    Serial.println(joystick.isClick);
}
