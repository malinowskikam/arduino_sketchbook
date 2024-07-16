const int motor_pin_1 = 2;
const int motor_pin_2 = 3;
const int motor_pin_3 = 4;
const int motor_pin_4 = 5;

const int x_axis_pin = A0;

const unsigned long step_motor_t = 1;

int step = 1;
unsigned long last_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(x_axis_pin, INPUT);
  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(motor_pin_3, OUTPUT);
  pinMode(motor_pin_4, OUTPUT);
}

void loop() {
  unsigned long current_time = millis();

  if (current_time - last_time > step_motor_t) {
    digitalWrite(motor_pin_1, step == 1 ? HIGH : LOW);
    digitalWrite(motor_pin_2, step == 2 ? HIGH : LOW);
    digitalWrite(motor_pin_3, step == 3 ? HIGH : LOW);
    digitalWrite(motor_pin_4, step == 4 ? HIGH : LOW);

    int x_pos = analogRead(x_axis_pin);

    int change = 0;
    if (x_pos < 510) {
      change = -1;
    } else if (x_pos > 525) {
      change = 1;
    }

    step = step + change;
    if (step == 5) {
      step = 1;
    }
    if (step == 0) {
      step = 4;
    }
    last_time = current_time;
  }
}
