#pragma once

#include "SubSystem.h"
#include "RovData.h"
#include "UDPConnection.h"
#include "InputOutput.h"

class IOSubSystem : public SubSystem
{
public:
	IOSubSystem()
	{
		int i = 0;
#ifdef UDP_ENABLE
		devices[i++] = new UDPConnection();
#endif
	}
	void apply(RovData& rov_data) override;
	InputOutput* devices[SIZE_IO_DEVICES];
};
