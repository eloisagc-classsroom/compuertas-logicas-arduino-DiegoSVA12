
//VARIABLES
const byte ledPin[] = {5,6,7,8};
int ledPinLength = sizeof(ledPin) / sizeof(ledPin[0]);
int option;

//PREPARAR SALIDA
void setup()
{
  	for (int i=0; i<ledPinLength; i++) {
   		pinMode(ledPin[i], OUTPUT);  //los preparamos para salida
 	}
  Serial.begin(9600);
}

//LOOP PRINCIPAL
void loop() {
  
  Serial.println("Seleccione el orden del conteo binario");
  Serial.println("1. Ascendente ");
  Serial.println("2. Descendente ");
  while (Serial.available()== 0)
  {
  }
  option = Serial.parseInt();
  
  while (Serial.available() > 0) {
    Serial.read();
  }

  if(option == 1){
      //Ascendente
    for (int num = 0; num < Exponente(ledPinLength); num++) { // Cuenta de 0 a 15
      Serial.print("Numero decimal: ");Serial.print(num);
      String numBit = "";
      for (int i = 0; i < ledPinLength; i++) {
        if (num & (1 << i)) { // Comprueba si el bit en la posición i está encendido
          digitalWrite(ledPin[i], HIGH); // Enciende el LED si el bit está encendido
          numBit += "1";
        } else {
          digitalWrite(ledPin[i], LOW); // Apaga el LED si el bit está apagado
          numBit += "0";
        }

      }
      Serial.print(", Numero binario: ");Serial.println(invertirCadena(numBit));
      delay(500); // Espera un segundo antes de mostrar el siguiente número
    }
  }
  
  else if (option == 2){
    //Descendente
    for (int num = Exponente(ledPinLength) - 1; num >= 0; num--) {
      Serial.print("Numero decimal: ");Serial.print(num);
      String numBit = "";
      for (int i = 0; i < ledPinLength; i++) {
        if (num & (1 << i)) {
          digitalWrite(ledPin[i], HIGH);
          numBit += "1";
        } else {
          digitalWrite(ledPin[i], LOW);
          numBit += "0";
        }
      }
      Serial.print(", Numero binario: ");Serial.println(invertirCadena(numBit));
      delay(500); // Espera un segundo
    }
    
  }
  else {Serial.println("Opcion invalida!");}

  delay(1000);
  
  
}

int Exponente(int num){
  int resultado = 1;
  for(int i = 0 ; i<num ; i++){
    resultado = resultado * 2;
  }
  return resultado;
}

String invertirCadena(String s) {
  String temporal = "";
  for (int m = s.length() - 1; m >= 0; m--)
    temporal += s[m];
  return temporal;
}