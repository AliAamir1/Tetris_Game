#include<iostream>
#include"mygraphics.h"
#include<ctime>
#include<cstdlib>
using namespace std;


// a to rotate counter clockwise
// s to rotate clockwise
// l to shift left
// r to shift right

class piece
{
protected:
	int **pg;    // piece grid
	int size;     // piece grid size 
	int pvalue;   // tells the digit that each piece has
public:
	friend class board;
	piece();
	~piece();
	virtual void set_piece();
	bool piece_rotation_check(char key);   // handles the shifting of the piece ;
	void spd();                  // this will make sure that piece does not have all zeros on last row after rotation;
	void rotate_clockwise(); // rotate left
	void rotate_counter_clockwise(); // rotate right
	void clear_piece();
	void display();
};


piece::piece()
{
	size = 4;
	size = 4;
	pg = new int*[size];
	for (int i = 0; i < size; i++)
	{
		pg[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			pg[i][j] = 0;
		}
	}
}
piece::~piece()
{
	for (int i = 0; i < size; i++)
	{
		delete[] pg[i];
	}
	pg = NULL;
}
void piece::set_piece()
{

}
void piece::clear_piece()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			pg[i][j] = 0;
		}
	}
}
void piece::rotate_counter_clockwise()
{
	int ** temp = new int *[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			temp[i][j] = pg[i][j];
			//arr[i][j] = 0;
		}
	}

	/*cout << "displaying temp" << endl;
	display(temp, size);*/


	for (int k = 0; k < size; k++)
	{

		for (int i = size - 2 - k, j = 1 + k; j < size && i >= 0; i--, j++)
		{
			pg[i][k] = temp[k][j];
		}
		//	display(arr, size);
		for (int i = 1 + k, j = 1 + k; j <size && i<size; i++, j++)
		{
			pg[k][i] = temp[j][size - 1 - k];
		}
		//	display(arr, size);

		for (int i = 1 + k, j = size - 2 - k; j >= 0 && i < size; i++, j--)
		{
			pg[i][size - 1 - k] = temp[size - 1 - k][j];
		}
		//display(arr, size);
		for (int i = size - 2 - k, j = size - 2 - k; j >= 0 && i >= 0; i--, j--)
		{
			pg[size - 1 - k][i] = temp[j][k];
		}
		//	display(arr, size);
	}
	spd();
}
void piece::rotate_clockwise()
{
	int ** temp = new int *[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			temp[i][j] = pg[i][j];
			//arr[i][j] = 0;
		}
	}

	/*cout << "displaying temp" << endl;
	display(temp, size);*/


	for (int k = 0; k < size; k++)
	{

		for (int i = size - 2 - k, j = 1 + k; j < size && i >= 0; i--, j++)
		{
			pg[k][j] = temp[i][k];
		}
		//	display(arr, size);
		for (int i = 1 + k, j = 1 + k; j <size && i<size; i++, j++)
		{
			pg[j][size - 1 - k] = temp[k][i];
		}
		//	display(arr, size);

		for (int i = 1 + k, j = size - 2 - k; j >= 0 && i < size; i++, j--)
		{
			pg[size - 1 - k][j] = temp[i][size - 1 - k];
		}
		//display(arr, size);
		for (int i = size - 2 - k, j = size - 2 - k; j >= 0 && i >= 0; i--, j--)
		{
			pg[j][k] = temp[size - 1 - k][i];
		}
		//	display(arr, size);
	}



	spd();
}
void piece::display()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << pg[i][j];
		}
		cout << endl;
	}
}
bool piece::piece_rotation_check(char key)
{
	//	char key = getKey();
	if (key == 'a')
	{
		rotate_counter_clockwise();
		return true;
	}
	else if (key == 's')
	{
		rotate_clockwise();
		return true;
	}

	else
		return false;


}
void piece::spd()
{
	// prow and pcol are the starting index of the piece array
	while (pg[size - 1][0] == 0 && pg[size - 1][1] == 0 && pg[size - 1][2] == 0 && pg[size - 1][3] == 0)
	{
		for (int i = size - 2; i >= 0; i--)
		{
			for (int j = 0; j < size; j++)
			{
				pg[i + 1][j] = pg[i][j];
			}
		}
		for (int i = 0; i < size; i++)
		{
			pg[0][i] = 0;
		}
	}


}

class piece1 : public piece
{
public:
	piece1();
	~piece1();

	void set_piece();



};
piece1::piece1()
{

}
piece1::~piece1()
{
}
void  piece1::set_piece()
{
	pvalue = 1;
	for (int j = 0; j < size; j++)
	{
		pg[size - 1][j] = 1;
	}

}



class piece2 :
	public piece
{
public:
	piece2();
	~piece2();

	void set_piece();


};
piece2::piece2()
{
}
piece2::~piece2()
{
}
void piece2::set_piece()
{
	pvalue = 2;
	pg[2][0] = 2;
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			pg[3][i] = 2;
	}

}



