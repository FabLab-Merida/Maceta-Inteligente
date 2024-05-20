/* 
*
* FABLAB MÉRIDA - Sistema de riego automatizado 
* VER: 0.9 by CyX
*
*/

// ########### CONFIGURACION ###########
int pin_sensorh = A0;   //Pin sensor 
int pin_rele = 10;      //Pin relé / bomba de agua
int lvl_humedad = 410;  //Sera el valor por el cual funcionará la bomba si este esta por debajo.



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pin_rele, OUTPUT);
  pinMode(pin_sensorh, INPUT);
  Serial.begin(9600);
}

int medicion();

/*
    ADVERTENCIA LOS RELÉS QUE USA ESTE PROGRAMA SON DE LÓGICA INVERSA, POR LO QUE HIGH = LOW Y LOW = HIGH
*/
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Esta linea indicara si la pico ó placa sin luces rx tx esta funcionando
  while (medicion() > lvl_humedad) {
    Serial.println("Regando...");
    digitalWrite(pin_rele, LOW);
  }
  digitalWrite(pin_rele, HIGH);
}

int medicion() {
  int humedad = analogRead(pin_sensorh);
  Serial.print("El nivel de humedad es: ");
  Serial.println(humedad);
  return humedad;
  delay(500);
}