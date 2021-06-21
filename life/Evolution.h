#pragma once
#include "Colony.h"

#include<vector>

class Evolution {
public:
	Evolution();
	explicit Evolution(const std::vector<std::pair<size_t, Coordinates>>& params);
	~Evolution(){
		for (auto cl : this->colonys_) {
			delete cl;
		}
	}

	void GenerateColony(const std::vector<std::pair<size_t, Coordinates>>& params);
	void AddColony(const Colony* colony);
	void KillColonys();
	void BornColonys();
	void LifeCircle();
	const std::vector<Colony*>& GetColonys();

private:
	std::vector<Colony*> colonys_;
};

