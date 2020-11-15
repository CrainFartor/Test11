#include "pe_axis.h"
#include <arduino.h>
//------------------------------------------------------------------------------------------------------------------------
c_pe_axis_indexed :: c_pe_axis_indexed(void):
	c_pe_axis(),
	m_axis_index(no_axis){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_axis_indexed :: c_pe_axis_indexed(unsigned int pin_number, axis_index axis_index):
	c_pe_axis(pin_number),
	m_axis_index(axis_index){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_axis :: c_pe_axis(void):
	m_axis_pin(0),
	m_axis_raw_value(0){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_axis :: c_pe_axis(unsigned int pin_number):
	m_axis_pin(pin_number),
	m_axis_raw_value(0){}
//------------------------------------------------------------------------------------------------------------------------
unsigned int c_pe_axis :: get_axis_raw_value(void){
	m_axis_raw_value = acquire_raw_value();
	return m_axis_raw_value;
}
//------------------------------------------------------------------------------------------------------------------------
unsigned int c_pe_axis :: acquire_raw_value(void){
	return analogRead(m_axis_pin);
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_axis :: print_raw_axis_value(void){
	Serial.print("Axis value: ");
	Serial.print(m_axis_raw_value);
}
//------------------------------------------------------------------------------------------------------------------------
bool c_pe_axis :: is_inside_deadzone(void){
	return ((m_axis_raw_value >= AXIS_DEADZONE_LOWER) && (m_axis_raw_value <= AXIS_DEADZONE_UPPER)) ? true : false;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_axis_indexed:: print_raw_axis_value_indexed(void){
	Serial.print("Axis n: ");
	Serial.print(m_axis_index);
	Serial.print(", value: ");
	Serial.print(get_axis_raw_value());
}
