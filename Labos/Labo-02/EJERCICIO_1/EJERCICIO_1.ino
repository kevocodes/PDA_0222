int LDR = A0;
int value = 0;
int percentage = 0;
float volts = 0;

void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(LDR);
  percentage = map(value, 0, 1023, 0, 100);
  volts = (percentage*5.0)/100.0;
  Serial.println(volts);
}
