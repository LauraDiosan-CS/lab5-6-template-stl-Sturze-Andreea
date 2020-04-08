#include "stdafx.h"
#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() {

}

UI::~UI() {
}

UI::UI(const Service& serv) {
	this->service = serv;
}

void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Add Car" << endl;
	cout << "\t 2.Print Cars" << endl;
	cout << "\t 3.Delete Car" << endl;
	cout << "\t 4.Update Car" << endl;
	cout << "\t 5.Enter the parking" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::addCar() {
	cout << "Name: ";
	char* name = new char[20];
	cin >> name;
	cout << "License plate: ";
	char* licensePlate = new char[20];
	cin >> licensePlate;
	cout << "Status: ";
	char* status = new char[20];
	cin >> status;
	if (strcmp(status, "liber") == 0 or strcmp(status, "ocupat") == 0)
	{
		int rez = service.addToRepo(name, licensePlate, status);
		if (rez == 0)
			cout << "The car can't be added!" << endl;
		else
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
	cout << "Name: ";
	char* name = new char[20];
	cin >> name;
	cout << "License plate: ";
	char* licensePlate = new char[20];
	cin >> licensePlate;
	cout << "Status: ";
	char* status = new char[20];
	cin >> status;
	if (strcmp(status, "liber") == 0 or strcmp(status, "ocupat") == 0)
	{
		int rez = service.delFromRepo(name, licensePlate, status);
		if (rez == -1)
			cout << "The car does not exist!" << endl;
		else if (rez==0)
			cout << "The car was deleted succesfully!" << endl;
	}
	else
		cout << "Status must be 'liber' or 'ocupat'" << endl;
}

void UI::updateCar() {
	cout << "\t Car to update:" << endl;
	cout << "Name: ";
	char* name = new char[20];
	cin >> name;
	cout << "License plate: ";
	char* licensePlate = new char[20];
	cin >> licensePlate;
	cout << "Status: ";
	char* status = new char[20];
	cin >> status;
	Car c(name, licensePlate, status);
	if (service.findCar(c))
	{
		cout << "\t New datas:" << endl;
		cout << "Name: ";
		char* newName = new char[20];
		cin >> newName;
		cout << "License plate: ";
		char* newLicensePlate = new char[20];
		cin >> newLicensePlate;
		cout << "Status: ";
		char* newStatus = new char[20];
		cin >> newStatus;
		if (strcmp(newStatus, "liber") == 0 or strcmp(newStatus, "ocupat") == 0)
			service.updateInRepo(name, licensePlate, status, newName, newLicensePlate, newStatus);
		else
			cout << "Status must be 'liber' or 'ocupat'" << endl;
	}
	else
		cout << "The car does not exist" << endl;
}

void UI::enterParking() {
	Car c;
	cin >> c;
	if (service.findCar(c) == true) {
		int rez = service.enterParking(c);
		if (rez == -1)
			cout << "The car is already in the parking!" << endl;
		else if (rez == -2)
			cout << "The parking is full!" << endl;
		else if (rez == 0)
			cout << "The car has entered the parking!" << endl;
	}
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
