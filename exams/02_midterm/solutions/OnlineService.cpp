#include "OnlineService.h"
#include <iostream>

int OnlineService::getPort() const
{
	return m_port;
}

void OnlineService::setPort(int port)
{
	m_port = port;
}

void OnlineService::plugDevice()
{
	if (m_plugged_devices == m_max_plugged_devices) {
		std::cerr << "Device plug is impossible. Max plugged devices limit is reached.\n";
		return;
	}
	else {
		m_plugged_devices++;
		std::cout << "Device plugged in successfully!" << std::endl;
	}
}

void OnlineService::unplugDevice()
{
	if (m_plugged_devices <= 0) {
		std::cerr << "No devices to unplug!\n";
		return;
	}
	else {
		m_plugged_devices--;
	}
}
