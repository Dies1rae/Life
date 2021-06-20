#pragma once
#include "Cell.h"

#include <deque>

class Colony {
public:
	Colony();
	explicit Colony(const size_t size);
	explicit Colony(const size_t size, const Point& start_loc);
	explicit Colony(const Cell& newcolony);
	~Colony(){}
	
	const std::deque<Cell> GetColony();
	void KillCells();
	void BornCells();
	void RemoveCell(const Cell& cell);
	void AddCell(const Cell& cell);
	const size_t Size() const;
	const bool Empty() const;

private:
	size_t colony_gen_ = 0;
	Point colony_location_;
	std::deque<Cell> colony_;
};

