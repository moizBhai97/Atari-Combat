//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

class Obstacle { // basic obstacles
public:
	int x;
	int y;
	int width;
	int height;
};

class Car;

class Fruit { //to get extra large cannon

public:

	int radius;
	int x;
	int y;

	Fruit()
	{
		x = -100;
		y = -100;
		radius = 15;
	}

	void Create();
	void Draw();
	bool Collusion();
	bool Eat(Car);
};

class Map { //consists of obstacles and fruit for different maps and both are composition
public:
	Obstacle * o[3];
	Fruit* fruit;
	int fruit_count;
	int map_no;
	int obs_no[3];
	Map();
	void drawMap(int);
};

class Bullet;
class Player;

class Car {  // bi-associativiy with bullet 
public:
	int id;
	int x;
	int y;
	int lenght;
	bool detect1;
	bool detect2;

	int direction;
	bool start;
	bool first;
	bool powerup;
	Bullet* bullet[3];
	int num_medium;
	int num_large;

	Car();
	Car(int,int);
	void drawCar();
	bool CollisionCar(int=0,int=0);
	void moveCar(Car&,Player&);
	void shootCar(Car);

};

class Bullet {

public:

	int x;
	int y;
	int direction;
	bool start;
	bool end;
	int hit;
	int radius;

	Bullet(int n1 = -100, int n2 = -100)
	{
		x = n1;
		y = n2;
		start = false;
		end = true;
		hit = 0;
		radius = 5;
	}

	void createBullet(Car);
	void drawBullet();
	void moveBullet();
	bool Collision();
	bool CarCollision(Car);
	void Control();
};

class Player { // two players with cars

public:

	Car *car;
	string name;
	int key_setup;
	int score;
	int level;
	int lives;

	Player()
	{
		score = 0;
		lives = 10;
		car = new Car;
		level = 0;

	}


};


class SceneManager { //main scene managing class

public:

	Player play[2];

	SceneManager* scene;

	SceneManager()
	{

		scene = nullptr;
	}

	virtual void GameDisplay(Player[]) = 0;
	void movement_key1();
	void movement_key2();
	void attack_key();

};

class Menu : public SceneManager { // main menu inherited from scene manager

public:
	bool colorChange[4]{false};
	void GameDisplay(Player[]);
};

class LeaderBoard : public SceneManager {// leaderboard inherited from scene manager

public:

	string *name;
	int *score;
	int total;


	LeaderBoard()
	{
		name = nullptr;
		score = nullptr;
		total = 0;
	}

	void readFile(Player[]);
	void GameDisplay(Player[]);
};

class Setting : public SceneManager {// setting inherited from scene manager

public:
	bool colorChange[11];

	Setting()
	{
		colorChange[0] = true;
		colorChange[1] = false;
		colorChange[2] = true;
		colorChange[3] = false;
		colorChange[4] = false;
		colorChange[5] = false;
		colorChange[6] = true;
		colorChange[7] = true;
		colorChange[8] = false;
		colorChange[9] = false;
		colorChange[10] = false;
	}

	void GameDisplay(Player[]);
};


class MultiLevel : public SceneManager { // multi-player inherited from scene manager

public:

	bool gamestart;

	MultiLevel()
	{
		gamestart = false;
	}

	void GameDisplay(Player[]);
};

class MultiEndScene : public SceneManager { // end of multi-player inherited from scene manager

public:

	void GameDisplay(Player[]);
};

class SingleEndScene : public SceneManager { // end of single player inherited from scene manager

public:

	void GameDisplay(Player[]);
};

class SingleLevel : public SceneManager { // single player inherited from scene manager

public:

	bool gamestart;

	SingleLevel()
	{
		gamestart = false;
	}

	void GameDisplay(Player[]);
};


Map::Map()
{
	fruit = nullptr;
	fruit_count = 0;

	o[0] = new Obstacle[11];
	obs_no[0] = 11;
	o[0][0].x = 0;
	o[0][0].y = 50;
	o[0][0].width = 20;
	o[0][0].height = 600;

	o[0][1].x = 1000;
	o[0][1].y = 50;
	o[0][1].width = 20;
	o[0][1].height = 600;

	o[0][2].x = 100;
	o[0][2].y = 0;
	o[0][2].width = 360;
	o[0][2].height = 20;

	o[0][3].x = 560;
	o[0][3].y = 0;
	o[0][3].width = 360;
	o[0][3].height = 20;

	o[0][4].x = 100;
	o[0][4].y = 680;
	o[0][4].width = 360;
	o[0][4].height = 20;

	o[0][5] .x = 560;
	o[0][5].y = 680;
	o[0][5].width = 360;
	o[0][5].height = 20;

	o[0][6] .x = 310;
	o[0][6].y = 200;
	o[0][6].width = 20;
	o[0][6].height = 400;

	o[0][7] .x = 690;
	o[0][7].y = 200;
	o[0][7].width = 20;
	o[0][7].height = 400;

	o[0][8] .x = 310;
	o[0][8].y = 100;
	o[0][8].width = 400;
	o[0][8].height = 20;

	o[0][9] .x = 310;
	o[0][9].y = 580;
	o[0][9].width = 400;
	o[0][9].height = 20;

	o[0][10] .x = 460;
	o[0][10].y = 350;
	o[0][10].width = 100;
	o[0][10].height = 100;

	o[1] = new Obstacle[13];
	obs_no[1] = 13;
	o[1][0].x = 0;
	o[1][0].y = 0;
	o[1][0].width = 20;
	o[1][0].height = 700;

	o[1][1].x = 1000;
	o[1][1].y = 0;
	o[1][1].width = 20;
	o[1][1].height = 700;
	
	o[1][2].x = 0;
	o[1][2].y = 0;
	o[1][2].width = 1020;
	o[1][2].height = 20;

	o[1][3].x = 0;
	o[1][3].y = 680;
	o[1][3].width = 1020;
	o[1][3].height = 20;

	o[1][4].x = 460;
	o[1][4].y = 350;
	o[1][4].width = 100;
	o[1][4].height = 100;

	o[1][5].x = 460;
	o[1][5].y = 450;
	o[1][5].width = 20;
	o[1][5].height = 100;

	o[1][6].x = 360;
	o[1][6].y = 530;
	o[1][6].width = 100;
	o[1][6].height = 20;

	o[1][7].x = 460;
	o[1][7].y = 450-200;
	o[1][7].width = 20;
	o[1][7].height = 100;

	o[1][8].x = 360;
	o[1][8].y = 530-280;
	o[1][8].width = 100;
	o[1][8].height = 20;

	o[1][9].x = 460+80;
	o[1][9].y = 450;
	o[1][9].width = 20;
	o[1][9].height = 100;

	o[1][10].x = 360+200;
	o[1][10].y = 530;
	o[1][10].width = 100;
	o[1][10].height = 20;

	o[1][11].x = 460+80;
	o[1][11].y = 450 - 200;
	o[1][11].width = 20;
	o[1][11].height = 100;

	o[1][12].x = 360+200;
	o[1][12].y = 530 - 280;
	o[1][12].width = 100;
	o[1][12].height = 20;

	o[2] = new Obstacle[20];
	obs_no[2] = 20;

	o[2][0].x = 0;
	o[2][0].y = 0;
	o[2][0].width = 1020;
	o[2][0].height = 20;

	o[2][1].x = 0;
	o[2][1].y = 680;
	o[2][1].width = 1020;
	o[2][1].height = 20;

	o[2][2].x = 70;
	o[2][2].y = 600;
	o[2][2].width = 320;
	o[2][2].height = 20;

	o[2][3].x = 370;
	o[2][3].y = 400;
	o[2][3].width = 20;
	o[2][3].height = 200;

	o[2][4].x = 70;
	o[2][4].y = 520;
	o[2][4].width = 240;
	o[2][4].height = 20;

	o[2][5].x = 290;
	o[2][5].y = 400;
	o[2][5].width = 20;
	o[2][5].height = 120;

	o[2][6].x = 70;
	o[2][6].y = 600-530;
	o[2][6].width = 320;
	o[2][6].height = 20;

	o[2][7].x = 370;
	o[2][7].y = 400-310;
	o[2][7].width = 20;
	o[2][7].height = 200;

	o[2][8].x = 70;
	o[2][8].y = 520-370;
	o[2][8].width = 240;
	o[2][8].height = 20;

	o[2][9].x = 290;
	o[2][9].y = 400-230;
	o[2][9].width = 20;
	o[2][9].height = 120;

	o[2][10].x = 70+560;
	o[2][10].y = 600;
	o[2][10].width = 320;
	o[2][10].height = 20;

	o[2][11].x = 370+260;
	o[2][11].y = 400;
	o[2][11].width = 20;
	o[2][11].height = 200;

	o[2][12].x = 70+640;
	o[2][12].y = 520;
	o[2][12].width = 240;
	o[2][12].height = 20;

	o[2][13].x = 290+420;
	o[2][13].y = 400;
	o[2][13].width = 20;
	o[2][13].height = 120;

	o[2][14].x = 70+560;
	o[2][14].y = 600 - 530;
	o[2][14].width = 320;
	o[2][14].height = 20;

	o[2][15].x = 370+260;
	o[2][15].y = 400 - 310;
	o[2][15].width = 20;
	o[2][15].height = 200;

	o[2][16].x = 70+640;
	o[2][16].y = 520 - 370;
	o[2][16].width = 240;
	o[2][16].height = 20;

	o[2][17].x = 290+420;
	o[2][17].y = 400 - 230;
	o[2][17].width = 20;
	o[2][17].height = 120;

	o[2][18].x = 0;
	o[2][18].y = 300;
	o[2][18].width = 20;
	o[2][18].height = 100;

	o[2][19].x = 1000;
	o[2][19].y = 300;
	o[2][19].width = 20;
	o[2][19].height = 100;


}


