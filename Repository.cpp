#include "stdafx.h"
#include "Repository.h"

Repository::Repository() {

}


Repository::~Repository() {

}

int Repository::addElem(Car c) {
	list<Car>::iterator it;
	int ok = 1;
	for (it = cars.begin(); it != cars.end(); it++)
		if (strcmp((*it).getLicensePlate(), c.getLicensePlate()) == 0)
			ok = 0;
	it = find(cars.begin(), cars.end(), c);
	if (it == cars.end() and ok == 1)
	{
		cars.push_back(c);
		return 1;
	}
	return 0;
}

list<Car> Repository::getAll() {
	return cars;
}

int Repository::getSize() {
	return cars.size();
}

int Repository::delElem(Car c) {
	list<Car>::iterator it;
	it = find(cars.begin(), cars.end(), c);
	if (it != cars.end())
	{
		cars.erase(it);
		return 0;
	}
	else
		return -1;
}

void Repository::updateElem(Car c, const char* n, const char* l, const char* s) {
	list<Car>::iterator it;
	it = find(cars.begin(), cars.end(), c);
	if (it != cars.end())
	{
		(*it).setName(n);
		(*it).setLicensePlate(l);
		(*it).setStatus(s);
	}
}

int Repository::findElem(Car c) {
	list<Car>::iterator it;
	int i = 0;
	for (it = cars.begin(); it != cars.end(); it++)
	{
		if (*it == c)
			return i;
		i++;

	}
	return -1;
}

Car Repository::getItemFromPos(int i) {
	list<Car>::iterator it;
	int k = 0;
	for (it = cars.begin(); it != cars.end(); it++)
	{
		if (k==i)
			return *it;
		k++;

	}
}

bool Repository::findCar(Car c) {
	list<Car>::iterator it;
	it = find(cars.begin(), cars.end(), c);
	if (it !=cars.end())
		return true;
	return false;
}