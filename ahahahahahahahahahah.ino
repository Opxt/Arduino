#include <AFMotor.h>

//#motorB = motor da esquerda
//#motorA = motor da direita

AF_DCMotor motorA(1);
AF_DCMotor motorB(2);

int sensorLinhaDir = A0;
int sensorLinhaEsq = A5;

int valorLinhaEsq, valorLinhaDir;



void setup(){
  Serial.begin(9600);
  pinMode(sensorLinhaDir, INPUT);
  pinMode(sensorLinhaEsq, INPUT);
  
  motorA.setSpeed(90);
  motorB.setSpeed(90);
  delay(5000);
}

void loop(){  
  valorLinhaEsq = digitalRead(sensorLinhaEsq);
  valorLinhaDir = digitalRead(sensorLinhaDir);

  Serial.println("Esquerda: "+ String(valorLinhaEsq) + "||" + " Direita: " + String(valorLinhaDir));

  digitalWrite(sensorLinhaDir, HIGH);
  digitalWrite(sensorLinhaEsq, HIGH);

  if ((valorLinhaEsq == 0) && (valorLinhaDir == 0)) {
    frente();
  }
  else if ((valorLinhaEsq == 1) && (valorLinhaDir == 0)) {  
    direita();
  }
  else if ((valorLinhaEsq == 0) && (valorLinhaDir == 1)) {
    esquerda();
  }
  else if ((valorLinhaEsq == 1) && (valorLinhaDir == 1)) {
    parar();
  }
}

void frente() {
  motorB.setSpeed(130);
  motorA.setSpeed(130);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}

void parar() {
  motorB.setSpeed(0);
  motorA.setSpeed(0);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}

void direita() {
  motorA.setSpeed(50);
  motorB.setSpeed(170);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}

void esquerda() {
  motorA.setSpeed(120);
  motorB.setSpeed(50);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}
