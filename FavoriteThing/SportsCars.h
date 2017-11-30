#pragma once
#include <string>
using namespace std;

class SportsCar
{
private:
	string Name;
	string Make; 
	string Type;
	int Year;
	
public:
	int addVehicle();
	void displayVehicle();
	SportsCar();
	SportsCar(int y, string t, string n, string m);

	friend ofstream& operator<<(ofstream &fs, SportsCar *item);
};
