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
	~Colony(){}
	
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