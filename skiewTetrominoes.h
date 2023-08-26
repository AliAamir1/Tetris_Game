#ifndef tetrominoesS_H
#include<iostream>
#include"pieces.h"

class skiewTetrominoes:public piece {

public:
	skiewTetrominoes() {
		array = new bool *[3];
		for (int i = 0; i < 3; i++) {
			array[i] = new bool[3];
		}
		upperShape();
	}
	void print(int x, int y) {
		piece::print(x, y);
	}
	void clear(int x, int y) {
		piece::clear(x, y);
	}
	void changeDirection(int rot) {

		if (rot == 1) {
			roatePosition++;
			if (roatePosition == 4) {
				roatePosition = 0;
			}
			if (roatePosition == 0) {
				leftShape();
			}
			else if (roatePosition == 1) {
				bottomShape();
			}
			else if (roatePosition == 2) {
				rightShape();
			}
			else if (roatePosition == 3) {
				upperShape();
			}
		}
	}
	void leftShape() {
		array[0][0] = 0, array[0][1] = 0, array[0][2] = 0;
		array[1][0] = 0, array[1][1] = 1, array[1][2] = 1;
		array[2][0] = 1, array[2][1] = 1, array[2][2] = 0;
	}
	void rightShape() {
		array[0][0] = 0, array[0][1] = 0, array[0][2] = 0;
		array[1][0] = 1, array[1][1] = 1, array[1][2] = 0;
		array[2][0] = 0, array[2][1] = 1, array[2][2] = 1;
	}
	void bottomShape() {
		array[0][0] = 0, array[0][1] = 0, array[0][2] = 1;
		array[1][0] = 0, array[1][1] = 1, array[1][2] = 1;
		array[2][0] = 0, array[2][1] = 1, array[2][2] = 0;
	}
	void upperShape() {
		array[0][0] = 0, array[0][1] = 1, array[0][2] = 0;
		array[1][0] = 0, array[1][1] = 1, array[1][2] = 1;
		array[2][0] = 0, array[2][1] = 0, array[2][2] = 1;
	}
	bool ** getshape() {
		return array;
	}
};
#endif
