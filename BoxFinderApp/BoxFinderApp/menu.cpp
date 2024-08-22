#include <iostream>
#include "menu.h"
#include "BoxSearch.h"
#include <string>



using namespace std;


Menu::Menu(){
	
	boxNum = 0;
	
}
void Menu::findBox() {
	string i;
	cin.clear();
	cout << "Please enter a box number without the DY." << endl;
	cout << "If the box is 32h use the last 4 digits of the box number." << endl;
	cout << flush;
	getline(cin, i);

	boxNum = stoi(i);
	
	if (!cin.fail()) { boxSearch.isValid(boxNum); }
	else { cin.clear(); }
		
}
void Menu::boxList() {
	boxSearch.getBoxlist();
}
void Menu::setOutBox() {
	string i;
	cout << "Please enter the box number that is out of stock." << endl;
	cout << flush;
	getline(cin, i);

	boxNum = stoi(i);
	if (!cin.fail()) {
		boxSearch.setOb(boxNum);
	}
	else {
		cin.clear();
	}

	
}
void Menu::setInbox() {
	string i;
	cout << "Please enter the box number that is in stock." << endl;
	cout << flush;
	getline(cin, i);
	boxNum = stoi(i);
	if (!cin.fail()) {
		boxSearch.setIb(boxNum);

	}
	else {
		cin.clear();
	}
}
void Menu::save() {
	boxSearch.save();
}

