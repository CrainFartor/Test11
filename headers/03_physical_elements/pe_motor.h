#include "common_types.h"
//------------------------------------------------------------------------------------------------------------------------
#ifndef PE_MOTOR_H
#define PE_MOTOR_H
//------------------------------------------------------------------------------------------------------------------------
//Classes:
class c_pe_motor{
public:
	c_pe_motor(void);
	c_pe_motor(unsigned char dir_pin, unsigned char pulse_pin);

	void execute_pulse(void);

	void set_dir(bool dir);
	
	bool is_active(void);
	void set_to_active(void);
	void set_to_inactive(void);

	void step_pulse(void);
	void reset_pulse_count(void);

	void set_pulse_treshold(unsigned int treshold);
	unsigned int get_pulse_treshold(void);

	unsigned int get_pulse_count(void);
	bool is_finished_stepping(void);
protected:
private:
	bool m_dir;
	bool m_is_active;
	unsigned int m_pulse_count;
	unsigned int m_pulse_count_treshold;

	unsigned char m_pulse_pin;
	unsigned char m_dir_pin;
}typedef motor_g;
//------------------------------------------------------------------------------------------------------------------------
class c_pe_motor_indexed : public c_pe_motor{
public:
	c_pe_motor_indexed(void);
	c_pe_motor_indexed(unsigned char dir_pin, unsigned char pulse_pin, axis_index associated_axis, motor_index linked_motor);

	motor_index get_motor_index(void);
	axis_index get_axis_index(void);
protected:
private:
	axis_index m_associated_axis;
	motor_index m_motor_link;
}typedef motor;
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//Structs:
struct s_motor_group{
	motor group[TOTAL_MOTORS];
	unsigned char amount;
}typedef motor_group;
//------------------------------------------------------------------------------------------------------------------------
#endif