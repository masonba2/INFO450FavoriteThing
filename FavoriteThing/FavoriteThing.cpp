// Inventory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SportsCars.h"
#include <iostream>
#include <fstream>
using namespace std;

const int LISTSIZE = 25;

int main()
{
	SportsCar **mylist;
	int count = 0 ;
	int i;
	string urlPrompt;
	string response = "Y";

	cout << "Before beginning, please enter a Full-Path Filename for the tracker to save and read from: " << endl;
	cout << "i.e. - c:\\\\users\\\\YourName\\\\Documents\\\\SportsCars.txt" << endl;
	getline(cin, urlPrompt);


	mylist = new SportsCar*[LISTSIZE];

	// read from a file
	ifstream infile(urlPrompt);
	if (infile.good())
	{
		while (!infile.eof())
		{
			string Year, Name, Make, Type;	
			getline(infile, Year, '|');
			if (Year.length())
			{
				getline(infile, Name, '|');
				getline(infile, Make, '|');
				getline(infile, Type, '\n');

				mylist[count] = new SportsCar(stoi(Year), Name, Make, Type);
				count++;
			}
		}
	}

	// enter more???
	cout << "This list has " << count << "sports cars.  Would you like to add more? " << endl;
	cin >> response;


	// get inventory items from user
	while (response == "Y" || response == "y")
	{
		mylist[count] = new SportsCar();
		if (mylist[count]->addVehicle() == 0)
			count++;
		
		cout << "Another one???" << endl;
		cin >> response;
		}

	// now that we have array populated w/ object, show them
	for (i = 0; i < count; i++)
	{
		mylist[i]->displayVehicle();
	}

	//Save to a File
	ofstream outfile(urlPrompt);
	if (!outfile.good())
	{
		cout << "Error, file cannot be opened" << endl;
		return -1;
	}
	// printing to console
	for (i = 0; i < count; i++)
	{
		outfile << mylist[i];
	}

	// cleaning up
	for (i = 0; i < count; i++)
	{
		delete mylist[i];
	}
	delete mylist;


	return 0;
}
