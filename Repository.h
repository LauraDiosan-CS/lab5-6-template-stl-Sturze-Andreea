#pragma once
#include <list>
#include <iostream>
#include "Car.h"
using namespace std;

class Repository {
protected:
	list<Car> elem;
public:
	Repository();
	virtual int addElem(Car);
	virtual int delElem(const Car&);
	virtual void updateElem(const Car&, const Car);
	bool findElem(const Car&);
	Car getItemFromPos(int);
	list<Car> getAll();
	int getSize();
	~Repository();
};