class piece3 :
	public piece
{
public:
	piece3();
	~piece3();

	void set_piece();

};
piece3::piece3()
{
}
piece3::~piece3()
{
}
void piece3::set_piece()
{
	pvalue = 3;
	pg[2][3] = 3;
	for (int i = 1; i < size; i++)
	{
		pg[3][i] = 3;
	}
}



class piece4 :
	public piece
{
public:
	piece4();
	~piece4();

	void set_piece();
};
piece4::piece4()
{
}
piece4::~piece4()
{
}
void piece4::set_piece()
{
	pvalue = 4;

	pg[2][1] = 4;
	pg[2][2] = 4;
	pg[3][1] = 4;
	pg[3][2] = 4;
}



class piece5 :
	public piece
{
public:
	piece5();
	~piece5();

	void set_piece();
};
piece5::piece5()
{
}
piece5::~piece5()
{
}
void piece5::set_piece()
{
	pvalue = 5;

	pg[3][0] = 5;
	pg[3][1] = 5;
	pg[2][1] = 5;
	pg[2][2] = 5;
}


class piece6 :
	public piece
{
public:
	piece6();
	~piece6();

	void set_piece();
};
piece6::piece6()
{
}
piece6::~piece6()
{
}
void piece6::set_piece()
{
	pvalue = 6;

	pg[3][0] = 6;
	pg[3][1] = 6;
	pg[3][2] = 6;
	pg[2][1] = 6;
}



class piece7 :
	public piece
{
public:
	piece7();
	~piece7();

	void set_piece();
};
piece7::piece7()
{
}
piece7::~piece7()
{
}
void piece7::set_piece()
{
	pvalue = 7;

	pg[3][2] = 7;
	pg[3][1] = 7;
	pg[2][1] = 7;
	pg[2][0] = 7;
}



class board
{
protected:
	int ** grid;
	int  gr;       // rows of grid 
	int  gc;       // columns of grid 
	piece * p;
	int pcol;      // the starting col of piece 
	int prow;      // the starting row of piece
				   //bool check;
	int score;

public:
	board();
	~board();


	void play_game();//done         controlls the game
	void shift_left();//done         parameters are row and col from which the shift is to take place
	void shift_right();//done         parameters are row and col from which the shift is to take place
	void shift_down();//done         parameters are row and col from which the shift is to take place
	void score_update();//done         update the score of the player
	void display_grid();//done         display the game board 
	void shift_check(char key);//done         this will check if shift is left right or no shift at all ;
	void new_piece_on_board();//done         creates new piece on bord
	void update_piece_after_rotation();//not done          updates piece after rotating the piece     
	void eliminate_row();              // eliminates the whole row if filled ;


	bool place_piece_on_grid();//done         set_piece inner loop in the play game function that will run until the piece is played 
	bool end_game_check();//done         check if game ended or not 


