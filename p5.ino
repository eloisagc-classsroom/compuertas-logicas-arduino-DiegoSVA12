// C++ code
//
int estado = 0; // La variable 'estado' se debe declarar fuera de 'loop' para que mantenga su valor entre iteraciones
bool estadoAnterior = LOW;
void setup() {
  pinMode(8, OUTPUT); //LED
  pinMode(9, OUTPUT); //LED
  pinMode(10, OUTPUT); //LED RESULTANTE
  pinMode(7, INPUT);  //BOTON ENTRADA
  pinMode(6, INPUT);  //BOTON ENTRADA
  pinMode(11, INPUT);  //BOTON ESTADO
}
void loop() {
  bool p, q, r;
  
  p = PressAndTurn(7,8);
  q = PressAndTurn(6,9);
  
  
  bool estadoActual = digitalRead(11);
  if(estadoActual == HIGH && estadoAnterior == LOW){
    estado++;
    if (estado > 5) estado = 0; // Reiniciar estado si excede el número de compuertas
  }
  estadoAnterior = estadoActual; // Actualizar estado anterior
  
  r = Resultado(estado, p, q); // Llamada a la función Resultado para obtener 'r'
  
  if(r) digitalWrite(10,HIGH);
  else digitalWrite(10,LOW);

  
}

bool Resultado(int estado,bool p, bool q){
  
  switch(estado){
    case 0:return opAND(p,q);    
    case 1:return opOR(p,q);
    case 2:return opNAND(p,q);   
    case 3:return opNOR(p,q);
    case 4:return opXOR(p,q);
    case 5:return opXNOR(p,q);    
    default: return 0;
    
  }
}

bool PressAndTurn(int pinRead, int pinWrite){
  if (digitalRead(pinRead) == HIGH) {
    digitalWrite(pinWrite, HIGH);
    return true;
  }
  else {
    digitalWrite(pinWrite, LOW);
    return false;
  }
}

bool opOR(bool p, bool q){
  if(!p && !q){return false;}
  else if(p && !q){return true;}
  else if(!p && q){return true;}
  else{return true;}
}

bool opNOR(bool p, bool q){
  if(!p && !q){return true;}
  else if(p && !q){return false;}
  else if(!p && q){return false;}
  else {return false;}
}

bool opAND(bool p, bool q){
  if(!p && !q){return false;}
  else if(p && !q){return false;}
  else if(!p && q){return false;}
  else {return true;}
}

bool opNAND(bool p, bool q){
  if(!p && !q){return true;}
  else if(p && !q){return true;}
  else if(!p && q){return true;}
  else {return false;}
}

bool opXOR(bool p, bool q){
  if(!p && !q){return false;}
  else if(p && !q){return true;}
  else if(!p && q){return true;}
  else {return false;}
}

bool opXNOR(bool p, bool q){
  if(!p && !q){return true;}
  else if(p && !q){return false;}
  else if(!p && q){return false;}
  else {return true;}
}
