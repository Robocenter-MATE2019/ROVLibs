#pragma once

#include "SubSystem.h"
#include "RovData.h"
#include "Input.h"
#include "Config.h"

class InputSubSystem :public SubSystem
{
public:
	InputSubSystem()
	{

		int i = 0;
#ifdef IMU_ENABLE
		//devices[i++] = new IMU();
#endif 
#ifdef DnT_ENABLE
		//devices[i++] = new DnT();
#endif

	}
	void apply(RovData& rov_data) override;
	Input* devices[SIZE_INPUT_DEVICES];
};




