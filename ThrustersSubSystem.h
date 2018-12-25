#pragma once

#include "BrushlessMotor.h"
#include "Config.h"
#include "RovData.h"
#include "Output.h"

class ThrustersSubSystem : public Output
{
public:
	ThrustersSubSystem();
	void init();
	void write(RovData& rov_data);
	void set_power(int8_t x, int8_t y, int8_t w, int8_t z, uint8_t regulator_type);
private:
	void manual_regulator(int8_t power[], int8_t x, int8_t y, int8_t w, int8_t z);
	BrushlessMotor m_motors[THRUSTER_SIZE];
};