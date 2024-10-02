# Projeto de Controle de Carrinho com Arduino e Mindwave

## [PT-BR] Descrição

Este projeto utiliza o Mindwave Mobile 2 e um Arduino para controlar um carrinho movido a motores DC. O nível de atenção detectado pelo Mindwave determina se o carrinho se move para frente. Quando o nível de atenção atinge um valor superior a 45, o carrinho começa a andar.

## [ENG] Description

This project uses the Mindwave Mobile 2 and an Arduino to control a car powered by DC motors. The attention level detected by the Mindwave determines whether the car moves forward. When the attention level exceeds 45, the car starts moving.

---

## [PT-BR / ENG] Bibliotecas / Libraries

- **SoftwareSerial.h**
- **Mindwave.h** 

---

## [PT-BR] Materiais

- 1 Arduino UNO
- 1 Mindwave Mobile 2
- 1 Módulo Bluetooth **HC-05** (não pode ser outro modelo)
- 1 Ponte H L298N
- 2 Motores DC
- 1 Chassi de carrinho cortado a laser (qualquer formato)
- 2 Rodas para motores DC
- 1 Roda "solta" para apoio
- 1 Suporte para 4 pilhas AA
- 4 Pilhas AA
- Vários jumpers

## [ENG] Materials

- 1 Arduino UNO
- 1 Mindwave Mobile 2
- 1 Bluetooth Module **HC-05** (no other model allowed)
- 1 L298N Motor Driver
- 2 DC Motors
- 1 Car chassis cut by laser (any shape)
- 2 Wheels for DC motors
- 1 "Free" wheel for support
- 1 Battery holder for 4 AA batteries
- 4 AA batteries
- Various jumper wires

---

## [PT-BR] How to

### 1. Comandos AT para o HC-05:

Para configurar o HC-05 e pareá-lo com o Mindwave, siga os comandos AT abaixo. Conecte o HC-05 ao Arduino nas portas 10 (TX do HC-05 para RX do Arduino) e 11 (RX do HC-05 para TX do Arduino), para começar, rode esse programa no ide:

#include <SoftwareSerial.h>
SoftwareSerial BT(11,10); //Rx/Tx
'''ccp
void setup(){
  BT.begin(38400);
  Serial.begin(9600);
}
 
void loop(){
  if( BT.available() ) Serial.write( BT.read() );
  if( Serial.available() ) BT.write(Serial.read());
}
'''
Após rodar o código, coloque esses comando 1 por 1 no monitor serial, o monitor deverá responder ok para cada linha:

- AT+UART=57600,0,0
- AT+ROLE=1
- AT+PSWD="0000"
- AT+CMODE=0
- AT+BIND=0081,F9,12CF79 (ou seu código de pareamento Mindwave)
- AT+IAC=9E8B33
- AT+CLASS=0
- AT+INQM=1,9,48

Certifique-se de que o monitor serial está configurado com NL&CR e com a taxa de baud a 9600 para enviar os comandos.

### 2. Conexões dos Fios:

- **Módulo Bluetooth HC-05**: RX na porta 10, TX na porta 11 (conectar apenas após a carga do código no Arduino).
- **Ponte H L298N**: 
    - ENA na porta 9, IN1 na porta 8, IN2 na porta 7, IN3 na porta 6, IN4 na porta 5, ENB na porta 4.
    - Motores conectados aos bornes de saída da ponte H.
    - Alimentação dos motores via o suporte de 4 pilhas AA.
    - GND da ponte H conectado ao GND do Arduino.
- **Motores DC**: 
    - Conectar os dois motores nas saídas da ponte H.

### 3. Carregamento do Programa:

Para carregar o código no Arduino, desconecte os fios RX e TX do módulo Bluetooth (portas 10 e 11). Após o carregamento, reconecte os fios e inicie o monitor serial.

### 4. Conectar o Mindwave:

Ligue o Mindwave Mobile 2 e espere até que o HC-05 seja pareado automaticamente. Verifique no monitor serial se o status de conexão está correto.

### 5. Funcionamento do Carrinho:

O carrinho começará a se mover quando o nível de atenção detectado pelo Mindwave ultrapassar 45. Esse valor pode ser ajustado para testes alterando o código no parâmetro condicional. Se a atenção cair abaixo de 45, o carrinho para.

---

## [ENG] How to

### 1. AT Commands for HC-05:

To configure the HC-05 and pair it with the Mindwave, follow the AT commands below. Connect the HC-05 to the Arduino using pins 10 (TX from HC-05 to Arduino RX) and 11 (RX from HC-05 to Arduino TX) then run this code:

#include <SoftwareSerial.h>
SoftwareSerial BT(11,10); //Rx/Tx
 
void setup(){
  BT.begin(38400);
  Serial.begin(9600);
}
 
void loop(){
  if( BT.available() ) Serial.write( BT.read() );
  if( Serial.available() ) BT.write(Serial.read());
}

After running the code, place these commands 1 by 1 on the serial monitor, the monitor should respond ok for each line:

- AT+UART=57600,0,0
- AT+ROLE=1
- AT+PSWD="0000"
- AT+CMODE=0
- AT+BIND=0081,F9,12CF79 (or your Mindwave pairing code)
- AT+IAC=9E8B33
- AT+CLASS=0
- AT+INQM=1,9,48

Ensure that the serial monitor is set to NL&CR and a 9600 baud rate to send commands.

### 2. Wiring:

- **Bluetooth Module HC-05**: RX on pin 10, TX on pin 11 (connect only after uploading the code).
- **L298N Motor Driver**: 
    - ENA on pin 9, IN1 on pin 8, IN2 on pin 7, IN3 on pin 6, IN4 on pin 5, ENB on pin 4.
    - Motors connected to the motor driver output.
    - Motors powered by a 4x AA battery pack.
    - GND from the motor driver connected to Arduino GND.
- **DC Motors**: 
    - Connect both motors to the L298N motor driver outputs.

### 3. Uploading the Program:

To upload the code to the Arduino, disconnect the RX and TX wires from the Bluetooth module (pins 10 and 11). After uploading, reconnect the wires and open the serial monitor.

### 4. Connect the Mindwave:

Power on the Mindwave Mobile 2 and wait until it pairs with the HC-05. Check the serial monitor to ensure the connection is successful.

### 5. Car Movement:

The car will start moving when the attention level detected by the Mindwave exceeds 45. This value can be adjusted for testing by changing the conditional parameter in the code. If attention drops below 45, the car will stop.
