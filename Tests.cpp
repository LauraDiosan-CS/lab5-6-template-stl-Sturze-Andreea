#include "stdafx.h"
#include "Repository.h"
#include "RepoFile.h"
#include "Car.h"
#include "Tests.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include<list>
using namespace std;

void testCar() {
	Car c("ion", "CJ23AAA", "liber");
	assert(strcmp(c.getName(), "ion") == 0);
	assert(strcmp(c.getLicensePlate(), "CJ23AAA") == 0);
	assert(strcmp(c.getStatus(), "liber") == 0);
	Car c1;
	assert(c1.getName() == NULL);
	assert(c1.getLicensePlate() == NULL);
	assert(c1.getStatus() == NULL);
	Car c2(c);
	assert(strcmp(c2.getName(), "ion") == 0);
	assert(strcmp(c2.getLicensePlate(), "CJ23AAA") == 0);
	assert(strcmp(c2.getStatus(), "liber") == 0);
	c.setName("ana");
	assert(strcmp(c.getName(), "ana") == 0);
	c.setLicensePlate("CJ44BBB");
	assert(strcmp(c.getLicensePlate(), "CJ44BBB") == 0);
	c.setStatus("ocupat");
	assert(strcmp(c.getStatus(), "ocupat") == 0);
	Car c3("ana", "CJ44BBB", "ocupat");
	assert(c == c3);

}

void testRepo(){
	Repository repo;
	Car c("ion", "CJ23AAA", "liber");
	Car c1("ana", "CJ44BBB", "ocupat");
	Car c2("maria", "CJ42BCB", "liber");
	Car c3("ioana", "B47HHH", "ocupat");
	Car cars[] = { c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Car> l = repo.getAll();
	assert(repo.getSize() == 4);
	assert(l.front() == c);
	assert(l.back() == c3);
	int i = 0;
	for (list<Car>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == cars[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 3);
	assert(repo.findElem(c2) == -1);
	repo.updateElem(c1, "dana", "CJ11LLL", "liber");
	assert(repo.findCar(c1) == false);
	Car c4("dana", "CJ11LLL", "liber");
	assert(repo.getItemFromPos(1) == c4);
}

void testService() {
	Car c("ion", "CJ23AAA", "liber");
	Car c1("ana", "CJ44BBB", "ocupat");
	Car c2("maria", "CJ42BCB", "liber");
	Car c3("ioana", "B47HHH", "ocupat");
	Service serv;
	serv.addToRepo("ion", "CJ23AAA", "liber");
	serv.addToRepo("ana", "CJ44BBB", "ocupat");
	serv.addToRepo("maria", "CJ42BCB", "liber");
	serv.addToRepo("ioana", "B47HHH", "ocupat");
	assert(serv.getItemFromPos(0) == c);
	assert(serv.getItemFromPos(1) == c1);
	assert(serv.getItemFromPos(2) == c2);
	assert(serv.getItemFromPos(3) == c3);
	assert(serv.getRepoSize() == 4);
	assert(serv.findElemInRepo(c) == 0);
	serv.delFromRepo("ana", "CJ44BBB", "ocupat");
	assert(serv.getRepoSize() == 3);
	serv.updateInRepo("ion", "CJ23AAA", "liber", "ana", "CJ44BBB", "ocupat");
	assert(serv.findCar(c) == false);
	assert(serv.getItemFromPos(0) == c1);
	assert(serv.findElemInRepo(c1) == 0);
}

void testRepoFile() {
	RepoFile repo("test.txt");
	Car c("ion", "CJ23AAA", "liber");
	Car c1("ana", "CJ44BBB", "ocupat");
	Car c2("maria", "CJ42BCB", "liber");
	Car c3("ioana", "B47HHH", "ocupat");
	Car c4("Ion", "B44CCC", "liber");
	Car c5("Ana", "CJ65AAA", "ocupat");
	Car cars[] = { c4,c5, c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Car> l = repo.getAll();
	assert(repo.getSize() == 6);
	int i = 0;
	for (list<Car>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == cars[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 5);
	assert(repo.findElem(c2) == -1);
	repo.updateElem(c1, "dana", "CJ11LLL", "liber");
	assert(repo.findCar(c1) == false);
	Car c6("dana", "CJ11LLL", "liber");
	assert(repo.getItemFromPos(3) == c6);
	repo.addElem(c1);
	repo.saveToFile();
	repo.loadFromFile("test.txt");
	assert(repo.getSize() == 6);
	assert(repo.getItemFromPos(5) == c1);
}