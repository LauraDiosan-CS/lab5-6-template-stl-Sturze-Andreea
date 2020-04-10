#include "stdafx.h"
#include "Car.h"
#include <string.h>
#include <iostream>
using namespace std;


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
	strcpy_s(status, strlen(c.status)+ 1, c.status);
}

Car::~Car() {
	if (name)
	{
		delete[] name;
		name = NULL;
	}
	if (licensePlate)
	{
		delete[] licensePlate;
		licensePlate = NULL;
	}
	if (status)
	{
		delete[] status;
		status = NULL;
	}
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
	licensePlate = new char[strlen(l) + 1];
	strcpy_s(licensePlate, strlen(l) + 1, l);
}

void Car::setStatus(const char* s) {
	if (status)
		delete[] status;
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}

Car& Car::operator=(const Car& c) {
	if (this == &c)
		return *this;
	if (c.name)
		setName(c.name);
	if (c.licensePlate)
		setLicensePlate(c.licensePlate);
	if (c.status)
		setStatus(c.status);
	return *this;
}

bool Car::operator==(const Car& c) {
	if (c.name and c.licensePlate and c.status)
		return (strcmp(name, c.name) == 0 and strcmp(licensePlate, c.licensePlate) == 0 and strcmp(status, c.status) == 0);
	return false;
}

ostream& operator<<(ostream& os, Car c) {
	if(c.getName())
		os << c.getName() << " " << c.getLicensePlate()<<" "<<c.getStatus() << endl;
	return os;
}

istream & operator>>(istream &is, Car &c)
{
	cout << "Name: ";
	char* name = new char[20];
	is >> name;
	cout << "License plate: ";
	char* licensePlate = new char[20];
	is >> licensePlate;
	cout << "Status: ";
	char* status = new char[20];
	is >> status;
	c.setName(name);
	c.setLicensePlate(licensePlate);
	c.setStatus(status);
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	return is;
}
