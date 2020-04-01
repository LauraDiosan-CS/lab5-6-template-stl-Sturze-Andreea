#include "stdafx.h"
#include "Repository.h"
#include "Car.h"
#include "Tests.h"
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

void testCar() {
	Car c("ion", "CJ 23 AAA", "liber");
	assert(strcmp(c.getName(), "ion") == 0);
	assert(strcmp(c.getLicensePlate(), "CJ 23 AAA") == 0);
	assert(strcmp(c.getStatus(), "liber") == 0);
	Car c1;
	assert(c1.getName() == NULL);
	assert(c1.getLicensePlate() == NULL);
	assert(c1.getStatus() == NULL);
	Car c2(c);
	assert(strcmp(c2.getName(), "ion") == 0);
	assert(strcmp(c2.getLicensePlate(), "CJ 23 AAA") == 0);
	assert(strcmp(c2.getStatus(), "liber") == 0);
	c.setName("ana");
	assert(strcmp(c.getName(), "ana") == 0);
	c.setLicensePlate("CJ 44 BBB");
	assert(strcmp(c.getLicensePlate(), "CJ 44 BBB") == 0);
	c.setStatus("ocupat");
	assert(strcmp(c.getStatus(), "ocupat") == 0);
}

void testRepo() {
	Repository repo;
	Car c("ion", "CJ 23 AAA", "liber");
	repo.addElem(c);
	list<Car> l = repo.getAll();
	assert(repo.getSize()==1);
}