#include "Evolution.h"

#include <unordered_map>

void Evolution::AddColony(const Colony& colony) {
	this->colonys_.push_back(colony);
}

void Evolution::AddColony(Colony&& colony) {
	this->colonys_.push_back(std::move(colony));
}

void Evolution::KillColonys() {
	this->colonys_.erase(std::remove_if(this->colonys_.begin(), this->colonys_.end(), [](const Colony& A){
		return A.Empty();
		}), this->colonys_.end());
}

void Evolution::BornColonys() {
	for (auto& colony : this->colonys_) {
		auto& ptr_tovec = colony.GetColony();
		std::unordered_map<Cell, int, CellHesher> coords;
		for (auto ptr = 0; ptr < ptr_tovec.size(); ptr++) {
			coords[{ptr_tovec[ptr].Coords_.x_ - 1, ptr_tovec[ptr].Coords_.y_}]++;
			coords[{ptr_tovec[ptr].Coords_.x_ - 1, ptr_tovec[ptr].Coords_.y_ - 1}]++;
			coords[{ptr_tovec[ptr].Coords_.x_ - 1, ptr_tovec[ptr].Coords_.y_ + 1}]++;
			coords[{ptr_tovec[ptr].Coords_.x_, ptr_tovec[ptr].Coords_.y_ - 1}]++;
			coords[{ptr_tovec[ptr].Coords_.x_ + 1, ptr_tovec[ptr].Coords_.y_ - 1}]++;
			coords[{ptr_tovec[ptr].Coords_.x_ + 1, ptr_tovec[ptr].Coords_.y_}]++;
			coords[{ptr_tovec[ptr].Coords_.x_ + 1, ptr_tovec[ptr].Coords_.y_ + 1}]++;
			coords[{ptr_tovec[ptr].Coords_.x_, ptr_tovec[ptr].Coords_.y_ + 1}]++;

			for (auto& [cell, ctr] : coords) {
				auto cl_same = std::find_if(ptr_tovec.begin(), ptr_tovec.end(), [cell](const Cell& A) {
					return A == cell;
					});
				if (ctr == 2 && cl_same == ptr_tovec.end()) {
					/// HOW TO SLICE ALL FIGURE??????
				}
			}
		}
	}
}

void Evolution::LifeCircle(const Coordinates& field) {
	for (auto& colony : this->colonys_) {
		bool cellpos = true;
		for (Cell& cell : colony.GetColony()) {
			if (cell.Coords_.x_ >= field.x_ - 1 || cell.Coords_.y_ >= field.y_ - 1 || cell.Coords_.x_ < 1 || cell.Coords_.y_ < 1) {
				cellpos = false;
				colony.RemoveCell(cell);
			}
		}
		if (cellpos) {
			colony.ColonyLifeCircle();
		}
	}
	this->KillColonys();
}

const std::vector<Colony>& Evolution::GetColonys() const {
	return this->colonys_;
}

bool Evolution::Empty() const {
	return this->colonys_.empty();
}

size_t Evolution::Size() const {
	return this->colonys_.size();
}

std::vector<std::pair<std::string, size_t>> Evolution::GetColonyData() const {
	std::vector<std::pair<std::string, size_t>> data;
	for (const auto& colony : this->colonys_) {
		data.push_back({colony.GetType(),colony.GetGen()});
	}
	return data;
}

double Evolution::GetLifeTime() const {
	HightTime::time_point end_time = HightTime::now();
	return std::chrono::duration<double, std::milli>(end_time - this->timer_start_).count() / 1000;
}

const bool Evolution::Static() const {
	for (const auto& colony : this->colonys_) {
		if (!colony.Static()) {
			return false;
		}
	}
	return true;
}

void Evolution::Clear() {
	this->colonys_.clear();
	this->timer_start_ = HightTime::now();
}