void Fruit::Create()
{
	do {

		x = rand() % 900;
		y = rand() % 600;

	} while (Collusion());

	DrawCircle(x, y, radius, colors[WHITE]);

}

void Fruit::Draw()
{

	DrawCircle(x, y, radius, colors[WHITE]);

}

bool Fruit::Eat(Car c)
{
	int Sx = c.x;
	int Sy = c.y;
	int r = c.x + 40;
	int t = c.y + 40;
	int xx = max(Sx, min(x, r));

	int yy = max(Sy, min(y, t));

	int dx = xx - x;
	int dy = yy - y;

	//cout << dx << " " << dy << " "<<Sx<<" "<<Sy<<endl;


	if ((dx * dx + dy * dy) < (radius * radius))
		return true;

	return false;
}

void Map::drawMap(int n)
{
	map_no = n;
	
	for (int i = 0; i < obs_no[map_no]; i++)
	{
		DrawRectangle(o[map_no][i].x, o[map_no][i].y, o[map_no][i].width, o[map_no][i].height, colors[GREEN]);
	}

}


Car::Car()
{
	id = -1;

	x = -100;
	y = -100;

	lenght = 0;
	detect1 = false;
	detect2 = false;
	direction = 0;

	first = true;
	start = true;
	powerup = false;

	for (int i = 0; i < 3; i++)
		bullet[i] = nullptr;

	num_medium = 3;
	num_large = 1;

}

Car::Car(int n1, int n2) : Car()
{
	x = n1;
	y = n2;
	start = true;

}



// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


Menu menu;
LeaderBoard* lead;
SceneManager* s = &menu;
MultiLevel *multi;
SingleLevel* sing;
MultiEndScene* Mend;
SingleEndScene* Send;
Setting* setting;
bool gameStart = false;

Map m;
Car *c1=nullptr;

bool keyarr[127]{false};

bool Fruit::Collusion()
{
	for (int i = 0; i < m.obs_no[m.map_no]; i++)
	{
		int Sx = m.o[m.map_no][i].x;
		int Sy = m.o[m.map_no][i].y;
		int r = m.o[m.map_no][i].x + m.o[m.map_no][i].width;
		int t = m.o[m.map_no][i].y + m.o[m.map_no][i].height;
		int xx = max(Sx, min(x, r));

		int yy = max(Sy, min(y, t));

		int dx = xx - x;
		int dy = yy - y;


		if ((dx * dx + dy * dy) <= (radius * radius))
		{
			return true;
		}

	}

	return false;
}

void Car :: drawCar() {

	if (x >= 1020 && direction==2)
		x = -30;
	else if (x <= -40 && direction==-2)
		x = 1010;
	else if (y >= 700 && direction==1)
		y = -30;
	else if (y <= -40 && direction == -1)
		y = 690;

	//cout << x << " " << y <<" " <<direction<< endl;

	DrawSquare(x, y, 40, colors[WHITE]);
	DrawSquare(x+15, y+15, 10, colors[RED]);

	if(direction==-2)
		DrawRectangle(x, y + 17,20,5, colors[RED]);

	else if (direction == 2)
		DrawRectangle(x + 20, y + 17, 20, 5, colors[RED]);

	else if (direction==1 || start==true)
		DrawRectangle(x + 17, y + 20, 5, 20, colors[RED]);
		
	else if (direction==-1)
		DrawRectangle(x + 17, y, 5, 20, colors[RED]);

	glutPostRedisplay();
}

bool Car::CollisionCar(int n1, int n2)
{
	for (int i = 0; i < m.obs_no[m.map_no]; i++)
	{
		int Sx = x+n1;
		int Sy = y+n2;
	    int r = m.o[m.map_no][i].x + m.o[m.map_no][i].width;
		int t = m.o[m.map_no][i].y + m.o[m.map_no][i].height;

	    if (Sx == r)
			Sx++;

		int x = max(m.o[m.map_no][i].x, min(Sx, r));

		if (Sy == t)
			Sy++;

		int y = max(m.o[m.map_no][i].y, min(Sy, t));

		int dx = x - Sx;
		int dy = y - Sy;

		if ((dx >= 0) && (dy >= 0) && (dx < 40) && (dy < 40))
			return true;
	}

	/*
	Car car[2] = { *c1,*c2 };

	for (int i = 0; i < 3; i++)
	{
		if (id != car[i].id)
		{
			int Sx = x + n1;
			int Sy = y + n2;
			int r = car[i].x + 40;
			int t = car[i].y + 40;

			if (Sx == r)
				Sx++;

			int x = max(car[i].x, min(Sx, r));

			if (Sy == t)
				Sy++;

			int y = max(car[i].y, min(Sy, t));

			int dx = x - Sx;
			int dy = y - Sy;
			//cout << id << "\t" << car[i].id << endl;
			//cout << this->x <<"\t"<< this->y << endl;
			if ((dx >= 0) && (dy >= 0) && (dx < 40) && (dy < 40))
			{
				return true;
			}
				
		}
	}*/


	
	return false;
}

