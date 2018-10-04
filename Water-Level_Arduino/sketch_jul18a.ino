#define DANGER 10
#define WARNING 11
#define SAFE 12
#define BUZZER 13
int read_pins[7] = {2, 3, 4, 5, 6, 7, 8};

void _blink(int read_val);
void _beep(int read_val);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i < 7 ; i++) {
    pinMode(read_pins[i], INPUT);
  }

  pinMode(DANGER, OUTPUT);
  pinMode(WARNING, OUTPUT);
  pinMode(SAFE, OUTPUT);
  pinMode(BUZZER, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int read_val;
  for (int i = 0; i < 7; i++) {
    read_val = digitalRead(read_pins[i]);
    if(read_val == 1){
        read_val = i * 100;
      }
    else if(read_val == 0){
      continue;
      }
    Serial.print(read_val);
    Serial.print("\n");
    _blink(read_val);
    _beep(read_val);
  }
}


void _blink(int read_val) {

  int time_count, time_count1;
  int pin;
  if (read_val >= 0 && read_val <= 200) {
    time_count = 500;
    time_count1 = 1500;
    pin = SAFE;
  }
  else if ( read_val >= 300 && read_val <= 400) {
    time_count = 500;
    time_count1 = time_count;
    pin = WARNING;
  }
  else {
    time_count = 1500;
    time_count = 250;
    pin = DANGER;
  }


  long _time = millis();
  while (millis() - _time == time_count) {
    digitalWrite(pin, HIGH);
  }
  while (millis() - _time == time_count) {
    digitalWrite(pin, LOW);
  }
}

void _beep(int read_val) {
  int time_count, time_count1;
  if ( read_val >= 300 && read_val <= 400) {
    time_count = 500;
    time_count1 = time_count;
  }
  else if (read_val > 400) {
    time_count = 1500;
    time_count = 250;
  }

  long _time = millis();
  while (millis() - _time == time_count) {
    digitalWrite(BUZZER, HIGH);
  }
  while (millis() - _time == time_count) {
    digitalWrite(BUZZER, LOW);
  }

}
