#include "stdafx.h"
#include "Repository.h"

Repository::Repository() {

}


Repository::~Repository() {

}

int Repository::addElem(Car c) {
	list<Car>::iterator it;
	int ok = 1;
	for (it = elem.begin(); it != elem.end(); it++)
		if (strcmp((*it).getLicensePlate(), c.getLicensePlate()) == 0)
			ok = 0;
	it = find(elem.begin(), elem.end(), c);
	if (it == elem.end() and ok == 1)
	{
		elem.push_back(c);
		return 0;
	}
	return -1;
}

int Repository::delElem(const Car& c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	else
		return -1;
}

void Repository::updateElem(const Car& c, const Car newC) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
	{
		elem.insert(it, newC);
		elem.erase(it);
	}
}
list<Car> Repository::getAll() {
	return elem;
}

int Repository::getSize() {
	return elem.size();
}

bool Repository::findElem(const Car& c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
		return true;
	return false;
}

Car Repository::getItemFromPos(int i) {
	list<Car>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k==i)
			return *it;
		k++;

	}
}
