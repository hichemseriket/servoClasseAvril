//test d'integration de la classe directement dans le meme fichier sans crée ma bibliotheque servoM a part

#include <Servo.h>

class ServoM : public Servo
{
    int m_pin;
    int m_state;
    int m_angleMin;
    int m_angleMax;
    int m_move;
    Servo hichem;

public:
    construct(int pin, int angleMin, int angleMax)
    {
        Servo hichem;
        m_pin = pin;
        m_angleMin = angleMin;
        m_angleMax = angleMax;
        hichem.attach(pin);
        m_state = 90;
        m_state = hichem.read();
    }
    ServoM(int pin, int angleMin, int angleMax)
    {
        Servo hichem;
        m_pin = pin;
        m_angleMin = angleMin;
        m_angleMax = angleMax;
        m_state = 90;
        hichem.attach(pin);
        // hichem.attach(m_pin);

        m_state = hichem.read();
    }
    void serialEvent()
    {
        int donneesALire = Serial.available();
        if (donneesALire > 0) // si le buffer n'est pas vide
        {
            // Il y a des données, on les lit et on fait du traitement
            Serial.println(donneesALire);
        }

    }
    void getAngleMax(int angle)
    {
        hichem.read();
    }
    void getAngleMin(int angle)
    {
        hichem.read();
    }
    void WRITE_Servo_Angle(int angle)
    {
        hichem.write(angle);
        Serial.println((String)"L'angle lu est qui doit etre ecrit est :" + hichem.read());

    }
    int READ_Servo_Angle() const
    {
        return m_state;
    }
    bool estAllume() const
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
    void afficherEtat()
    {
        // Serial.println((String)"le servo branché est  : "+ nom_objet);
        Serial.println((String)"branché sur pin : " + m_pin);
        Serial.println((String)"l'angle actuel est de  : " + m_state);
        Serial.println((String)"l'angle minimale : " + m_angleMin);
        Serial.println((String)"l'angle maximale : " + m_angleMax);
    }
    void interaction() {
        for (m_state = 10; m_state <= 180; m_state += 1)
            if (Serial.available())
            {
                String stateString = Serial.readString();
                Serial.println(stateString);
                int state = stateString.toInt();

                if (state < 10)

                {
                    Serial.print(">");
                    Serial.println(state);
                    Serial.println("can not execute command, too low number");

                }

                if (state >= 10 && state < 180)
                {
                    Serial.print(">");
                    Serial.println(state);
                    Serial.print("servo tourne vers : ");
                    Serial.print(state);
                    Serial.println(" degrees");
                    hichem.write(state);
                    delay(1000);
                }

            }
    }
};

//ServoM poignet(5, 50, 110);
ServoM pince(9, 10, 180);

void setup()
{

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
    pince.WRITE_Servo_Angle(90);
    delay(1000);
    Serial.println("servo calibré");
    Serial.println("-------------------------");
    Serial.println("écrivez la commande à excuté/donnez l'angle ");
    Serial.println("-------------------------");
    //pince.afficherEtat();
    // pince.serialEvent();
    //pince.getAngleMax(30);
}

void loop() {
// pince.afficherEtat();
    pince.interaction();
}