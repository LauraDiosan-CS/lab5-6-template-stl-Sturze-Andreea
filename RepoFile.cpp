#include "stdafx.h"
#include "RepoFile.h"
#include <fstream>

RepoFile::RepoFile():Repository() {
	fileName = "";
}

RepoFile::RepoFile(const char* file) : Repository() {
	cars.clear();
	this->fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			Car c(name,  licensePlate, status);
			cars.push_back(c);
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
	cars.clear();
	fileName= file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			Car c(name, licensePlate, status);
			cars.push_back(c);
		}
	}
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	f.close();
}

void RepoFile::saveToFile() {
	ofstream f(this->fileName);
	for (int i = 0; i < cars.size(); i++)
		if (i == cars.size() - 1)
			f << getItemFromPos(i).getName() << " " << getItemFromPos(i).getLicensePlate() << " " << getItemFromPos(i).getStatus();
		else
			f << getItemFromPos(i);
	f.close();
}