#include <Arduino.h>
#include "pe_joystick.h"
//------------------------------------------------------------------------------------------------------------------------
c_pe_joystick :: c_pe_joystick(void):
	m_joystick_position_raw( JOY_POS_NULL ),
	m_inputs( {{axis(),axis(),axis(),axis()}, TOTAL_AXIS} ){}
//------------------------------------------------------------------------------------------------------------------------
c_pe_joystick :: c_pe_joystick(axis_group inputs):
	m_joystick_position_raw( JOY_POS_NULL ),
	m_inputs(inputs){}
//------------------------------------------------------------------------------------------------------------------------
joy_pos c_pe_joystick :: get_joystick_position_raw(void){
	unsigned int i=0;

	for(i=0;i<m_inputs.amount;i++)
		m_joystick_position_raw.axis_val[i] = m_inputs.group[i].get_axis_raw_value();

	return m_joystick_position_raw;
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_joystick :: print_joystick_position_raw(void){
	unsigned int i=0;
	Serial.print("Joystick value:: ");
	for(i=0;i<m_inputs.amount;i++){
		Serial.print('\t');
		m_inputs.group[i].print_raw_axis_value_indexed();
		Serial.print('\t');
	}
	Serial.print('\t');
	Serial.print("axis amount:");
	Serial.print(m_inputs.amount);
	Serial.println();
}
//------------------------------------------------------------------------------------------------------------------------
void c_pe_joystick :: print_joystick_position_raw(joy_pos jp){
	unsigned int i=0;
	Serial.print("Joystick value:: ");
	for(i=0;i<jp.axis_amount;i++){
		Serial.print("axis value:");
		Serial.print('\t');
		Serial.print(jp.axis_val[i]);
		Serial.print('\t');
	}
	Serial.print('\t');
	Serial.print("axis amount:");
	Serial.print(jp.axis_amount);
	Serial.println();
}
//------------------------------------------------------------------------------------------------------------------------