#include "Cell.h"

const Coordinates Coordinates::NONE = { -1, -1 };
const Coordinates Coordinates::NONE_MAX = { 16384, 16384 };


bool Coordinates::operator==(const Coordinates rhs) const {
	return this->x_ == rhs.x_ && this->y_ == rhs.y_;
}

bool Coordinates::operator<(const Coordinates rhs) const {
	return this->x_ < rhs.x_ && this->y_ < rhs.y_;
}

bool Coordinates::operator!=(const Coordinates& rhs) const {
	return !(*this == rhs);
}

bool Coordinates::operator>(const Coordinates& rhs) const {
	if (*this != rhs) {
		return !(*this < rhs);
	}
	return false;
}


bool Cell::operator>(const Cell& rhs) const {
	if (*this != rhs) {
		return !(*this < rhs);
	}
	return false;
}

bool Cell::operator<(const Cell& rhs) const {
	return this->Coords_.x_ < rhs.Coords_.x_ && this->Coords_.y_ < rhs.Coords_.y_;
}

bool Cell::operator==(const Cell& rhs) const {
	if(this->life_ && rhs.life_) {
		return this->Coords_.x_ == rhs.Coords_.x_ && this->Coords_.y_ == rhs.Coords_.y_;
	}
	return false;
}

bool Cell::operator!=(const Cell& rhs) const {
	return !(*this == rhs);
}


