#include "BoxSearch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream> 
using namespace std;

BoxSearch::BoxSearch() {	
	boxNum = 0;
	outBox = 0;
	inBox = 0;
	string s;
	ifstream oobFile("oob.txt");
	int i = 0;
	
	al = sizeof(boxList) / sizeof(boxList[0]);
	doesExist = 0;
	


	if (oobFile) {
		while (getline(oobFile, s)) {	
				
				outBoxList[i] = s[0];
				i++;
		}
		oobFile.close();
	}
	else {
		ofstream oob_file("oob.txt");

		for (int i = 0; i < al; i++) {
			outBoxList[i] = 'n';
			oob_file << outBoxList[i] << "\n";
			
		}
		
	}
	
	
}
void BoxSearch::save() {
	remove("oob.txt");	

	ofstream oobFile("oob.txt");	
	
	
	if (oobFile.is_open()) {
		for (int i = 0; i < al; i++) {
			
			oobFile << outBoxList[i] << "\n";

		}
	}
}
void BoxSearch::isValid(int b)
{
	boxNum = b;
	doesExist = 0;

	for (int i = 0; i < al; i++) {

		if (boxList[i] == boxNum) {
			doesExist = 1;
			break;
		}

	}
	if (doesExist == 1) {
		getBoxLocation();
		
	}
	else if(doesExist == 0) {
		cout << "Please enter a valid box number." << endl;
	}

	 
	
}
void BoxSearch::setOb(int b) {
	
	outBox = b;
	for (int i = 0; i < al; i++) {

		if (boxList[i] == outBox) {

			outBoxList[i] = 'y';
			cout << "you have set DY" << outBox << " to out of stock." << endl;
			break;

		}
		

	}
}

void BoxSearch::setIb(int b) {
	inBox = b;
	for (int i = 0; i < al; i++) {
		if (boxList[i] == inBox) {

			outBoxList[i] = 'n';
			cout << "You have set DY" << inBox << " to in stock." << endl;
			break;

		}
	}

}




void BoxSearch::getBoxlist(){
	for (int i = 0; i < al; i++) {
		cout << "DY" << boxList[i] << endl;
		isValid(boxList[i]);		
	}
	_getch();
}
void BoxSearch::getOob(){
	for (int i = 0; i < al; i++) {
		
		if (outBoxList[i] == 'y' && boxNum == boxList[i]) {
			cout << "DY" << boxList[i] << " is currently out." << endl;
			break;
		}
		else if (outBoxList[i] == 'n' && boxNum == boxList[i]) {
			cout << "DY" << boxList[i] << " is in stock." << endl;
			break;
		}


	}

}

