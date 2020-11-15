#include "pe_axis.h"
#include "common_types.h"

//------------------------------------------------------------------------------------------------------------------------
#ifndef PE_JOYSTICK_H
#define PE_JOYSTICK_H
//------------------------------------------------------------------------------------------------------------------------
//Classes:
class c_pe_joystick{
public:
	c_pe_joystick(void);
	c_pe_joystick(axis_group inputs);

	joy_pos get_joystick_position_raw(void);
	void print_joystick_position_raw(void);
	void print_joystick_position_raw(joy_pos);
protected:
private:
	axis_group m_inputs;
	joy_pos m_joystick_position_raw;
}typedef joystick;
//------------------------------------------------------------------------------------------------------------------------
#endif