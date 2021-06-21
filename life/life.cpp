#include "Board.h"

#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>


using namespace std;

const char border_sym = '0';
const char ground_sym = '.';
const char cell_sym = '*';

void makeplayground(vector<vector<char>>& field) {
	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			if (x == 0 || y == 0 || x == 121 - 1 || y == 51 - 1) {
				field[y][x] = border_sym;
			} else {
				field[y][x] = ground_sym;
			}
		}
	}
}

void displayplayground(vector<vector<char>>& field, std::ostream& out) {
	std::string buff;
	
	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			buff += field[y][x];
		}
		buff += '\n';
	}
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	out << buff;
	//system("PAUSE");
	Sleep(500);
}

void markcolony(vector<vector<char>>& field, const Colony& colony) {
	for (const auto& cell : colony.GetColony()) {
		field[cell.Coords_.x_][cell.Coords_.y_] = cell_sym;
	}
}

int main() {
	vector<vector<char>> field(51);
	for (auto& vec : field) {
		vec.resize(121);
	}
	Colony test;
	Cell A = { 25, 60 };
	Cell B = { 25, 61 };
	Cell C = { 25, 62 };
	Cell D = { 24, 62 };
	Cell E = { 23, 61 };
	test.AddCell(A);
	test.AddCell(B);
	test.AddCell(C);
	test.AddCell(D);
	test.AddCell(E);
	while(1){
		for (const auto& cell : test.GetColony()) {
			std::cout << cell.Coords_.x_ << ' ' << cell.Coords_.y_ << std::endl;
		}
		makeplayground(field);
		markcolony(field, test);
		displayplayground(field, cout);
		cout << "Generation: " << test.GetGen() << endl;
		cout << "Colony size: " << test.GetColony().size() << endl;
		test.IncrementGen();
		test.BornCells();
		

	}

	return 0;
}
