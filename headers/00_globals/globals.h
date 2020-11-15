#include <Arduino.h>
#include "pe_joystick.h"
#include "common_types.h"
#include "mg_speed_manager.h"
//------------------------------------------------------------------------------------------------------------------------
#ifndef GLOBALS_H
#define GLOBALS_H
//------------------------------------------------------------------------------------------------------------------------
extern unsigned int aux;
//------------------------------------------------------------------------------------------------------------------------
extern axis potentiometers[4];
extern axis_group potentiometers_group;
extern joystick joy;
extern motor_group mg;
extern speed_manager sm;
//------------------------------------------------------------------------------------------------------------------------
extern motor_config mcfg1;
//------------------------------------------------------------------------------------------------------------------------
extern motor_config_indexed mcfgi1;
//------------------------------------------------------------------------------------------------------------------------
extern const motor_config_group mcfgg1;
extern const motor_config_group mcfgg2;
extern const motor_config_group mcfgg3;

extern const motor_config_group mcfgg4;
extern const motor_config_group mcfgg5;
extern const motor_config_group mcfgg6;

extern const motor_config_group mcfgg_array[24];
//------------------------------------------------------------------------------------------------------------------------
#endif