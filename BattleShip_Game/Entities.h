#pragma once
enum Directions { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13, REVERS = 32 };//

struct Point {

	int x = 1;
	int y = 1;

} point;


struct Striked
{
	bool striked = false;
	bool right = false;
	bool right_Access = false;
	bool left = false;
	bool left_Access = false;
	bool up = false;
	bool up_Access = false;
	bool down = false;
	bool down_Access = false;
	int striked_x = -1;
	int striked_y = -1;

}strike;