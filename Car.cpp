#include "stdafx.h"
#include "Car.h"
#include <string.h>


Car::Car() {
	name = NULL;
	licensePlate = NULL;
	status = NULL;
}

Car::Car(const char* n, const char* l, const char* s) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	licensePlate = new char[strlen(l) + 1];
	strcpy_s(licensePlate, strlen(l) + 1, l);
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}

Car::Car(const Car& c) {
	name = new char[strlen(c.name) + 1];
	strcpy_s(name, strlen(c.name) + 1, c.name);

	licensePlate = new char[strlen(c.licensePlate) + 1];
	strcpy_s(licensePlate, strlen(c.licensePlate) + 1, c.licensePlate);

	status = new char[strlen(c.status) + 1];
	strcpy_s(status, strlen(c.status) + 1, c.status);
}

Car::~Car() {
	if (name)
		delete[] name;
	name = NULL;
	if (licensePlate)
		delete[] licensePlate;
	licensePlate = NULL;
	if (status)
		delete[] status;
	status = NULL;
}

char* Car::getName() {
	return name;
}

char* Car::getLicensePlate() {
	return licensePlate;
}

char* Car::getStatus() {
	return status;
}

void Car::setName(const char* n) {
	if (name)
		delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Car::setLicensePlate(const char* l) {
	if (licensePlate)
		delete[] licensePlate;
	name = new char[strlen(l) + 1];
	strcpy_s(licensePlate, strlen(l) + 1, l);
}

void Car::setStatus(const char* s) {
	if (status)
		delete[] status;
	name = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}

Car& Car::operator=(const Car& c) {
	if (this == &c)
		return *this; 
	if (c.name) {
		if (this->name)delete[]this->name;
		this->name = new char[strlen(c.name) + 1];
		strcpy_s(this->name, strlen(c.name) + 1, c.name);
	}
	if (c.status) {
		if (this->status)
			delete[]this->status;
		this->status = new char[strlen(c.status) + 1];
		strcpy_s(this->status, strlen(c.status) + 1, c.status);
	}
	if (c.licensePlate) {
		if (this->licensePlate)
			delete[]this->licensePlate;
		this->licensePlate = new char[strlen(c.licensePlate) + 1];
		strcpy_s(this->licensePlate, strlen(c.licensePlate) + 1, c.licensePlate);
	}
	return *this;
}

bool Car::operator==(const Car& c) {
	return (strcmp(name, c.name) == 0 and strcmp(licensePlate, c.licensePlate) == 0 and strcmp(status, c.status) == 0);
}