#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	void printMenu();
	void addCar();
	void printCars();
	void deleteCar();
	void updateCar();
	void enterParking();
	void exitParking();
public:
	UI(Service &serv) :service(serv) {};
	void run();
	~UI();
};