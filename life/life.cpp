#include "Board.h"

#include <iostream>
#include <iomanip>

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
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	out << buff;
	//system("PAUSE");
	//Sleep(50);
}

void markcolony(std::vector<std::vector<char>>& field, const vector<Colony>& colonys) {
	for (const auto& colony : colonys) {
		for (const Cell& cell : colony.GetColony()) {
			field[cell.Coords_.x_][cell.Coords_.y_] = '*';
		}
	}
}

int main() {
	Coordinates max_filed_coords{ 101,131 };
	system("MODE CON COLS=150 LINES=190");
	vector<vector<char>> field(max_filed_coords.x_);
	for (auto& vec : field) {
		vec.resize(max_filed_coords.y_);
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

	Colony Toad;
	Cell I = { 40, 60 };
	Cell K = { 40, 61 };
	Cell L = { 41, 62 };
	Cell M = { 42, 59 };
	Cell O = { 43, 60 };
	Cell P = { 43, 61 };
	Toad.AddCell(I).AddCell(K).AddCell(L).AddCell(M).AddCell(O).AddCell(P);

	Colony PentaminoR;
	Cell pA = { 55, 60 };
	Cell pB = { 55, 61 };
	Cell pC = { 55, 62 };
	Cell pD = { 56, 61 };
	Cell pE = { 54, 60 };
	PentaminoR.AddCell(pA).AddCell(pB).AddCell(pC).AddCell(pD).AddCell(pE);


	vector<Colony> test{ PentaminoR };

	Evolution Earth(std::move(test));

	while(1){
	

		makeplayground(field);
		markcolony(field, Earth.GetColonys());
		displayplayground(field, cout);
		Earth.LifeCircle(max_filed_coords);
		cout << "Evolution lifetime: " << std::fixed << std::setprecision(2) << Earth.GetLifeTime() << " seconds" << endl;
	}

	return 0;
}
