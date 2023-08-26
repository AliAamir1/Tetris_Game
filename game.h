#ifndef game_H

#include<iostream>
#include<conio.h> // kbhit function
#include<fstream>

#include"board.h"
#include"LTetromino.h"
#include"skiewTetrominoes.h"
#include"squareTetromino.h"
#include"straightTetromino.h"
#include"TTetromino.h"
#include"pieces.h"
#include"mygraphics.h"
using namespace std;
class game:public board{
private:
	int totalScore;
	LTetromino LTet;
	skiewTetrominoes skiew;
	squareTetromino square;
	straightTetromino straight;
	TTetromino TTet;

public:
	game()
	{
		showConsoleCursor(false);
		totalScore = 0;
	}
	int randomNumber() {

		srand(time(0));
		return (rand() % 4);
	}
	
	int move(int &x, int &y){ // take all key action according to key
		char key = ' ';
		if (_kbhit()) {
			key = _getch();
			if (key == 'A' || key == 'a') { // move piece toward left
 
				if (x != 6) {
					x--;
				}
			}
			else if (key == 'D' || key == 'd') { // move piece toward left
				if (x <= 52) {
					x += 2;
				}
				else if (x == 53) {
					x++;
				}
			}
			else if (key == 'W' || key == 'w' && x > 7) {
				return 1;
			}
			
		}
	}

	void store(bool ** array, int x, int y) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (array[i][j]) {
					grid[(x-6) + i][(y-6)+ j] = array[i][j];
				}
			}
		}
	}

	bool isBottomLine(bool ** array, int x, int y) {
		int k = -1;
		for (int i = x; i < x + 3; i++) {
			int l = -1;
			k++;
			for (int j = y; j < y + 3; j++) {
				l++;
				if (array[k][l] && grid[x - 6 + 1][(y - 6) + 3]) {
					return true;
				}
			}
		}
		return false;
	}

	bool leftLineDetect(bool **array, int x, int y) {
		bool leftLine = false;
		if (array[0][2] && grid[x + 3][y]) {
			leftLine = true;
		}
		else if (array[1][2] && grid[x + 3][y]) {
			leftLine = true;
		}
		else if (array[2][2] && grid[x + 3][y]) {
			leftLine = true;
		}
		bool leftBottom = false;


		return 0;

	}
	void deleteRow(int row) {
		for (int i = 0; i <53; i++) {
			for (int j = row; j > 0; j--) {
				grid[i][j] = grid[i][j - 1];
			}
		}

	}
	void checkEmptyrow() {
		for (int i = 28; i > 0; i--) { // check each column
			if (lineFill(i)) {
				totalScore += 10;
				blank();
				displayGridout();
				deleteRow(i);
			}
		}
	}
	void pritnPlayerScore() { // print player score
		gotoxy(45, 4);
		cout << "Score : "<<this->totalScore;
	}
	bool isGameOver() {
		for (int i = 16; i < 22; i++) {
			for (int j = 0; j < 3; j++) {
				if (grid[i][j]) {
					return true;
				}
			}
		}
		return false;
	}
	void play() {
		displayGameBoard();

		while (!isGameOver()) { // untill game not loose

			bool isSet = 0;
			int pieceIndex = randomNumber(); // take random piece
			int x = 25;
			int y = 6;
			int downward = 1;

			int xpre = 30;
			int ypre = 11;
			
			bool bottomLineTouch = true;
			bool leftLine = true;
			
			int isRotate = 3; // check is we want to rotate shape or not

			pritnPlayerScore();

			while (!isSet) 
			{ // untill piece not touch any point
				if (pieceIndex == 0) {
					LTet.clear(xpre, ypre);//clear previous
					LTet.changeDirection(isRotate);
					LTet.clear(xpre, ypre);//clear previous
					isRotate = move(x, y);
					LTet.print(x,y); // print piece
					
					//check is bottom line touch
					bottomLineTouch = isBottomLine(LTet.array, x, y);
					
					leftLine = leftLineDetect(LTet.array, x, y);
					gotoxy(70, 25);
					cout << bottomLineTouch;
					//is Bottom line foumd
					if (bottomLineTouch) {
						store(LTet.array, x, y);
					}
				}
				else if (pieceIndex == 1) {
					skiew.clear(xpre, ypre);//clear previous
					skiew.changeDirection(isRotate);
					skiew.clear(xpre, ypre);//clear previous
					isRotate = move(x, y);
					skiew.print(x, y); // print piece
					//check is bottom line touch
					bottomLineTouch = isBottomLine(skiew.array, x, y);
					//is Bottom line foumd
					if (bottomLineTouch) {
						store(skiew.array, x, y);
					}
				}
				else if (pieceIndex == 2) {
					square.clear(xpre, ypre);//clear previous
					square.changeDirection(isRotate);
					square.clear(xpre, ypre);//clear previous
					isRotate = move(x, y);
					square.print(x, y); // print piece
					
					//check is bottom line touch
					bottomLineTouch = isBottomLine(square.array, x, y);
					
					//is Bottom line foumd
					if (bottomLineTouch) {
						store(square.array, x, y);
					}
				}
				
				else if (pieceIndex == 4) {
					TTet.clear(xpre, ypre);//clear previous
					TTet.changeDirection(isRotate);
					TTet.clear(xpre, ypre);//clear previous
					isRotate = move(x, y);
					TTet.print(x, y); // print piece
					
					//check is bottom line touch
					bottomLineTouch = isBottomLine(TTet.array, x, y);
					
					//is Bottom line foumd
					if (bottomLineTouch) {
						store(TTet.array, x, y);
					}
				}
				else if (pieceIndex == 3) {
					straight.clear(xpre, ypre);//clear previous
					straight.changeDirection(isRotate);
					straight.clear(xpre, ypre);//clear previous
					isRotate = move(x, y);
					straight.print(x, y); // print piece

					//check is bottom line touch
					bottomLineTouch = isBottomLine(straight.array, x, y);

					//is Bottom line foumd
					if (bottomLineTouch) {
						store(straight.array, x, y);
					}
				}
				checkEmptyrow();
				displayGrid();
				delay(100);
				
				xpre = x;
				ypre = y;
				y++;
				if (bottomLineTouch) {
					isSet = true;
				}
			}
		}

	}
};
#endif // !game_H
