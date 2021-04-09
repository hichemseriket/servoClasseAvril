#include "ServoM.h"

// dois je le declaré ici en tant que Servo ?
//Servo ServoM;
// je declare ici lobjet pince en tant que servoM et donc en tant que servo , pour utilisé la creation a laide du constructdans le setup au lieu du constructeur a 3 param en init
ServoM pince;
// ci bas la creation de pince avec le constructeur a 3 param, avant de le remplacer par le contrcut
//ServoM pince (5,45,110);

// je mets cette variable mais a terme faut reflichir a comment plutt mettre m_state qui evolue et qui stock a tt moment l'etat actuel
int pos = 0;

void setup() {
  // ici bas jai creéé mon objet a laide de construct en remplacement du constructeur ServoM
  pince.construct(5, 45, 110);
  //ServoM pince (5,45,110);
  // m_pin = pince.construct.pin;
  //Serial.println((String)"le pin depuis le main est :" + m_pin);
  
  Serial.begin(9600);

  while (!Serial);
  Serial.println("-------------------------");
  Serial.println("HICHEM is loading....");
  delay(1000);
  Serial.println("HICHEM loaded succesfully (ca fait style hein ?)");
  Serial.println("-------------------------");
  Serial.println("calibration du servo...(bababa la nasa tremble)");

   pince.WRITE_Servo_Angle(0);
    delay(1000);
    pince.WRITE_Servo_Angle(180);
    delay(1000);
    pince.WRITE_Servo_Angle(110);
  delay(1000);
  Serial.println("servo calibré");
  Serial.println("-------------------------");
  Serial.println("écrivez la commande à excuté/donnez l'angle ");
  Serial.println("-------------------------");
  pince.afficherEtat();

}

void loop() {
 /* for (pos = 50; pos <= 100; pos += 1) {
    // in steps of 1 degree
    pince.WRITE_Servo_Angle(pos);
    // pince.write(pos);
    delay(15);
  }
  for (pos = 100; pos >= 50; pos -= 1) { 
    pince.write(pos);              
    delay(15);                 
  } */
  /*// lecture du nombre de caractères disponibles dans le buffer
    int donneesALire = Serial.available();
    if(donneesALire > 0) // si le buffer n'est pas vide
    {
      // Il y a des données, on les lit et on fait du traitement
    }
    // on a fini de traiter la réception ou il n'y a rien à lire    pince.WRITE_Servo_Angle(20);
  */
  /* char choseLue = Serial.read();

    if(choseLue == -1) // si le buffer est vide
    {
       // Rien à lire, rien lu
    }
    else // le buffer n'est pas vide
    {
       // On a lu un caractère
    }
    delay(300);*/

  // pince.WRITE_Servo_Angle(50);

  //    pince.serialEvent();

    for (pos = 50; pos <= 100; pos += 1)
      if (Serial.available())


      {
        String stateString = Serial.readString();
        Serial.println(stateString);
        int state = stateString.toInt();

        if (state < 50)

        {
          Serial.print(">");
          Serial.println(state);
          Serial.println("can not execute command, too low number");

        }

        if (state >= 50 && state < 100)
        {
          Serial.print(">");
          Serial.println(state);
          Serial.print("servo tourne vers : ");
          Serial.print(state);
          Serial.println(" degrees");
          pince.WRITE_Servo_Angle(state);
          delay(1000);

        }

      }
  //pince.afficherEtat();


}
