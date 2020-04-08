#include "stdafx.h"
#include "Service.h"

Service::Service() {
}

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
	Car c(name, licensePlate, status);
	int rez = this->repo.addElem(c);
	repo.saveToFile();
	return rez;
}

int Service::delFromRepo(const char* name, const char* licensePlate, const char* status) {
	Car c(name, licensePlate, status);
	int rez =  this->repo.delElem(c);
	repo.saveToFile();
	return rez;
	
}

void Service::updateInRepo(const char* name, const char* licensePlate, const char* status, const char* newName, const char* newLicensePlate, const char* newStatus) {
	Car c(name, licensePlate, status);
	this->repo.updateElem(c, newName, newLicensePlate, newStatus);
	repo.saveToFile();
}

list<Car> Service::getFromRepo() {
	return repo.getAll();
}

int Service::getRepoSize() {
	return repo.getSize();
}

int Service::findElemInRepo(const Car& c) {
	return repo.findElem(c);
}


Car Service::getItemFromPos(int i) {
	return repo.getItemFromPos(i);
}

bool Service::findCar(const Car& c) {
	return repo.findCar(c);
}

int Service::enterParking(Car c) {
	if (strcmp(c.getStatus(), "ocupat") == 0)
		return -1;
	else
	{
		int k = 0;
		for (int i = 0; i < repo.getSize(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k == parking)
			return -2;
		else {
			repo.updateElem(c, c.getName(), c.getLicensePlate(), "ocupat");
			repo.saveToFile();
			return 0;
		}
	}

}