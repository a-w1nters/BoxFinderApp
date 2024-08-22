// BoxFinderApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "menu.h"
#include <conio.h>
#include <cwchar>
#include <Windows.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{   
    //set console attributes
    int k = 10;
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 400;
    fontex.dwFontSize.X = 23;
    fontex.dwFontSize.Y = 23;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    SetConsoleTextAttribute(hOut, k);
    HWND console = GetConsoleWindow();
   
    MoveWindow(console, 400, 200, 800, 400, true);
    system("cls");
    
    string menuChoice;
    Menu menu;
    int i = 0;
    cout << "Welcome to the box finder app." << endl;
    cout << "Menu Options: " << endl;
    cout << "1. Find box" << endl;
    cout << "2. Set oob(out of box)" << endl;
    cout << "3. Get boxlist" << endl;
    cout << "4. Quit" << endl;
    cout << "Please type the option you want to use without the numbers." << endl;
    cout << flush;
    getline(cin, menuChoice);
    //main program loop.
    if (!cin.fail()) {


        while (i != 1) {
            system("cls");
            if (menuChoice == "Find box" || menuChoice == "find box" || menuChoice == "1") {
                menuChoice = "";
                system("cls");
                
                 menu.findBox();
                
                string t;
                cout << "Would you like to find another box? please type y or n" << endl;
                getline(cin, t);
                if (t == "y" || t == "Y") {
                    menuChoice = "1";
                    i = 0;
                }
                else if (t == "n" || t == "N") {
                    cin.clear();
                    system("cls");
                    cout << "Welcome to the box finder app." << endl;
                    cout << "Menu Options: " << endl;
                    cout << "1. Find box" << endl;
                    cout << "2. Set oob(out of box)" << endl;
                    cout << "3. Get boxlist" << endl;
                    cout << "4. Quit" << endl;
                    cout << "Please enter an option number" << endl;
                    cout << flush;
                    getline(cin, menuChoice);

                }
            }
            else if (menuChoice == "Get boxlist" || menuChoice == "get boxlist") {
                menu.boxList();
                menuChoice = "";
                system("cls");
                cout << "Welcome to the box finder app." << endl;
                cout << "Menu Options: " << endl;
                cout << "1. Find box" << endl;
                cout << "2. Set oob(out of box)" << endl;
                cout << "3. Get boxlist" << endl;
                cout << "4. Quit" << endl;
                cout << "Please enter an option number" << endl;
                cout << flush;
                getline(cin, menuChoice);

            }
            else if (menuChoice == "set oob" || menuChoice == "Set oob" || menuChoice == "2") {
                string t;
                cout << "Would you like to set a box out of stock or in stock?" << endl;
                cout << "please type inbox to set a box in stock or type outbox to set a box \nout of stock." << endl;
                cout << flush;
                getline(cin, t);
                
                if (t == "inbox") {
                    t = "";
                    system("cls");
                    menu.setInbox();
                    cout << "Would you like to set another box? please type y or n." << endl;
                    cout << flush;
                    getline(cin, t);
                    if (t == "y" || t == "Y") {
                        menuChoice = "2";
                        i = 0;
                        
                    }
                    else if (t == "n" || t == "N") {
                        menu.save();
                        cin.clear();
                        system("cls");
                        cout << "Welcome to the box finder app." << endl;
                        cout << "Menu Options: " << endl;
                        cout << "1. Find box" << endl;
                        cout << "2. Set oob(out of box)" << endl;
                        cout << "3. Get boxlist" << endl;
                        cout << "4. Quit" << endl;
                        cout << "Please enter an option number:" << endl;
                        cout << flush;
                        getline(cin, menuChoice);
                    }
                }
                else if(t == "outbox") {
                    t = "";
                    system("cls");
                    menu.setOutBox();

                    cout << "Would you like to set another box? please type y or n." << endl;
                    cout << flush;
                    getline(cin, t);

                    if (t == "y" || t == "Y") {
                        menuChoice = "2";
                        i = 0;
                    }
                    else if (t == "n" || t == "N") {
                        menu.save();
                        cin.clear();
                        system("cls");
                        cout << "Welcome to the box finder app." << endl;
                        cout << "Menu Options: " << endl;
                        cout << "1. Find box" << endl;
                        cout << "2. Set oob(out of box)" << endl;
                        cout << "3. Get boxlist" << endl;
                        cout << "4. Quit" << endl;
                        cout << "Please enter an option number:" << endl;
                        cout << flush;
                        getline(cin, menuChoice);
                    }
                    
                }

            }
            else if (menuChoice == "Quit" || menuChoice == "quit") {    
                
                cout << "Goodbye!" << endl;
                cout << "Press any key to quit program" << endl;
                _getch();
                i = 1;
            }
            else {
                cout << "Please enter a valid menu choice." << endl;
                _getch();
                cin.clear();
                system("cls");
                cout << "Welcome to the box finder app." << endl;
                cout << "Menu Options: " << endl;
                cout << "1. Find box" << endl;
                cout << "2. Set oob(out of box)" << endl;
                cout << "3. Get boxlist" << endl;
                cout << "4. Quit" << endl;
                cout << "Please enter an option number" << endl;
                cout << flush;
                getline(cin, menuChoice);               

            }



        }
    }
    else {

        cin.clear(); 
    }

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
