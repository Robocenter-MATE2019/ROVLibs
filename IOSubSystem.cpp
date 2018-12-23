#include "IOSubSystem.h"
#include "RovData.h"


void IOSubSystem::apply(RovData& rov_data)
{
	for (auto device : devices)
	{
		device->read(rov_data);
	}
	for (auto device : devices)
	{
		device->write(rov_data);
	}
}

