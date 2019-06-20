#include "OnlineStorage.h"
#include <cmath>

void OnlineStorage::uploadFile(int file_size)
{
	plugDevice();
	setUsedCapacity(file_size / 1024 + getUsedCapacity());
}

double OnlineStorage::calcPricePerMonth() const
{
	return ceil(m_price_per_gb * getUsedCapacity());
}
