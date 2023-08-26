#ifndef board_H
#include<iostream>
#include"mygraphics.h"
//#include<Windows.h>
#include<time.h>
#include"pieces.h"

using namespace std;

class board{
public:
	int height;
	bool **grid;
public:
	/*BOOL setxy(int x, int y) {// this will set cursor position
		COORD c = { x,y };
		return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
	void delaay(int number_of_seconds) {
		int milli_seconds = 100 * number_of_seconds; // Converting time into milli_seconds  
		clock_t start_time = clock();     // Stroing start time 
		while (clock() < start_time + milli_seconds); // looping till required time is not acheived 
	}*/
	board() {
		height = 0;
		grid = new bool*[58];
		for (int i = 0; i < 58; i++) {
			grid[i] = new bool[35];
			for (int j = 0; j < 36; j++) {
				grid[i][j] = false;
			}
		}
		for (int i = 0; i < 52; i++) {
			grid[i][29] = true;
		}
	}
	void displayGrid() {
		for (int i = 0; i < 54; i++) {
			for (int j = 0; j < 29; j++) {
				gotoxy(6+i, 6+j);
				if (grid[i][j]) {
					cout << char(177);
				}
			}
		}
	}
	void displayGridout() {
		for (int i = 0; i < 54; i++) {
			for (int j = 0; j < 30; j++) {
				gotoxy(70 + i, 6 + j);
				if (grid[i][j]) {
					cout << char(177);
				}
			}
		}
	}

	void displayGameBoard() {	
		//Print upper line of board
		gotoxy(5, 5);
		cout << char(201);
		for (int i = 0; i <= 50; i++) {
			cout << char(205);
		}
		cout << char(187);

		//print left line
		for (int i = 0; i < 30; i++) {
			gotoxy(5, 6 + i);
			cout << char(186);
		}
		//print right line

		for (int i = 0; i < 30; i++) {
			gotoxy(57, 6 + i);
			cout << char(186);
		}
		//print bottom line
		gotoxy(5, 35);
		cout << char(200);
		for (int i = 0; i <= 50; i++) {
			cout << char(205);
		}
		cout << char(188);
	}
	void blank() { // print spaces
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 29; j++) {
				gotoxy(6 + i, 6 + j);
				cout << " ";
			}
		}
	}
	bool lineFill(int row) { // check is given line true
		for (int i = 1; i < 51; i++) {
			if (grid[i][row] == false) {
				return false;
			}
		}
		return true;
	}


	~board() {
		grid == NULL;
	}
};


#endif // !board_H