void Car:: moveCar(Car &c, Player &p) {
	
	start = false;

	if (p.level == 0)
	{
		static int xx;

		if (detect1 == false)
			xx = rand() % 4;

		if (xx==0 && !CollisionCar(-10, 0))
		{
			x -= 10;
			direction = -2;
			detect1 = true;
		}
		else if (xx == 0 && CollisionCar(-10, 0))
		{
			detect1 = false;
		}

		if (xx==1 && !CollisionCar(0, -10))
		{
			y -= 10;
			direction = -1;
			detect1 = true;
		}
		else if (xx == 1 && CollisionCar(0, -10))
		{
			detect1 = false;
		}

		if (xx==2 && !CollisionCar(0, 10))
		{
			y += 10;
			direction = 1;
			detect1 = true;
		}
		else if (xx == 2 && CollisionCar(0, 10))
		{
			detect1 = false;
		}

		if (xx==3 && !CollisionCar(10, 0))
		{
			x += 10;
			direction = 2;
			detect1 = true;
		}
		else if (xx == 3 && CollisionCar(10, 0))
		{
			detect1 = false;
		}

	}

	else
	{
		if (x > c.x && detect2 == false) {

			if (CollisionCar(-10, 0) && y == c.y)
			{
				bool up = false, down = false;
				for (int i = 10, j = -10, count = 0; count < 70; i = i + 10, j = j - 10, count++)
				{
					if (y + i == 840)
						i = -870;
					else if (y + j == -40)
						j = 870;

					if (!CollisionCar(-10, i))
					{
						up = true;
						break;
					}
					if (!CollisionCar(-10, j))
					{
						down = true;
						break;
					}
				}

				//cout << "Up: " << up << endl;
				//cout << "Down: " << down << endl;

				if (up == true)
				{
					y += 10;
					direction = 1;
					cout << "up: " << up << endl;
					//cout << "y: " << y << endl;
				}
				else if (down == true)
				{
					y -= 10;
					direction = -1;
					cout << "down: " << down << endl;
					//cout << "y: " << y << endl;
				}

				detect1 = true;

			}
			if (!CollisionCar(-10, 0)) {
				x -= 10;
				direction = -2;
				cout << "going left" << endl;
				detect1 = false;
			}
		}


		else if (x < c.x && detect2 == false) {

			if (CollisionCar(10, 0) && y == c.y)
			{
				bool up = false, down = false;
				for (int i = 10, j = -10, count = 0; count < 70; i = i + 10, j = j - 10, count++)
				{
					if (y + i == 840)
						i = -870;
					else if (y + j == -40)
						j = 870;

					if (!CollisionCar(10, i))
					{
						up = true;
						break;
					}
					if (!CollisionCar(10, j))
					{
						down = true;
						break;
					}
				}

				//cout << "Up: " << up << endl;
				//cout << "Down: " << down << endl;

				if (up == true)
				{
					y += 10;
					direction = 1;
					cout << "up: " << up << endl;
					//cout << "y: " << y << endl;
				}
				else if (down == true)
				{
					y -= 10;
					direction = -1;
					cout << "down: " << down << endl;
					//cout << "y: " << y << endl;
				}

				detect1 = true;

			}

			if (!CollisionCar(10, 0)) {
				x += 10;
				direction = 2;
				cout << "go right" << endl;
				detect1 = false;
			}
		}

		if (y > c.y && detect1 == false) {

			//cout << "Collision: " << CollisionCar(-10, 0) << endl;

			if (CollisionCar(0, -10))
			{
				bool right = false, left = false;
				for (int i = 10, j = -10, count = 0; count < 102; i = i + 10, j = j - 10, count++)
				{
					if (y + i == 1020)
						i = -1050;
					else if (y + j == -40)
						j = 1050;

					if (!CollisionCar(i, -10))
					{
						right = true;
						break;
					}
					if (!CollisionCar(j, -10))
					{
						left = true;
						break;
					}
				}
				//cout << "Right: " << right << endl;
				//cout << "Left: " << left << endl;

				if (right == true)
				{
					x += 10;
					direction = 2;
					cout << "right: " << right << endl;
					//cout << "x: " << x << endl;
				}
				else if (left == true)
				{
					x -= 10;
					direction = -2;
					cout << "left: " << left << endl;
					//cout << "x: " << x << endl;
				}

				detect2 = true;
			}

			if (!CollisionCar(0, -10)) {
				y -= 10;
				direction = -1;
				cout << "go down y: " << y << "y2: " << c.y << "direction: " << direction << endl;
				detect2 = false;
			}
		}

		else if (y < c.y && detect1 == false) {

			if (CollisionCar(0, 10) && x == c.x)
			{
				bool right = false, left = false;
				for (int i = 10, j = -10, count = 0; count < 102; i = i + 10, j = j - 10, count++)
				{
					if (y + i == 1020)
						i = -1050;
					else if (y + j == -40)
						j = 1050;

					if (!CollisionCar(i, 10))
					{
						right = true;
						break;
					}
					if (!CollisionCar(j, 10))
					{
						left = true;
						break;
					}
				}
				//cout << "Right: " << right << endl;
				//cout << "Left: " << left << endl;

				if (right == true)
				{
					x += 10;
					direction = 2;
					cout << "right: " << right << endl;
					//cout << "x: " << x << endl;
				}
				else if (left == true)
				{
					x -= 10;
					direction = -2;
					cout << "left: " << left << endl;
					//cout << "x: " << x << endl;
				}

				detect2 = true;

			}

			if (!CollisionCar(0, 10)) {
				y += 10;
				direction = 1;
				cout << "go up" << endl;
				detect2 = false;
			}
		}
	}
}

void Car::shootCar(Car c)
{
	int xx=0;

	if (num_large > 0 && num_medium > 0)
	{
		xx = rand() % 3;
	}
	else if (num_large == 0 && num_medium > 0)
	{
		xx = rand() % 2;
	}
	else if (num_large > 0 && num_medium == 0)
	{
		xx = rand() % 2;
		if (xx == 1)
			xx = xx + 1;
	}

	else if (num_large == 0 && num_medium == 0)
		xx = 0;


	if (x == c.x && y<c.y && direction == 1)
	{
		bool flag = true;
		for (int i = 0; i < m.obs_no[m.map_no]; i++)
		{
			if (m.o[m.map_no][i].x == x && m.o[m.map_no][i].y > y && m.o[m.map_no][i].y < c.y)
			{
				flag = false;
				break;

			}
		}

		if (flag == true)
		{
			cout << "create!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

			if (bullet[xx] == nullptr)
			{
				cout << "in" << endl;

				bullet[xx] = new Bullet;
				bullet[xx]->start = true;

				if (xx == 1)
				{
					bullet[xx]->radius = 10;
					num_medium--;
				}
				else if (xx == 2)
				{
					bullet[xx]->radius = 15;
					num_large--;
				}

				cout << "out" << endl;
			}

			if (bullet[xx]->start == true)
			{
				bullet[xx]->direction = direction;
				bullet[xx]->createBullet(*this);
				bullet[xx]->start = false;
			}
		}
	}
	else if (x == c.x && y > c.y && direction == -1)
	{
		bool flag = true;
		for (int i = 0; i < m.obs_no[m.map_no]; i++)
		{
			if (m.o[m.map_no][i].x == x && m.o[m.map_no][i].y < y && m.o[m.map_no][i].y > c.y)
			{
				flag = false;
				break;

			}
		}

		if (flag == true)
		{
			cout << "create!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

			if (bullet[xx] == nullptr)
			{
				cout << "in" << endl;

				bullet[xx] = new Bullet;
				bullet[xx]->start = true;

				if (xx == 1)
				{
					bullet[xx]->radius = 10;
					num_medium--;
				}
				else if (xx == 2)
				{
					bullet[xx]->radius = 15;
					num_large--;
				}

				cout << "out" << endl;
			}

			if (bullet[xx]->start == true)
			{
				bullet[xx]->direction = direction;
				bullet[xx]->createBullet(*this);
				bullet[xx]->start = false;
			}
		}
	}
	else if (y == c.y && x < c.x && direction == 2)
	{
		bool flag = true;
		for (int i = 0; i < m.obs_no[m.map_no]; i++)
		{
			if (m.o[m.map_no][i].y == y && m.o[m.map_no][i].x > x && m.o[m.map_no][i].x < c.x)
			{
				flag = false;
				break;

			}
		}

		if (flag == true)
		{
			cout << "create!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

			if (bullet[xx] == nullptr)
			{
				cout << "in" << endl;

				bullet[xx] = new Bullet;
				bullet[xx]->start = true;

				if (xx == 1)
				{
					bullet[xx]->radius = 10;
					num_medium--;
				}
				else if (xx == 2)
				{
					bullet[xx]->radius = 15;
					num_large--;
				}

				cout << "out" << endl;
			}

			if (bullet[xx]->start == true)
			{
				bullet[xx]->direction = direction;
				bullet[xx]->createBullet(*this);
				bullet[xx]->start = false;
			}
		}
	}
	else if (y == c.y && x> c.x && direction == -2)
	{
		bool flag = true;
		for (int i = 0; i < m.obs_no[m.map_no]; i++)
		{
			if (m.o[m.map_no][i].y == y && m.o[m.map_no][i].x < x && m.o[m.map_no][i].x > c.x)
			{
				flag = false;
				break;

			}
		}

		if (flag == true)
		{
			cout << "create!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

			if (bullet[xx] == nullptr)
			{
				cout << "in" << endl;

				bullet[xx] = new Bullet;
				bullet[xx]->start = true;

				if (xx == 1)
				{
					bullet[xx]->radius = 10;
					num_medium--;
				}
				else if (xx == 2)
				{
					bullet[xx]->radius = 15;
					num_large--;
				}

				cout << "out" << endl;
			}

			if (bullet[xx]->start == true)
			{
				bullet[xx]->direction = direction;
				bullet[xx]->createBullet(*this);
				bullet[xx]->start = false;
			}
		}
	}

}


void Bullet::createBullet(Car c)
{
	if (direction == 1)
	{
		x = c.x + 20;
		y = c.y + 40 + radius;
		DrawCircle(x, y, radius, colors[RED]);
	}

	else if (direction == -1)
	{
		x = c.x + 20;
		y = c.y -radius;
		DrawCircle(x, y, radius, colors[RED]);
	}

	else if (direction == 2)
	{
		x = c.x + 40 + radius;
		y = c.y + 20;
		DrawCircle(x, y, radius, colors[RED]);
	}
		

	else if (direction == -2)
	{
		x = c.x - radius;
		y = c.y + 20;
		DrawCircle(x , y , radius, colors[RED]);
	}
		
}

void Bullet :: moveBullet()
{
	//cout << x << " " << y << endl;
	//start = false;

	if (Collision())
	{
		hit++;
		direction *= -1;
	}

	//cout << "Direction: " << direction << endl;

	if (direction == 1)
	{
		y += 10;
	}
	else if (direction == -1)
	{
		y -= 10;
	}
	else if (direction == 2)
	{
		x += 10;
	}
	else if (direction == -2)
	{
		x -= 10;
	}
	
}

