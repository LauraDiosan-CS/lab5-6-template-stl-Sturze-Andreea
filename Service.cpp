#include "stdafx.h"
#include "Service.h"
#include <algorithm>
using namespace std;

Service::Service() {
	number = 10;
}

/*Service::Service(const RepoTemplate<Car>& repository) {
	this->repo = repository;
}*/

/*Service::Service(const Repository& repository) {
	this->repo = repository;
}*/

Service::Service(const RepoFile& repository) {
	this->repo = repository;
}

Service::~Service() {

}

void Service::setParkingNr(int nr) {
	parking = nr;
}

int Service::addToRepo(const char* name, const char* licensePlate, const char* status) {
	if (strcmp(status, "ocupat") == 0) {
		int k = 0;
		for (int i = 0; i < repo.getSize(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking)
			return -2;
	}
	Car c(name, licensePlate, status);
	int rez = this->repo.addElem(c);
	return rez;
}

int Service::delFromRepo(const char* name, const char* licensePlate, const char* status) {
	if (strcmp(status, "liber") == 0) {
		Car c(name, licensePlate, status);
		return this->repo.delElem(c);
	}
	else
		return -2;
	
}

void Service::updateInRepo(const char* name, const char* licensePlate, const char* status, const char* newName, const char* newLicensePlate, const char* newStatus) {
	Car c(name, licensePlate, status);
	Car newC(newName, newLicensePlate, newStatus);
	this->repo.updateElem(c, newC);
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
			else {
				Car newC(c.getName(), c.getLicensePlate(), "ocupat");
				repo.updateElem(c, newC);
				number = 0;
				return 0;
			}
		}
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