	int random_generator(int n);//done         generates a random number 





};
board::board()
{
	//check = 1;
	score = 0;
	gr = 20;
	gc = 20;


	grid = new int *[gr + 1];
	for (int i = 0; i < gr; i++)
	{
		grid[i] = new int[gc];
		for (int j = 0; j < gc; j++)
		{
			grid[i][j] = 0;
		}
	}
	for (int i = 0; i < gc; i++)
	{
		grid[gr - 1][i] = 9;
	}


}
board::~board()
{
	for (int i = 0; i < gc; i++)
	{
		delete[] grid[i];
	}
}
int board::random_generator(int limit)
{
	srand(time(0));
	return (1 + (rand() % (limit)));

}
//void board::shift_left()
//{
//	// prow and pcol are the starting index of the piece array 
//	for (int i = pcol; i < pcol + p->size && i>0; i++)
//	{
//		for (int j = prow; j < prow + p->size; j++)
//		{
//			grid[j][i - 1] = grid[j][i];
//		}
//	}
//	for (int i = prow; i < prow + p->size; i++)
//	{
//		grid[i][pcol + p->size] = 0;
//	}
//	pcol = pcol - 1;
//}
//void board::shift_right()
//{
//	// prow and pcol are the starting index of the piece array 
//	for (int i = pcol + p->size; i > pcol && i < gc; i--)
//	{
//		for (int j = prow + p->size; j > prow; j--)
//		{
//			grid[j][i + 1] = grid[j][i];
//		}
//	}
//	for (int j = prow + p->size; j > prow; j--)
//	{
//		grid[j][pcol] = 0;
//	}
//	pcol = pcol + 1;
//}
//void board::shift_down()
//{
//	// prow and pcol are the starting index of the piece array
//	for (int i = prow + p->size; i > prow && i >0; i--)
//	{
//		for (int j = pcol + p->size; j > pcol; j--)
//		{
//			grid[i + 1][j] = grid[i][j];
//		}
//	}
//
//	for (int i = 0; i < gc && prow; i++)
//	{
//		grid[0][i] = 0;
//	}
//
//	prow = prow + 1;
//}
void board::shift_right()
{
	// prow and pcol are the starting index of the piece array 

	if (pcol < gc - 1)
	{
		for (int i = pcol + p->size; i > pcol; i--)           // && i < gc
		{
			for (int j = prow + p->size; j >= prow; j--)
			{

				grid[j][i + 1] = grid[j][i];
			}
		}
		for (int j = prow + p->size; j >= prow; j--)           // && pcol < gc
		{
			grid[j][pcol] = 0;
		}
		pcol = pcol + 1;
	}
}
void board::shift_down()
{
	// prow and pcol are the starting index of the piece array
	if (prow < gr - 1)
	{
		for (int i = prow + p->size - 1; i >= prow && i > 0; i--)
		{
			for (int j = pcol + p->size; j >= pcol; j--)
			{
				int temp = 0;

				if (!(p->pvalue != grid[i + 1][j] && grid[i + 1][j] != 0))
				{
					grid[i + 1][j] = grid[i][j];
				}

			}
		}

		for (int i = pcol; i <= pcol + p->size; i++)
		{
			grid[prow][i] = 0;
		}

		prow = prow + 1;
	}
}
void board::shift_left()
{
	// prow and pcol are the starting index of the piece array 
	if (pcol > 0)
	{
		for (int i = pcol; i < pcol + p->size && i>0; i++)
		{
			for (int j = prow; j < prow + p->size; j++)
			{
				grid[j][i - 1] = grid[j][i];
			}
		}
		for (int i = prow; i < prow + p->size && i > 0; i++)  // added i > 0 ;
		{
			grid[i][pcol + p->size - 1] = 0;
		}
		pcol = pcol - 1;
	}
}
bool board::place_piece_on_grid()
{
	bool state = 1;
	for (int i = prow + p->size - 1, j = pcol; j < pcol + p->size; j++)
	{
		if (grid[i + 1][j] != 0 && grid[i][j] != 0)
			state = 0;
	}
	return state;
}
void board::score_update()
{
	score = score + 40;
}
//void board::display_grid()
//{
//	// drawLine(int x1, int y1, int x2, int y2, int colour);
//	//cout << "fuck displlay " << endl;
//	//int w = 0, h = 0;
//	//getWindowDimensions(w, h);
//	//int x = 50, y = 50;        // x and y are the  starting coordinates of the grid 
//	//
//	//
//	//	drawLine(x, y, x, y + (gc*8), 0, 255, 0);
//	//	drawLine(x, y, x +(gr*8), y, 0, 255, 0);
//	//	drawLine(x, y + (gc*8), x + (gr*8), y + (gc*8), 0, 255, 0);
//	//	drawLine(x + (gr*8), y, x + (gr*8), y + (gc*8), 0, 255, 0);
//	//	
//	//	gotoxy(gr+ 1, gc+1);
//	//	for (int i = 0; i < gr; i++)
//	//	{
//	//		gotoxy(gr + 1 + i, gc);
//	//	for (int j = 0; j < gc; j++)
//	//	{
//	//	if (grid[i][j] == 0)
//	//	
//	//	else
//	//	cout << grid[i][j];
//	//	}
//	//	cout << endl;
//	//	}
//	//	delay(100000);
//	
//
//	//gotoxy(0, 50);
//	/*for (int i = 0; i < gr; i++)
//	{
//		for (int j = 0; j < gc; j++)
//		{
//			if (grid[i][j] == 0)
//				cout << "0";
//			else
//				cout << grid[i][j];
//		}
//		cout << endl;
//	}
//	gotoxy(150, 150);
//	cout << "your current score is   :" << score << endl;*/
//}
void board::shift_check(char key)
{
	//char key = getKey();

	if (key == 'l')
	{
		shift_left();
	}
	else if (key == 'r')
	{
		shift_right();
	}

}
void board::new_piece_on_board()
{
	int temp = random_generator(7);
	if (temp == 1)
	{
		p = new piece1;
	}
	else if (temp == 2)
	{
		p = new piece2;
	}
	else if (temp == 3)
	{
		p = new piece3;
	}
	else if (temp == 4)
	{
		p = new piece4;
	}
	else if (temp == 5)
	{
		p = new piece5;
	}
	else if (temp == 6)
	{
		p = new piece6;
	}
	else if (temp == 7)
	{
		p = new piece7;
	}

	prow = 0;
	//pcol = random_generator(gc - 5);
	pcol = 7;
	p->set_piece();
	for (int i = 0; i < p->size; i++)
	{
		for (int j = 0; j < p->size; j++)
		{
			grid[i + prow][j + pcol] = p->pg[i][j];
		}
	}
}
bool board::end_game_check()
{
	bool check = 1;
	for (int i = 0; i < gc; i++)
	{
		if (grid[1][i] != 0)
			check = 0;
	}

	return check;
}
void  board::update_piece_after_rotation()
{
	for (int i = prow, k = 0; i < prow + p->size; i++, k++)
	{
		for (int j = pcol, l = 0; j < pcol + p->size; j++, l++)
		{
			//if (p->pg[k][i]!=0)
			grid[i][j] = p->pg[k][l];
		}
	}
}
void board::display_grid()
{

	/*for (int i = 0; i < gr; i++)
	{

		gotoxy(1, i + 1);
		cout << "|";
		for (int j = 0; j < gc; j++)
		{
			if (grid[i][j] == 9)
				cout << "-";
			else if (grid[i][j] == 0)
				cout << " ";
			else
				cout << grid[i][j];
		}
		cout << "|" << endl;
	}*/


	int x = 15, y = 15;
	for (int i = 0; i < gr-1; i++)
	{
		for (int j = 0; j < gc; j++)
		{
			     if (grid[i][j] == 1)
			{
				drawRectangle( x,y,x+25,y+25,200,0,0,200,0,0);
				drawLine(x, y, x+25, y, 0, 0, 0);
				drawLine(x, y, x, y+25, 0, 0, 0);
				drawLine(x+25, y, x+25, y+25, 0, 0, 0);
				drawLine(x, y+25, x + 25, y+25, 0, 0, 0);
			}
			else if (grid[i][j] == 2)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 200, 200, 0);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			else if (grid[i][j] == 3)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 200, 200, 200);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			else if (grid[i][j] == 4)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 200, 200, 200);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			else if (grid[i][j] == 5)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 0, 200, 200);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			else if (grid[i][j] == 6)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 0, 0, 200);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			else if (grid[i][j] == 7)
			{
				drawRectangle(x, y, x + 25, y + 25, 200, 0, 0, 200, 0, 200);
				drawLine(x, y, x + 25, y, 0, 0, 0);
				drawLine(x, y, x, y + 25, 0, 0, 0);
				drawLine(x + 25, y, x + 25, y + 25, 0, 0, 0);
				drawLine(x, y + 25, x + 25, y + 25, 0, 0, 0);
			}
			x = x + 15;
		}
		x = 15;
		y = y + 15;
	}
	int s = 15;      // the size of each box
	float xscale = 1.7;
	float yscale = 0.7;
	float grid_top_scale = 3;
	drawLine(s, (s*grid_top_scale), (s*(gc+xscale)), (s*3), 0, 0, 200);
	drawLine(s, (s*grid_top_scale), s, (s * (gr + yscale)), 0, 0, 200);
	drawLine((s * (gc+ xscale)), (s*grid_top_scale), (s * (gc+ xscale)), (s * (gr+ yscale)), 0, 0, 200);
	drawLine(s, (s * (gr+ yscale)), (s * (gc+ xscale)), (s * (gr+yscale)), 0, 0, 200);
	//delay(100000);
}

