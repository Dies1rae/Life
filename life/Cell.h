#pragma once

#include "Exception.h"

#include <algorithm>
#include <numeric>

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

struct Coordinates {
	int x_ = 0;
	int y_ = 0;
};

struct Cell {
public:
	Cell& operator=(const Cell& rhs) {
		if (this != &rhs) {
			Cell tmp(rhs);
			std::swap(tmp.Coords_.x_, this->Coords_.x_);
			std::swap(tmp.Coords_.y_, this->Coords_.y_);
			std::swap(tmp.life_, this->life_);
		}
		return *this;
	}

	Coordinates Coords_;
	bool life_ = true;
	inline static constexpr int hasher_salt = 32;
};

struct CellHesher {
	int operator()(const Cell& cell) const {
		return (cell.Coords_.x_ * cell.hasher_salt) + ((cell.Coords_.y_ * cell.hasher_salt) * (cell.Coords_.y_ * cell.hasher_salt));
	}
	int operator()(const Cell* cell) const {
		return (cell->Coords_.x_ * cell->hasher_salt) + ((cell->Coords_.y_ * cell->hasher_salt) * (cell->Coords_.y_ * cell->hasher_salt));
	}
};

bool operator<(const Cell& lhs, const Cell& rhs);
bool operator>(const Cell& lhs, const Cell& rhs);
bool operator==(const Cell& lhs, const Cell& rhs);
bool operator!=(const Cell& lhs, const Cell& rhs);