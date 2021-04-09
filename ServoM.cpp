//
// Created by serik on 24/02/2021.
//
#include <Servo.h>
#include "ServoM.h"

// je doit a chaque fois instancier l'objet dans chaque fonction comment pallier acela stp ?

/* le constructeur que j'ai commenté pour utlisé uniquement le construct plus bas*/
ServoM::ServoM(int pin, int angleMin, int angleMax)
{
  Servo hichem;
  m_pin = pin;
  m_angleMin = angleMin;
  m_angleMax = angleMax;
  m_state = 55;
  hichem.attach(pin);
  hichem.attach(m_pin);

  m_state = hichem.read();
}

void ServoM::construct(int pin, int angleMin, int angleMax)
{
  Servo hichem;
  m_pin = pin;
  m_angleMin = angleMin;
  m_angleMax = angleMax;
  hichem.attach(pin);
  m_state = 55;
  m_state = hichem.read();
}


void ServoM::serialEvent() // déclaration de la fonction d'interruption sur la voie série
{
  int donneesALire = Serial.available();
  if (donneesALire > 0) // si le buffer n'est pas vide
  {
    // Il y a des données, on les lit et on fait du traitement
    Serial.println(donneesALire);
  }

}
void ServoM::getAngleMax(int angle)
{
  hichem.read();
}

void ServoM::getAngleMin(int angle)
{
  hichem.read();
  //Serial.println("ceci est l'angle lu :  " + angle);

}

void ServoM::WRITE_Servo_Angle(int angle)
{
  hichem.write(angle);
  Serial.println((String)"L'angle lu est qui doit etre ecrit est :" + hichem.read());

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
  // Serial.println((String)"le servo branché est  : "+ nom_objet);
  Serial.println((String)"branché sur pin : " + m_pin);
  Serial.println((String)"l'angle actuel est de  : " + m_state);
  Serial.println((String)"l'angle minimale : " + m_angleMin);
  Serial.println((String)"l'angle maximale : " + m_angleMax);
}

ServoM::ServoM() = default;
