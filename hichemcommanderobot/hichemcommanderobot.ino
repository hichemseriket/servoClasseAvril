
#include <Servo.h>

Servo myservo;


int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  while (!Serial);
  Serial.println("-------------------------");
  Serial.println("HICHEM is loading....");
  delay(1000);
  Serial.println("HICHEM loaded succesfully (ca fait style hein ?)");
  Serial.println("-------------------------");
  Serial.println("calibration du servo...(bababa la nasa tremble)");
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  Serial.println("servo calibré");
  Serial.println("-------------------------");
  Serial.println("écrivez la commande à excuté/donnez l'angle ");
  Serial.println("-------------------------");
}

void loop() {
  /*
    for (pos = 0; pos <= 180; pos += 1) {
     // in steps of 1 degree
     myservo.write(pos);
     delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
     myservo.write(pos);
     delay(15);
    }*/
  for (pos = 0; pos <= 180; pos += 1)
    if (Serial.available())
    {
     /* String donnee = Serial.readString();
      Serial.println(donnee);*/

      String stateString = Serial.readString();
      Serial.println(stateString);
      int state = stateString.toInt();
      if (state < 10)
      {
        Serial.print(">");
        Serial.println(state);
        Serial.println("can not execute command, too low number");
      }
      if (state >= 0 && state < 180)
      {
        Serial.print(">");
        Serial.println(state);
        Serial.print("servo tourne vers : ");
        Serial.print(state);
        Serial.println(" degrees");
        myservo.write(state);
        delay(1000);
      }
     /* if (donnee)
      {
        Serial.print((String)"etat actuel : " + state);
      }*/

    }
}
