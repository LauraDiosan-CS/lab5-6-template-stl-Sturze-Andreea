#pragma once
#include <list>
#include <iostream>
#include "Car.h"
#include "RepoTemplate.h"
using namespace std;


class RepoFile :public RepoTemplate<Car>
{
private:
	const char* fileName;
public:
	RepoFile();
	RepoFile(const char*);
	int addElem(Car);
	int delElem(Car);
	void updateElem(Car, const Car);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFile();
};