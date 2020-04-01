#pragma once
#include <list>
#include <iostream>
#include "Car.h"
using namespace std;

class Repository {
private:
	list<Car> cars;
public:
	Repository();
	void addElem(Car);
	list<Car> getAll();
	int getSize();
	~Repository();
};