//Bibliotecas externas
#include <Wire.h>       //Auxiliar dos sensores
#include <VL53L0X.h>    //sensores de distância v1.3.1

// TODO: Defenir melhor SCL e SCA
//SCL, SDA FOR DISTANCE SENSORS
#define SCL_SDIST 22
#define SDA_SDIST 21
#define SDIST_L 23
#define SDIST_C 19
#define SDIST_R 18
#define SDIST_4 5
#define SDIST_5 17
#define SDIST_6 4
#define SDIST_7 16

//Cria os objetos para cada sensor
VL53L0X sensorL;  //Sensor da esquerda
VL53L0X sensorC;  //Sensor da frente
VL53L0X sensorR;  //Sensor da direita
VL53L0X sensor4;  //Sensor da direita
VL53L0X sensor5;  //Sensor da direita
VL53L0X sensor6;  //Sensor da direita
VL53L0X sensor7;  //Sensor da direita

//Variáveis que vão receber os valores lidos dos pinos dos sensores
int distL;  //Valor lido pelo sensor da esquerda
int distC;  //Valor lido pelo sensor da frente
int distR;  //Valor lido pelo sensor da direita
int dist4;  //Valor lido pelo sensor da direita
int dist5;  //Valor lido pelo sensor da direita
int dist6;  //Valor lido pelo sensor da direita
int dist7;  //Valor lido pelo sensor da direita

void setup(){
  Serial.begin(115200);
  sensorsInit();
}

void loop() {
  distanceRead();
  printDistances();

}

void sensorsInit() {

    //Iniciando o endereçamento dos sensores
    Wire.begin();

    pinMode(SDIST_L, OUTPUT);
    pinMode(SDIST_C, OUTPUT);
    pinMode(SDIST_R, OUTPUT);
    pinMode(SDIST_4, OUTPUT);
    pinMode(SDIST_5, OUTPUT);
    pinMode(SDIST_6, OUTPUT);
    pinMode(SDIST_7, OUTPUT);

    digitalWrite(SDIST_L, LOW);
    digitalWrite(SDIST_C, LOW);
    digitalWrite(SDIST_R, LOW);
    digitalWrite(SDIST_4, LOW);
    digitalWrite(SDIST_5, LOW);
    digitalWrite(SDIST_6, LOW);
    digitalWrite(SDIST_7, LOW);

    pinMode(SDIST_L, INPUT);
    sensorL.init(true);
    sensorL.setAddress((uint8_t)0x21); //endereço do sensor da esquerda

    pinMode(SDIST_C, INPUT);
    sensorC.init(true);
    sensorC.setAddress((uint8_t)0x22); //endereço do sensor da frente

    pinMode(SDIST_R, INPUT);
    sensorR.init(true);
    sensorR.setAddress((uint8_t)0x23); //endereço do sensor da direita

    pinMode(SDIST_4, INPUT);
    sensor4.init(true);
    sensor4.setAddress((uint8_t)0x24); //endereço do sensor da direita

    pinMode(SDIST_5, INPUT);
    sensor5.init(true);
    sensor5.setAddress((uint8_t)0x25); //endereço do sensor da direita

    pinMode(SDIST_6, INPUT);
    sensor6.init(true);
    sensor6.setAddress((uint8_t)0x26); //endereço do sensor da direita

    pinMode(SDIST_7, INPUT);
    sensor7.init(true);
    sensor7.setAddress((uint8_t)0x27); //endereço do sensor da direita

    sensorL.setTimeout(20);
    sensorC.setTimeout(20);
    sensorR.setTimeout(20);
    sensor4.setTimeout(20);
    sensor5.setTimeout(20);
    sensor6.setTimeout(20);
    sensor7.setTimeout(20);
}

void distanceRead() {
    //Armazena os valores lidos nas respectivas variáveis
    distL = sensorL.readRangeSingleMillimeters();
    distC = sensorC.readRangeSingleMillimeters();
    distR = sensorR.readRangeSingleMillimeters();
    dist4 = sensor4.readRangeSingleMillimeters();
    dist5 = sensor5.readRangeSingleMillimeters();
    dist6 = sensor6.readRangeSingleMillimeters();
    dist7 = sensor7.readRangeSingleMillimeters();

//    if(distL > 600) distL = 600;
//    if(distC > 600) distC = 600;
//    if(distR > 600) distR = 600;
}


void printDistances() {
  // Mostra o valor de cada sensor na tela e a decisão escolhida
  Serial.print("L: ");
  Serial.print(distL);
  Serial.print("\t");
  Serial.print("C: ");
  Serial.print(distC);
  Serial.print("\t");
  Serial.print("R: ");
  Serial.print(distR);
  Serial.print("\t");
  Serial.print("4: ");
  Serial.print(dist4);
  Serial.print("\t");
  Serial.print("5: ");
  Serial.print(dist5);
  Serial.print("\t");
  Serial.print("6: ");
  Serial.print(dist6);
  Serial.print("\t");
  Serial.print("7: ");
  Serial.print(dist7);
  Serial.println("\t\t");
}