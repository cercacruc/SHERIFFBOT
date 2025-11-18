void setup() {
  Serial.begin(9600);
  
  // Configurar los 6 pines como salida (pines 2-7)
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  // Pequeña secuencia de inicio para verificar LEDs
  for (int i = 2; i <= 7; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  delay(500);
  for (int i = 2; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  
  Serial.println("ARDUINO_LISTO_CON_6_LEDS");
  Serial.println("Comandos: LED1_ON, LED1_OFF, LED2_ON, LED2_OFF, LED3_ON, LED3_OFF");
  Serial.println("          LED4_ON, LED4_OFF, LED5_ON, LED5_OFF, LED6_ON, LED6_OFF");
  Serial.println("          ALL_ON, ALL_OFF, TEST");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    // Comando de prueba
    if (command == "TEST") {
      Serial.println("ARDUINO_OK");
      return;
    }
    
    // Comandos individuales para cada LED
    if (command == "LED1_ON") {
      digitalWrite(2, HIGH);
      Serial.println("LED1_ENCENDIDO");
    }
    else if (command == "LED1_OFF") {
      digitalWrite(2, LOW);
      Serial.println("LED1_APAGADO");
    }
    else if (command == "LED2_ON") {
      digitalWrite(3, HIGH);
      Serial.println("LED2_ENCENDIDO");
    }
    else if (command == "LED2_OFF") {
      digitalWrite(3, LOW);
      Serial.println("LED2_APAGADO");
    }
    else if (command == "LED3_ON") {
      digitalWrite(4, HIGH);
      Serial.println("LED3_ENCENDIDO");
    }
    else if (command == "LED3_OFF") {
      digitalWrite(4, LOW);
      Serial.println("LED3_APAGADO");
    }
    else if (command == "LED4_ON") {
      digitalWrite(5, HIGH);
      Serial.println("LED4_ENCENDIDO");
    }
    else if (command == "LED4_OFF") {
      digitalWrite(5, LOW);
      Serial.println("LED4_APAGADO");
    }
    else if (command == "LED5_ON") {
      digitalWrite(6, HIGH);
      Serial.println("LED5_ENCENDIDO");
    }
    else if (command == "LED5_OFF") {
      digitalWrite(6, LOW);
      Serial.println("LED5_APAGADO");
    }
    else if (command == "LED6_ON") {
      digitalWrite(7, HIGH);
      Serial.println("LED6_ENCENDIDO");
    }
    else if (command == "LED6_OFF") {
      digitalWrite(7, LOW);
      Serial.println("LED6_APAGADO");
    }
    // Comandos especiales
    else if (command == "ALL_ON") {
      for (int i = 2; i <= 7; i++) {
        digitalWrite(i, HIGH);
      }
      Serial.println("TODOS_LEDS_ENCENDIDOS");
    }
    else if (command == "ALL_OFF") {
      for (int i = 2; i <= 7; i++) {
        digitalWrite(i, LOW);
      }
      Serial.println("TODOS_LEDS_APAGADOS");
    }
    else {
      Serial.println("COMANDO_DESCONOCIDO: " + command);
    }
  }
}