#include "Board.h"

#include <iostream>

using namespace std;


void makeplayground(std::vector<std::vector<char>>& field) {
	for (size_t y = 0; y < field.size(); y++) {
		for (size_t x = 0; x < field[y].size(); x++) {
			if (x == 0 || y == 0 || x == 121 - 1 || y == 51 - 1) {
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
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	out << buff;
	//system("PAUSE");
	Sleep(300);
}

void markcolony(std::vector<std::vector<char>>& field, const vector<Colony>& colonys) {
	for (const auto& colony : colonys) {
		for (const auto& cell : colony.GetColony()) {
			field[cell.Coords_.x_][cell.Coords_.y_] = '*';
		}
	}
}

int main() {
	vector<vector<char>> field(51);
	for (auto& vec : field) {
		vec.resize(121);
	}
	Colony Glider;
	Cell A = { 25, 60 };
	Cell B = { 25, 61 };
	Cell C = { 25, 62 };
	Cell D = { 24, 62 };
	Cell E = { 23, 61 };
	Glider.AddCell(A);
	Glider.AddCell(B);
	Glider.AddCell(C);
	Glider.AddCell(D);
	Glider.AddCell(E);
	Colony Stick;
	Cell F = { 10, 31 };
	Cell J = { 10, 32 };
	Cell H = { 10, 33 };
	Stick.AddCell(F).AddCell(J).AddCell(H);

	vector<Colony> test{ Glider, Stick };

	while(1){
		makeplayground(field);
		markcolony(field, test);
		displayplayground(field, cout);
		cout << "Generation Glider: " << test[0].GetGen() << endl;
		cout << "Colony Glider size: " << test[0].GetColony().size() << endl;
		cout << "Generation Stick: " << test[1].GetGen() << endl;
		cout << "Colony Stick size: " << test[1].GetColony().size() << endl;
		for (auto& colony : test) {
			colony.ColonyLifeCircle();
		}

	}

	return 0;
}
