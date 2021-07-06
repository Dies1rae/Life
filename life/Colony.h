#pragma once

#include "Cell.h"

#include <vector>
#include <string>

class Colony {
public:
	Colony() = default;
	explicit Colony(const std::vector<Cell>& cells) {
		for (const auto& cell : cells) {
			this->AddCell(cell);
		}
	}
	explicit Colony(const Coordinates& mfieldsize) : max_field_sizes_(mfieldsize) {}
	explicit Colony(const std::vector<Cell>& cells, const Coordinates& mfieldsize) : max_field_sizes_(mfieldsize) {
		for (const auto& cell : cells) {
			this->AddCell(cell);
		}
	}
	Colony(const Colony& rhs) {
		if (this != &rhs) {
			this->cell_static = rhs.cell_static;
			this->colony_gen_ = rhs.colony_gen_;
			this->colony_type_ = rhs.colony_type_;
			this->max_field_sizes_ = rhs.max_field_sizes_;
			this->colony_.resize(rhs.colony_.size());
			std::copy(rhs.colony_.begin(), rhs.colony_.end(), this->colony_.begin());
		}
	}
	virtual ~Colony(){}
	
	const std::vector<Cell>& GetColony() const;
	std::vector<Cell>& GetColony();

	void KillCells();
	void ColonyLifeCircle();

	void RemoveCell(const size_t pos);
	void RemoveCell(const Cell& cell);

	Colony& AddCell(const Cell& cell);
	Colony& AddCell(const Coordinates& cellcoord);

	size_t Size() const;
	bool Empty() const;

	size_t GetGen() const;
	void IncrementGen();

	void SetType(const std::string& Type);
	const std::string GetType() const;

	const bool Static() const;
private:
	std::pair<int, int> cell_static = {0,0};
	size_t colony_gen_ = 1;
	Coordinates max_field_sizes_ = Coordinates::NONE;
	std::string colony_type_ = "Free";
	std::vector<Cell> colony_;
};


inline bool operator==(const Colony& lhs, const Colony& rhs) {
	return lhs.GetGen() == rhs.GetGen() && lhs.GetColony() == rhs.GetColony() && lhs.GetType() == rhs.GetType();
}

inline bool operator!=(const Colony& lhs, const Colony& rhs) {
	return !(lhs == rhs);
}