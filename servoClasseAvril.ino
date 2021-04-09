#include "ServoM.h"

// dois je le declaré ici en tant que Servo ?
//Servo ServoM;
ServoM pince(5, 0, 180);
// j'ai ici rajouté un constructeur qui prends un seul argume,nt le pin our comprendre le probleme de la valeur 90 qui s'affichait avant et que je pensais du au min /max
//ServoM pince(5);
ServoM poignet(6, 20, 160);
ServoM mains(7, 20, 160);
ServoM avantBras(8, 20, 160);
ServoM bras(9, 20, 160);
ServoM base(10, 20, 160);
// je mets cette variable mais a terme faut reflichir a comment plutt mettre m_state qui evolue et qui stock a tt moment l'etat actuel
int pos = 0;

void setup() {
    pince.afficherEtat();
    poignet.afficherEtat();
    Serial.begin(9600);
   // MyObject.attach(7);
    while (!Serial);
    Serial.println("-------------------------");
    Serial.println("HICHEM is loading....");
    delay(1000);
    Serial.println("HICHEM loaded succesfully (ca fait style hein ?)");
    Serial.println("-------------------------");
    Serial.println("calibration du servo...(bababa la nasa tremble)");
    for(pos = 0; pos <= 180; pos += 1)
        pince.write(0);
    delay(1000);
    pince.write(180);
    delay(1000);
    pince.write(90);
    delay(1000);
    Serial.println("servo calibré");
    Serial.println("-------------------------");
    Serial.println("écrivez la commande à excuté/donnez l'angle ");
    Serial.println("-------------------------");

}

void loop() {
    /*// lecture du nombre de caractères disponibles dans le buffer
    int donneesALire = Serial.available();
    if(donneesALire > 0) // si le buffer n'est pas vide
    {
        // Il y a des données, on les lit et on fait du traitement
    }
    // on a fini de traiter la réception ou il n'y a rien à lire    pince.WRITE_Servo_Angle(20);
     */
    // on lit le premier caractère non traité du buffer
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
    /*pince.write(120);
    poignet.READ_Servo_Angle();
    pince.afficherEtat();
    poignet.afficherEtat();
    mains.afficherEtat();
    avantBras.afficherEtat();
    bras.afficherEtat();*/
//    pince.serialEvent();

    for(pos = 0; pos <= 180; pos += 1)
        if (Serial.available())


        {
            int state = Serial.parseInt();

            if (state < 10)

            {
                Serial.print(">");
                Serial.println(state);
                Serial.println("can not execute command, too low number");

            }

            if (state >= 10 && state < 170)
            {
                Serial.print(">");
                Serial.println(state);
                Serial.print("servo tourne vers : ");
                Serial.print(state);
                Serial.println(" degrees");
                pince.write(state);

            }

        }

}
