#pragma once
#include "Cell.h"

#include <vector>
#include <random>
#include <algorithm>

class Colony {
public:
	Colony() = default;
	~Colony(){}
	
	std::vector<Cell> GetColony() const;

	void KillCells();
	const void ColonyLifeCircle();
	void RemoveCell(const size_t pos);

	Colony& AddCell(const Cell& cell);
	void AddCell(const Coordinates& cellcoord);

	const size_t Size() const;
	const bool Empty() const;

	const size_t GetGen() const;
	const void IncrementGen();

	Coordinates GetColonyCoord() const;
	void SetColonyCoord(const Coordinates& coord);

private:
	Coordinates PositionRandomizer(const std::pair<int, int>& minmax_x, const std::pair<int, int>& minmax_y) {
		std::random_device r;
		std::mt19937 edge(r());

		std::uniform_int_distribution<int> normal_dist_x(minmax_x.first, minmax_x.second);
		std::uniform_int_distribution<int> normal_dist_y(minmax_y.first, minmax_y.second);
		return { normal_dist_x(edge), normal_dist_y(edge) };
	}

	size_t colony_gen_ = 1;
	Coordinates colony_location_;
	std::vector<Cell> colony_;
};

