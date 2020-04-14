#include "stdafx.h"
#include "UI.h"
#include <iostream>
using namespace std;


UI::~UI() {
}

void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Add Car" << endl;
	cout << "\t 2.Print Cars" << endl;
	cout << "\t 3.Delete Car" << endl;
	cout << "\t 4.Update Car" << endl;
	cout << "\t 5.Enter parking" << endl;
	cout << "\t 6.Exit parking" << endl;
	cout << "\t 7.How many cars tried to enter but didn't have space?" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::addCar() {
	Car c;
	cin >> c;
	if (strcmp(c.getStatus(), "liber") == 0 or strcmp(c.getStatus(), "ocupat") == 0)
	{
		int rez = service.addToRepo(c);
		if (rez == -1)
			cout << "The car can't be added!" << endl;
		else if (rez == -2)
			cout << "The car can't be added as 'ocupat' because the parking is full!" << endl;
		else if (rez==0)
			cout << "The car was added succesfully!" << endl;
	}
	else
		cout << "Status must be 'liber' or 'ocupat'" << endl;
}

void UI::printCars() {
	int i = 0;
	while (i < service.getRepoSize())
	{
		Car car = service.getItemFromPos(i);
		cout << car;
		i++;
	}
}

void UI::deleteCar() {
	Car c;
	cin >> c;
	if (strcmp(c.getStatus(), "liber") == 0 or strcmp(c.getStatus(), "ocupat") == 0)
	{
		int rez = service.delFromRepo(c);
		if (rez == -1)
			cout << "The car does not exist!" << endl;
		else if (rez == 0)
			cout << "The car was deleted succesfully!" << endl;
		else if (rez == -2)
			cout << "The car is still in the parking lot!" << endl;
	}
	else
		cout << "Status must be 'liber' or 'ocupat'" << endl;
}

void UI::updateCar() {
	cout << "\t Car to update:" << endl;
	Car c;
	cin >> c;
	if (service.findElemInRepo(c))
	{
		cout << "\t New datas:" << endl;
		Car newC;
		cin >> newC;
		if (strcmp(newC.getStatus(), "liber") == 0 or strcmp(newC.getStatus(), "ocupat") == 0)
		{
			int rez = service.updateInRepo(c, newC);
			if (rez == -2)
				cout << "The car can't be updated as 'ocupat' because the parking is full!" << endl;
		}
		else
			cout << "Status must be 'liber' or 'ocupat'" << endl;
	}
	else
		cout << "The car does not exist!" << endl;
}

void UI::enterParking() {
	char* l = new char[20];
	cout << "License plate: ";
	cin >> l;
	Car c;
	for (int i = 0; i < service.getRepoSize(); i++)
		if (strcmp(service.getItemFromPos(i).getLicensePlate(), l) == 0)
			c = service.getItemFromPos(i);
	delete l;
	if (service.findElemInRepo(c) == true) {
		int rez = service.enterParking(c);
		if (rez == -1)
			cout << "The car is already in the parking!" << endl;
		else if (rez == -2)
			cout << "The parking is full!" << endl;
		else if (rez == 0)
			cout << "The car has entered the parking!" << endl;
	}
	else
		cout << "The car does not exist!" << endl;
}

void UI::exitParking() {
	char* l = new char[20];
	cout << "License plate: ";
	cin >> l;
	Car c;
	for (int i = 0; i < service.getRepoSize(); i++)
		if (strcmp(service.getItemFromPos(i).getLicensePlate(), l) == 0)
			c = service.getItemFromPos(i);
	delete l;
	if (service.findElemInRepo(c) == true) {
		int rez = service.exitParking(c);
		if (rez == -1)
			cout << "The car is not in the parking!" << endl;
		else if (rez==0)
			cout << "The exit was successful!" << endl;
	}
	else
		cout<<"The car does not exist!" << endl;
}

void UI::run() {
	cout << "The number of parking spaces: ";
	int nr;
	cin >> nr;
	service.setParkingNr(nr);
	int option;
	bool works = true;
	while (works != false)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case 1: {
			addCar();
			break;
		}
		case 2: {
			printCars();
			break;
		}
		case 3: {
			deleteCar();
			break;
		}
		case 4: {
			updateCar();
			break;
		}
		case 5: {
			enterParking();
			break;
		}
		case 6: {
			exitParking();
			break;
		}
		case 7: {
			cout << "Answer: " << service.number << endl;
			break;
		}
		case 0: {

			works = false;
			break;
		}
		default: {
			cout << "There is no such option." << endl;
		}
		}
	}
}
