//#include <Servo.h>
#include "ServoM.h"

// dois je le declaré ici en tant que Servo ?
//Servo ServoM;
int potpin = 0;
int val;
ServoM pince(5, 45, 110);
ServoM poignet(6, 20, 160);
ServoM mains(7, 20, 160);
ServoM avantBras(8, 20, 160);
ServoM bras(9, 20, 160);
ServoM base(10, 20, 160);

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 40, 160);
  pince.write(val);
  pince.WRITE_Servo_Angle(val);

  Serial.println(val);
  delay(15);
  pince.WRITE_Servo_Angle(110);
  pince.WRITE_Servo_Angle(50);
  pince.write(80);
  poignet.READ_Servo_Angle();
  pince.afficherEtat();
  poignet.afficherEtat();
  mains.afficherEtat();
  avantBras.afficherEtat();
  bras.afficherEtat();
  base.afficherEtat();
}
