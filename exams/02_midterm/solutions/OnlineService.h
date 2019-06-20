#ifndef ONLINE_SERVICE_H
#define ONLINE_SERVICE_H

class OnlineService {

public:
	OnlineService(int port = 0,
		int plugged_devices = 0,
		int max_plugged_devices = 0) :
			m_port(port),
			m_plugged_devices(plugged_devices),
			m_max_plugged_devices(max_plugged_devices){};

	int getPort() const;

	void setPort(int port);

	void plugDevice();

	void unplugDevice();

private:
	int m_port;
	int m_plugged_devices;
	int m_max_plugged_devices;
};

#endif
