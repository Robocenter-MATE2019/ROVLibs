#include "OutputSubSystem.h"
#include "RovData.h"


void OutputSubSystem::apply(RovData& rov_data)
{
	for (auto device : devices)
	{
		device->write(rov_data);
	}
}