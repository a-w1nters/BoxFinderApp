#include "BoxSearch.h"
#include <string>

#ifndef MENU_H
#define MENU_H


class Menu {
public:
	Menu();
	void findBox();
	void setOutBox();
	void boxList();
	void setInbox();
	void save();


private:
	BoxSearch boxSearch;
	int boxNum;
	
	

};


#endif