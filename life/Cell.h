#pragma once

#include "Exception.h"

#include <algorithm>

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

struct Coordinates {
	int x_ = 0;
	int y_ = 0;

	static const Coordinates NONE;
	static const Coordinates NONE_MAX;

	bool operator==(Coordinates rhs) const;
	bool operator<(Coordinates rhs) const;
	bool operator!=(const Coordinates& rhs) const;
	bool operator>(const Coordinates& rhs) const;
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

	bool operator<(const Cell& rhs) const;
	bool operator>(const Cell& rhs) const;
	bool operator==(const Cell& rhs) const;
	bool operator!=(const Cell& rhs) const;

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


