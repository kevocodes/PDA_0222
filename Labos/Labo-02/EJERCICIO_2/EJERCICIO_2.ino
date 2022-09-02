int red = 6;
int blue = 5;
int green = 3;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Secuencia 1
  analogWrite(red, 255);
  analogWrite(blue, 75);
  analogWrite(green, 100);
  delay(2000);

  //Secuencia 2
  analogWrite(red, 255);
  analogWrite(blue, 75);
  analogWrite(green, 100);
  delay(2000);

  //Secuencia 3
  analogWrite(red, 60);
  analogWrite(blue, 250);
  analogWrite(green, 20);
  delay(2000);

  //Secuencia 4
  analogWrite(red, 10);
  analogWrite(blue, 90);
  analogWrite(green, 255);
  delay(2000);

  //Secuencia 5
  analogWrite(red, 255);
  analogWrite(blue, 150);
  analogWrite(green, 255);
  delay(2000);

  //Secuencia 6
  analogWrite(red, 100);
  analogWrite(blue, 5);
  analogWrite(green, 210);
  delay(2000);

  //Secuencia 7
  analogWrite(red, 0);
  analogWrite(blue, 150);
  analogWrite(green, 150);
  delay(2000);

  //Secuencia 8
  analogWrite(red, 150);
  analogWrite(blue, 150);
  analogWrite(green, 150);
  delay(2000);

  //Secuencia 9
  analogWrite(red, 0);
  analogWrite(blue, 75);
  analogWrite(green, 255);
  delay(2000);

  //Secuencia 10
  analogWrite(red, 255);
  analogWrite(blue, 0);
  analogWrite(green, 0);
  delay(2000);
}
