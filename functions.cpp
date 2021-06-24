#include<iomanip>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<limits>
#include<map>
#include<string>
#include"Header.h"

using namespace std;
typedef map<string, int> listMap;

auto buildList() {
	listMap items;
	string item;

	ifstream infile;
	infile.open("ItemList.txt");  // opens file for reading

	if (infile.is_open()) {

		while (infile >> item) {  // iterates through the items in the list to increase count for each that is the same.
			++items[item];
		}

		infile.close();
	}
	else {
		cout << "File failed to open." << endl;  // file open fail check
		exit(EXIT_FAILURE);
	}

	return (items);
}

int menu() {
	int choice = 0;

	cout << "1. List all items purchased" << endl; // displays menu
	cout << "2. Number of times purchased" << endl;
	cout << "3. Histogram of items purchased" << endl;
	cout << "4. Exit Program" << endl;
	
	cin >> choice;

	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // verifying integer input.
			cout << "Please enter a valid option." << endl;
			cin >> choice;
		}
		if (!cin.fail()) {
			if ((choice <= 4) && (choice >= 1)) { // verifying input fits in menu choices.
				break;
			}
			else {
				cout << "Please enter a valid option." << endl;
				cin >> choice;
			}
		}
	}

	return(choice);
}

void itemsPurchased() {
	listMap items;
	string item;

	items = buildList();

	for (listMap::iterator p = items.begin(); p != items.end(); ++p) {  // prints the map
		cout << p->first << " " << p->second << endl;
	}

}

void item() {
	listMap items;
	string item, userItem;

	cout << "Item you are searching for? ";  // gets user input for item tot search
	cin >> userItem;

	items = buildList();

	for (listMap::iterator p = items.begin(); p != items.end(); ++p) {  // only outputs matching item from list
		if (p->first == userItem) {
			cout << p->first << " " << p->second << endl;
		}
	}

}

void histogram() {  // displays histogram
	listMap items;
	string item;
	int star;

	ifstream infile;
	ofstream outfile;

	outfile.open("frequency.dat");  // open out file

	items = buildList();

	for (listMap::iterator p = items.begin(); p != items.end(); ++p) {  // puts item list with numbers into file
		outfile << p->first << " " << p->second << endl;
	}
	outfile.close();

	infile.open("frequency.dat");  // opens frequancy.dat file for reading
	if (infile.is_open()) {

		while (infile >> item) {  // prints item followed by number of stars
			infile >> star;
			cout << item << " ";
			for (int i = 1; i <= star; ++i) {
				cout << "*";
			}
			cout << endl;
		}

		infile.close(); // closes file
	}
	else {
		cout << ".dat File failed to open." << endl;  // error checking for file opening or not
		exit(EXIT_FAILURE);
	}

}