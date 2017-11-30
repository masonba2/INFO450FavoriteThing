#include "stdafx.h"
#include "SportsCars.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;


int SportsCar::addVehicle()
{
	cout << "what Year? " << endl;
	cin >> Year;
	cin.ignore();
	cin.clear();
	cout << "what Name" << endl;
	getline(cin, Name);  
	cout << "Make?" << endl;
	getline(cin, Make);
	cout << "Type?" << endl;
	getline(cin, Type);
	//TBD - do error checking
	return 0;
}

void SportsCar::displayVehicle()
{
	cout << "Year: " << Year << endl;
	cout << "Name: " << Name << endl;
	cout << "Make: " << Make << endl;
	cout << "Type: " << Type << endl;
}

// default constructor
SportsCar::SportsCar()
{
	Name = "";
	Make = "";
	Year = 0;
	Type = "";
}

// overloaded constructor
SportsCar::SportsCar(int y, string t, string n, string m)
{
	Name = n;
	Make = m;
	Year = y;
	Type = t;
}

ofstream& operator<<(ofstream &fs, SportsCar *item)
{
	fs << item->Name<< "|" << item->Make<< "|" << item->Year << "|" << item->Type<< endl;
	return fs;
}
