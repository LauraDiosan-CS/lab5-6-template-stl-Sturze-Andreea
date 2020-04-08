#pragma once
#include <list>
#include <iostream>
#include "Car.h"
using namespace std;

class Repository {
protected:
	list<Car> cars;
public:
	Repository();
	int addElem(Car);
	int delElem(Car);
	void updateElem(Car, const char*, const char*, const char*);
	int findElem(Car);
	bool findCar(Car);
	Car getItemFromPos(int);
	list<Car> getAll();
	int getSize();
	~Repository();
};