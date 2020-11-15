#include "globals.h"
//------------------------------------------------------------------------------------------------------------------------
unsigned int aux = 0;
//------------------------------------------------------------------------------------------------------------------------
axis potentiometers[4] = {
	DESIRED_AXIS
};
//------------------------------------------------------------------------------------------------------------------------
axis_group potentiometers_group = {
	{DESIRED_AXIS},
	TOTAL_DESIRED_AXIS
};
//------------------------------------------------------------------------------------------------------------------------
joystick joy( { {DESIRED_AXIS}, TOTAL_DESIRED_AXIS } );
//------------------------------------------------------------------------------------------------------------------------
motor_group mg = { {DESIRED_MOTORS}, TOTAL_DESIRED_MOTORS };
//------------------------------------------------------------------------------------------------------------------------
speed_manager sm( { {DESIRED_MOTORS}, TOTAL_DESIRED_MOTORS }, joystick({{DESIRED_AXIS}, TOTAL_DESIRED_AXIS}) );
//------------------------------------------------------------------------------------------------------------------------
motor_config mcfg1 = {ADVANCE, PULSE_WIDTH_MAX-3};
//------------------------------------------------------------------------------------------------------------------------
motor_config_indexed mcfgi1 = { mot_x, {ADVANCE, PULSE_WIDTH_MAX-3} };
//------------------------------------------------------------------------------------------------------------------------
motor_config_group const mcfgg1 = { {{ mot_x, {ADVANCE, 2} }, { mot_y, {ADVANCE, 4} }, { mot_z, {ADVANCE, 8} }}, 3 };
motor_config_group const mcfgg2 = { {{ mot_x, {RECEDE, 2} }, { mot_y, {RECEDE, 4} }, { mot_z, {RECEDE, 8} }}, 3  };
motor_config_group const mcfgg3 = { {{ mot_x, {ADVANCE, 8} }, { mot_y, {RECEDE, 2} }, { mot_z, {ADVANCE, 8} }}, 3  };

motor_config_group const mcfgg4 = { {{ mot_x, {RECEDE, 1} }, { mot_y, {RECEDE, 2} }, { mot_z, {RECEDE, 3} }}, 3 };
motor_config_group const mcfgg5 = { {{ mot_x, {ADVANCE, 2} }, { mot_y, {RECEDE, 3} }, { mot_z, {RECEDE, 4} }}, 3  };
motor_config_group const mcfgg6 = { {{ mot_x, {RECEDE, 3} }, { mot_y, {ADVANCE, 4} }, { mot_z, {RECEDE, 5} }}, 3  };

const motor_config_group mcfgg_array[24]={
	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {ADVANCE, 4} }, { mot_z, {ADVANCE, 8} }}, 3 },
	{ {{ mot_x, {RECEDE, 2} }, { mot_y, {RECEDE, 4} }, { mot_z, {RECEDE, 8} }}, 3  },
	{ {{ mot_x, {ADVANCE, 8} }, { mot_y, {RECEDE, 2} }, { mot_z, {ADVANCE, 8} }}, 3  },
	{ {{ mot_x, {RECEDE, 1} }, { mot_y, {RECEDE, 2} }, { mot_z, {RECEDE, 3} }}, 3 },
	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {RECEDE, 3} }, { mot_z, {RECEDE, 4} }}, 3  },
	{ {{ mot_x, {RECEDE, 3} }, { mot_y, {ADVANCE, 4} }, { mot_z, {RECEDE, 5} }}, 3  },

	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {ADVANCE, 4} }, { mot_z, {ADVANCE, 8} }}, 3 },
	{ {{ mot_x, {RECEDE, 2} }, { mot_y, {RECEDE, 4} }, { mot_z, {RECEDE, 8} }}, 3  },
	{ {{ mot_x, {ADVANCE, 8} }, { mot_y, {RECEDE, 2} }, { mot_z, {ADVANCE, 8} }}, 3  },
	{ {{ mot_x, {RECEDE, 1} }, { mot_y, {RECEDE, 2} }, { mot_z, {RECEDE, 3} }}, 3 },
	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {RECEDE, 3} }, { mot_z, {RECEDE, 4} }}, 3  },
	{ {{ mot_x, {RECEDE, 3} }, { mot_y, {ADVANCE, 4} }, { mot_z, {RECEDE, 5} }}, 3  },

	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {ADVANCE, 4} }, { mot_z, {ADVANCE, 8} }}, 3 },
	{ {{ mot_x, {RECEDE, 2} }, { mot_y, {RECEDE, 4} }, { mot_z, {RECEDE, 8} }}, 3  },
	{ {{ mot_x, {ADVANCE, 8} }, { mot_y, {RECEDE, 2} }, { mot_z, {ADVANCE, 8} }}, 3  },
	{ {{ mot_x, {RECEDE, 1} }, { mot_y, {RECEDE, 2} }, { mot_z, {RECEDE, 3} }}, 3 },
	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {RECEDE, 3} }, { mot_z, {RECEDE, 4} }}, 3  },
	{ {{ mot_x, {RECEDE, 3} }, { mot_y, {ADVANCE, 4} }, { mot_z, {RECEDE, 5} }}, 3  },

	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {ADVANCE, 4} }, { mot_z, {ADVANCE, 8} }}, 3 },
	{ {{ mot_x, {RECEDE, 2} }, { mot_y, {RECEDE, 4} }, { mot_z, {RECEDE, 8} }}, 3  },
	{ {{ mot_x, {ADVANCE, 8} }, { mot_y, {RECEDE, 2} }, { mot_z, {ADVANCE, 8} }}, 3  },
	{ {{ mot_x, {RECEDE, 1} }, { mot_y, {RECEDE, 2} }, { mot_z, {RECEDE, 3} }}, 3 },
	{ {{ mot_x, {ADVANCE, 2} }, { mot_y, {RECEDE, 3} }, { mot_z, {RECEDE, 4} }}, 3  },
	{ {{ mot_x, {RECEDE, 3} }, { mot_y, {ADVANCE, 4} }, { mot_z, {RECEDE, 5} }}, 3  }
};
//------------------------------------------------------------------------------------------------------------------------