#ifndef GLOBAL_TYPES_H
#define GLOBAL_TYPES_H

#define AXIS_ALL_ZEROS {0,0,0,0}
#define TOTAL_AXIS 4
#define JOY_POS_NULL {AXIS_ALL_ZEROS,TOTAL_AXIS}

#define TOTAL_MOTORS 3
#define	PULSE_WIDTH_MAX	10

#define ADVANCE true
#define RECEDE false

#define ADC_RESOLUTION 1024
#define AXIS_DEADZONE_CENTER ((ADC_RESOLUTION/2)-1)
#define AXIS_DEADZONE_RADIUS 200
#define AXIS_DEADZONE_UPPER (AXIS_DEADZONE_CENTER + AXIS_DEADZONE_RADIUS)
#define AXIS_DEADZONE_LOWER (AXIS_DEADZONE_CENTER - AXIS_DEADZONE_RADIUS)

//------------------------------------------------------------------------------------------------------------------------
#define DESIRED_AXIS axis(A1,rile), axis(A2,foba), axis(A3,roll), axis(A4,velo)
#define TOTAL_DESIRED_AXIS TOTAL_AXIS
//------------------------------------------------------------------------------------------------------------------------
#define DESIRED_MOTORS motor(2,3,rile,mot_x), motor(4,5,foba,mot_y), motor(6,7,roll,mot_z)
#define TOTAL_DESIRED_MOTORS TOTAL_MOTORS
//------------------------------------------------------------------------------------------------------------------------

enum e_axis_index : unsigned char {rile=0,foba=1,roll=2,velo=3,no_axis=255};
typedef e_axis_index axis_index;

enum e_motor_index : unsigned char {mot_x=0,mot_y=1,mot_z=2,no_motor=255};
typedef e_motor_index motor_index;

struct s_data_motor_config_general{
	const bool dir;
	const unsigned int pulse_width;
}typedef motor_config;

struct s_data_motor_config_indexed{
	const motor_index idx;
	const motor_config mot_cfg;
}typedef motor_config_indexed;

struct s_data_motor_config_group{
	const motor_config_indexed config_array[TOTAL_MOTORS];
	const unsigned int amount;
}typedef motor_config_group;

struct s_data_joystick_position{
	unsigned int axis_val[TOTAL_AXIS];
	unsigned char axis_amount;
}typedef joy_pos;

#endif