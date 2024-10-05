#include <SoftwareSerial.h>
#include <Mindwave.h>

Mindwave mindwave;   // Inicializa o Mindwave

// Pinos do módulo L298N para controlar os motores
const int motor1Pin1 = 9; // Motor A - Pino 1
const int motor1Pin2 = 8; // Motor A - Pino 2
const int motor2Pin1 = 7; // Motor B - Pino 1
const int motor2Pin2 = 6; // Motor B - Pino 2

void setup() {
  // Configuração dos pinos dos motores
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Inicializa a comunicação serial para o Mindwave
  Serial.begin(57600);
  delay(500); // Pequeno delay para garantir a inicialização

  Serial.println("Mindwave Ready!");
}

// Função para mover o carrinho para frente
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Função para parar os motores
void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

// Função para exibir o nível de atenção e controlar o carrinho
void onMindwaveData() {
  int attentionLevel = mindwave.attention(); // Obter o valor de atenção

  if (attentionLevel == 0 || attentionLevel == 1) {
    Serial.println("Carregando..."); // Exibir "Carregando" se o valor for 0 ou 1
  } else {
    // Exibir o nível de atenção
    Serial.print("Nível de atenção: ");
    Serial.println(attentionLevel);

    // Se o nível de atenção for maior que 45, mover o carrinho; caso contrário, parar
    if (attentionLevel > 45) {
      moveForward();
      Serial.println("Movendo para frente");
    } else {
      stopMotors();
      Serial.println("Parado");
    }
  }
}

void loop() {
  // Atualiza os dados do Mindwave no loop principal
  mindwave.update(Serial, onMindwaveData);
}
