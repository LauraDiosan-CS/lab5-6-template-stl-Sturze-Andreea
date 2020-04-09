#pragma once
#include "Car.h"
#include "Repository.h"
#include "RepoFile.h"

class Service {
private:
	int parking;
	RepoFile repo;
public:
	int number;
	Service();
	//Service(const Repository&);
	Service(const RepoFile&);
	//Service(const RepoTemplate<Car>&);
	~Service();
	int addToRepo(const char*, const char*, const char*);
	int delFromRepo(const char*, const char*, const char*);
	void updateInRepo(const char*, const char*, const char*, const char*, const char*, const char*);
	bool findElemInRepo(const Car&);
	Car getItemFromPos(int);
	list<Car> getFromRepo();
	int getRepoSize();
	void setParkingNr(int);
	int enterParking(Car);
	int exitParking(Car);
};