#pragma once
#include "Evolution.h"

#include <sstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>

class Board {
	inline static constexpr char border_sym = '0';
	inline static constexpr char ground_sym = '.';
	inline static constexpr char cell_sym = '*';

	Board();
	Board(Evolution& evol) : petri_(evol){}
	~Board(){}

	void makeplayground(std::vector<std::vector<char>>& field);

	void displayplayground(std::vector<std::vector<char>>& field, std::ostream& out) const;

	void markcolony(std::vector<std::vector<char>>& field, const Colony& colony);

private:
	//time neded in sec
	Evolution& petri_;
};

