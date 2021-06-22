#include "Colony.h"

#include<unordered_map>
#include <set>

std::vector<Cell> Colony::GetColony() const {
	return this->colony_;
}

void Colony::KillCells() {
	std::unordered_map<Cell*, int, CellHesher> coords;

	for (auto ptr = 0; ptr < this->colony_.size(); ptr++) {
		Cell tmp_cl_1 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_};
		auto cl_1 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_1](const Cell& A){
			return A == tmp_cl_1;
			});
		if (cl_1 != this->colony_.end()) {
			coords[&(*cl_1)]++;
		}

		Cell tmp_cl_2 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_2 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_2](const Cell& A) {
			return A == tmp_cl_2;
			});
		if (cl_2 != this->colony_.end()) {
			coords[&(*cl_2)]++;
		}

		Cell tmp_cl_3 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_3 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_3](const Cell& A) {
			return A == tmp_cl_3;
			});
		if (cl_3 != this->colony_.end()) {
			coords[&(*cl_3)]++;
		}
		
		Cell tmp_cl_4 = { this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_4 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_4](const Cell& A) {
			return A == tmp_cl_4;
			});
		if (cl_4 != this->colony_.end()) {
			coords[&(*cl_4)]++;
		}
		
		Cell tmp_cl_5 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_5 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_5](const Cell& A) {
			return A == tmp_cl_5;
			});
		if (cl_5 != this->colony_.end()) {
			coords[&(*cl_5)]++;
		}
		
		Cell tmp_cl_6 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_};
		auto cl_6 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_6](const Cell& A) {
			return A == tmp_cl_6;
			});
		if (cl_6 != this->colony_.end()) {
			coords[&(*cl_6)]++;
		}
		
		Cell tmp_cl_7 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_7 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_7](const Cell& A) {
			return A == tmp_cl_7;
			});
		if (cl_7 != this->colony_.end()) {
			coords[&(*cl_7)]++;
		}
		
		Cell tmp_cl_8 = { this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_8 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_8](const Cell& A) {
			return A == tmp_cl_8;
			});
		if (cl_8 != this->colony_.end()) {
			coords[&(*cl_8)]++;
		}
	}

	for (const auto [cell, ctr] : coords) {
		if (ctr < 2 || ctr > 3) {
			cell->life_ = false;
		}
	}

	this->colony_.erase(std::remove_if(this->colony_.begin(), this->colony_.end(), [](const Cell& A) {return A.life_ == false;}), this->colony_.end());
}

const void Colony::ColonyLifeCircle() {
	std::unordered_map<Cell, int, CellHesher> coords;
	for (auto ptr = 0; ptr < this->colony_.size(); ptr++) {
		coords[{this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_}]++;
		coords[{this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ - 1}]++;
		coords[{this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ + 1}]++;
		coords[{this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ - 1}]++;
		coords[{this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ - 1}]++;
		coords[{this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_}]++;
		coords[{this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ + 1}]++;
		coords[{this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ + 1}]++;
	}

	this->KillCells();
	for (auto& [cell, ctr] : coords) {
		auto cl_same = std::find_if(this->colony_.begin(), this->colony_.end(), [cell](const Cell& A) {
			return A == cell;
			});
		if (ctr == 3 && cl_same == this->colony_.end()) {
			this->AddCell(cell);
		}
	}
	this->IncrementGen();
}

void Colony::RemoveCell(const size_t pos) {
	this->colony_.erase(this->colony_.begin() + pos);
}

Colony& Colony::AddCell(const Cell& cell) {
	this->colony_.push_back(cell);
	return *this;
}

void Colony::AddCell(const Coordinates& cellcoord) {
	this->colony_.push_back({ cellcoord });
}

const size_t Colony::Size() const {
	return this->colony_.size();
}

const bool Colony::Empty() const {
	return this->colony_.empty();
}

const size_t Colony::GetGen() const {
	return this->colony_gen_;
}

const void Colony::IncrementGen() {
	this->colony_gen_++;
}

Coordinates Colony::GetColonyCoord() const {
	return this->colony_location_;
}

void Colony::SetColonyCoord(const Coordinates& coord) {
	this->colony_location_ = coord;
}