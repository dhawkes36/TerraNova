#pragma once

#include <Arduino.h>
#include "Encoder.hpp"

class DriveMotor : public PinInterrupt {
  public:
    DriveMotor(uint8_t INA, uint8_t INB, uint8_t PWM, uint8_t EN, uint8_t CS, uint8_t ENCA, uint8_t ENCB, uint16_t ticks_per_rot);

    void init();
    void setSpeed(uint8_t speed);
    void updateSpeed(float supply_voltage);
    void setBrake(uint8_t brake);
    float readCurrent();
    float readRotationalSpeed();
    bool readFaultStatus();

    void pinChanged(uint8_t pin);

  private:
    Encoder* encoder;
    uint8_t _INA;
    uint8_t _INB;
    uint8_t _PWM;
    uint8_t _EN;
    uint8_t _CS;
    uint8_t _desired_speed;
    uint8_t _current_speed;
    volatile bool fault;
    volatile bool checked;
};
