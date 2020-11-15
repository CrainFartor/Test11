#include <Arduino.h>
#include "pe_axis.h"
#include "globals.h"
#include "common_types.h"
#include "pe_motor.h"

#ifndef TESTS_H
#define TESTS_H

unsigned int test_get_axis_value_single(axis &a);
void test_get_axis_value_all_array(axis *pots);
void test_get_axis_value_all_group(axis_group &g);
void test_get_axis_all(void);

joy_pos test_get_axis_joy_pos(joystick &j);

bool test_pin(unsigned int &pin);
void test_pin_all(void);

void test_toggle(unsigned int input_pin, unsigned int output_pin);
void test_toggle_all_pins_by_input(void);

void print_bool(bool &b);
void toggle_pin(unsigned int &pin);
void toggle_all_pins(void);

void test_motor_pulse(motor &m, unsigned int pulse_max);
void test_speed_manager_pulses(void);
void test_speed_manager_configurator(void);

void setup_timer(void);
#endif