#pragma once

#include "Colony.h"

class Glider {
public:
	Glider(const Coordinates& pos, const Direction& direction, const Coordinates& max_field_size) : colony_(max_field_size) {
		if (pos.x_ < 3 || pos.x_ > (max_field_size.x_ - 4) || pos.y_ < 3 || pos.y_ >(max_field_size.y_ - 4)) {
			throw InvalidPosition("Invalid Glider start position");
		}
		switch (direction) {
		case Direction::UP:
			if (pos.y_ <= (max_field_size.y_ - 1) / 2) {
				Cell A = { pos.x_, pos.y_ };
				Cell B = { pos.x_, pos.y_ + 1 };
				Cell C = { pos.x_, pos.y_ + 2 };
				Cell D = { pos.x_ + 1, pos.y_ + 2 };
				Cell E = { pos.x_ + 2, pos.y_ + 1 };
				this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
			} else {
				Cell A = { pos.x_, pos.y_ };
				Cell B = { pos.x_, pos.y_ + 1 };
				Cell C = { pos.x_, pos.y_ + 2 };
				Cell D = { pos.x_ + 1, pos.y_ };
				Cell E = { pos.x_ + 2, pos.y_ + 1 };
				this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
			}
			break;
		case Direction::DOWN:
			if(pos.y_ <= (max_field_size.y_ - 1) / 2) {
				Cell A = { pos.x_, pos.y_ };
				Cell B = { pos.x_, pos.y_ + 1 };
				Cell C = { pos.x_, pos.y_ + 2 };
				Cell D = { pos.x_ - 1, pos.y_ + 2 };
				Cell E = { pos.x_ - 2, pos.y_ + 1 };
				this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
			} else {
				Cell A = { pos.x_, pos.y_ };
				Cell B = { pos.x_, pos.y_ + 1 };
				Cell C = { pos.x_, pos.y_ + 2 };
				Cell D = { pos.x_ - 1, pos.y_ };
				Cell E = { pos.x_ - 2, pos.y_ + 1 };
				this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
			}
			break;
		default:
			throw InvalidPosition("Invalid Glider direction");
			break;
		}
		this->colony_.SetType("Glider");
	}
	~Glider() {}

	Colony colony_;
};


class Blinker {
public:
	Blinker(const Coordinates& pos, const Coordinates& max_field_size) : colony_(max_field_size) {
		if (pos.x_ < 3 || pos.x_ > (max_field_size.x_ - 4) || pos.y_ < 3 || pos.y_ > (max_field_size.y_ - 4)) {
			throw InvalidPosition("Invalid Blinker start position");
		}
		Cell A = { pos.x_, pos.y_ };
		Cell B = { pos.x_, pos.y_ + 1 };
		Cell C = { pos.x_, pos.y_ + 2 };
		this->colony_.AddCell(A).AddCell(B).AddCell(C);
		this->colony_.SetType("Blinker");
	}
	~Blinker() {}

	Colony colony_;
};

class Toad {
public:
	Toad(const Coordinates& pos, const Direction& direction, const Coordinates& max_field_size) : colony_(max_field_size) {
		if (pos.x_ < 4 || pos.x_ >(max_field_size.x_ - 5) || pos.y_ < 4 || pos.y_ >(max_field_size.y_ - 5)) {
			throw InvalidPosition("Invalid Toad start position");
		}
		switch (direction) {
		case Direction::UP:
			{
				Cell A = { pos.x_, pos.y_ };
				Cell B = { pos.x_, pos.y_ + 1 };
				Cell C = { pos.x_ + 1, pos.y_ + 2 };
				Cell D = { pos.x_ + 2, pos.y_ - 1 };
				Cell E = { pos.x_ + 3, pos.y_ };
				Cell F = { pos.x_ + 3, pos.y_ + 1 };
				this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E).AddCell(F);
			}
			break;
		case Direction::DOWN:
			{
				Cell a = { pos.x_, pos.y_ };
				Cell b = { pos.x_ + 1, pos.y_ };
				Cell c = { pos.x_ + 2, pos.y_ + 1 };
				Cell d = { pos.x_ - 1, pos.y_ + 2 };
				Cell e = { pos.x_, pos.y_ + 3 };
				Cell g = { pos.x_ + 1, pos.y_ + 3 };
				this->colony_.AddCell(a).AddCell(b).AddCell(c).AddCell(d).AddCell(e).AddCell(g);
			}
			break;
		default:
			throw InvalidPosition("Invalid Toad direction");
			break;
		}
		this->colony_.SetType("Toad");
	}
	~Toad() {}

	Colony colony_;
};

class RPentomino {
public:
	RPentomino(const Coordinates& pos, const Direction& direction, const Coordinates& max_field_size) : colony_(max_field_size) {
		if (pos.x_ < 3 || pos.x_ >(max_field_size.x_ - 4) || pos.y_ < 3 || pos.y_ >(max_field_size.y_ - 4)) {
			throw InvalidPosition("Invalid RPentomino start position");
		}
		switch (direction) {
		case Direction::UP:
		{
			Cell A = { pos.x_, pos.y_ };
			Cell B = { pos.x_ + 1, pos.y_ };
			Cell C = { pos.x_ + 2, pos.y_ };
			Cell D = { pos.x_ + 1, pos.y_ - 1 };
			Cell E = { pos.x_, pos.y_ + 1 };
			this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
		}
		break;
		case Direction::DOWN:
		{
			Cell A = { pos.x_, pos.y_ };
			Cell B = { pos.x_ + 1, pos.y_ };
			Cell C = { pos.x_ + 2, pos.y_ };
			Cell D = { pos.x_ + 1, pos.y_ - 1 };
			Cell E = { pos.x_ + 2, pos.y_ + 1 };
			this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
		}
		break;
		case Direction::RIGHT:
		{
			Cell A = { pos.x_, pos.y_ };
			Cell B = { pos.x_, pos.y_ + 1 };
			Cell C = { pos.x_, pos.y_ + 2 };
			Cell D = { pos.x_ - 1, pos.y_ + 2 };
			Cell E = { pos.x_ + 1, pos.y_ + 1 };
			this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
		}
		break;
		case Direction::LEFT:
		{
			Cell A = { pos.x_, pos.y_ };
			Cell B = { pos.x_, pos.y_ + 1 };
			Cell C = { pos.x_, pos.y_ + 2 };
			Cell D = { pos.x_ + 1, pos.y_ };
			Cell E = { pos.x_ - 1, pos.y_ + 1 };
			this->colony_.AddCell(A).AddCell(B).AddCell(C).AddCell(D).AddCell(E);
		}
		break;
		default:
			throw InvalidPosition("Invalid RPentomino direction");
			break;
		}
		this->colony_.SetType("RPentomino");
	}
	~RPentomino() {}

	Colony colony_;
};

class Free {
public:
	Free(const Coordinates& max_field_size) : colony_(max_field_size) {}
	~Free() {}

	Colony colony_;
};