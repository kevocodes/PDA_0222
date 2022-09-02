//LDR VARIABLES
int LDR = A0;
int value = 0;
int percentage = 0;
float volts = 0;

//RGB VARIABLES
int red = 6;
int blue = 5;
int green = 3;

void setup() {
  //LDR PIN
  pinMode(LDR, INPUT);

  //RGB PINS
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  //Initializing serial monitor
  Serial.begin(9600);
}

void loop() {
  //Reading Volts from LDR
  value = analogRead(LDR);
  percentage = map(value, 0, 1023, 0, 100);
  volts = (percentage*5.0)/100.0;
  Serial.println(volts);

  //RGB LOGIC

  if(volts>=0 and volts<1){
    analogWrite(red, 255);
    analogWrite(blue, 75);
    analogWrite(green, 100); 
  }else if(volts>=1 and volts<2){
    analogWrite(red, 60);
    analogWrite(blue, 250);
    analogWrite(green, 20);
  }else if(volts>=2 and volts<3){
    analogWrite(red, 255);
    analogWrite(blue, 255);
    analogWrite(green, 255);
  }else if(volts>=3 and volts<4){
    analogWrite(red, 100);
    analogWrite(blue, 5);
    analogWrite(green, 210);
  }else if(volts>=4 and volts<=5){
    analogWrite(red, 150);
    analogWrite(blue, 150);
    analogWrite(green, 150);
  }
}
