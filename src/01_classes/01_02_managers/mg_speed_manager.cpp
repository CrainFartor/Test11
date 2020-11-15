#include "mg_speed_manager.h"
#include <Arduino.h>
//------------------------------------------------------------------------------------------------------------------------
c_mg_speed_manager :: c_mg_speed_manager(void):
	m_joystick(),
	m_motors( {{motor(), motor(), motor()}, TOTAL_MOTORS} ),
	m_max_pulse_steps(PULSE_WIDTH_MAX){}
//------------------------------------------------------------------------------------------------------------------------
c_mg_speed_manager :: c_mg_speed_manager(motor_group motors, joystick joy):
	m_joystick(joy),
	m_motors(motors),
	m_max_pulse_steps(PULSE_WIDTH_MAX){}
//------------------------------------------------------------------------------------------------------------------------
void c_mg_speed_manager :: pulse_manager(void){
	unsigned int i=0;
	for(i=0;i<m_motors.amount;i++){
		if(m_motors.group[i].is_finished_stepping()) m_motors.group[i].execute_pulse();
		else m_motors.group[i].step_pulse();
	}
}
//------------------------------------------------------------------------------------------------------------------------
void c_mg_speed_manager :: configure_motor_single(motor &m, const motor_config &cfg){
	m.reset_pulse_count();
	m.set_pulse_treshold( (cfg.pulse_width > m_max_pulse_steps) ? m_max_pulse_steps : cfg.pulse_width );
	m.set_dir(cfg.dir);
}
//------------------------------------------------------------------------------------------------------------------------
void c_mg_speed_manager :: configure_motor_group(motor_config_group const &group_cfg){
	unsigned int i=0, j=0;
	for(i=0;i<m_motors.amount;i++){
		for(j=0;j<group_cfg.amount;j++){
			if( m_motors.group[j].get_motor_index() == group_cfg.config_array[i].idx ){
				configure_motor_single(m_motors.group[j], group_cfg.config_array[i].mot_cfg);
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------
motor_config_group set_motor_config_by_joystick(void);
//