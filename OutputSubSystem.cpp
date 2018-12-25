#include "OutputSubSystem.h"
#include "RovData.h"


 OutputSubSystem::OutputSubSystem()
{
	int i = 0;
#if MANIPULATOR_ENABLE
	m_devices[i++] = new ROVBuilderManipulator();
#endif
#if THRUSTERSSUBSYSTEM_ENABLE
	m_devices[i++] = new ThrustersSubSystem();
#endif
#if ROTARYCAMERA_ENABLE
	m_devices[i++] = new Cameras();
#endif

}

void OutputSubSystem::init()
{
	for (auto device : m_devices)
	{
		device->init();
	}
}

void OutputSubSystem::apply(RovData& rov_data)
{
	for (auto device : m_devices)
	{
		device->write(rov_data);
	}
}