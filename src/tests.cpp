#include "tests.h"
#include <Arduino.h>
//------------------------------------------------------------------------------------------------------------------------
unsigned int test_get_axis_value_single(axis &a){
	unsigned int tmp = a.get_axis_raw_value();
	a.print_raw_axis_value();
	return tmp;
}
//------------------------------------------------------------------------------------------------------------------------
void test_get_axis_value_all_array(axis *pots){
	Serial.println("Testing array aproach");
	unsigned int i=0;
	for(i=0;i<4;i++) test_get_axis_value_single(pots[i]);
	Serial.println("--------------------");
	delay(250);
}
//------------------------------------------------------------------------------------------------------------------------
void test_get_axis_value_all_group(axis_group &g){
	Serial.println("Testing group aproach");
	unsigned int i=0;
	for(i=0;i<4;i++) test_get_axis_value_single(g.group[i]);
	Serial.println("--------------------");
	delay(250);
}
//------------------------------------------------------------------------------------------------------------------------
void test_get_axis_all(void){
	test_get_axis_value_all_array((axis *) potentiometers);
	delay(4000);
	test_get_axis_value_all_group(potentiometers_group);
	delay(4000);	
}
//------------------------------------------------------------------------------------------------------------------------
joy_pos test_get_axis_joy_pos(joystick &j){
	joy_pos jp = j.get_joystick_position_raw();
	j.print_joystick_position_raw();
	return jp;
}
//------------------------------------------------------------------------------------------------------------------------
bool test_pin(unsigned int &pin){
	bool aux;
	Serial.print("Reading pin: ");
	Serial.print(pin);
	Serial.print(", value: ");
	aux = digitalRead(pin);
	print_bool(aux);
	Serial.println();
	return aux;
}
//------------------------------------------------------------------------------------------------------------------------
void test_pin_all(void){
	unsigned int i=10;
	for(i=10;i<=13;i++) test_pin(i);
	Serial.println("-------------------------");
}
//------------------------------------------------------------------------------------------------------------------------
void test_toggle(unsigned int input_pin, unsigned int output_pin){
	if(digitalRead(input_pin) == HIGH) toggle_pin(output_pin);
}
//------------------------------------------------------------------------------------------------------------------------
void print_bool(bool &b){
	(b == true) ? Serial.print("true") : Serial.print("false");
}
//------------------------------------------------------------------------------------------------------------------------
void toggle_pin(unsigned int &pin){
	(digitalRead(pin) == HIGH) ? digitalWrite(pin, LOW) : digitalWrite(pin, HIGH);
}
//------------------------------------------------------------------------------------------------------------------------
void toggle_all_pins(void){
	unsigned int i= 2;
	for(i=2;i<=13;i++) toggle_pin(i);
}
//------------------------------------------------------------------------------------------------------------------------
void test_toggle_all_pins_by_input(void){
	test_toggle(10, 2);
	test_toggle(11, 4);
	test_toggle(12, 6);
	test_toggle(13, 8);
}
//------------------------------------------------------------------------------------------------------------------------
void test_motor_pulse(motor &m, unsigned int pulse_max){
	if(m.get_pulse_count() <= pulse_max){
		m.step_pulse();
	}
	else{
		m.execute_pulse();
		Serial.println("Finished counting pulses");
	}
}
//------------------------------------------------------------------------------------------------------------------------
void test_speed_manager_pulses(void){
	sm.pulse_manager();
}
//------------------------------------------------------------------------------------------------------------------------
void test_speed_manager_configurator(void){
	if(aux >= 24) aux = 0;
	sm.configure_motor_group(mcfgg_array[aux]);
	aux++;
}
//------------------------------------------------------------------------------------------------------------------------
void setup_timer(void){
	TCCR0B = 0x01;
	OCR0A = 0xfe;
	TIMSK0 = 0x02;
	interrupts();
}