# Mindwave carrinho

---

## Descrição

### [PT-BR]
Este projeto utiliza o Mindwave Mobile 2 e um Arduino para controlar um carrinho movido a motores DC. O nível de atenção detectado pelo Mindwave determina se o carrinho se move para frente. Quando o nível de atenção atinge um valor superior a 45, o carrinho começa a andar.

### [ENG]
This project uses the Mindwave Mobile 2 and an Arduino to control a car powered by DC motors. The attention level detected by the Mindwave determines whether the car moves forward. When the attention level exceeds 45, the car starts moving.

 ---

## Versão / Version

### [PT-BR]
- **Arduino IDE**: 1.8.13
- **Bibliotecas**:
  - [Mindwave](https://github.com/orgicus/Mindwave.git): Acesse o link, baixe o repositório como um arquivo ZIP e coloque na IDE Arduino.
  - SoftwareSerial: Incluída na IDE Arduino.

### [ENG]
- **Arduino IDE**: 1.8.13
- **Libraries**:
  - [Mindwave](https://github.com/orgicus/Mindwave.git): Access the link, download the repository as a ZIP file, and add it to the Arduino IDE.
  - SoftwareSerial: Included in the Arduino IDE.

---

## Materiais / Materials

### [PT-BR]
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

### [ENG]
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

## Como Fazer / How to 

### 1. Comandos AT para o HC-05 / AT Commands for HC-05:

### [PT-BR]
Para configurar o HC-05 e pareá-lo com o Mindwave, siga os comandos AT abaixo. Conecte o HC-05 ao Arduino nas portas 10 (TX do HC-05 para RX do Arduino) e 11 (RX do HC-05 para TX do Arduino). Para começar, rode o seguinte programa no IDE:

#include <SoftwareSerial.h>
SoftwareSerial BT(11, 10); // Rx/Tx

''' cpp
void setup() {
    BT.begin(38400);
    Serial.begin(9600);
}

void loop() {
    if (BT.available()) Serial.write(BT.read());
    if (Serial.available()) BT.write(Serial.read());
}
''' 

Após rodar o código, coloque esses comandos 1 por 1 no monitor serial; o monitor deverá responder "OK" para cada linha:

- `AT+UART=57600,0,0`
- `AT+ROLE=1`
- `AT+PSWD="0000"`
- `AT+CMODE=0`
- `AT+BIND=0081,F9,12CF79` (ou seu código de pareamento Mindwave)
- `AT+IAC=9E8B33`
- `AT+CLASS=0`
- `AT+INQM=1,9,48`

Certifique-se de que o monitor serial está configurado com NL&CR e com a taxa de baud a 9600 para enviar os comandos.

### [ENG]
To configure the HC-05 and pair it with the Mindwave, follow the AT commands below. Connect the HC-05 to the Arduino using pins 10 (TX from HC-05 to Arduino RX) and 11 (RX from HC-05 to Arduino TX) then run this code:

#include <SoftwareSerial.h>
SoftwareSerial BT(11, 10); // Rx/Tx

''' cpp
void setup() {
    BT.begin(38400);
    Serial.begin(9600);
}

void loop() {
    if (BT.available()) Serial.write(BT.read());
    if (Serial.available()) BT.write(Serial.read());
}
'''

After running the code, place these commands 1 by 1 on the serial monitor; the monitor should respond "OK" for each line:

- `AT+UART=57600,0,0`
- `AT+ROLE=1`
- `AT+PSWD="0000"`
- `AT+CMODE=0`
- `AT+BIND=0081,F9,12CF79` (or your Mindwave pairing code)
- `AT+IAC=9E8B33`
- `AT+CLASS=0`
- `AT+INQM=1,9,48`

Ensure that the serial monitor is set to NL&CR and a 9600 baud rate to send commands.

 
