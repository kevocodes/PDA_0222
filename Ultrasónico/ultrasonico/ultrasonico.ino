const int trigPin = D5; //Para ESP82266 usar D5 si o si; 
const int echoPin = D6;//Para ESP82266 usar D6 si o si;

long duration;
float distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= (duration*0.0343)/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
//Importante este delay de 2 seg. entre medidas
delay(2000);
}
