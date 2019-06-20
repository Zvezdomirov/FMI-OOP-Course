#ifndef STORAGE_H
#define STORAGE_H

class Storage {
	
public:
	Storage(const char *hashcode = "",
		const char *name = "",
		int max_capacity = 0,
		int used_capacity = 0); //default constructor included

	Storage(const Storage&); // copy constructor

	Storage& operator=(const Storage& rhs);

	virtual ~Storage();

	char *getHashcode() const;

	void setHashcode(const char *hashcode);

	char *getName() const;

	void setName(const char *name);

	int getMaxCapacity() const;

	void setMaxCapacity(int max_capacity);

	int getUsedCapacity() const;

	void setUsedCapacity(int used_capacity);

private:
	char *m_hashcode;
	char *m_name;
	int m_max_capacity;
	int m_used_capacity;
};

#endif