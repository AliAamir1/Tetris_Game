#include<iostream>
#include"game.h"
using namespace std;
int main() {
	game Game;
	system("pause");
	Game.play();
	gotoxy(70, 20);
	cout << "Game Over :(";
	gotoxy(0, 33);
	system("PAUSE");
	return 0;
}