void Bullet::drawBullet()
{
	if (x == 1020 && direction == 2)
		x = -radius;
	else if (x == -radius && direction == -2)
		x = 1020-radius;
	else if (y == 700 && direction == 1)
		y = -radius;
	else if (y == -radius && direction == -1)
		y = 700-radius;

	DrawCircle(x, y, radius, colors[RED]);
}

bool Bullet::Collision()
{
	for (int i = 0; i < m.obs_no[m.map_no]; i++)
	{
		int Sx = m.o[m.map_no][i].x;
		int Sy = m.o[m.map_no][i].y;
		int r = m.o[m.map_no][i].x + m.o[m.map_no][i].width;
		int t = m.o[m.map_no][i].y + m.o[m.map_no][i].height;
		int xx = max(Sx, min(x, r));

		int yy = max(Sy, min(y, t));

		int dx = xx - x;
		int dy = yy - y;


		if ((dx * dx + dy * dy) <= (radius * radius))
		{
			return true;
		}
			
	}

	return false;
}

bool Bullet::CarCollision(Car c)
{
	int Sx = c.x;
	int Sy = c.y;
	int r = c.x + 40;
	int t = c.y + 40;
	int xx = max(Sx, min(x, r));

	int yy = max(Sy, min(y, t));

	int dx = xx - x;
	int dy = yy - y;

	//cout << dx << " " << dy << " "<<Sx<<" "<<Sy<<endl;


	if ((dx * dx + dy * dy) < (radius * radius))
		return true;

	return false;
}

/*
 * Main Canvas drawing function.
 * */

