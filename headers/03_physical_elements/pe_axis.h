 #include "common_types.h"
//------------------------------------------------------------------------------------------------------------------------
 #ifndef PE_AXIS_H
 #define PE_AXIS_H
//------------------------------------------------------------------------------------------------------------------------
//Classes:
class c_pe_axis{
public:
	c_pe_axis(void);
	c_pe_axis(unsigned int pin_number);

	unsigned int get_axis_raw_value(void);
	void print_raw_axis_value(void);
	bool is_inside_deadzone(void);
protected:
private:
	unsigned int acquire_raw_value(void);
	unsigned int m_axis_pin;
	unsigned int m_axis_raw_value;
}typedef axis_g;
//------------------------------------------------------------------------------------------------------------------------
class c_pe_axis_indexed : public c_pe_axis{
public:
	c_pe_axis_indexed(void);
	c_pe_axis_indexed(unsigned int pin_number, axis_index axis_index);
	void print_raw_axis_value_indexed(void);
protected:
private:
	axis_index m_axis_index;
}typedef axis;
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//Structs:
struct s_pe_axis_group{
	axis group[TOTAL_AXIS];
	const unsigned char amount;
}typedef axis_group;
//------------------------------------------------------------------------------------------------------------------------
#endif