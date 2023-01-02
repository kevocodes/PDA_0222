//Variables
int infrarojoPin = D0; 
int estado = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(infrarojoPin, INPUT);
}

void loop() {
  //Lectura del sensor
  estado = digitalRead(infrarojoPin); 

  //Si se detecta un obstaculo se lee "0" o "LOW" caso contrario se lee "1" o "HIGH" 
  if (estado == 0){
    Serial.println("Encontrado");
  }else{
    Serial.println("No encontrado");
  }

  delay(500);

}
