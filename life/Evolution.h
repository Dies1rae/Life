#pragma once
#include "Colony.h"

#include<vector>

class Evolution {
public:
	Evolution();
	explicit Evolution(const std::vector<std::pair<size_t, Point>>& params);
	~Evolution(){
		for (auto cl : this->colonys_) {
			delete cl;
		}
	}

	void GenerateColony(const std::vector<std::pair<size_t, Point>>& params);
	void AddColony(const std::pair<size_t, Point>& params);
	void KillColonys();
	void BornColonys();
	void LifeCircle();
	const std::vector<Colony*>& GetColonys();

private:
	std::vector<Colony*> colonys_;
};

