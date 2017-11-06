/*
Iniciando os servos de acordo com a ficha 1.
*/

#include <Servo.h>

Servo srvP1;
Servo srvP2;
Servo srvG;

int potpin = A0;
int val;

void setup() {
	Serial.begin(9600);

	//Attach servos
	srvP1.attach(3,1000,2000);
	srvP2.attach(5,1000,2000);
	srvG.attach(6,1000,2000);

	//Inicia os servos na mesma posição
	srvP1.write(0);
	srvP2.write(180);
	srvG.write(180);	//Iniciado com valor 180 pois irá girar no sentido contrario do motor da haste1


}

void loop() {

	//Serial
	Serial.write(27);       // ESC command
	Serial.print("[2J");    // clear screen command
	Serial.write(27);
	Serial.print("[H");     // cursor to home command
	Serial.print(analogRead(A0));
}
