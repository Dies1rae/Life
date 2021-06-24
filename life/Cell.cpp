#include "Cell.h"

bool operator>(const Cell& lhs, const Cell& rhs) {
	if (lhs != rhs) {
		return !(lhs < rhs);
	}
	return false;
}

bool operator<(const Cell& lhs, const Cell& rhs) {
	return lhs.Coords_.x_ < rhs.Coords_.x_&& lhs.Coords_.y_ < rhs.Coords_.y_;
}

bool operator==(const Cell& lhs, const Cell& rhs) {
	if(lhs.life_ && rhs.life_) {
		return lhs.Coords_.x_ == rhs.Coords_.x_ && lhs.Coords_.y_ == rhs.Coords_.y_;
	}
	return false;
}

bool operator!=(const Cell& lhs, const Cell& rhs) {
	return !(lhs == rhs);
}