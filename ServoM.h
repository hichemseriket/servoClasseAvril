//
// Created by serik on 24/02/2021.
//

#ifndef DRONE_SERVOM_H
#define DRONE_SERVOM_H
#include <Servo.h>
#include "arduino.h"
// dois je le declaré ici en tant que Servo ?
//Servo ServoM;

// j'ai fait un heritage en cpp de la classe servo pour eviter les probleme de compil est ce une bonne solution ?
class ServoM : public Servo
{

  private:
    int m_pin;
    int m_state;
    int m_angleMin;
    int m_angleMax;
    int m_move;
    int m_potpin = 0;  // analog pin used to connect the potentiometer
    int m_val;    // variable to read the value from the analog pin

  public:

    ServoM();
    ServoM(int pin, int angleMin, int angleMax);
    //        {
    //            this.servoH = new ServoH()
    //                    this.servoh.attach(pin)
    //        };
    void analog(int potpin);
    static void getAngleMax(int angle);
    static void getAngleMin(int angle);
    static void WRITE_Servo_Angle(int angle);
    int READ_Servo_Angle() const;
    bool estAllume() const;
    void afficherEtat() const;
};

#endif //DRONE_SERVOM_H
