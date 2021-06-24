#pragma once
#include "Colony.h"

#include <string>
#include <vector>
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

	std::vector<std::string> GetColonyData() const {
		std::vector<std::string> data;
		for (const auto& colony : this->colonys_) {
			data.push_back(std::to_string(colony.GetGen()));
		}
		return data;
	}

	double GetLifeTime() {
		HightTime::time_point end_time = HightTime::now();
		return std::chrono::duration<double, std::milli>(end_time - this->timer_start_).count() / 1000;
	}
private:
	HightTime::time_point timer_start_ = HightTime::now();
	std::vector<Colony> colonys_;
};

