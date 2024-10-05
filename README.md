# Mindwave carrinho

---

### Sumário / summary

- [1. Descrição / Description](#1-descrição--description)
- [2. Versão / Version](#2-versão--version)
- [3. Materiais / Materials](#3-materiais--materials)
- [4. Como usar / How to](#4-como-usar--how-to)
  - [1. Comandos AT para o HC-05 / AT Commands for HC-05](#1-comandos-at-para-o-hc-05--at-commands-for-hc-05)
  - [2. Conexões dos Fios / Wiring](#2-conexões-dos-fios--wiring)
  - [3. Carregamento do Programa / Uploading the Program](#3-carregamento-do-programa--uploading-the-program)
  - [4. Conectar o Mindwave / Connect the Mindwave](#4-conectar-o-mindwave--connect-the-mindwave)
  - [5. Funcionamento do Carrinho / Car Movement](#5-funcionamento-do-carrinho--car-movement)

---

### 1. Descrição / Description

### [PT-BR]
Este projeto utiliza o Mindwave Mobile 2 e um Arduino para controlar um carrinho movido a motores DC. O nível de atenção detectado pelo Mindwave determina se o carrinho se move para frente. Quando o nível de atenção atinge um valor superior a 45, o carrinho começa a andar.

### [ENG]
This project uses the Mindwave Mobile 2 and an Arduino to control a car powered by DC motors. The attention level detected by the Mindwave determines whether the car moves forward. When the attention level exceeds 45, the car starts moving.

 ---

### 2. Versão / Version

### [PT-BR]
- **Arduino IDE**: 1.8.13
- **Bibliotecas**:
  - [Mindwave.h](https://github.com/orgicus/Mindwave.git): Acesse o link, baixe o repositório como um arquivo ZIP e coloque na IDE Arduino.
  - SoftwareSerial.h: Incluída na IDE Arduino.

### [ENG]
- **Arduino IDE**: 1.8.13
- **Libraries**:
  - [Mindwave.h](https://github.com/orgicus/Mindwave.git): Access the link, download the repository as a ZIP file, and add it to the Arduino IDE.
  - SoftwareSerial.h: Included in the Arduino IDE.

---

### 3. Materiais / Materials

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

### 4. Como usar / How to

### 1. Comandos AT para o HC-05 / AT Commands for HC-05:

### [PT-BR]
Para configurar o HC-05 e pareá-lo com o Mindwave, siga os passos abaixo. Conecte o HC-05 ao Arduino nas portas 10 (TX do HC-05 para RX do Arduino) e 11 (RX do HC-05 para TX do Arduino). Para começar, coloque o módulo HC-05 no modo AT, para poder configurá-lo, para isso desconecte o cabo usb do arduíno do computador, segure o botão presente no módulo e reconecte o cabo, assim, a luz irá piscar lentamente, após isso, rode o código do arquivo "PrepAT.ino".


Após rodar o código, coloque esses comandos 1 por 1 no monitor serial; o monitor deverá responder "OK" para cada linha:

- `AT+UART=57600,0,0`
- `AT+ROLE=1`
- `AT+PSWD="0000"`
- `AT+CMODE=0`
- `AT+BIND=xxxx,xx,xxxxxx` (endereço MAC do Mindwave, utilizando esse formato, obtenha conectando ele ao bluetooth de outro dispositivo)
- `AT+IAC=9E8B33`
- `AT+CLASS=0`
- `AT+INQM=1,9,48`

Certifique-se de que o monitor serial está configurado com NL&CR e com a taxa de baud a 9600 para enviar os comandos.
Uma vez que os comandos AT estiverem no Módulo, não é necessário entrar novamente no modo AT

### [ENG]
To configure the HC-05 and pair it with the Mindwave, follow the steps below. Connect the HC-05 to the Arduino on ports 10 (HC-05 TX to Arduino RX) and 11 (HC-05 RX to Arduino TX). To begin, place the HC-05 module in AT mode, to be able to configure it, to do this, disconnect the Arduino USB cable from the computer, hold down the button on the module and reconnect the cable, so the light will blink slowly, then run the code from the "PrepAT.ino" file.


After running the code, place these commands 1 by 1 on the serial monitor; the monitor should respond "OK" for each line:

- `AT+UART=57600,0,0`
- `AT+ROLE=1`
- `AT+PSWD="0000"`
- `AT+CMODE=0`
- `AT+BIND=xxxx,xx,xxxxxx` (the Mindwave MAC adress, using this format, you can get that pairing the mindwave to a bluetooth device)
- `AT+IAC=9E8B33`
- `AT+CLASS=0`
- `AT+INQM=1,9,48`

Ensure that the serial monitor is set to NL&CR and a 9600 baud rate to send commands.
Once the AT commands are in the Module, it is not necessary to re-enter AT mode

---

### 2. Conexões dos Fios / Wiring:

### [PT-BR]
- **Módulo Bluetooth HC-05**: RX na porta 10, TX na porta 11 (conectar apenas após a carga do código no Arduino).
- **Ponte H L298N**: 
    - ENA na porta 9, IN1 na porta 8, IN2 na porta 7, IN3 na porta 6, IN4 na porta 5, ENB na porta 4.
    - Motores conectados aos bornes de saída da ponte H.
    - Alimentação dos motores via o suporte de 4 pilhas AA.
    - GND da ponte H conectado ao GND do Arduino.
- **Motores DC**: 
    - Conectar os dois motores nas saídas da ponte H.

### [ENG]
- **Bluetooth Module HC-05**: RX on pin 10, TX on pin 11 (connect only after uploading the code).
- **L298N Motor Driver**: 
    - ENA on pin 9, IN1 on pin 8, IN2 on pin 7, IN3 on pin 6, IN4 on pin 5, ENB on pin 4.
    - Motors connected to the motor driver output.
    - Motors powered by a 4x AA battery pack.
    - GND from the motor driver connected to Arduino GND.
- **DC Motors**: 
    - Connect both motors to the L298N motor driver outputs.

---

### 3. Carregamento do Programa / Uploading the Program:

### [PT-BR]
Para carregar o código no Arduino, você precisará seguir estas etapas. O código abaixo controla os motores do carrinho com base no nível de atenção detectado pelo Mindwave. Certifique-se de que os fios RX e TX do módulo Bluetooth estejam desconectados antes de fazer o upload. Após o upload, reconecte os fios e inicie o monitor serial.
Utilize o código do arquivo "CarrinhoMindwave.ino" no Arduino IDE.

### [ENG]

To upload the code to the Arduino, you will need to follow these steps. The code below controls the car's motors based on the attention level detected by the Mindwave. Ensure that the RX and TX wires from the Bluetooth module are disconnected before uploading. After uploading, reconnect the wires and open the serial monitor.
Use the code from the "CarrinhoMindwave.ino" file in the Arduino IDE.

---

### 4. Conectar o Mindwave / Connect the Mindwave:
### [PT-BR]
Para conectar o Mindwave Mobile 2, ligue-o e aguarde até que ele seja pareado automaticamente com o módulo Bluetooth HC-05. Certifique-se de que o módulo Bluetooth está corretamente configurado e que o Arduino está alimentado. Você pode verificar o monitor serial para confirmar se o status da conexão está correto, e o módulo irá piscar duas vezes a cada alguns segundos, isso afirmará que a conecção está pronta.

### [ENG]
To connect the Mindwave Mobile 2, power it on and wait for it to pair automatically with the HC-05 Bluetooth module. Ensure that the Bluetooth module is correctly configured and that the Arduino is powered. You can check the serial monitor to verify that the connection status is correct, and the module will blink twice every few seconds, this will confirm that the connection is ready.

---

### 5. Funcionamento do Carrinho / Car Movement
### [PT-BR]
O carrinho começará a se mover quando o nível de atenção detectado pelo Mindwave ultrapassar 45. Esse valor pode ser ajustado para testes alterando o parâmetro condicional no código. Se a atenção cair abaixo de 45, o carrinho para.

### [ENG]
The car will start moving when the attention level detected by the Mindwave exceeds 45. This value can be adjusted for testing by changing the conditional parameter in the code. If the attention drops below 45, the car will stop.

