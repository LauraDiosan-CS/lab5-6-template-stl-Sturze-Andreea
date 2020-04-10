#include "stdafx.h"
#include "RepoFile.h"
#include <fstream>

RepoFile::RepoFile():RepoTemplate<Car>() {
	fileName = "";
}

RepoFile::RepoFile(const char* file) : RepoTemplate<Car>() {
	elem.clear();
	this->fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			Car c(name,  licensePlate, status);
			elem.push_back(c);
		}
	}
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	f.close();
}

RepoFile::~RepoFile() {
}


void RepoFile::loadFromFile(const char* file) {
	elem.clear();
	fileName= file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			Car c(name, licensePlate, status);
			elem.push_back(c);
		}
	}
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	f.close();
}

void RepoFile::saveToFile() {
	ofstream f(this->fileName);
	for (int i = 0; i < elem.size(); i++)
		if (i == elem.size() - 1)
			f << getItemFromPos(i).getName() << " " << getItemFromPos(i).getLicensePlate() << " " << getItemFromPos(i).getStatus();
		else
			f << getItemFromPos(i);
	f.close();
}

int RepoFile::addElem(Car c){
	list<Car>::iterator it;
	int ok = 1;
	for (it = elem.begin(); it != elem.end(); it++)
		if (strcmp((*it).getLicensePlate(), c.getLicensePlate()) == 0)
			ok = 0;
	it = find(elem.begin(), elem.end(), c);
	if (it == elem.end() and ok == 1)
	{
		elem.push_back(c);
		saveToFile();
		return 0;
	}
	return -1;
}

int RepoFile::delElem(Car c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
	{
		elem.erase(it);
		saveToFile();
		return 0;
	}
	else
		return -1;
}

void RepoFile::updateElem(Car c , const Car newC) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
	{
		elem.insert(it, newC);
		elem.erase(it);
	}
	saveToFile();
}