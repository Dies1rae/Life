#pragma once

#include <stdexcept>
#include <string>


class InvalidPosition : public std::out_of_range {
public:
	using std::out_of_range::out_of_range;
};