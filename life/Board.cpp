#include "Board.h"


void Board::makeplayground(std::vector<std::vector<char>>& field) {
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

void Board::displayplayground(std::vector<std::vector<char>>& field, std::ostream& out) const {
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
	Sleep(300);
}

void Board::markcolony(std::vector<std::vector<char>>& field, const Colony& colony) {
	for (const auto& cell : colony.GetColony()) {
		field[cell.Coords_.x_][cell.Coords_.y_] = cell_sym;
	}
}