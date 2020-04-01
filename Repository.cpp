#include "stdafx.h"
#include "Repository.h"

Repository::Repository() {

}

Repository::~Repository() {

}

void Repository::addElem(Car c) {
	cars.push_back(c);
}

list<Car> Repository::getAll() {
	return cars;
}

int Repository::getSize() {
	return cars.size();
}