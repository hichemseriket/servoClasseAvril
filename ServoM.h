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
    int m_pin{};
    int m_state{};
    int m_angleMin{};
    int m_angleMax{};
    int m_move{};
    Servo hichem; 
    
  public:

    ServoM();
    ServoM(int pin);
    ServoM(int pin, int angleMin, int angleMax);
    void serialEvent();
    void getAngleMax(int angle);
    void getAngleMin(int angle);
    void WRITE_Servo_Angle(int angle);
    int READ_Servo_Angle() const;
    bool estAllume() const;
    void afficherEtat() const;
};
//ServoM oumayma(m_pin, m_state, m_angleMin, m_angleMax, m_move, hichem);
//ServoM MyObject(m_pin);
//ServoM MyObject(m_pin);


#endif //DRONE_SERVOM_H
