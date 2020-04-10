// Lab6-7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include "Repository.h"
#include "RepoFile.h"
#include "Service.h"
#include "RepoTemplate.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Start tests..." << endl;
	testCar();
	testRepo();
	testService();
	//testRepoFile();
	testServiceParking();
	testRepoTemplate();
	cout << "Tests finished succesfully!" << endl;
	RepoFile repo("Cars.txt");
	Service serv(repo);
	UI ui(serv);
	ui.run();
    return 0;
}

