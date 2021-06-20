#pragma once

struct Point {
	int x_ = 0;
	int y_ = 0;
};

struct Cell {
public:
	Point Coords_;
	bool life_ = true;
};

