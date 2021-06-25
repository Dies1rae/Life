#pragma once
#include "Colony.h"

#include <time.h>
#include <chrono>

class Evolution {
public:
	using HightTime = std::chrono::steady_clock;

	Evolution() = default;
	explicit Evolution(std::vector<Colony>&& params) noexcept {
		std::swap(this->colonys_, params);
	}
	explicit Evolution(const std::vector<Colony>& params) {
		this->colonys_ = params;
	}
	explicit Evolution(std::vector<std::vector<Cell>>& params) {
		for (auto& cells : params) {
			Colony* tmp = new Colony(std::move(cells));
			this->colonys_.push_back(std::move(*tmp));
		}
	}
	~Evolution(){}

	void AddColony(const Colony& colony);
	void AddColony(Colony&& colony);

	void KillColonys();
	void BornColonys();

	bool Empty() const;
	size_t Size() const;

	void LifeCircle(const Coordinates& field);

	const std::vector<Colony>& GetColonys() const;

	std::vector<std::pair<std::string, size_t>> GetColonyData() const;

	double GetLifeTime() const;

	const bool Static() const;

	void Clear();
private:
	HightTime::time_point timer_start_ = HightTime::now();
	std::vector<Colony> colonys_;
};

