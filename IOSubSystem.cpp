#include "IOSubSystem.h"
#include "RovData.h"


void IOSubSystem::apply(RovData& rov_data)
{
	for (auto device : m_devices)
	{
		device->read(rov_data);
		device->write(rov_data);
	}	
}
IOSubSystem::IOSubSystem()
{
	int i = 0;
#if UDP_ENABLE
	m_devices[i++] = new UDPConnection();
#endif
}
void IOSubSystem::init()
{
	for (auto device : m_devices)
	{
		device->init();
	}
}

