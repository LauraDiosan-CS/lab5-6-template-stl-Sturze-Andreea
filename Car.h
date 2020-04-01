#pragma once

class Car {
private:
	char* name;
	char* licensePlate;
	char* status;
public:
	Car();
	Car(const char*, const char*, const char*);
	Car(const Car&);
	char* getName();
	char* getLicensePlate();
	char* getStatus();
	void setName(const char*);
	void setLicensePlate(const char*);
	void setStatus(const char*);
	Car& operator=(const Car&);
	bool operator==(const Car&);
	~Car();

};