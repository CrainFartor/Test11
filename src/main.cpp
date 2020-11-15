#include <Arduino.h>
#include "pe_joystick.h"
#include "tests.h"
#include "globals.h"
#include "common_types.h"
#include "pe_motor.h"

void setup() {
	Serial.begin(9600);

	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);

	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, LOW);
	digitalWrite(6, LOW);
	digitalWrite(7, LOW);
	digitalWrite(8, LOW);
	digitalWrite(9, LOW);

	setup_timer();
}

void loop() {
	delay(10000);
	//test_get_axis_all();
	//test_pin_all();
	//test_get_axis_joy_pos(joy);
	//toggle_all_pins();
	//test_toggle_all_pins_by_input();
	//test_motor_pulse(m1, 3);
	//test_speed_manager_pulses();
	test_speed_manager_configurator();
}

ISR(TIMER0_COMPA_vect){
	test_speed_manager_pulses();
}