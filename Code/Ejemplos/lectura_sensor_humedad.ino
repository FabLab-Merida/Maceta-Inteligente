const int sensorPin = A0; //Conectamos el sensor al A0

void setup(){
  Serial.begin(9600);
}
void loop(){
  //Leemos el valor del sensor y lo imprimimos por pantalla
  int humedad = analogRead(sensorPin);
  Serial.print(humedad);
  delay(1000);
}
