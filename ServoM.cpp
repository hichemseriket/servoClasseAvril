//
// Created by serik on 24/02/2021.
//

#include "ServoM.h"

// je doit a chaque fois instancier l'objet dans chaque fonction comment pallier acela stp ?

ServoM::ServoM(int pin, int angleMin, int angleMax) : m_pin(pin), m_state(90), m_angleMin(angleMin), m_angleMax(angleMax), m_move(0), m_potpin(0), m_val(50)
{
  //test led si elle salume 
  pinMode(pin, OUTPUT);
  m_pin = pin;
  m_angleMin = angleMin;
  m_angleMax = angleMax;
}

void ServoM::analog( int m_potpin){
  m_val = analogRead(m_potpin);
  m_val = map(m_val, 0, 1023, 40, 160);
//  ServoM.WRITE_Servo_Angle(m_val);
//  Servo.write(m_val);
//  Serial.println(m_val);
//  delay(15);
}
void ServoM::getAngleMax(int angle)
{
  Servo ServoM;
  ServoM.read();
}

void ServoM::getAngleMin(int angle)
{
  Servo ServoM;
  ServoM.read();
  //  read(_angleMin);
  //  return angle;
}

void ServoM::WRITE_Servo_Angle(int angle)
{
  Servo ServoM;
  ServoM.write(angle);
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
}
