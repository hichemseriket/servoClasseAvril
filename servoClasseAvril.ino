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

void setup() {
    Serial.begin(9600);
   // MyObject.attach(7);
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
    char choseLue = Serial.read();

    if(choseLue == -1) // si le buffer est vide
    {
        // Rien à lire, rien lu
    }
    else // le buffer n'est pas vide
    {
        // On a lu un caractère
    }
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
    pince.serialEvent();
    poignet.afficherEtat();
}
