#include "stdafx.h"
#include "Service.h"
using namespace std;

Service::~Service() {
}

void Service::setParkingNr(int nr) {
	parking = nr;
}

int Service::addToRepo(Car c) {
	if (strcmp(c.getStatus(), "ocupat") == 0) {
		int k = 0;
		for (int i = 0; i < repo.getSize(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking) {
			number++;
			return -2;
		}
	}
	int rez = repo.addElem(c);
	return rez;
}

int Service::delFromRepo(Car c) {
	if (strcmp(c.getStatus(), "liber") == 0) {
		return repo.delElem(c);
	}
	else
		return -2;
	
}

int Service::updateInRepo(const Car& c, Car newC) {
	if (strcmp(newC.getStatus(), "ocupat") == 0) {
		int k = 0;
		for (int i = 0; i < repo.getSize(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking) {
			number++;
			return -2;
		}
	}
	repo.updateElem(c, newC);
	return 0;
}

list<Car> Service::getFromRepo() {
	return repo.getAll();
}

int Service::getRepoSize() {
	return repo.getSize();
}

bool Service::findElemInRepo(const Car& c) {
	return repo.findElem(c);
}


Car Service::getItemFromPos(int i) {
	return repo.getItemFromPos(i);
}


int Service::enterParking(Car c) {
	if (c.getStatus())
		if (strcmp(c.getStatus(), "ocupat") == 0){
			return -1;
		}
		else{
			int k = 0;
			for (int i = 0; i < repo.getSize(); i++)
				if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
					k++;
			if (k >= parking) {
				number++;
				return -2;
			}
		}
	Car newC(c.getName(), c.getLicensePlate(), "ocupat");
	repo.updateElem(c, newC);
	number = 0;
	return 0;
}

int Service::exitParking(Car c) {
	if (strcmp(c.getStatus(), "ocupat") == 0) {
		Car newC(c.getName(), c.getLicensePlate(), "liber");
		repo.updateElem(c, newC);
		number = 0;
		return 0;
	}
	else {
		return -1;
	}
}