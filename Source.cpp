#define _CRT_SECURE_NO_WARNINGS
#include<iomanip>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<limits>
#include<map>
#include<string>
#include <Windows.h>
#include"Header.h"

using namespace std;

int main() {
	int choice;

	choice = menu();

	while (choice != 4) {
		system("CLS");
		if (choice == 1) {
			itemsPurchased();
		}
		if (choice == 2) {
			item();
		}
		if (choice == 3) {
			histogram();
		}
		cout << endl << "Press any key to continue . . . ";
		while (true) {
			Sleep(1000);
			if (_kbhit()) {
				system("CLS");
				break;
			}
		}
		_getch();
		choice = menu();
	}
}