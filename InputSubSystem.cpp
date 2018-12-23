#include "InputSubSystem.h"
#include"RovData.h"


void InputSubSystem::apply(RovData& rov_data)
{
	for (auto device : devices)
	{
		device->read(rov_data);
	}
}
