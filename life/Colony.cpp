#include "Colony.h"

#include <unordered_map>

const std::vector<Cell>& Colony::GetColony() const {
	return this->colony_;
}

std::vector<Cell>& Colony::GetColony() {
	return this->colony_;
}

void Colony::KillCells() {
	std::unordered_map<Cell*, int, CellHesher> coords;
	bool not_alone_cell = false;
	for (auto ptr = 0; ptr < this->colony_.size(); ptr++) {
		not_alone_cell = false;
		Cell tmp_cl_1 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_};
		auto cl_1 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_1](const Cell& A){
			return A == tmp_cl_1;
			});
		if (cl_1 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_1)]++;
		}

		Cell tmp_cl_2 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_2 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_2](const Cell& A) {
			return A == tmp_cl_2;
			});
		if (cl_2 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_2)]++;
		}

		Cell tmp_cl_3 = { this->colony_[ptr].Coords_.x_ - 1, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_3 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_3](const Cell& A) {
			return A == tmp_cl_3;
			});
		if (cl_3 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_3)]++;
		}
		
		Cell tmp_cl_4 = { this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_4 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_4](const Cell& A) {
			return A == tmp_cl_4;
			});
		if (cl_4 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_4)]++;
		}
		
		Cell tmp_cl_5 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ - 1};
		auto cl_5 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_5](const Cell& A) {
			return A == tmp_cl_5;
			});
		if (cl_5 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_5)]++;
		}
		
		Cell tmp_cl_6 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_};
		auto cl_6 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_6](const Cell& A) {
			return A == tmp_cl_6;
			});
		if (cl_6 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_6)]++;
		}
		
		Cell tmp_cl_7 = { this->colony_[ptr].Coords_.x_ + 1, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_7 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_7](const Cell& A) {
			return A == tmp_cl_7;
			});
		if (cl_7 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_7)]++;
		}
		
		Cell tmp_cl_8 = { this->colony_[ptr].Coords_.x_, this->colony_[ptr].Coords_.y_ + 1};
		auto cl_8 = std::find_if(this->colony_.begin(), this->colony_.end(), [&tmp_cl_8](const Cell& A) {
			return A == tmp_cl_8;
			});
		if (cl_8 != this->colony_.end()) {
			not_alone_cell = true;
			coords[&(*cl_8)]++;
		}

		if (!not_alone_cell) {
			this->colony_[ptr].life_ = false;
		}
	}

	for (const auto [cell, ctr] : coords) {
		if (ctr < 2 || ctr > 3) {
			cell->life_ = false;
		}
	}
	this->cell_static.first = this->colony_.size();
	this->colony_.erase(std::remove_if(this->colony_.begin(), this->colony_.end(), [](const Cell& A) {return A.life_ == false;}), this->colony_.end());
	this->cell_static.second = this->cell_static.first - this->colony_.size();
}

void Colony::ColonyLifeCircle() {
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

void Colony::RemoveCell(const Cell& cell) {
	this->colony_.erase(std::remove_if(this->colony_.begin(), this->colony_.end(), [&cell](const Cell& A) {return A == cell;}), this->colony_.end());
}

Colony& Colony::AddCell(const Cell& cell) {
	if (this->max_field_sizes_ != Coordinates::NONE) {
		if (cell.Coords_ > Coordinates::NONE && cell.Coords_ < this->max_field_sizes_) {
			this->cell_static.first = this->cell_static.second;
			this->cell_static.second++;
			this->colony_.push_back(cell);
		} else {
			throw InvalidPosition("Invalid Coordinates to Cell position");
		}
	} else {
		if (cell.Coords_ > Coordinates::NONE && cell.Coords_ < Coordinates::NONE_MAX) {
			this->cell_static.first = this->cell_static.second;
			this->cell_static.second++;
			this->colony_.push_back(cell);
		} else {
			throw InvalidPosition("Invalid Coordinates to Cell position");
		}
	}
	return *this;
}

Colony& Colony::AddCell(const Coordinates& cellcoord) {
	if (this->max_field_sizes_ != Coordinates::NONE) {
		if (cellcoord > Coordinates::NONE && cellcoord < this->max_field_sizes_) {
			this->cell_static.first = this->cell_static.second;
			this->cell_static.second++;
			this->colony_.push_back({ cellcoord });
		} else {
			throw InvalidPosition("Invalid Coordinates to Cell position");
		}
	} else {
		if (cellcoord > Coordinates::NONE && cellcoord < Coordinates::NONE_MAX) {
			this->cell_static.first = this->cell_static.second;
			this->cell_static.second++;
			this->colony_.push_back({ cellcoord });
		} else {
			throw InvalidPosition("Invalid Coordinates to Cell position");
		}
	}
	return *this;
}

size_t Colony::Size() const {
	return this->colony_.size();
}

bool Colony::Empty() const {
	return this->colony_.empty();
}

size_t Colony::GetGen() const {
	return this->colony_gen_;
}

void Colony::IncrementGen() {
	this->colony_gen_++;
}

void Colony::SetType(const std::string& Type) {
	this->colony_type_ = Type;
}

const std::string Colony::GetType() const {
	return this->colony_type_;
}

const bool Colony::Static() const {
	return this->cell_static.second == 0;
}