void  board::eliminate_row()
{
	bool check = true;
	for (int i = gr-2;  i > 0; i--)
	{
		check = true;
		for (int j = 0; j < gc; j++)
		{			

			if (grid[i][j] == 0)
				check = false;

		}
		if (check == true)
		{
			for (int k = i; k > 1; k--)
			{
				for (int l = 0; l < gc; i++)
				{
					//grid[k][l] = grid[k - 1][l];
				}
			}
			//break;
		}
	}
	
}
void board::play_game()
{
	showConsoleCursor(false);
	while (end_game_check())
	{
		new_piece_on_board();
		while (place_piece_on_grid())
		{
			gotoxy(0, 0);
			int w = 0, h = 0;
			getWindowDimensions(w, h);


			char key = getKey();
			if (key == 'l' || key == 'r')
			{

				shift_check(key);  			// allows  user to shift the piece left or right 
				p->rotate_clockwise();
				p->rotate_clockwise();
				p->rotate_clockwise();
				p->rotate_clockwise();
				update_piece_after_rotation();

			}
			else if (key == 'a' || key == 's')
			{
				if (p->piece_rotation_check(key))
				{
					update_piece_after_rotation();
					//delay(1000);
				}
			}
			shift_down();
			
			
			gotoxy(0, 0);
				cout << "score is :" << score  << "  l:left    r:right  a:counter clockwise   s : clockwise";
			display_grid();
			delay(500);
			cls();
			//eliminate_row();



		}
		score_update();


		gotoxy(0, 0);
		p->~piece();
	}

	board :: ~board();
}

int main()

{
	


	board tetris;
	tetris.play_game();

	
	system("pause");
	return 0;
}



