#include "UDPConnection.h"

UDPConnection::UDPConnection() :
	m_self_ip(SELF_IP),
	m_remote_ip(REMOTE_IP),
	m_self_port(SELF_PORT),
	m_remote_port(REMOTE_PORT)
{}

void UDPConnection::init()
{
	Ethernet.init(10);
	Ethernet.begin(m_mac, m_self_ip);
	m_udp.begin(m_self_port);
	delay(100);
	m_timer.start();
}

bool UDPConnection::receivePacket(RovData& rov_data)
{
	if (m_udp.parsePacket())
	{
		InputPacket packet;
		char packetBuffer[17];
		m_udp.read(packetBuffer, 17);
		memcpy(&packet, packetBuffer, sizeof(packetBuffer));
		//Serial.println(m_timer_1.elapsed());
		//m_timer_1.start();
		parsePayload(packet, rov_data);
		return true;
	}
	else return false;
}

void UDPConnection::sendPacket(const OutputPacket& packet)
{
	if (m_timer.elapsed() > 250)
	{
		m_udp.beginPacket(m_udp.remoteIP(), m_udp.remotePort());
		m_udp.write((byte*)&packet, sizeof(packet));
		m_udp.endPacket();
		m_timer.start();
	}
}

bool UDPConnection::parsePayload(InputPacket& packet, RovData& rov_data)
{
	bool actionState[12];
	for (int i = 0; i <= 7; i++) 
	{
		actionState[i] = bitRead(packet.button_data1, i);
		Serial.print("button = ");
		Serial.print(i);
		Serial.print(" value = ");
		Serial.println(actionState[i]);
	}
	for (int i = 8; i < 12; i++) 
	{
		actionState[i] = bitRead(packet.button_data2, i - 8);
		Serial.print("button = ");
		Serial.print(i);
		Serial.print(" value = ");
		Serial.println(actionState[i]);
	}

	

	rov_data.m_axis_x = packet.axisX;
	rov_data.m_axis_y = packet.axisY;
	rov_data.m_axis_w = packet.axisW;
	rov_data.m_axis_z = packet.axisZ;

	rov_data.m_rotary_camera_1 = packet.cameraRotation[0];
	rov_data.m_rotary_camera_2 = packet.cameraRotation[1];

	rov_data.m_regulator_type = packet.regulators;

	rov_data.m_manipulator_grab = packet.manipulatorGrab;
	rov_data.m_manipulator_rotate = packet.manipulatorRotation;

	return true;
}

void UDPConnection::write(RovData& rov_data)
{
	OutputPacket packet;
	packet.yaw = rov_data.m_yaw;
	packet.depth = rov_data.m_depth;
	packet.roll = rov_data.m_roll;
	packet.temp = rov_data.m_temperature;
	sendPacket(packet);
}

void UDPConnection::read(RovData& rov_data)
{
	receivePacket(rov_data);
}