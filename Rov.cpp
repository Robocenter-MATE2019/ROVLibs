#include "Rov.h"

Rov::Rov()
{
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


