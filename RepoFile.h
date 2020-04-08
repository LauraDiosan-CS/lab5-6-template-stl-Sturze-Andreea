#pragma once
#include <list>
#include <iostream>
#include "Car.h"
#include "Repository.h"
using namespace std;

class RepoFile :public Repository{
private:
	const char* fileName;
public:
	RepoFile();
	RepoFile(const char*);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFile();
};