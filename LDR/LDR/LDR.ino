//Pin analogico para el LDR
int LDR = A5;

//Variables a utilizar
int value = 0;
int percentage = 0;
float volts = 0;

void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Valor leido del pin analogo
  value = analogRead(LDR);
  //Porcentaje de luminosidad
  percentage = map(value, 0, 1023, 0, 100);
  //Porcentaje a partir del porcentaje de luminosidad
  volts = (percentage*5.0)/100.0;
  
  Serial.println(volts);
}
