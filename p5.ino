// Código en C++

// Declaración de variables globales
int estado = 0; // La variable 'estado' se debe declarar fuera de 'loop' para que mantenga su valor entre iteraciones
bool estadoAnterior = LOW;

// Configuración inicial
void setup() {
  // Configuración de pines
  pinMode(8, OUTPUT); // LED
  pinMode(9, OUTPUT); // LED
  pinMode(10, OUTPUT); // LED RESULTANTE
  pinMode(7, INPUT);  // BOTON ENTRADA
  pinMode(6, INPUT);  // BOTON ENTRADA
  pinMode(11, INPUT);  // BOTON ESTADO
}

// Bucle principal
void loop() {
  bool p, q, r;
  
  // Leer estado de los botones y obtener valores de p y q
  p = PressAndTurn(7,8);
  q = PressAndTurn(6,9);
  
  // Leer estado del botón de cambio de compuerta
  bool estadoActual = digitalRead(11);
  if(estadoActual == HIGH && estadoAnterior == LOW){
    estado++;
    if (estado > 5) estado = 0; // Reiniciar estado si excede el número de compuertas
  }
  estadoAnterior = estadoActual; // Actualizar estado anterior
  
  // Calcular resultado de la compuerta actual
  r = Resultado(estado, p, q); // Llamada a la función Resultado para obtener 'r'
  
  // Encender o apagar LED resultado según 'r'
  if(r) digitalWrite(10,HIGH);
  else digitalWrite(10,LOW); 
}

// Función para calcular el resultado de la compuerta seleccionada
bool Resultado(int estado,bool p, bool q){
  switch(estado){
    case 0: return opAND(p,q);    // AND
    case 1: return opOR(p,q);     // OR
    case 2: return opNAND(p,q);   // NAND
    case 3: return opNOR(p,q);    // NOR
    case 4: return opXOR(p,q);    // XOR
    case 5: return opXNOR(p,q);   // XNOR
    default: return 0;            // Valor por defecto
  }
}

// Función para leer el botón y encender o apagar un LED
bool PressAndTurn(int pinRead, int pinWrite){
  if (digitalRead(pinRead) == HIGH) {
    digitalWrite(pinWrite, HIGH); // Encender LED
    return true;
  }
  else {
    digitalWrite(pinWrite, LOW); // Apagar LED
    return false;
  }
}

// Funciones para operaciones lógicas

bool opOR(bool p, bool q){
  if(!p && !q) {return false;}
  else if(p && !q) {return true;}
  else if(!p && q) {return true;}
  else {return true;}
}

bool opNOR(bool p, bool q){
  if(!p && !q) {return true;}
  else if(p && !q) {return false;}
  else if(!p && q) {return false;}
  else {return false;}
}

bool opAND(bool p, bool q){
  if(!p && !q) {return false;}
  else if(p && !q) {return false;}
  else if(!p && q) {return false;}
  else {return true;}
}

bool opNAND(bool p, bool q){
  if(!p && !q) {return true;}
  else if(p && !q) {return true;}
  else if(!p && q) {return true;}
  else {return false;}
}

bool opXOR(bool p, bool q){
  if(!p && !q) {return false;}
  else if(p && !q) {return true;}
  else if(!p && q) {return true;}
  else {return false;}
}

bool opXNOR(bool p, bool q){
  if(!p && !q) {return true;}
  else if(p && !q) {return false;}
  else if(!p && q) {return false;}
  else {return true;}
}
