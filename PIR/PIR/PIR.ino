//Variables 
int sensorpir = D2; //Pin de datos, Digital
int valor = 0; //Estado del sensor

void setup()
{
  //Debe ser una entrada la lectura del sensor
  pinMode(sensorpir, INPUT);
  
  Serial.begin(115200);
}

void loop()
{
  valor = digitalRead(sensorpir); //Se lee el estado
  
  Serial.print("Estado: ");
  Serial.println(valor);

  //Si se detecta movimiento el estado es "1" o "HIGH" caso contrario es "0" o "LOW"
  if(valor == HIGH){
    Serial.print("Se ha detectado movimiento");
  }else{
    Serial.print("No se ha detectado movimiento");
  }

  //Delay entre mediciones, sino provoca errores
  delay(500);
}
