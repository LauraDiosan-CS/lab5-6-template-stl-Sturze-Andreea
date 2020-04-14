#pragma once
#include "Car.h"
#include "RepoFile.h"
#include "RepoTemplate.h"

class Service {
private:
	int parking;
	RepoTemplate<Car> &repo;
public:
	int number;
	Service(RepoTemplate<Car>& r) :repo(r) { repo = r; number = 10; };
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