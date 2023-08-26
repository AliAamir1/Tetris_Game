#ifndef piece_H
#define piece_H
#include<iostream>
#include <time.h>
using namespace std;

class piece {
public:
	int roatePosition;
	bool **array;//hold piece
public:
	piece() {
		array = NULL;
		roatePosition = 0;
	}
	bool ** getArray() {
		return array;
	}
	
	void bootmLineIndexes(int &x, int &y) {
		for (int i = 2; i >= 0; i--) {
			for (int j = 2; j >= 0; j--) {
				if (array[i][j]) {
					x = i;
					y = j;
					j = -1;
					i = -1;
				}
			}
		}
	}

	int startRowIndex() {
		for (int i = 0; i < 3; i++) { // check Coloumwise
			for (int j = 0; j < 3; j++) {
				if (array[i][j]) {
					return i;
				}
			}
		}
	}
	void setRoatePosition() {
		if (roatePosition == 0) {

		}
		else if (roatePosition == 1) {

		}
		else if (roatePosition == 2) {

		}
		else if (roatePosition == 3) {

		}
		roatePosition++;
		
	}
	virtual void print(int x, int y) { // print piece
		if (array != NULL) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (array[i][j]) {
						gotoxy(x + i, y + j);
						cout << char(177);
					}
				}
			}
		}
	}
	void clear(int x, int y) {
		if (array != NULL) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (array[i][j]) {
						gotoxy(x + i, y + j);
						cout << " ";
					}
				}
			}
		}
	}
	void rotate() {
		bool **temp = array;
		array = new bool*[3];
		for (int i = 0; i < 3; i++) {
			array[i] = new bool[3];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0, k = 0; j < 3; j++, k++) {
				array[k][i] = temp[i][j];
			}
		}
	}
	~piece() {
		if (array != NULL) {
			for (int i = 0; i < 3; i++) {
				delete []array[i];
			}
			delete[]array;
		}
	}
};


#endif 
