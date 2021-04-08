//
// Created by serik on 24/02/2021.
//

#include "ServoM.h"

// je doit a chaque fois instancier l'objet dans chaque fonction comment pallier acela stp ?

ServoM::ServoM(int pin, int angleMin, int angleMax) : m_pin(pin), m_state(90), m_angleMin(angleMin), m_angleMax(angleMax), m_move(0)
{
  Servo hichem;
  m_pin = pin;
  m_angleMin = angleMin;
  m_angleMax = angleMax;
  hichem.attach(pin);
}
ServoM::ServoM(int pin) : m_pin(pin), m_state(90), m_angleMin(20), m_angleMax(160), m_move(0)
{
  Servo hichem;
  m_pin = pin;
  hichem.attach(pin);
}


void ServoM::getAngleMax(int angle)
{
  hichem.read();
}

void ServoM::getAngleMin(int angle)
{
  hichem.read( );
  //Serial.println("ceci est l'angle lu :  " + angle);

}

void ServoM::WRITE_Servo_Angle(int angle)
{
  hichem.write(angle);
  Serial.println("hichem"+ angle);
}

int ServoM::READ_Servo_Angle() const
{
  return m_state;
}

bool ServoM::estAllume() const
{
  if (20 < m_state < 160)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void ServoM::afficherEtat() const
{
  Serial.println(pin);
  Serial.println("  l'etat actuel est "[ m_state]);
  Serial.println("   branché sur pin : "[ m_pin]);
}

ServoM::ServoM() = default;
