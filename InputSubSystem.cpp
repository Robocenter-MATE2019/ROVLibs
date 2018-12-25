#include "InputSubSystem.h"
#include"RovData.h"


InputSubSystem::InputSubSystem()
{

	int i = 0;
#if IMU_ENABLE
#endif 
#if DnT_ENABLE
#endif

}

void InputSubSystem::init()
{
	for (auto device : m_devices)
	{
		device->init();
	}
}

void InputSubSystem::apply(RovData& rov_data)
{
	for (auto device : m_devices)
	{
		device->read(rov_data);
	}
}
