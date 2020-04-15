#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include "RepoTemplate.h"
using namespace std;

template<class T> class RepoFile :public RepoTemplate<T>
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


template<class T> RepoFile<T>::RepoFile() :RepoTemplate<T>() {
	fileName = "";
}

template<class T> RepoFile<T>::RepoFile(const char* file) : RepoTemplate<T>() {
	loadFromFile(file);
}

template<class T> RepoFile<T>::~RepoFile() {
}


template<class T> void RepoFile<T>::loadFromFile(const char* file) {
	RepoTemplate<T>::clear();
	fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* licensePlate = new char[20];
	char* status = new char[20];
	while (!f.eof()) {
		f >> name >> licensePlate >> status;
		if (name != "") {
			T c(name, licensePlate, status);
			RepoTemplate<T>::addElem(c);
		}
	}
	delete[] name;
	delete[] licensePlate;
	delete[] status;
	f.close();
}

template<class T> void RepoFile<T>::saveToFile() {
	ofstream f(this->fileName);
	for (int i = 0; i < RepoTemplate<T>::getSize(); i++)
		if (i == RepoTemplate<T>::getSize() - 1)
			f << RepoTemplate<T>::getItemFromPos(i).getName() << " " << RepoTemplate<T>::getItemFromPos(i).getLicensePlate() << " " << RepoTemplate<T>::getItemFromPos(i).getStatus();
		else
			f << RepoTemplate<T>::getItemFromPos(i);
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