void  SceneManager:: movement_key1()
{
	cout << "in key" << endl;
	if ((keyarr[int('s')] || keyarr[int('S')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			play[0].car->direction = -1;
			play[0].car->start = false;
			play[0].car->y -= 10;
		}
	}
	if ((keyarr[int('w')] || keyarr[int('W')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			play[0].car->direction = 1;
			play[0].car->start = false;
			play[0].car->y += 10;
		}
	}
	if ((keyarr[int('a')] || keyarr[int('A')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			play[0].car->direction = -2;
			play[0].car->start = false;
			play[0].car->x -= 10;
		}

	}
	if ((keyarr[int('d')] || keyarr[int('D')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			play[0].car->direction = 2;
			play[0].car->start = false;
			play[0].car->x += 10;
		}

	}
	if ((keyarr[40]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			play[0].car->direction = -1;
			play[0].car->start = false;
			play[0].car->y -= 10;
		}
	}
	if ((keyarr[38]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			play[0].car->direction = 1;
			play[0].car->start = false;
			play[0].car->y += 10;
		}
	}
	if ((keyarr[37]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			play[0].car->direction = -2;
			play[0].car->start = false;
			play[0].car->x -= 10;
		}
	}
	if ((keyarr[39]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			play[0].car->direction = 2;
			play[0].car->start = false;
			play[0].car->x += 10;
		}
	}

	glutPostRedisplay();
}

void  SceneManager:: movement_key2()
{
	if ((keyarr[int('s')] || keyarr[int('S')]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 0)
		{
			play[1].car->direction = -1;
			play[1].car->start = false;
			play[1].car->y -= 10;
		}
	}
	if ((keyarr[int('w')] || keyarr[int('W')]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 0)
		{
			play[1].car->direction = 1;
			play[1].car->start = false;
			play[1].car->y += 10;
		}
	}
	if ((keyarr[int('a')] || keyarr[int('A')]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 0)
		{
			play[1].car->direction = -2;
			play[1].car->start = false;
			play[1].car->x -= 10;
		}

	}
	if ((keyarr[int('d')] || keyarr[int('D')]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 0)
		{
			play[1].car->direction = 2;
			play[1].car->start = false;
			play[1].car->x += 10;
		}

	}
	if ((keyarr[40]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 1)
		{
			play[1].car->direction = -1;
			play[1].car->start = false;
			play[1].car->y -= 10;
		}
	}
	if ((keyarr[38]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 1)
		{
			play[1].car->direction = 1;
			play[1].car->start = false;
			play[1].car->y += 10;
		}
	}
	if ((keyarr[37]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 1)
		{
			play[1].car->direction = -2;
			play[1].car->start = false;
			play[1].car->x -= 10;
		}
	}
	if ((keyarr[39]) && play[0].car != nullptr)
	{
		if (play[1].key_setup == 1)
		{
			play[1].car->direction = 2;
			play[1].car->start = false;
			play[1].car->x += 10;
		}
	}
	glutPostRedisplay();
}

void SceneManager :: attack_key()
{
	if ((keyarr[int('j')]) && play[0].car != nullptr)
	{
		cout << "j" << endl;
		if (play[0].key_setup == 0)
		{
			if (play[0].car->bullet[0] == nullptr)
			{
				play[0].car->bullet[0] = new Bullet;
				play[0].car->bullet[0]->start = true;

				if (play[0].car->powerup == true)
					play[0].car->bullet[0]->radius = 15;
			}
		}
		else
		{
			if (play[1].car->bullet[0] == nullptr)
			{
				play[1].car->bullet[0] = new Bullet;
				play[1].car->bullet[0]->start = true;

				if (play[1].car->powerup == true)
					play[1].car->bullet[0]->radius = 15;
			}
		}
	}

	if ((keyarr[int('k')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			cout << play[0].car->num_medium << endl;
			if (play[0].car->bullet[1] == nullptr && play[0].car->num_medium != 0)
			{
				play[0].car->bullet[1] = new Bullet;
				play[0].car->bullet[1]->start = true;
				play[0].car->bullet[1]->radius = 10;
				play[0].car->num_medium--;

				cout << play[0].car->bullet[1]->start << endl;
			}
		}
		else
		{
			if (play[1].car->bullet[1] == nullptr && play[1].car->num_medium != 0)
			{
				play[1].car->bullet[1] = new Bullet;
				play[1].car->bullet[1]->start = true;
				play[1].car->bullet[1]->radius = 10;
				play[1].car->num_medium--;
			}
		}
	}

	if ((keyarr[int('l')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 0)
		{
			if (play[0].car->bullet[2] == nullptr && play[0].car->num_large!=0)
			{
				play[0].car->bullet[2] = new Bullet;
				play[0].car->bullet[2]->start = true;
				play[0].car->bullet[2]->radius = 15;
				play[0].car->num_large--;
			}
		}
		else
		{
			if (play[1].car->bullet[2] == nullptr && play[1].car->num_large != 0)
			{
				play[1].car->bullet[2] = new Bullet;
				play[1].car->bullet[2]->start = true;
				play[1].car->bullet[2]->radius = 15;
				play[1].car->num_large--;
			}
		}
	}

	if ((keyarr[int('c')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			if (play[0].car->bullet[0] == nullptr)
			{
				play[0].car->bullet[0] = new Bullet;
				play[0].car->bullet[0]->start = true;

				if (play[0].car->powerup == true)
					play[0].car->bullet[0]->radius = 15;
			}
		}
		else
		{
			if (play[1].car->bullet[0] == nullptr)
			{
				play[1].car->bullet[0] = new Bullet;
				play[1].car->bullet[0]->start = true;

				if (play[1].car->powerup == true)
					play[1].car->bullet[0]->radius = 15;
			}
		}
	}

	if ((keyarr[int('v')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			if (play[0].car->bullet[1] == nullptr && play[0].car->num_medium != 0)
			{
				play[0].car->bullet[1] = new Bullet;
				play[0].car->bullet[1]->start = true;
				play[0].car->bullet[1]->radius = 10;
				play[0].car->num_medium--;
			}
		}
		else
		{
			cout << play[1].car->num_medium << endl;
			if (play[1].car->bullet[1] == nullptr && play[1].car->num_medium != 0)
			{
				play[1].car->bullet[1] = new Bullet;
				play[1].car->bullet[1]->start = true;
				play[1].car->bullet[1]->radius = 10;
				play[1].car->num_medium--;
			}
		}
	}

	if ((keyarr[int('b')]) && play[0].car != nullptr)
	{
		if (play[0].key_setup == 1)
		{
			if (play[0].car->bullet[2] == nullptr && play[0].car->num_large != 0)
			{
				play[0].car->bullet[2] = new Bullet;
				play[0].car->bullet[2]->start = true;
				play[0].car->bullet[2]->radius = 15;
				play[0].car->num_large--;
			}
		}
		else
		{
			if (play[1].car->bullet[2] == nullptr && play[1].car->num_large != 0)
			{
				play[1].car->bullet[2] = new Bullet;
				play[1].car->bullet[2]->start = true;
				play[1].car->bullet[2]->radius = 15;
				play[1].car->num_large--;
			}
		}
	}

	glutPostRedisplay();
}

void MultiLevel :: GameDisplay( Player play[])
{
	
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
//	DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	static int xx;

	if (gamestart == false)
	{
		xx = rand() % 3;

		gamestart = true;
	}

	m.drawMap(xx);
	
	//Display Score
	DrawString( 50, 660, "Player 1 score: " + to_string(play[0].score), colors[MISTY_ROSE]);
	DrawString(50, 600, "Player 1 lives: " + to_string(play[0].lives), colors[MISTY_ROSE]);

	DrawString(800, 660, "Player 2 score: " + to_string(play[1].score), colors[MISTY_ROSE]);
	DrawString(800, 600, "Player 2 lives: " + to_string(play[1].lives), colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
//	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
//	DrawCircle(50,670,10,colors[RED]);
//	DrawCircle(70,670,10,colors[RED]);
//	DrawCircle(90,670,10,colors[RED]);
//	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
//	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
//	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
//	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	
	
	/*
	if (car[1].start == true)
	{
		car[1].id = 1;
		car[1].x = 600;
		car[1].y = 400;
	}
	if (car[2].start == true)
	{
		car[2].id = 2;
		car[2].x = 0;
		car[2].y = 0;
	}
	*/

	if (play[0].car->first == true)
	{
		do {

			play[0].car->x = rand() % 900;
			play[0].car->y = rand() % 600;

		} while (play[0].car->CollisionCar());

		play[0].car->first = false;
	}

	if (play[1].car->first == true)
	{
		do {

			play[1].car->x = rand() % 900;
			play[1].car->y = rand() % 600;

		} while (play[1].car->CollisionCar());

		play[1].car->first = false;
	}

	play[0].car->drawCar();
	play[1].car->drawCar();

	for (int i = 0; i < 3; i++)
	{
		if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->start == true)
		{
			cout << "Bullet k!!" << endl;
			play[0].car->bullet[i]->direction = play[0].car->direction;
			play[0].car->bullet[i]->createBullet(*play[0].car);
			play[0].car->bullet[i]->start = false;
		}

		else if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->start == false)
		{
			play[0].car->bullet[i]->drawBullet();
		}

		if (play[1].car->bullet[i] != nullptr && play[1].car->bullet[i]->start == true)
		{
			cout << "Car 3 bullet!!" << endl;
			play[1].car->bullet[i]->direction = play[1].car->direction;
			play[1].car->bullet[i]->createBullet(*play[1].car);
			play[1].car->bullet[i]->start = false;
		}

		else if (play[1].car->bullet[i] != nullptr && play[1].car->bullet[i]->start == false)
		{
			play[1].car->bullet[i]->drawBullet();
		}

		if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->Collision() && play[0].car->bullet[i]->hit == 3)
		{
			//cout << "Hit3 times!!" << car[0].bullet->hit<< endl;
			delete play[0].car->bullet[i];
			play[0].car->bullet[i] = nullptr;
		}
		else if (play[0].car->bullet[i] != nullptr && (play[0].car->bullet[i]->CarCollision(*play[1].car)))
		{
			play[0].score++;
			play[1].lives--;
			delete play[0].car->bullet[i];
			play[0].car->bullet[i] = nullptr;
		}
		else if (play[0].car->bullet[i] != nullptr && (play[0].car->bullet[i]->CarCollision(*play[0].car)))
		{
			play[0].lives--;
			delete play[0].car->bullet[i];
			play[0].car->bullet[i] = nullptr;
		}

		if (play[1].car->bullet[i] != nullptr && play[1].car->bullet[i]->Collision() && play[1].car->bullet[i]->hit == 3)
		{
			delete play[1].car->bullet[i];
			play[1].car->bullet[i] = nullptr;
		}
		else if (play[1].car->bullet[i] != nullptr && (play[1].car->bullet[i]->CarCollision(*play[0].car)))
		{
			play[1].score++;
			play[0].lives--;
			delete play[1].car->bullet[i];
			play[1].car->bullet[i] = nullptr;
		}
		else if (play[1].car->bullet[i] != nullptr && (play[1].car->bullet[i]->CarCollision(*play[1].car)))
		{
			play[1].lives--;
			delete play[1].car->bullet[i];
			play[1].car->bullet[i] = nullptr;
		}
	}

	if (play[0].car->CollisionCar())
	{
		do {

			play[0].car->x = rand() % 900;
			play[0].car->y = rand() % 600;

		} while (play[0].car->CollisionCar());


		play[0].lives--;
		play[0].car->start = true;
	}
	if (play[1].car->CollisionCar())
	{
		do {

			play[1].car->x = rand() % 900;
			play[1].car->y = rand() % 600;

		} while (play[1].car->CollisionCar());;

		play[1].lives--;
		play[1].car->start = true;
	}

 	if (play[0].car->num_large == 0 && play[1].car->num_large == 0 && play[0].car->bullet[2]==nullptr && play[1].car->bullet[2] == nullptr && m.fruit_count!=1)
	{
		m.fruit = new Fruit;
		m.fruit->Create();
		m.fruit_count = 1;
	}
	if (m.fruit != nullptr)
	{
		m.fruit->Draw();
	}
	//cout << m.fruit_count << endl;
	if (m.fruit!=nullptr && m.fruit->Eat(*play[0].car))
	{
		play[0].car->num_large++;
	    delete m.fruit;
		m.fruit = nullptr;
	}
	else if (m.fruit != nullptr && m.fruit->Eat(*play[1].car))
	{
		play[1].car->num_large++;
		delete m.fruit;
		m.fruit = nullptr;
	}

	if (play[0].lives == 1 && play[0].score < 5)
	{
		play[0].car->powerup = true;
	}

	else play[0].car->powerup = false;
	
	if (play[1].lives == 3 && play[1].score < 5)
	{
		play[1].car->powerup = true;
	}

	else play[1].car->powerup = false;


	//if (b.Collision())
	{
		//b.end = true;
	}
	/*
	if (car[1].CollisionCar())
	{
		car[1].x = 600;
		car[1].y = 400;
		car[1].start = true;
	}

	if (car[2].CollisionCar())
	{
		car[2].x = 0;
		car[2].y = 0;
		car[2].start = true;
	}
	*/
	
	if (play[0].lives == 0 || play[1].lives == 0)
	{
		Mend = new MultiEndScene;
		s->scene = Mend;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		s->scene->GameDisplay(s->play);
	}

	glutSwapBuffers(); // do not modify this line..

}

void SingleLevel::GameDisplay(Player play[])
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
//	DrawSquare(400, 20, 40, colors[RED]);

	//Green Square

	static int xx;

	if (gamestart == false)
	{
		xx= rand() % 3;

		play[0] = s->play[0];
	}

	m.drawMap(xx);

	cout << m.map_no << endl;

	//Display Score
	DrawString(50, 660, "Player 1 score: " + to_string(play[0].score), colors[MISTY_ROSE]);
	DrawString(50, 600, "Player 1 lives: " + to_string(play[0].lives), colors[MISTY_ROSE]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
//	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 



	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

//	DrawCircle(50,670,10,colors[RED]);
//	DrawCircle(70,670,10,colors[RED]);
//	DrawCircle(90,670,10,colors[RED]);
//	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
//	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
//	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
//	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);



	if (gamestart==false)
	{

		c1 = new Car[play[0].level+1];

		for (int i = 0; i < play[0].level + 1; i++)
		{
			do {

				c1[i].x = (rand() % 90) * 10;
				c1[i].y = (rand() % 60) * 10;

			} while (c1[i].CollisionCar());
		}
		gamestart = true;
	}

	if (play[0].car->first == true)
	{
		do {

			play[0].car->x = (rand() % 90) * 10;
			play[0].car->y = (rand() % 60) * 10;

		} while (play[0].car->CollisionCar());

		play[0].car->first = false;
	}

	cout << "Level 1 " << play[0].level << endl;

	play[0].car->drawCar();

	for (int i = 0; i < play[0].level + 1; i++)
	{
		c1[i].drawCar();
	}

	for (int i = 0; i < 3; i++)
	{
		if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->start == true)
		{
			cout << "Bullet k!!" << endl;
			play[0].car->bullet[i]->direction = play[0].car->direction;
			play[0].car->bullet[i]->createBullet(*play[0].car);
			play[0].car->bullet[i]->start = false;
		}

		else if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->start == false)
		{
			play[0].car->bullet[i]->drawBullet();
		}
	

		if (play[0].car->bullet[i] != nullptr && play[0].car->bullet[i]->Collision() && play[0].car->bullet[i]->hit == 3)
		{
			//cout << "Hit3 times!!" << car[0].bullet->hit<< endl;
			delete play[0].car->bullet[i];
			play[0].car->bullet[i] = nullptr;
		}
		else if (play[0].car->bullet[i] != nullptr && (play[0].car->bullet[i]->CarCollision(*play[0].car)))
		{
			play[0].lives--;
			delete play[0].car->bullet[i];
			play[0].car->bullet[i] = nullptr;
		}

		for (int j = 0; j < play[0].level + 1; j++)
		{
			if (play[0].car->bullet[i] != nullptr && (play[0].car->bullet[i]->CarCollision(c1[j])))
			{
				play[0].score++;
				delete play[0].car->bullet[i];
				play[0].car->bullet[i] = nullptr;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < play[0].level + 1; j++)
		{
			if (c1[j].bullet[i] != nullptr && c1[j].bullet[i]->start == false)
			{
				c1[j].bullet[i]->drawBullet();
			}

			if (c1[j].bullet[i] != nullptr && c1[j].bullet[i]->start == false)
			{
				c1[j].bullet[i]->drawBullet();
			}


			if (c1[j].bullet[i] != nullptr && c1[j].bullet[i]->Collision() && c1[j].bullet[i]->hit == 3)
			{
				delete c1[j].bullet[i];
				c1[j].bullet[i] = nullptr;
			}
			else if (c1[j].bullet[i] != nullptr && (c1[j].bullet[i]->CarCollision(*play[0].car)))
			{
				play[0].lives--;
				delete c1[j].bullet[i];
				c1[j].bullet[i] = nullptr;
			}
			else if (c1[j].bullet[i] != nullptr && (c1[j].bullet[i]->CarCollision(c1[j])))
			{
				delete c1[j].bullet[i];
				c1[j].bullet[i] = nullptr;
			}
		}
	}


	if (play[0].car->CollisionCar())
	{
		do {

			play[0].car->x = (rand() % 90)*10;
			play[0].car->y = (rand() % 60)*10;

		} while (play[0].car->CollisionCar());


		play[0].lives--;
		play[0].car->start = true;
	}

	for (int i = 0; i < play[0].level + 1; i++)
	{
		if (c1[i].CollisionCar())
		{
			do {

				c1[i].x = (rand() % 90) * 10;
				c1[i].y = (rand() % 60) * 10;

			} while (c1[i].CollisionCar());
			c1[i].start = true;
		}
	}

	if (play[0].car->num_large == 0 && play[0].car->bullet[2] ==nullptr && play[0].score<5 && m.fruit_count != 1)
	{
		m.fruit = new Fruit;
		m.fruit->Create();
		m.fruit_count = 1;
	if (m.fruit != nullptr)
	{
		m.fruit->Draw();
	}
	//cout << m.fruit_count << endl;
	if (m.fruit != nullptr && m.fruit->Eat(*play[0].car))
	{
		play[0].car->num_large++;
	}
		delete m.fruit;
		m.fruit = nullptr;
	}

	if (play[0].lives == 1 && play[0].score < 6)
	{
		play[0].car->powerup = true;
	}

	else play[0].car->powerup = false;



	if (play[0].lives == 0)
	{
		Send = new SingleEndScene;
		s->scene = Send;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		play[0].lives = 10;

		lead = new LeaderBoard;
		lead->readFile(s->play);
		delete lead;

		play[0].score = 0;

		m.fruit_count = 0;

		delete play[0].car;

		play[0].car = nullptr;

		delete c1;

		c1 = nullptr;

		s->scene->GameDisplay(s->play);
	}

	else if (play[0].score == 10)
	{
		if (play[0].level + 1 == 4)
		{
			Send = new SingleEndScene;
			s->scene = Send;
		}

		else
		{
			delete sing;

			sing = new SingleLevel;

			s->scene = sing;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		play[0].lives = 10;

		cout << "Level : " << play[0].level << endl;

		play[0].level++;

		lead = new LeaderBoard;
		lead->readFile(s->play);
		delete lead;

		play[0].score = 0;

		m.fruit_count = 0;

		delete play[0].car;

		play[0].car = nullptr;

		play[0].car = new Car;

		delete c1;

		c1 = nullptr;

		s->scene->GameDisplay(s->play);
	}

	glutSwapBuffers(); // do not modify this line..

}

void Menu::GameDisplay(Player play[])
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
//	DrawSquare(400, 20, 40, colors[RED]);

	//Green Square

	//Display Score
	//DrawString(50, 800, "Score=0", colors[MISTY_ROSE]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
//	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 



	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

//	DrawCircle(50,670,10,colors[RED]);
//	DrawCircle(70,670,10,colors[RED]);
//	DrawCircle(90,670,10,colors[RED]);
	if(colorChange[0] == false)
		DrawRoundRect(310,500,400,100,colors[DARK_OLIVE_GREEN],20);
	else DrawRoundRect(310, 500, 400, 100, colors[LIME_GREEN], 20);
	
	DrawString(440, 540, "Single Player", colors[RED]);

	if (colorChange[1] == false)
		DrawRoundRect(310, 300, 400, 100, colors[DARK_OLIVE_GREEN], 20);
	else DrawRoundRect(310, 300, 400, 100, colors[LIME_GREEN], 20);

	DrawString(440, 340, "Multi-Player", colors[RED]);

	if (colorChange[2] == false)
		DrawRoundRect(310, 100, 400, 100, colors[DARK_OLIVE_GREEN], 20);
	else DrawRoundRect(310, 100, 400, 100, colors[LIME_GREEN], 20);

	DrawString(470, 140, "Setting", colors[RED]);


	if (colorChange[3] == false)
		DrawRoundRect(770, 600, 200, 50, colors[DARK_OLIVE_GREEN], 20);
	else DrawRoundRect(770, 600, 200, 50, colors[LIME_GREEN], 20);

	DrawString(810, 620, "Leader Board", colors[RED]);

//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);

	glutSwapBuffers(); // do not modify this line..

}


void LeaderBoard::readFile(Player play[])
{
	ifstream leader;
	ofstream temp;
	string line;
	bool flag1 = false;
	bool flag2 = false;

	leader.open("leader.txt");
	temp.open("temp.txt");

	if (leader.is_open() && temp.is_open())
	{
		while (getline(leader,line))
		{
            temp << line<<"\n";

			if (line == play[0].name)
			{
				getline(leader, line);
				temp << play[0].score+stoi(line) << "\n";

				getline(leader, line);
				if (play[0].level < stoi(line))
					temp << line << "\n";
				else temp << play[0].level << "\n";

				flag1 = true;
			}

			else if (line == play[1].name)
			{
				getline(leader, line);
				temp << play[1].score + stoi(line) <<"\n";
				flag2 = true;
			}

		}

		if (flag1 == false)
			temp << play[0].name << "\n" << play[0].score <<"\n"<<play[0].level<< endl;
		if (flag2 == false)
			temp << play[1].name << "\n" << play[1].score << "\n" << play[1].level << endl;

		leader.close();
		temp.close();

		remove("leader.txt");
		rename("temp.txt", "leader.txt");
	}

	leader.open("leader.txt");

	if (leader.is_open())
	{
		while (getline(leader, line))
		{
			total++;
		}

		leader.close();
	}

	total = total / 3;
	cout << total << endl;

	name = new string[total];
	score = new int[total];

	leader.open("leader.txt");

	if (leader.is_open())
	{
		int i = 0;
		int n = 0;
		while (getline(leader, line))
		{
			if (i % 3 == 0)
			{
				name[n] = line;
			}
			else if (i % 3 == 1)
			{
				score[n] = stoi(line);
				n++;
			}
			else if (i % 3 == 2)
			{
				if (name[n - 1] == play[0].name)
					play[0].level = stoi(line);

				cout << play[0].name << " " << line << endl;

			}
			i++;
		}

		leader.close();
	}

	for (int i = 0; i < total; i++)
	{
		for (int j = i+1; j < total; j++)
		{
			if (score[i] < score[j])
			{
				int temp = score[i];
				score[i] = score[j];
				score[j] = temp;

				string l = name[i];
				name[i] = name[j];
				name[j] = l;
			}
		}
	}
}

void LeaderBoard :: GameDisplay(Player play[])
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
//	DrawSquare(400, 20, 40, colors[RED]);

	//Green Square

	DrawString(400, 600, "Leader Board", colors[RED]);

	if (total > 10)
		total = 10;

	for (int i = 0; i < total; i++)
	{
		DrawString(350, 550-(i*50), name[i], colors[MISTY_ROSE]);
		DrawString(550, 550 - (i * 50), to_string(score[i]), colors[MISTY_ROSE]);
	}

	DrawRoundRect(50, 550, 100, 100, colors[DARK_OLIVE_GREEN], 20);
	DrawString(75, 590, "Back", colors[RED]);


	glutSwapBuffers(); // do not modify this line..
}

void Setting::GameDisplay(Player play[])
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
//	DrawSquare(400, 20, 40, colors[RED]);

	//Green Square

	//Display Score
	//DrawString(50, 800, "Score=0", colors[MISTY_ROSE]);

	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
//	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 



	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
//	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

//	DrawCircle(50,670,10,colors[RED]);
//	DrawCircle(70,670,10,colors[RED]);
//	DrawCircle(90,670,10,colors[RED]);

	if(colorChange[10]==false)
		DrawRoundRect(50, 550, 100, 100, colors[DARK_OLIVE_GREEN], 20);
	else DrawRoundRect(50, 550, 100, 100, colors[LIME_GREEN], 20);
	DrawString(75, 590, "Back", colors[RED]);

	DrawRoundRect(310, 350, 400, 250, colors[DARK_OLIVE_GREEN], 20);

	DrawString(450, 570, "Player 1", colors[RED]);
	DrawString(340, 540, "Keys:", colors[RED]);
	DrawString(340, 420, "Vehicle:", colors[RED]);

	if(colorChange[0]==false)
		DrawRoundRect(320, 450, 150, 80, colors[YELLOW], 20);
	else DrawRoundRect(320, 450, 150, 80, colors[ORANGE], 20);
	{
		DrawRectangle(380, 497, 30, 30, colors[WHITE]);
		DrawString(387, 504, "^", colors[BLACK]);

		DrawRectangle(380, 464, 30, 30, colors[WHITE]);
		DrawString(389, 471, "v", colors[BLACK]);

		DrawRectangle(347, 464, 30, 30, colors[WHITE]);
		DrawString(356, 471, "<", colors[BLACK]);

		DrawRectangle(413, 464, 30, 30, colors[WHITE]);
		DrawString(422, 471, ">", colors[BLACK]);
	}

	if(colorChange[1]==false)
		DrawRoundRect(550, 450, 150, 80, colors[YELLOW], 20);
	else DrawRoundRect(550, 450, 150, 80, colors[ORANGE], 20);
	{
		DrawRectangle(610, 497, 30, 30, colors[WHITE]);
	    DrawString(617, 504, "w", colors[BLACK]);

		DrawRectangle(610, 464, 30, 30, colors[WHITE]);
		DrawString(619, 471, "s", colors[BLACK]);

		DrawRectangle(577, 464, 30, 30, colors[WHITE]);
		DrawString(586, 471, "a", colors[BLACK]);

		DrawRectangle(643, 464, 30, 30, colors[WHITE]);
		DrawString(652, 471, "d", colors[BLACK]);
	}
	
	if(colorChange[2]==false)
		DrawRoundRect(320, 370, 100, 40, colors[YELLOW], 20);
	else DrawRoundRect(320, 370, 100, 40, colors[ORANGE], 20);
	DrawString(345, 382, "Tank", colors[RED]);

	if(colorChange[3]==false)
		DrawRoundRect(430, 370, 150, 40, colors[YELLOW], 20);
	else DrawRoundRect(430, 370, 150, 40, colors[ORANGE], 20);
	DrawString(455, 382, "Helicopter", colors[RED]);

	if(colorChange[4]==false)
		DrawRoundRect(590, 370, 100, 40, colors[YELLOW], 20);
	else DrawRoundRect(590, 370, 100, 40, colors[ORANGE], 20);
	DrawString(615, 382, "Plan", colors[RED]);
	

	DrawRoundRect(310, 50, 400, 250, colors[DARK_OLIVE_GREEN], 20);

	DrawString(450, 570-300, "Player 2", colors[RED]);
	DrawString(340, 540 - 300, "Keys:", colors[RED]);
	DrawString(340, 420 - 300, "Vehicle:", colors[RED]);

	if(colorChange[5]==false)
		DrawRoundRect(320, 450 - 300, 150, 80, colors[YELLOW], 20);
	else DrawRoundRect(320, 450 - 300, 150, 80, colors[ORANGE], 20);
	{
		DrawRectangle(380, 497 - 300, 30, 30, colors[WHITE]);
		DrawString(387, 504 - 300, "^", colors[BLACK]);

		DrawRectangle(380, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(389, 471 - 300, "v", colors[BLACK]);

		DrawRectangle(347, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(356, 471 - 300, "<", colors[BLACK]);

		DrawRectangle(413, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(422, 471 - 300, ">", colors[BLACK]);
	}

	if(colorChange[6]==false)
		DrawRoundRect(550, 450 - 300, 150, 80, colors[YELLOW], 20);
	else DrawRoundRect(550, 450 - 300, 150, 80, colors[ORANGE], 20);
	{
		DrawRectangle(610, 497 - 300, 30, 30, colors[WHITE]);
		DrawString(617, 504 - 300, "w", colors[BLACK]);

		DrawRectangle(610, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(619, 471 - 300, "s", colors[BLACK]);

		DrawRectangle(577, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(586, 471 - 300, "a", colors[BLACK]);

		DrawRectangle(643, 464 - 300, 30, 30, colors[WHITE]);
		DrawString(652, 471 - 300, "d", colors[BLACK]);
	}

	if(colorChange[7]==false)
		DrawRoundRect(320, 370 - 300, 100, 40, colors[YELLOW], 20);
	else DrawRoundRect(320, 370 - 300, 100, 40, colors[ORANGE], 20);
	DrawString(345, 382 - 300, "Tank", colors[RED]);

	if(colorChange[8]==false)
		DrawRoundRect(430, 370 - 300, 150, 40, colors[YELLOW], 20);
	else DrawRoundRect(430, 370 - 300, 150, 40, colors[ORANGE], 20);
	DrawString(455, 382 - 300, "Helicopter", colors[RED]);

	if(colorChange[9]==false)
		DrawRoundRect(590, 370 - 300, 100, 40, colors[YELLOW], 20);
	else DrawRoundRect(590, 370 - 300, 100, 40, colors[ORANGE], 20);
	DrawString(615, 382 - 300, "Plan", colors[RED]);

	//	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);

	glutSwapBuffers(); // do not modify this line..

}


void MultiEndScene :: GameDisplay(Player play[])
{
	if(play[0].lives>play[1].lives)
	  DrawString(400, 600, "Player 1 WINS!!!", colors[MISTY_ROSE]);
	else DrawString(400, 600, "Player 2 WINS!!!", colors[MISTY_ROSE]);

	play[0].lives = 10;
	play[1].lives = 10;

	lead = new LeaderBoard;
	lead->readFile(s->play);
	delete lead;

	play[0].score = 0;
	play[1].score = 0;

	m.fruit_count = 0;

	delete play[0].car;
	delete play[1].car;

	play[0].car = nullptr;
	play[1].car = nullptr;

    DrawRoundRect(310, 400, 400, 50, colors[DARK_OLIVE_GREEN], 20);
	DrawString(470, 420, "Again", colors[RED]);

	DrawRoundRect(310, 200, 400, 50, colors[DARK_OLIVE_GREEN], 20);
	DrawString(470, 220, "Menu", colors[RED]);

	//glutSwapBuffers();
}

void SingleEndScene::GameDisplay(Player play[])
{
	if (play[0].level > 3)
		DrawString(400, 600, "Player WINS!!!", colors[MISTY_ROSE]);
	else DrawString(400, 600, "Player LOSE!!!", colors[MISTY_ROSE]);

	DrawRoundRect(310, 200, 400, 50, colors[DARK_OLIVE_GREEN], 20);
	DrawString(470, 220, "Menu", colors[RED]);

	//glutSwapBuffers();
}


void GameDisplay()
{
	if (gameStart == false)
	{
        s->scene = &menu;

		lead = new LeaderBoard;
		lead->readFile(s->play);
		delete lead;
	}
		

	gameStart = true;

	s->scene->GameDisplay(s->play);
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	if (key == GLUT_KEY_UP)
	{
		//kee = key;
		keyarr[38] = true;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		//kee = key;
		keyarr[40] = true;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		//kee = key;
		keyarr[37] = true;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		//kee = key;
		keyarr[39] = true;
	}
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();
}

void NonPrintableKeyUP(int key, int x, int y) {

	if (key == GLUT_KEY_UP)
	{
		keyarr[38] = false;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		keyarr[40] = false;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		keyarr[37] = false;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		keyarr[39] = false;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	//cout << key << endl;
	keyarr[int(key)] = true;

	glutPostRedisplay();
}

void PrintableKeyUP(unsigned char key, int x, int y) {

	//cout << key << endl;
	keyarr[int(key)] = false;
	glutPostRedisplay();
	
}


/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer_bot(int m) {

	// implement your functionality here

	if (s->play[0].car != nullptr && c1 != nullptr)
	{
		cout << "medium " << c1[0].num_medium << endl;
		for (int i = 0;i< s->play[0].level + 1; i++)
		{
			c1[i].moveCar(*s->play[0].car,s->play[0]);

			c1[i].shootCar(*s->play[0].car);
		}
	}

	if(s->play[0].level==3)
		glutTimerFunc(175, Timer_bot, 0);

	else glutTimerFunc(200, Timer_bot, 0);
}

void Timer_bullet(int m) {

	// implement your functionality here

	if (s->play[0].car != nullptr)
	{
		for (int i = 0; i < 3; i++)
		{
			if (s->play[0].car->bullet[i] != nullptr)
				s->play[0].car->bullet[i]->moveBullet();

			if (s->play[1].car && s->play[1].car->bullet[i] != nullptr)
				s->play[1].car->bullet[i]->moveBullet();
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (c1 != nullptr)
		{
			for (int j = 0; j < s->play[0].level + 1; j++)
			{
				if (c1[j].bullet[i] != nullptr)
					c1[j].bullet[i]->moveBullet();
			}
		}
	}
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(30, Timer_bullet, 0);
}

void Timer_multi1(int m) {

	// implement your functionality here
	s->attack_key();

	s->movement_key1();

	cout<<"player "<<s->play[0].name << endl;

	// once again we tell the library to call our Timer function after next 1000/FPS

	if(s->play[0].car!=nullptr && s->play[0].car->powerup==true)
		glutTimerFunc(35, Timer_multi1, 0);

	else glutTimerFunc(50, Timer_multi1, 0);
}

void Timer_multi2(int m) {

	// implement your functionality here
	s->attack_key();
	s->movement_key2();

	// once again we tell the library to call our Timer function after next 1000/FPS

	if(s->play[1].car != nullptr && s->play[1].car->powerup==true)
		glutTimerFunc(35, Timer_multi2, 0);

	else glutTimerFunc(50, Timer_multi2, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//cout << x << " " << y << endl;
	if (s->scene==&menu && x > 310 && x < 710 && y > 100 && y < 200)
	{
		menu.colorChange[0] = true;
	}

	else if (s->scene == &menu && x > 310 && x < 710 && y > 300 && y < 400)
	{
		menu.colorChange[1] = true;
	}

	else if (s->scene == &menu && x > 310 && x < 710 && y > 500 && y < 600)
	{
		menu.colorChange[2] = true;
	}
	else if (s->scene == &menu && x > 770 && x < 970 && y > 50 && y < 100)
	{
		menu.colorChange[3] = true;
	}
	else if (s->scene == setting && x > 50 && x < 150 && y>50 && y < 150)
	{
		setting->colorChange[10] = true;
	}

	else if (s->scene && s->scene == setting)
	{
		setting->colorChange[10] = false;
	}
	else if(s->scene==&menu)
	{
		menu.colorChange[0] = false;
		menu.colorChange[1] = false;
		menu.colorChange[2] = false;
		menu.colorChange[3] = false;
	}

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if (s->scene == &menu && x > 310 && x < 710 && y > 100 && y < 200)
		{
			if (s->play[0].car == nullptr)
			{
				s->play[0].car = new Car;
			}
			sing = new SingleLevel;

			s->scene = sing;
			s->scene->GameDisplay(s->play);
		}
		else if (s->scene == &menu && x > 310 && x < 710 && y > 300 && y < 400)
		{
			if (s->play[0].car == nullptr)
			{
				s->play[0].car = new Car;
				s->play[1].car = new Car;
			}
			multi = new MultiLevel;

			s->scene = multi;
			s->scene->GameDisplay(s->play);
		}

		else if (s->scene == &menu && x > 310 && x < 710 && y > 500 && y < 600)
		{
			setting = new Setting;
			s->scene = setting;
			s->scene->GameDisplay(s->play);
		}
		else if (s->scene == &menu && x > 770 && x < 970 && y > 50 && y < 100)
		{
			lead = new LeaderBoard;

			s->scene=lead;
			lead->total = 0;
			lead->readFile(s->play);
			s->scene->GameDisplay(s->play);
		}
		else if (s->scene == setting && x > 320 && x < 470 && y>170 && y < 250)
		{
			setting->colorChange[0] = true;
			setting->colorChange[1] = false;
			setting->colorChange[5] = false;
			setting->colorChange[6] = true;

			s->play[0].key_setup = 0;
			s->play[1].key_setup = 0;
		}
		else if (s->scene == setting && x > 550 && x < 700 && y>170 && y < 250)
		{
			setting->colorChange[0] = false;
			setting->colorChange[1] = true;
			setting->colorChange[5] = true;
			setting->colorChange[6] = false;

			s->play[1].key_setup = 1;
			s->play[0].key_setup = 1;
		}
		else if (s->scene == setting && x > 320 && x < 470 && y>470 && y < 550)
		{
			setting->colorChange[0] = false;
			setting->colorChange[1] = true;
			setting->colorChange[5] = true;
			setting->colorChange[6] = false;

			s->play[1].key_setup = 1;
			s->play[0].key_setup = 1;
		}
		else if (s->scene == setting && x > 550 && x < 700 && y>470 && y < 550)
		{
			setting->colorChange[0] = true;
			setting->colorChange[1] = false;
			setting->colorChange[5] = false;
			setting->colorChange[6] = true;

			s->play[0].key_setup = 0;
			s->play[1].key_setup = 0;
		}
		else if (s->scene == setting && x > 320 && x < 420 && y>290 && y < 330)
		{
			setting->colorChange[2] = true;
			setting->colorChange[3] = false;
			setting->colorChange[4] = false;
		}
		else if (s->scene == setting && x > 430 && x < 580 && y>290 && y < 330)
		{
			setting->colorChange[2] = false;
			setting->colorChange[3] = true;
			setting->colorChange[4] = false;
		}
		else if (s->scene == setting && x > 590 && x < 690 && y>290 && y < 330)
		{
			setting->colorChange[2] = false;
			setting->colorChange[3] = false;
			setting->colorChange[4] = true;
		}
		else if (s->scene == setting && x > 320 && x < 420 && y>590 && y < 630)
		{
			setting->colorChange[7] = true;
			setting->colorChange[8] = false;
			setting->colorChange[9] = false;
		}
		else if (s->scene == setting && x > 430 && x < 580 && y>590 && y < 630)
		{
			setting->colorChange[7] = false;
			setting->colorChange[8] = true;
			setting->colorChange[9] = false;
		}
		else if (s->scene == setting && x > 590 && x < 690 && y>590 && y < 630)
		{
			setting->colorChange[7] = false;
			setting->colorChange[8] = false;
			setting->colorChange[9] = true;
		}
		else if (s->scene == setting && x > 50 && x < 150 && y>50 && y < 150)
		{
			setting->colorChange[10] = true;

			delete setting;

			s->scene = &menu;
			s->scene->GameDisplay(s->play);
		}

		else if (s->scene == lead && x > 50 && x < 150 && y>50 && y < 150)
		{
		   delete lead;

		    s->scene = &menu;
		    s->scene->GameDisplay(s->play);
		}

		else if (s->scene == Mend && x > 310 && x < 710 && y>250 && y < 300)
		{
		    s->play[0].car = new Car;
		    s->play[1].car = new Car;

			delete multi;

			multi = new MultiLevel;

		    s->scene = multi;
		    s->scene->GameDisplay(s->play);
		}
		else if (s->scene == Mend && x > 310 && x < 710 && y>450 && y < 500)
		{  
		    delete Mend;

		    s->scene = &menu;
		    s->scene->GameDisplay(s->play);
		}
		else if (s->scene == Send && x > 310 && x < 710 && y>450 && y < 500)
		{
		    delete Send;

		    s->scene = &menu;
		    s->scene->GameDisplay(s->play);
		}

	} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}

void idle()
{

	glutPostRedisplay();
}

void resize(int n1, int n2)
{
	glutPositionWindow(50, 20);
	glutReshapeWindow(1020, 700);
}
/*
 * our gateway main function
 * */

int main(int argc, char*argv[]) {


	cout << "Welcome to Combat!" << endl;
	cout << "**************************************" << endl;
	cout << endl;
	cout << "Enter Name of Player 1: ";
	cin >> s->play[0].name;
	cout << "Enter Name of Player 2: ";
	cin >> s->play[1].name;

	srand(time(0));

	int width = 1020, height = 700; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 20); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Combat by Moiz Akhtar"); // set the title of our game window
	glutReshapeFunc(resize);
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	
	glutSpecialUpFunc(NonPrintableKeyUP);
	glutKeyboardUpFunc(PrintableKeyUP);

	glutTimerFunc(1000.0, Timer_bot, 0);
	glutTimerFunc(1000.0, Timer_bullet, 0);
	glutTimerFunc(1000.0, Timer_multi1, 0);
	glutTimerFunc(1000.0, Timer_multi2, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	glutIdleFunc(idle);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
