#include "Rov.h"
#include "OutputSubSystem.h"
#include "InputSubSystem.h"
#include "IOSubSystem.h"
Rov::Rov()
{
	int i = 0;
#if OUTPUTSUBSYSTEM_ENABLE
	m_subsystem[i++] = new OutputSubSystem;
#endif
#if INPUTSUBSYSTEM_ENABLE
	m_subsystem[i++] = new InputSubSystem;
#endif
#if IOSUBSYSTEM_ENABLE
	m_subsystem[i++] = new IOSubSystem;
#endif
}


void Rov::init()
{
	for (auto device : m_subsystem)
	{
		device->init();
	}
}

void Rov::run()
{
	for (auto device : m_subsystem)
	{
		device->apply(m_rov_data);
	}
}


