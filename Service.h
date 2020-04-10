#pragma once
#include "Car.h"
#include "RepoFile.h"

class Service {
private:
	int parking;
	RepoFile repo;
public:
	int number;
	Service();
	Service(const RepoFile&);
	~Service();
	int addToRepo(Car);
	int delFromRepo(Car);
	int updateInRepo(const Car&, Car);
	bool findElemInRepo(const Car&);
	Car getItemFromPos(int);
	list<Car> getFromRepo();
	int getRepoSize();
	void setParkingNr(int);
	int enterParking(Car);
	int exitParking(Car);
};