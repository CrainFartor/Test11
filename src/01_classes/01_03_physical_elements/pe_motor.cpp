#include "pe_motor.h"
#include <Arduino.h>
//------------------------------------------------------------------------------------------------------------------------
c_pe_motor :: c_pe_motor(void):
	m_dir(false),
	m_dir_pin(0),
	m_pulse_pin(0),
	m_is_active(false),
	m_pulse_count_treshold(0),
	m_pulse_count(PULSE_WIDTH_MAX){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_motor :: c_pe_motor(unsigned char dir_pin, unsigned char pulse_pin):
	m_dir(false),
	m_is_active(false),
	m_pulse_count_treshold(0),
	m_pulse_count(PULSE_WIDTH_MAX),
	m_dir_pin(dir_pin),
	m_pulse_pin(pulse_pin){}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: execute_pulse(void){
	(digitalRead(m_pulse_pin) == HIGH) ? digitalWrite(m_pulse_pin, LOW) : digitalWrite(m_pulse_pin, HIGH);
	
	m_pulse_count=0;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: step_pulse(void){
	m_pulse_count++;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: set_dir(bool dir){
	m_dir = dir;
	digitalWrite(m_dir_pin, m_dir);
}
//------------------------------------------------------------------------------------------------------------------------
bool c_pe_motor :: is_active(void){
	return m_is_active;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: set_to_active(void){
	m_is_active = true;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: set_to_inactive(void){
	m_is_active = false;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: reset_pulse_count(void){
	m_pulse_count = 0;
}
//------------------------------------------------------------------------------------------------------------------------
unsigned int c_pe_motor :: get_pulse_count(void){
	return m_pulse_count;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_motor :: set_pulse_treshold(unsigned int treshold){
	m_pulse_count_treshold = treshold;
}
//------------------------------------------------------------------------------------------------------------------------
unsigned int c_pe_motor :: get_pulse_treshold(void){
	return m_pulse_count_treshold;
}
//------------------------------------------------------------------------------------------------------------------------
bool c_pe_motor :: is_finished_stepping(void){
	if(m_pulse_count <= m_pulse_count_treshold) return false;
	else return true;
}
//------------------------------------------------------------------------------------------------------------------------
c_pe_motor_indexed :: c_pe_motor_indexed(void):
	c_pe_motor(), m_associated_axis(no_axis), m_motor_link(no_motor){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_motor_indexed :: c_pe_motor_indexed(unsigned char dir_pin, unsigned char pulse_pin, axis_index associated_axis, motor_index linked_motor):
	c_pe_motor(dir_pin, pulse_pin), m_associated_axis(associated_axis), m_motor_link(linked_motor){}
//------------------------------------------------------------------------------------------------------------------------
motor_index c_pe_motor_indexed :: get_motor_index(void){
	return m_motor_link;
}
//------------------------------------------------------------------------------------------------------------------------
axis_index c_pe_motor_indexed :: get_axis_index(void){
	return m_associated_axis;
}
//------------------------------------------------------------------------------------------------------------------------
