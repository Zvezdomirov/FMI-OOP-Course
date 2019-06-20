#ifndef ONLINE_STORAGE_H
#define ONLINE_STORAGE_H

#include "Storage.h"
#include "OnlineService.h"


class OnlineStorage : public Storage,
	public OnlineService {

public:
	OnlineStorage(const char *hashcode = "",
		const char *name = "",
		int max_capacity = 0,
		int used_capacity = 0,
		int port = 0,
		int plugged_devices = 0,
		int max_plugged_devices = 0,
		double price_per_gb = 0.0) :
			Storage(hashcode, name, max_capacity,
				used_capacity),
			OnlineService(port, plugged_devices, max_plugged_devices),
			m_price_per_gb(price_per_gb) {};

	void uploadFile(int file_size);

	double calcPricePerMonth() const;

private:
	double m_price_per_gb;
};

#endif