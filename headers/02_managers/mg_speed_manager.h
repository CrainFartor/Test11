#include "common_types.h"
#include "pe_joystick.h"
#include "pe_motor.h"
//------------------------------------------------------------------------------------------------------------------------
#ifndef MG_SPEED_MANAGER_H
#define MG_SPEED_MANAGER_H
//------------------------------------------------------------------------------------------------------------------------
//Classes:
class c_mg_speed_manager{
public:
	c_mg_speed_manager(void);
	c_mg_speed_manager(motor_group motors, joystick joy);

	void pulse_manager(void);
	void configure_motor_single(motor &m, const motor_config &cfg);
	void configure_motor_group(motor_config_group const &cfg);

	motor_config_group set_motor_config_by_joystick(void);
protected:
private:

	unsigned int m_max_pulse_steps;

	joystick m_joystick;
	motor_group m_motors;
}typedef speed_manager;
//------------------------------------------------------------------------------------------------------------------------
#endif