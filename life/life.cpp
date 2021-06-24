#include "Structures.h"
#include "Evolution.h"

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;


void makeplayground(std::vector<std::vector<char>>& field) {
	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			if (x == 0 || y == 0 || y == field.size() - 1 || x == field[y].size() - 1) {
				field[y][x] = '@';
			} else {
				field[y][x] = '.';
			}
		}
	}
}

void displayplayground(std::vector<std::vector<char>>& field, std::ostream& out) {
	std::string buff;

	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			buff += field[y][x];
		}
		buff += '\n';
	}
	#ifdef __linux__ 
		system("clear");
	#elif _WIN32
		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	#endif
	out << buff;
}

void markcolony(std::vector<std::vector<char>>& field, const vector<Colony>& colonys) {
	for (const auto& colony : colonys) {
		for (const Cell& cell : colony.GetColony()) {
			field[cell.Coords_.x_][cell.Coords_.y_] = '*';
		}
	}
}

int main() {
	system("MODE CON COLS=150 LINES=190");

	Coordinates max_filed_coords{ 101,131 };
	vector<vector<char>> field(max_filed_coords.x_);
	for (auto& vec : field) {
		vec.resize(max_filed_coords.y_);
	}

	RPentomino pent_u({ 50,64 }, Direction::UP, max_filed_coords);

	vector<Colony> test{ pent_u.colony_};

	Evolution Earth(std::move(test));

	while(!Earth.Empty()){
		makeplayground(field);
		markcolony(field, Earth.GetColonys());
		displayplayground(field, cout);
		Earth.LifeCircle(max_filed_coords);
		cout << "Evolution lifetime: " << std::fixed << std::setprecision(2) << Earth.GetLifeTime() << " seconds" << endl;
	}
	makeplayground(field);
	displayplayground(field, cout);
	cout << "END!\n";
	return 0;
}
