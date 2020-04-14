#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include "Car.h"
#include "RepoTemplate.h"
using namespace std;

template<class T> class RepoFile :public RepoTemplate<Car>
{
private:
	const char* fileName;
public:
	RepoFile();
	RepoFile(const char*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, const T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFile();
};


template<class T> RepoFile<T>::RepoFile() :RepoTemplate() {
	fileName = "";
}

template<class T> RepoFile<T>::RepoFile(const char* file) : RepoTemplate<T>() {
	loadFromFile(file);
}

template<class T> RepoFile<T>::~RepoFile() {
}


template<class T> void RepoFile<T>::loadFromFile(const char* file) {
	elem.clear();
	fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			T c(name, licensePlate, status);
			elem.push_back(c);
		}
	}
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	f.close();
}

template<class T> void RepoFile<T>::saveToFile() {
	ofstream f(this->fileName);
	for (int i = 0; i < elem.size(); i++)
		if (i == elem.size() - 1)
			f << getItemFromPos(i).getName() << " " << getItemFromPos(i).getLicensePlate() << " " << getItemFromPos(i).getStatus();
		else
			f << getItemFromPos(i);
	f.close();
}

template<class T> int RepoFile<T>::addElem(T e) {
	int rez = RepoTemplate<T>::addElem(e);
	saveToFile();
	return rez;
}

template<class T> int RepoFile<T>::delElem(T e) {
	int rez = RepoTemplate<T>::delElem(e);
	saveToFile();
	return rez;
}

template<class T> void RepoFile<T>::updateElem(T e, const T newE) {
	RepoTemplate<T>::updateElem(e, newE);
	saveToFile();
}