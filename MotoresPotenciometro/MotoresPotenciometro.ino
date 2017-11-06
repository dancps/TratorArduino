/*
Iniciando os servos de acordo com a ficha 1.

Usando dois servos na haste principal e um na pá:
  Os dois da haste principal irão girar em sentidos
diferentes.
  O da pá gira em sentido diferente apenas para manter a pá 
nivelada
*/

#include <Servo.h>

Servo srvP1;
Servo srvP2;
Servo srvG;

int pot1 = A0, pot2 = A1; //Pino dos potenciometros
int valP1, valP2, valG; //Valor de leitura dos potenciometros
unsigned long time;

//Constantes dos motores
const int angMinSrvP1 = 0;
const int angMaxSrvP1 = 180;
const int angMinSrvP2 = 180;
const int angMaxSrvP2 = 0;
const int angMinSrvG = 180; //Iniciado com valor 180 pois irá girar no sentido contrario do motor da haste1
const int angMaxSrvG = 0;

//Função para PuTTy
void clearSerial(){
	Serial.write(27); // ESC
	Serial.print("[2J"); // clear screen
	Serial.write(27); // ESC
	Serial.print("[H"); // cursor to home
}

void setup() {
	Serial.begin(9600);

	//Attach servos
	srvP1.attach(3,1000,2000);
	srvP2.attach(5,1000,2000);
	srvG.attach(6,1000,2000);

	//Inicia os servos na mesma posição
	srvP1.write(angMinSrvP1);
	srvP2.write(angMinSrvP2);
	srvG.write(angMinSrvG);	



}

void loop() {

	valP1 = analogRead(A0);
	valP1 = map(valP1,0,1023,angMinSrvP1,angMaxSrvP1);
	valP2 = map(valP1,0,1023,angMinSrvP2,angMaxSrvP2);
	valG = analogRead(A1);
	valG = map(valG,0,1023,angMinSrvG,angMaxSrvG);

	//Serial
	time = millis();
	if(time%1000==0){
		clearSerial();
		Serial.println("Motores");
		Serial.print("  Servo 1: ");
		Serial.print(valP1);
		Serial.println("º");
		Serial.print("  Servo 2: ");
		Serial.print(valP2);
		Serial.println("º");
		Serial.print("  Servo 3: ");
		Serial.print(valG);
		Serial.println("º");
	}

	//Servos
	srvP1.write(valP1);
	srvP2.write(valP2);
	srvG.write(valG);
}
