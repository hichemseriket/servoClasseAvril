//#include <Servo.h>
#include "ServoM.h"

// dois je le declaré ici en tant que Servo ?
//Servo ServoM;
//ServoM pince(5, 0, 180);
ServoM pince(5);
ServoM poignet(6, 20, 160);
ServoM mains(7, 20, 160);
ServoM avantBras(8, 20, 160);
ServoM bras(9, 20, 160);
ServoM base(10, 20, 160);

void setup() {
  Serial.begin(9600);
}

void loop() {

  pince.WRITE_Servo_Angle(20);
  delay(300);
  // pince.WRITE_Servo_Angle(50);
  /*pince.write(120);
  poignet.READ_Servo_Angle();
  pince.afficherEtat();
  poignet.afficherEtat();
  mains.afficherEtat();
  avantBras.afficherEtat();
  bras.afficherEtat();*/
  pince.afficherEtat();
}