void BoxSearch::getBoxLocation(){
	
	
		if (boxNum == 10005) {
			cout << "Box number: DY" << boxNum << endl;
			cout << "Type: Carton" << endl;
			cout << "Location: " << 2 << "-C" << endl;
			cout << "Alternate: " << 1 << "-A" << endl;
			getOob();
		}
		else if (boxNum == 10007 || boxNum == 54153) {
			switch (boxNum) {
			case 10007:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 3 << "-C" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				//cout << "Carton telescopes with DY10041" << endl;
				getOob();
				break;
			case 54153:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 3 << "-B" << endl;
				cout << "Alternate: " << 52 << "-C" << endl;
				//cout << "Carton telescopes with DY10040" << endl;
				getOob();
				break;
			}

		}
		else if (boxNum == 10000 || boxNum == 10002 || boxNum == 10004 || boxNum == 10006) {
			switch (boxNum) {
			case 10000:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Insert" << endl;
				cout << "Location: " << 2 << "-B" << endl;
				cout << "Alternate: " << 68 << "-A" << endl;
				//cout << "Carton telescopes with DY10041" << endl;
				getOob();
				break;
			case 10002:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Insert" << endl;
				cout << "Location: " << 2 << "-B" << endl;
				cout << "Alternate: " << 68 << "-A" << endl;
				//cout << "Carton telescopes with DY10040" << endl;
				getOob();
				break;
			case 10004:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Insert" << endl;
				cout << "Location: " << 2 << "-B" << endl;
				cout << "Alternate: " << 68 << "-B" << endl;
				//cout << "Carton telescopes with DY10043" << endl;
				getOob();
				break;
			case 10006:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Insert" << endl;
				cout << "Location: " << 68 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				//cout << "Carton telescopes with DY10042" << endl;
				getOob();
				break;			

			}
		}
		else if (boxNum == 10023) {
			cout << "Box number: DY" << boxNum << endl;
			cout << "Type: Carton" << endl;
			cout << "Location: " << 4 << "-B" << endl;
			cout << "Alternate: " << 3 << "-B" << endl;
			getOob();
		}
		else if (boxNum == 10024 || boxNum == 10032 || boxNum == 10033) {
			switch (boxNum) {
			case 10024:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 5 << "-C" << endl;
				cout << "Alternate: " << "none" << endl;
				getOob();
				break;
			case 10032:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 5 << "-D" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10033" << endl;
				getOob();
				//getBoxLocation();
				break;
			case 10033:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 5 << "-D" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10032" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10036 || boxNum == 10037) {
			switch (boxNum) {
			case 10036:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 6 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10037" << endl;
				getOob();
				break;
			case 10037:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 6 << "-C" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10036" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10040 || boxNum == 10041 || boxNum == 10042 || boxNum == 10043 || boxNum == 10044 || boxNum == 10045 || boxNum == 10046 || boxNum == 10047) {
			switch (boxNum) {
			case 10040:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-A" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10041" << endl;
				getOob();
				break;
			case 10041:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-A" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10040" << endl;
				getOob();
				break;
			case 10042:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-B" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10043" << endl;
				getOob();
				break;
			case 10043:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-B" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10042" << endl;
				getOob();
				break;
			case 10044:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-C" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10045" << endl;
				getOob();
				break;
			case 10045:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-C" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10044" << endl;
				getOob();
				break;
			case 10046:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-D" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes wwith DY10047" << endl;
				getOob();
				break;
			case 10047:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 7 << "-D" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10048 || boxNum == 10049 || boxNum == 10050 || boxNum == 10051 || boxNum == 10062 || boxNum == 10086) {

			switch (boxNum) {
			case 10048:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-A" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10049" << endl;
				getOob();
				break;

			case 10049:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-A" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				cout << "Carton telescopes with DY10048" << endl;
				getOob();
				break;
			case 10050:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10051" << endl;
				getOob();
				break;
			case 10051:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10050" << endl;
				getOob();
				break;
			case 10062:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-C" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			case 10086:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 8 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;

				
			}

			


		}
		else if (boxNum == 10151 || boxNum == 10307 || boxNum == 10308 || boxNum == 10309) {
			switch (boxNum) {
			case 10151:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 9 << "-A" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			case 10307:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 9 << "-B" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			case 10308:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 9 << "-C" << endl;
				cout << "Alternate: " << 2 << "-A" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			case 10309:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 9 << "-D" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			}

		}
		else if (boxNum == 10410 || boxNum == 10417 || boxNum == 10418 || boxNum == 10589 || boxNum == 10590) {
			switch (boxNum) {
			case 10410:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 10 << "-A" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY10046" << endl;
				getOob();
				break;
			case 10417:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 10 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10418" << endl;
				getOob();
				break;
			case 10418:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 10 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				cout << "Carton telescopes with DY10417" << endl;
				getOob();
				break;
			case 10589:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 10 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10590" << endl;
				getOob();
				break;
			case 10590:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 10 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10589" << endl;
				getOob();
				break;
			}

		}
		else if (boxNum == 10593 || boxNum == 10594 || boxNum == 10595 || boxNum == 10596) {
			switch (boxNum) {
			case 10593:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 11 << "-A" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY10594" << endl;
				getOob();
				break;
			case 10594:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 11 << "-B" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY10593" << endl;
				getOob(); 
				break;
			case 10595:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 11 << "-C" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY10596" << endl;
				getOob();
				break;
			case 10596:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 11 << "-D" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY10595" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10597 || boxNum == 10598 || boxNum == 10599 || boxNum == 10600) {
			switch (boxNum) {
			case 10597:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 12 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10598" << endl;
				getOob();
				break;
			case 10598:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 12 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10597" << endl;
				getOob();
				break;
			case 10599:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 12 << "-B" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10600" << endl;
				getOob();
				break;
			case 10600:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 12 << "-A" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10601 || boxNum == 10897 || boxNum == 10663 || boxNum == 10017 || boxNum == 10614) {
			switch (boxNum) {
			case 10601:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 13 << "-A" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10602" << endl;
				getOob();
				break;
			case 10897:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 13 << "-B" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 10663:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 13 << "-D" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 10017:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 13 << "-D" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 10614:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 13 << "-C" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10602 || boxNum == 11007 || boxNum == 11140 || boxNum == 11001) {
			switch (boxNum) {
			case 10602:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 14 << "-A" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 11001:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 14 << "-B" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 11007:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 14 << "-C" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 11140:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 14 << "-D" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			}

		}
		else if (boxNum == 11085 || boxNum == 11075 || boxNum == 11105 || boxNum == 11106) {
			switch (boxNum) {
			case 11085:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 15 << "-A" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11086" << endl;
				getOob();
				break;
			case 11075:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Corrugated Lid" << endl;
				cout << "Location: " << 15 << "-B" << endl;
				cout << "Alternate: " << "None" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			case 11105:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 15 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11106" << endl;
				getOob();
				break;
			case 11106:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 15 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11105" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11086 || boxNum == 11242 || boxNum == 11243 || boxNum == 11247) {
			switch (boxNum) {
			case 11086:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 16 << "-A" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11085" << endl;
				getOob();
				break;
			case 11242:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 16 << "-B" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11243" << endl;
				getOob();
				break;
			case 11243:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 16 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11242" << endl;
				getOob();
				break;
			case 11247:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 16 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11248" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11248 || boxNum == 11249 || boxNum == 11250 || boxNum == 10003) {
			switch (boxNum) {
			case 11248:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 17 << "-D" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11247" << endl;
				getOob();
				break;
			case 11249:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 17 << "-C" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11250" << endl;
				getOob();
				break;
			case 11250:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 17 << "-B" << endl;
				cout << "Alternate: " << "None" << endl;
				cout << "Carton telescopes with DY11249" << endl;
				getOob();
				break;
			case 10003:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 17 << "-A" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				//cout << "Carton telescopes with DY10599" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11251 || boxNum == 11252) {
			switch (boxNum) {
			case 11251:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 18 << "-D" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11252" << endl;
				getOob();
				break;
			case 11252:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 18 << "-C" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11252" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11253 || boxNum == 11254 || boxNum == 11255 || boxNum == 11256) {
			switch (boxNum) {
			case 11253:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 19 << "-A" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11254" << endl;
				getOob();
				break;
			case 11254:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 19 << "-B" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11253" << endl;
				getOob();
				break;
			case 11255:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 19 << "-C" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11256" << endl;
				getOob();
				break;
			case 11256:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 19 << "-D" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11255" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11257 || boxNum == 11258 || boxNum == 11576 || boxNum == 11577) {
			switch (boxNum) {
			case 11257:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 20 << "-A" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY11258" << endl;
				getOob();
				break;
			case 11258:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 20 << "-B" << endl;
				cout << "Alternate: " << 6 <<"-A" << endl;
				cout << "Carton telescopes with DY11257" << endl;
				getOob();
				break;
			case 11576:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 20 << "-C" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11577" << endl;
				getOob();
				break;
			case 11577:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 20 << "-D" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11576" << endl;
				getOob();
				break;
		}

		}
		else if (boxNum == 11261 || boxNum == 11578 || boxNum == 11579 || boxNum == 11657) {
			
			switch (boxNum) {
			case 11261:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 21 << "-A" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11262" << endl;
				
				getOob();
				break;
			case 11578:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 21 << "-B" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11579" << endl;
				cout << "Top/Bottom: Top" << endl;
				getOob();
				break;
			case 11579:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 21 << "-C" << endl;
				cout << "Alternate: "<< 5 << "-A" << endl;
				cout << "Carton telescopes with DY11578" << endl;
				cout << "Top/Bottom: Bottom" << endl;
				getOob();
				break;
			case 11657:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 21 << "-D" << endl;
				cout << "Alternate: " << 4 <<"-A" << endl;
				cout << "Carton telescopes with DY11658" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 11262 || boxNum == 11581 || boxNum == 11580 || boxNum == 11658) {
			
			switch (boxNum) {
			case 11262:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 22 << "-A" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11261" << endl;
				getOob();
				break;
			case 11581:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 22 << "-B" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY11580" << endl;
				getOob();
				break;
			case 11580:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 22 << "-C" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY11581" << endl;
				getOob();
				break;
			case 11658:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 22 << "-D" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton telescopes with DY11657" << endl;
				getOob();
				break;
			}
		}
		else if (boxNum == 10603 || boxNum == 11671 || boxNum == 11672 || boxNum == 11673) {
			
			switch(boxNum){
			case 10603:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 23 << "-A" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY10604" << endl;
				getOob();
				break;
			case 11671:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 23 << "-C" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY11670" << endl;
				getOob();
				break;
			case 11672:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 23 << "-D" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11673" << endl;
				getOob();
				break;
			case 11673:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 23 << "-D" << endl;
				cout << "Alternate: " << 5 << "-A" << endl;
				cout << "Carton telescopes with DY11672" << endl;
				getOob();
				break;
			
			
			}
		}
		else if (boxNum == 10604 || boxNum == 11670 || boxNum == 11713 || boxNum == 11712) {
			
			switch (boxNum) {
			case 10604:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 24 << "-A" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 11670:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 24 << "-B" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 11713:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 24 << "-D" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 11712:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 24 << "-C" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			
			}
		}
		else if (boxNum == 11665 || boxNum == 11664 || boxNum == 11666 || boxNum == 10021 || boxNum == 10022) {
			switch (boxNum) {
			case 11665:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 25 << "-A" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 11664:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 25 << "-B" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 11666:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 25 << "-C" << endl;
				cout << "Alternate: " << "none" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 10021:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 25 << "-D" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10022:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 25 << "-D" << endl;
				cout << "Alternate: " << 2 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 11744 || boxNum == 11714 || boxNum == 11563 || boxNum == 11564) {
			switch (boxNum) {
			case 11744:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 26 << "-A" << endl;
				cout << "Alternate: " << "none" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 11714:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 26 << "-B" << endl;
				cout << "Alternate: " << "none" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 11563:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 26 << "-C" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				cout << "Carton telescopes with DY11564" << endl;
				getOob();
				break;
			case 11564:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 26 << "-D" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				cout << "Carton telescopes with DY11563" << endl;
				getOob();
				break;

			}
		} 
		else if (boxNum == 11745 || boxNum == 11667 || boxNum == 11260 || boxNum == 11259) {
			switch (boxNum) {
			case 11745:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 27 << "-A" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 11667:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 27 << "-B" << endl;
				cout << "Alternate: " << "none" << endl;
				cout << "Carton may be discontinued. Ask superviser for more details." << endl;
				getOob();
				break;
			case 11260:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 27 << "-D" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				cout << "Carton telescopes with DY11259" << endl;
				getOob();
				break;
			case 11259:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 27 << "-C" << endl;
				cout << "Alternate: " << 4 << "-A" << endl;
				cout << "Carton telescopes with DY11260" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 11748 || boxNum == 54026 || boxNum == 54395 || boxNum == 54498) {
			switch (boxNum) {
			case 11748:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 28 << "-A" << endl;
				cout << "Alternate: " << 6 << "-A" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 54026:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 28 << "-B" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
			//	cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 54395:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 28 << "-C" << endl;
				cout << "Alternate 1: " << 42 << "-B" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 54498:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 28 << "-D" << endl;
				cout << "Alternate 1: " << 38 << "-B" << endl;
				cout << "Alternate 2: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 54515 || boxNum == 54555 || boxNum == 54576
			|| boxNum == 60315 || boxNum == 60515) {
			switch (boxNum) {
			case 54515:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 29 << "-A" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 54555:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 29 << "-A" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
			    //cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 54576:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 29 << "-B" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 60315:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 29 << "-C" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 60515:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 29 << "-D" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 60615 || boxNum == 65775 || boxNum == 65625 || boxNum == 65675) {
			switch (boxNum) {
			case 60615:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 30 << "-A" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 65775:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 30 << "-B" << endl;
				cout << "Alternate: " << 3 << "-B" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 65625:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 30 << "-C" << endl;
				cout << "Alternate: " << 38 << "-B" << endl;
				cout << "Alternate 2: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 65675:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 30 << "-D" << endl;
				cout << "Alternate: " << 38 << "-B" << endl;
				cout << "Alternate 2: " << 3 << "-A" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10239 || boxNum == 10240 || boxNum == 10241 || boxNum == 10268 || boxNum == 10668 || boxNum == 60200 || boxNum == 65575) {
			switch (boxNum) {
			case 10239:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10240:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10241:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-B" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10268:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-B" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10668:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-C" << endl;
				cout << "Alternate: " << 40 << "-C" << endl;				
				getOob();
				break;
			case 60200:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-C" << endl;
				cout << "Alternate: " << 3 << "-A" << endl;				
				getOob();
				break;
			case 65575:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 31 << "-D" << endl;
				cout << "Alternate: " << 38 << "-B" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 1266 || boxNum == 2138 || boxNum == 10001 || boxNum == 65725) {
			switch (boxNum) {
			case 1266:
				cout << "Box number: 32H" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 32 << "-A" << endl;
				cout << "Alternate: " << 46 << "-D" << endl;				
				getOob();
				break;
			case 2138:
				cout << "Box number: 32H" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 32 << "-B" << endl;
				cout << "Alternate: " << 46 << "-D" << endl;
				getOob();
				break;
			case 10001:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 32 << "-C" << endl;
				cout << "Alternate: " << 38 << "-B" << endl;
				cout << "Alternate 2: " << 2 << "-B" << endl;
				getOob();
				break;
			case 65725:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 32 << "-D" << endl;				
				cout << "Alternate: " << 3 << "-B" << endl;
				cout << "Alternate 2: " << 38 << "-B" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10008 || boxNum == 10009 || boxNum == 10013 || boxNum == 10014 || boxNum == 10025 || boxNum == 10026 || boxNum == 10027 || boxNum == 10028) {
			switch (boxNum) {
			case 10008:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-A" << endl;
				cout << "Alternate: " << 45 << "-C" << endl;
				getOob();
				break;
			case 10009:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-A" << endl;
				cout << "Alternate: " << 45 << "-C" << endl;
				getOob();
				break;
			case 10013:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-B" << endl;
				cout << "Alternate: " << 45 << "-C" << endl;
				getOob();
				break;
			case 10014:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-B" << endl;
				cout << "Alternate: " << 45 << "-C" << endl;
				getOob();
				break;
			case 10025:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-C" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10026:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-C" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				cout << "Alternate 2: " << 5 << "-B" << endl;
				getOob();
				break;
			case 10027:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-D" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				getOob();
				break;
			case 10028:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 33 << "-D" << endl;
				cout << "Alternate: " << 45 << "-D`" << endl;
				getOob();
				break;


			}
		}
		else if (boxNum == 10230 || boxNum == 10231 || boxNum == 10232 || boxNum == 10029 || boxNum == 10031 || boxNum == 10038 || boxNum == 10039 || boxNum == 10234 || boxNum == 10156) {
			switch (boxNum) {
			case 10230:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				getOob();
				break;
			case 10231:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 10232:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 10029:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-B" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10031:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-B" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10039:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-C" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				cout << "Carton telescopes with DY10038" << endl;
				getOob();
				break;
			case 10038:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-C" << endl;
				cout << "Alternate: " << 45 << "-D" << endl;
				cout << "Carton telescopes with DY10039" << endl;
				getOob();
				break;
			case 10234:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-D" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10156:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 34 << "-D" << endl;
				cout << "Alternate: " << 44 <<"-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10235 || boxNum == 10236 || boxNum == 10251 || boxNum == 10252 || boxNum == 10259 ||
			boxNum == 10256 || boxNum == 10267 || boxNum == 10272) {
			switch (boxNum) {
			case 10235:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 10236:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 10251:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-B" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 10252:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-B" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10259:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-C" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10256:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-C" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10267:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-D" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10272:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 35 << "-D" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10237 || boxNum == 10238 || boxNum == 10273 || boxNum == 10274 || 
			boxNum == 10275 || boxNum == 10276 || boxNum == 10277 || boxNum == 10335) {
			switch (boxNum) {
			case 10237:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 10238:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-A" << endl;
				cout << "Alternate: " << 44 << "-C" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 10273:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-B" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 10274:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-B" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10275:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-C" << endl;
				cout << "Alternate: " << 42 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10276:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-C" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				cout << "Carton telescopes with DY10277" << endl;
				getOob();
				break;
			case 10277:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-D" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				cout << "Carton telescopes with DY10276" << endl;
				getOob();
				break;
			case 10335:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 36 << "-D" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 10243 || boxNum == 10244 || boxNum == 10245 ||
			boxNum == 10336 || boxNum == 10337 || boxNum == 10617 || boxNum == 10618 || 
			boxNum == 10619 || boxNum == 10620) {
			switch (boxNum) {
			case 10243:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-A" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 10244:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-A" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 10245:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-A" << endl;
				cout << "Alternate: " << 43 << "-C" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 10336:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-B" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;			
			case 10337:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-B" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10617:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-C" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10618:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-C" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10619:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-D" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10620:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 37 << "-D" << endl;
				cout << "Alternate: " << 41 << "-C" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 11245 || boxNum == 11246 || boxNum == 11478 
			|| boxNum == 11479 || boxNum == 11480 || boxNum == 10727) {
			switch (boxNum) {
			case 11245:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 49 << "-C" << endl;
				//cout << "Carton telescopes with DY10603" << endl;
				getOob();
				break;
			case 11246:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 49 << "-C" << endl;
				//cout << "Carton telescopes with DY11671" << endl;
				getOob();
				break;
			case 11478:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 51 << "-D" << endl;
				//cout << "Carton telescopes with DY11712" << endl;
				getOob();
				break;
			case 11479:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 52 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 11480:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 52 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;
			case 10727:
				cout << "Box number: DY" << boxNum << endl;
				cout << "Type: Carton" << endl;
				cout << "Location: " << 38 << "-B" << endl;
				cout << "Alternate: " << 48 << "-B" << endl;
				//cout << "Carton telescopes with DY11713" << endl;
				getOob();
				break;

			}
		}
		else if (boxNum == 65810 || boxNum == 65811 || boxNum == 65812 || 
			 boxNum == 65813 || boxNum == 65814 || boxNum == 65815 
			 || boxNum == 65816 || boxNum == 65817 || boxNum == 65818 || boxNum == 65819 || 
			 boxNum == 65820 || boxNum == 65821) {
				switch (boxNum) {
				case 65810:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 66 << "-A" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65811:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 66 << "-A" << endl;
					//cout << "Carton telescopes with DY11671" << endl;
					getOob();
					break;
				case 65812:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 66 << "-B" << endl;
					//cout << "Carton telescopes with DY11712" << endl;
					getOob();
					break;
				case 65813:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 66 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65814:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 66 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65815:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 66 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65816:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 64 << "-A" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65817:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 66 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65818:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 66 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65819:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 67 << "-A" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65820:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 67 << "-A" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65821:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 38 << "-A" << endl;
					cout << "Alternate: " << 67 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;

				}
		}
		else if (boxNum == 65804 || boxNum == 65805 || boxNum == 65806 || boxNum == 65807 ||
			boxNum == 65808 || boxNum == 65809 || boxNum == 65801
			|| boxNum == 65802 || boxNum == 65803 || boxNum == 60080 || boxNum == 60083 ||
			boxNum == 60087 || boxNum == 60100 || boxNum == 60105 || boxNum == 60110 || boxNum == 60120 ||
			boxNum == 60125 || boxNum == 60130 || boxNum == 60140 || boxNum == 60150 ||
			boxNum == 60160 || boxNum == 60163 || boxNum == 60164 || boxNum == 11271 || boxNum == 11272 || boxNum == 11273 || boxNum == 11274
			|| boxNum == 11275 || boxNum == 11276 || boxNum == 11277 ||
			boxNum == 11279 || boxNum == 11336 || boxNum == 65798 || boxNum == 65799 || boxNum == 65800 || boxNum == 65801 || boxNum == 65802 || boxNum == 65803)
			{
				switch (boxNum) {
				case 65803:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 63 << "-A" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65802:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 63 << "-A" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65801:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 65 << "-C" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65800:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 62 << "-A" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65799:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 62 << "-A" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65798:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 65 << "-B" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65804:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 65 << "-C" << endl;
					//cout << "Carton telescopes with DY10603" << endl;
					getOob();
					break;
				case 65805:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 63 << "-A" << endl;
					//cout << "Carton telescopes with DY11671" << endl;
					getOob();
					break;
				case 65806:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 64 << "-A" << endl;
					//cout << "Carton telescopes with DY11712" << endl;
					getOob();
					break;
				case 65807:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 64 << "-A" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65808:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 65 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 65809:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-A" << endl;
					cout << "Alternate: " << 65 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60080:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 58 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60083:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 58 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60087:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 58 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60100:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 58 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60105:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 58 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60110:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 59 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60120:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 59 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60125:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 59 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60130:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 59 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60140:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 59 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60150:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 59 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60160:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 60 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60163:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 60 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 60164:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 60 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11271:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 50 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11272:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 50 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11273:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 50 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11274:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 50 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11275:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 51 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11276:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 51 << "-B" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11277:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 51 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11279:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-C" << endl;
					cout << "Alternate: " << 51 << "-C" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				case 11336:
					cout << "Box number: DY" << boxNum << endl;
					cout << "Type: Carton" << endl;
					cout << "Location: " << 39 << "-B" << endl;
					cout << "Alternate: " << 51 << "-D" << endl;
					//cout << "Carton telescopes with DY11713" << endl;
					getOob();
					break;
				}
		}
		else if (boxNum == 11266 || boxNum == 11268 || boxNum == 11269 || boxNum == 11270 ||
					boxNum == 10800 || boxNum == 10801 || boxNum == 10802
					|| boxNum == 10803 || boxNum == 11045 || boxNum == 11047 || boxNum == 60003 ||
					boxNum == 60004 || boxNum == 60005 || boxNum == 60008 || boxNum == 60007 
					|| boxNum == 60010 || boxNum == 60015 || boxNum == 60045 || boxNum == 60050 || boxNum == 60055 || boxNum == 60060 || 
					boxNum == 60070 || boxNum == 65786 || boxNum == 65787 || boxNum == 65788 || boxNum == 65789 || boxNum == 65790 
					|| boxNum == 65791 || boxNum == 65792 || boxNum == 65793 || boxNum == 65794 || boxNum == 65795 || boxNum == 65796 || boxNum == 65797) {
					switch (boxNum) {
						case 11266:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 49 << "-D" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 11268:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 49 << "-D" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 11269:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 50 << "-B" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 11270:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 50 << "-B" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 10800:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 48 << "-C" << endl;
							cout << "Alternate 2: " << 5 << "-B" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 10801:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 48 << "-C" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 10802:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 48 << "-D" << endl;
							//cout << "Carton telescopes with DY10603" << endl;
							getOob();
							break;
						case 10803:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 48 << "-D" << endl;
							//cout << "Carton telescopes with DY11671" << endl;
							getOob();
							break;
						case 11045:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 49 << "-B" << endl;
							//cout << "Carton telescopes with DY11712" << endl;
							getOob();
							break;
						case 11047:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-C" << endl;
							cout << "Alternate: " << 49 << "-B" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60003:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 55 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60004:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 56 << "-D" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60005:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 55 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;						
						case 60007:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 55 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60008:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 56 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60010:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-B" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60015:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-B" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60045:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-C" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60050:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-C" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60055:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-D" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60060:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 57 << "-D" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 60070:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-B" << endl;
							cout << "Alternate: " << 58 << "-B" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65786:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 65 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65787:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 59 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65788:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 59 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65789:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 60 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65790:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 65 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65791:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 60 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65792:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 60 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65793:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 65 << "-B" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65794:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 61 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65795:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 61 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65796:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 61 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						case 65797:
							cout << "Box number: DY" << boxNum << endl;
							cout << "Type: Carton" << endl;
							cout << "Location: " << 40 << "-A" << endl;
							cout << "Alternate: " << 62 << "-A" << endl;
							//cout << "Carton telescopes with DY11713" << endl;
							getOob();
							break;
						}
					
		}
		else if (boxNum == 65778 || boxNum == 65779 || boxNum == 65780 || boxNum == 65781 ||
			boxNum == 65782 || boxNum == 65783 || boxNum == 65784
			|| boxNum == 65785 || boxNum == 65595 || boxNum == 65600 || boxNum == 65615 ||
			boxNum == 54530 || boxNum == 54520 || boxNum == 54450 || boxNum == 54460
			|| boxNum == 54470 || boxNum == 54480 || boxNum == 54490 || boxNum == 54492 || boxNum == 54500 || boxNum == 54510 ||
			boxNum == 10396 || boxNum == 10397 || boxNum == 10395 || boxNum == 54575) {
					//TODO: add shelf 41
					switch (boxNum) {
					case 54575:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 56 << "-D" << endl;
						//cout << "Carton telescopes with DY10603" << endl;
						getOob();
						break;
					case 65778:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 56 << "-A" << endl;
						//cout << "Carton telescopes with DY10603" << endl;
						getOob();
						break;
					case 65779:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 57 << "-A" << endl;
						//cout << "Carton telescopes with DY11671" << endl;
						getOob();
						break;
					case 65780:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 57 << "-A" << endl;
						//cout << "Carton telescopes with DY11712" << endl;
						getOob();
						break;
					case 65781:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 57 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65782:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 58 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65783:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 58 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65784:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 58 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65785:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 59 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65595:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 64 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65600:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 64 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65615:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-A" << endl;
						cout << "Alternate: " << 64 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54530:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 56 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54520:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 56 << "-B" << endl;
						cout << "Alternate 2: " << 5 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54450:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 54 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54460:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54470:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54480:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54490:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54492:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54500:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 55 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54510:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-B" << endl;
						cout << "Alternate: " << 56 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10395:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-C" << endl;
						cout << "Alternate: " << 50 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10396:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-C" << endl;
						cout << "Alternate: " << 51 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10397:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 41 << "-C" << endl;
						cout << "Alternate: " << 51 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;

					}
		}
		else if (boxNum == 65455 || boxNum == 65500 || boxNum == 65503 || boxNum == 65504 ||
			boxNum == 65515 || boxNum == 65505 || boxNum == 65525
			|| boxNum == 65535 || boxNum == 65545 || boxNum == 65551 || boxNum == 65555 
			 || boxNum == 65585 || boxNum == 54345 || boxNum == 54355
			|| boxNum == 54360 || boxNum == 54370 || boxNum == 54380 || boxNum == 54390 || boxNum == 54405 ||
			boxNum == 54410 || boxNum == 54420 || boxNum == 54430 || boxNum == 54440 || boxNum == 10257 || boxNum == 10258 || boxNum == 10261 || boxNum == 10264 || boxNum == 65565) {
					//TODO: add shelf 42
					switch (boxNum) {
					case 65455:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 62 << "-C" << endl;
						//cout << "Carton telescopes with DY10603" << endl;
						getOob();
						break;
					case 65500:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 62 << "-C" << endl;
						//cout << "Carton telescopes with DY11671" << endl;
						getOob();
						break;
					case 65503:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 62 << "-D" << endl;
						//cout << "Carton telescopes with DY11712" << endl;
						getOob();
						break;					
					case 65515:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65505:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 62 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65525:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65535:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65545:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65551:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65555:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 63 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65565:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 64 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65585:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-A" << endl;
						cout << "Alternate: " << 64 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54345:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-B" << endl;
						//cout << "Alternate 2: " << 5 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54355:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54360:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54370:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54380:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54390:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 53 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;					
					case 54405:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 54 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54410:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 54 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54420:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 54 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54430:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 54 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54440:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-B" << endl;
						cout << "Alternate: " << 54 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10257:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-C" << endl;
						cout << "Alternate: " << 49 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10258:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-C" << endl;
						cout << "Alternate: " << 67 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10261:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-C" << endl;
						cout << "Alternate: " << 50 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10264:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 42 << "-C" << endl;
						cout << "Alternate: " << 50 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;

					}
		}
		else if (boxNum == 60170 || boxNum == 60166 || boxNum == 60180 || boxNum == 60190 ||
			boxNum == 65075 || boxNum == 65155 || boxNum == 65200
			|| boxNum == 65251 || boxNum == 65265 || boxNum == 65300 || boxNum == 65355
			|| boxNum == 65400 || boxNum == 54220 || boxNum == 54235
			|| boxNum == 54270 || boxNum == 54290 || boxNum == 54300 || boxNum == 54303 || boxNum == 54310 || boxNum == 54320 ||
			boxNum == 54324 || boxNum == 54328 || boxNum == 54330 || boxNum == 54340 || boxNum == 10246 || boxNum == 10249 || boxNum == 10250 || boxNum == 10254 || boxNum == 10255) {
					//TODO: add shelf 43
					switch (boxNum) {
					case 60170:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 60 << "-D" << endl;
						//cout << "Carton telescopes with DY10603" << endl;
						getOob();
						break;
					case 60166:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 60 << "-C" << endl;
						//cout << "Carton telescopes with DY11671" << endl;
						getOob();
						break;
					case 60180:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 60 << "-D" << endl;
						//cout << "Carton telescopes with DY11712" << endl;
						getOob();
						break;
					case 60190:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65075:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65155:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65200:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 56 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65251:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65265:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65300:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 61 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65355:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 62 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 65400:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-A" << endl;
						cout << "Alternate: " << 62 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54220:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 51 << "-A" << endl;
						//cout << "Alternate 2: " << 5 << "-B" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54235:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54270:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54290:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54300:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 53 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54303:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-C" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54310:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 53 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54320:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 53 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54324:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 54 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54328:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 54 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54330:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 54340:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-B" << endl;
						cout << "Alternate: " << 52 << "-D" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10246:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-C" << endl;
						cout << "Alternate: " << 48 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10249:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-C" << endl;
						cout << "Alternate: " << 48 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10250:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-C" << endl;
						cout << "Alternate: " << 48 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10254:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-C" << endl;
						cout << "Alternate: " << 49 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;
					case 10255:
						cout << "Box number: DY" << boxNum << endl;
						cout << "Type: Carton" << endl;
						cout << "Location: " << 43 << "-C" << endl;
						cout << "Alternate: " << 49 << "-A" << endl;
						//cout << "Carton telescopes with DY11713" << endl;
						getOob();
						break;

					}

		}
		
		
		
		



	
	/*switch (boxNum) {

	case 10000:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Insert" << endl;
		cout << "Location: " << 48 << "-A" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10001:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 32 << "-C" << endl;
		cout << "Alternate 1: " << 2 << "-B" << endl;
		cout << "Alternate 2: " << 38 << "-B" << endl;
		break;
	case 10002:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Insert" << endl;
		cout << "Location: " << 48 << "-A" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10003:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 17 << "-A" << endl;
		cout << "Alternate: " << 5 << "-A" << endl;
		break;
	case 10004:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Insert" << endl;
		cout << "Location: " << 68 << "-B" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10005:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 2 << "-C" << endl;
		cout << "Alternate: " << 1 << "-A" << endl;
		break;
	case 10006:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Insert" << endl;
		cout << "Location: " << 68 << "-C" << endl;
		cout << "Alternate: " << "none" << endl;
		break;
	case 10007:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 3 << "-C" << endl;
		cout << "Alternate: " << 6 << "-A" << endl;
		break;
	case 10008:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-A" << endl;
		cout << "Alternate: " << 45 << "-C" << endl;
		break;
	case 10009:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-A" << endl;
		cout << "Alternate: " << 45 << "-C" << endl;
		break;
	case 10013:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-B" << endl;
		cout << "Alternate: " << 45 << "-C" << endl;
		break;
	case 10014:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-B" << endl;
		cout << "Alternate: " << 45 << "-C" << endl;
		break;
	case 10017:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 13 << "-D" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10021:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 25 << "-D" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10022:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 25 << "-D" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;
	case 10023:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 4 << "-B" << endl;
		cout << "Alternate: " << 3 << "-B" << endl;
		break;
	case 10024:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 5 << "-C" << endl;
		cout << "Alternate: " << "none" << endl;
		break;
	case 10025:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-C" << endl;
		cout << "Alternate 1: " << 5 << "-B" << endl;
		cout << "Alternate 2: " << 45 << "-D" << endl;
		break;
	case 10026:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-C" << endl;
		cout << "Alternate 1: " << 5 << "-B" << endl;
		cout << "Alternate 2: " << 45 << "-D" << endl;
		break;
	case 10027:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-D" << endl;
		cout << "Alternate: " << 45 << "-D" << endl;
		break;
	case 10028:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 33 << "-D" << endl;
		cout << "Alternate: " << 45 << "-D" << endl;
		break;
	case 10029:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 34 << "-B" << endl;
		cout << "Alternate: " << 45 << "-D" << endl;
		break;
	case 10031:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 34 << "-B" << endl;
		cout << "Alternate: " << 45 << "-D" << endl;
		break;
	case 10032:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 5 << "-D" << endl;
		cout << "Alternate: " << 2 << "-A" << endl;
		break;
	case 10033:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 5 << "-D" << endl;
		cout << "Alternate: " << 2 << "-A" << endl;
		break;
	case 10036:
		cout << "Box number: DY" << boxNum << endl;
		cout << "Type: Carton" << endl;
		cout << "Location: " << 6 << "-B" << endl;
		cout << "Alternate: " << 2 << "-B" << endl;
		break;




	}*/

}